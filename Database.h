#ifndef DATABASE_H
#define DATABASE_H

#include <Arduino.h>

#define MAX_RECORDS 8
#define MAX_KEY_LEN 16
#define MAX_VAL_LEN 64

struct DatabaseRecord {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
};

class Database {
public:
    Database();
    
    bool begin();
    bool insert(const char* key, const char* value);
    bool get(const char* key, char* buffer, size_t maxLen);
    void clear();
    uint8_t getCount();

private:
    DatabaseRecord _records[MAX_RECORDS];
    uint8_t _count;
};

#endif
