# Database

`Database` is a lightweight, non-blocking static key-value record library for Arduino designed for embedded knowledge lookup, configuration storage, and structured text caching without dynamic memory overhead.

## Features
- **Static Record Storage:** Fixed-capacity key-value pairs stored in static arrays (`malloc`-free).
- **Fast Lookups:** O(n) linear lookup optimized for small embedded datasets.
- **Zero Memory Allocation:** Completely safe from heap fragmentation, perfect for resource-constrained AVR and ARM microcontrollers.

---

## Quick Start Example

```cpp
#include <Database.h>

Database db;

void setup() {
    Serial.begin(9600);
    db.begin();

    db.insert("Key1", "Stored Encyclopedia Data");
    
    char buffer[64];
    if (db.get("Key1", buffer, sizeof(buffer))) {
        Serial.println(buffer);
    }
}

void loop() {}
