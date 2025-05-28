# Emergency_Alert_System
An Arduino-based emergency alert system utilizing the A9G GSM/GPS module to provide real-time location tracking and instant alerts for women's safety.

🛠️ What You Need
Arduino Uno (or any compatible Arduino board)
A9G GSM/GPS Module
SIM Card with active SMS and call services
Push Button (optional, for manual activation)
Jumper Wires
Breadboard
5V Power Supply (like a USB cable or battery pack)

🔌 How to Connect Everything
A9G Module to Arduino:
A9G TX → Arduino Pin 2
A9G RX → Arduino Pin 3
A9G VCC → 5V
A9G GND → GND
Push Button (optional):
One leg to Pin 8
Other leg to GND

Note: The push button is optional. If you prefer automatic activation, you can remove it and adjust the code accordingly.

📦 What the Code Does
Setup: Initializes communication with the A9G module.
Loop: Continuously checks if the button is pressed.
If pressed, it:
Makes a call to a predefined emergency number.
Retrieves the current GPS location.
Sends an SMS with the location link.

#Functions:
-> makeCall(): Initiates a call to the specified number.
-> getGPSLocation(): Fetches the current GPS coordinates and formats them into a Google Maps link.
-> sendSMS(): Sends an SMS to a specified number with the provided message.

# Important Notes:
Ensuring that SIM card has sufficient balance and is activated for SMS and call services.
Test the system in a safe environment before relying on it in real situations.
Handle the A9G module with care to prevent damage from voltage fluctuations.


