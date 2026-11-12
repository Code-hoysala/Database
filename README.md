# Database Library for Arduino

A lightweight, high-performance, **malloc-free** static key-value record library designed for resource-constrained microcontrollers. It uses fixed static memory allocation to prevent heap fragmentation while allowing efficient record insertion, retrieval, and modular package loading.

## Features

* **Zero Heap Allocation (`malloc`-free)**: Uses static memory buffers (`MAX_RECORDS`, `MAX_KEY_LEN`, `MAX_VAL_LEN`) ensuring safe and deterministic memory usage on AVR and other microcontrollers.
* **Modular Package Loading**: Built-in support via `loadPackage(uint8_t id)` to instantly load predefined datasets ranging from offline gaming engines (like Akinator) to 24+ standalone encyclopedia reference modules.
* **Non-Blocking & Fast**: Fast linear-search key-value lookups optimized for embedded execution loops.

## Installation

1. Download or clone this repository into your Arduino `libraries` folder.
2. Structure the folder as `Database/` containing `src/Database.h`, `src/Database.cpp`, and metadata files.
3. Restart the Arduino IDE.

## API Reference

### `Database()`
Constructs a new database instance.

### `void begin()`
Initializes and clears the database instance.

### `bool insert(const char* key, const char* value)`
Inserts a new key-value pair or updates an existing key if found. Returns `true` on success, or `false` if storage is full.

### `bool get(const char* key, char* buffer, size_t bufferSize) const`
Retrieves the value associated with the specified key into the provided character buffer. Returns `true` if found.

### `void clear()`
Clears all records from the database instance.

### `size_t count() const`
Returns the current number of active records stored in the database.

### `void loadPackage(uint8_t packageId)`
Loads a pre-configured static data package (Package 1 for Akinator game data, Packages 2–25 for reference excerpts across science, literature, history, and more).

## License

MIT License. See `LICENSE` for details.
