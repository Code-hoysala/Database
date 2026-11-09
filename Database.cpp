#include "Database.h"

Database::Database() {
    _count = 0;
    memset(_records, 0, sizeof(_records));
}

bool Database::begin() {
    _count = 0;
    return true;
}

bool Database::insert(const char* key, const char* value) {
    // Check if key already exists, update value if found
    for (uint8_t i = 0; i < _count; i++) {
        if (strcmp(_records[i].key, key) == 0) {
            strncpy(_records[i].value, value, MAX_VAL_LEN - 1);
            _records[i].value[MAX_VAL_LEN - 1] = '\0';
            return true;
        }
    }

    // Otherwise insert new record if space permits
    if (_count >= MAX_RECORDS) return false;

    strncpy(_records[i].key, key, MAX_KEY_LEN - 1);
    _records[i].key[MAX_KEY_LEN - 1] = '\0';
    
    strncpy(_records[i].value, value, MAX_VAL_LEN - 1);
    _records[i].value[MAX_VAL_LEN - 1] = '\0';
    
    _count++;
    return true;
}

bool Database::get(const char* key, char* buffer, size_t maxLen) {
    for (uint8_t i = 0; i < _count; i++) {
        if (strcmp(_records[i].key, key) == 0) {
            strncpy(buffer, _records[i].value, maxLen - 1);
            buffer[maxLen - 1] = '\0';
            return true;
        }
    }
    return false;
}

void Database::clear() {
    _count = 0;
    memset(_records, 0, sizeof(_records));
}

uint8_t Database::getCount() {
    return _count;
}
