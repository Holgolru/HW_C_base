#include <stdint.h>

extern const uint16_t SIZE;
extern const char* months[];

#pragma pack(push, 1)

struct tempTime
{
    uint16_t year;
    char month[3];
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    int8_t temperature;
};

#pragma pack(pop)

uint8_t addElement(struct tempTime* data, uint16_t* amount, const uint16_t SIZE,
    uint16_t year, const char* month, uint8_t day, uint8_t hour, uint8_t min, int8_t temperature);
uint8_t delElement(struct tempTime* data, uint16_t* amount, uint16_t curNumber);
void printAll(struct tempTime* data, uint16_t amount);
void swap(struct tempTime* a, struct tempTime* b);
void sortByTemp(struct tempTime* data, uint16_t amount);
uint8_t numberOfMonth(const char* month);
const char* monthOfNumber(const uint8_t num);
void sortByDate(struct tempTime* data, uint16_t amount);

float middleTempCurMonth(struct tempTime* data, uint16_t amount, const char* month);
int8_t minTempCurMonth(struct tempTime* data, uint16_t amount, const char* month);
int8_t maxTempCurMonth(struct tempTime* data, uint16_t amount, const char* month);
float middleTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year);
int8_t minTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year);
int8_t maxTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year);