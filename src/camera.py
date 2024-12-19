import cv2
import serial

# Configure serial port
ser = serial.Serial('COM3', 9600)  # Replace with your port

camera_on = False
cap = None
while True:
    if ser.in_waiting > 0:
        command = ser.readline().decode('utf-8').strip()
        if command == "ON":
            if not camera_on:
                print("Turning on camera")
                cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)  # Force DirectShow backend for faster initialization

                # Set properties immediately after opening
                cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
                cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
                cap.set(cv2.CAP_PROP_FPS, 30)

                camera_on = True
        elif command == "OFF":
            if camera_on:
                cap.release()  # Release the webcam
                cv2.destroyAllWindows()
                camera_on = False

    if camera_on:
        ret, frame = cap.read()
        if ret:
            cv2.imshow("Smart Rearview Mirror Feed", frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit
                break

if camera_on:
    cap.release()
    cv2.destroyAllWindows()
