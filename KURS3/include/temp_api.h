#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

extern const char* pMonths[];

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

uint8_t addElement(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity,
                   uint16_t year, const char* pMonth, uint8_t day, uint8_t hour, 
                   uint8_t min, int8_t temperature);

uint8_t delElement(struct tempTime *pData, uint32_t *pAmount, uint32_t curNumber);
void printAll(struct tempTime *pData, uint32_t amount);
uint8_t numberOfMonth(const char *pMonth);
const char* monthOfNumber(uint8_t num);
void sortByDate(struct tempTime *pData, uint32_t amount);
void sortByTemp(struct tempTime *pData, uint32_t amount);
float middleTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth);
int8_t minTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth);
int8_t maxTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth);
float middleTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year);
int8_t minTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year);
int8_t maxTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year);

#endif