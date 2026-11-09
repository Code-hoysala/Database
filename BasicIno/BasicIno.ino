#include <Database.h>

Database wikiDb;

void setup() {
    Serial.begin(9600);
    while (!Serial);

    wikiDb.begin();

    // Storing pre-fetched reference / encyclopedia snippets locally
    wikiDb.insert("Arduino", "An open-source hardware and software company and project.");
    wikiDb.insert("AVR", "A family of RISC microcontroller chips developed by Atmel.");
    wikiDb.insert("Python", "A high-level, general-purpose programming language.");

    Serial.println(F("--- Database Initialized ---"));
    Serial.print(F("Total Records stored: "));
    Serial.println(wikiDb.getCount());
    Serial.println();

    // Querying stored data
    char buffer[64];
    if (wikiDb.get("Arduino", buffer, sizeof(buffer))) {
        Serial.print(F("Query [Arduino]: "));
        Serial.println(buffer);
    }
}

void loop() {
    // Non-blocking core loop
}