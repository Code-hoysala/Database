#ifndef DATABASE_H
#define DATABASE_H

#include <Arduino.h>

#ifndef MAX_RECORDS
#define MAX_RECORDS 16
#endif

#ifndef MAX_KEY_LEN
#define MAX_KEY_LEN 24
#endif

#ifndef MAX_VAL_LEN
#define MAX_VAL_LEN 128
#endif

struct KeyValuePair {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
    bool isUsed;
};

class Database {
public:
    Database();
    void begin();
    bool insert(const char* key, const char* value);
    bool get(const char* key, char* buffer, size_t bufferSize) const;
    void clear();
    size_t count() const;
    void loadPackage(uint8_t packageId);

private:
    KeyValuePair records[MAX_RECORDS];
    size_t recordCount;
};

#endif
