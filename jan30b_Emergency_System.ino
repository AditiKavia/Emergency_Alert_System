#include <SoftwareSerial.h>

SoftwareSerial A9G(2, 3);  // A9G Module connected to pins 2 (RX) and 3 (TX)
//const int buttonPin = 8;   // Button connected to pin 8

void setup() {
  //  pinMode(buttonPin, INPUT_PULLUP);  // Set button as input with pull-up resistor
    Serial.begin(9600);
    A9G.begin(9600);
    Serial.println("A9G Initialized...");
}

void loop() {
    //if (digitalRead(buttonPin) == LOW) { // If button is pressed
     //   Serial.println("Button Pressed! Sending Alert...");
        makeCall("+91XXXXXXXXXX");  // Replace with your phone number
        String location = getGPSLocation();
        sendSMS("+91XXXXXXXXXX", location); // Replace with recipient's number
        delay(5000);  // Prevent multiple triggers
    
}

// **Function to Make a Call**
void makeCall(String number) {
    Serial.println("Calling " + number + "...");
    A9G.println("ATD" + number + ";"); // Dial number
    delay(10000); // Let it ring for 10 seconds
    A9G.println("ATH"); // Hang up
    Serial.println("Call Ended.");
}

// **Function to Get GPS Location**
String getGPSLocation() {
    Serial.println("Fetching GPS...");
    A9G.println("AT+GPS=1"); // Enable GPS
    delay(3000);
    A9G.println("AT+LOCATION=2"); // Get GPS data
    delay(3000);

    String response = "";
    while (A9G.available()) {
        response += A9G.readString();
    }

    Serial.println("GPS Response: " + response);
    int start = response.indexOf(":") + 1;
    int comma = response.indexOf(",");
    
    if (start == -1 || comma == -1) return "GPS data not available.";

    String latitude = response.substring(start, comma);
    String longitude = response.substring(comma + 1);

    return "Emergency! Location: https://www.google.com/maps/search/?api=1&query=" + latitude + "," + longitude;
}

// **Function to Send SMS**
void sendSMS(String number, String message) {
    Serial.println("Sending SMS...");
    A9G.println("AT+CMGF=1");  // Set SMS mode to text
    delay(1000);
    A9G.println("AT+CMGS=\"" + number + "\"");
    delay(1000);
    A9G.print("");
    A9G.write(26); // Send Ctrl+Z
    Serial.println("SMS Sent.");
}
