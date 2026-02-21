#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author Piyush-2909singh
 * @date 2026-02-21
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

// LDR sensor connected to Analog Pin A0
#define LDR_PIN A0

// Variable to store sensor reading
int ldrValue = 0;

/**
 * @brief Initializes serial communication and system peripherals.
 */
void setup() {
    Serial.begin(9600);

    Serial.println("LDR Light Monitoring System Initialized...");
    Serial.println("----------------------------------------");
}

/**
 * @brief Main execution loop: Reads LDR data and determines brightness status.
 */
void loop() {
    // Read analog value from LDR (Range: 0 - 1023)
    ldrValue = analogRead(LDR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("Raw LDR Value: ");
    Serial.print(ldrValue);

    // Threshold logic for brightness detection
    // Typical values: < 300 Dark, 300-700 Dim, > 700 BrigHT
    if (ldrValue < 300) {
        Serial.println(" - Status: [DARK]");
    } else if (ldrValue < 700) {
        Serial.println(" - Status: [DIM]");
    } else {
        Serial.println(" - Status: [BRIGHT]");
    }

    // Stability delay
    delay(500);
}