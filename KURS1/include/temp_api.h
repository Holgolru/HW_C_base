#include <stdint.h>

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

uint8_t middleTempCurMonth(struct tempTime* data, uint8_t amount, const char* month);
uint8_t minTempCurMonth(struct tempTime* data, uint8_t amount, const char* month);
uint8_t maxTempCurMonth(struct tempTime* data, uint8_t amount, const char* month);
uint8_t middleTempCurYear(struct tempTime* data, uint8_t amount, uint16_t year);
uint8_t minTempCurYear(struct tempTime* data, uint8_t amount, uint16_t year);
uint8_t maxTempCurYear(struct tempTime* data, uint8_t amount, uint16_t year);
