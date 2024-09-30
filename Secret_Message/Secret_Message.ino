#include <IRremote.h>

const int receiverPin = 11; // Pin connected to the IR receiver
IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
    Serial.begin(9600); // Initialize serial communication
    irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("IR Code: ");
        Serial.println(results.value, HEX); // Print the received code
        irrecv.resume(); // Prepare to receive the next value
    }
}
