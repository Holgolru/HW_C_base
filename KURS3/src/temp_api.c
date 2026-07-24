#define _CRT_SECURE_NO_WARNINGS
#include "temp_api.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float middleTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth)
{
    float middleTemp = 0;
    uint32_t counter = 0;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (strcmp(pData[i].month, pMonth) == 0)
        {
            middleTemp += pData[i].temperature;
            counter++;
        }
    }

    if (counter == 0)
        return -273.0;
    else
        return (middleTemp / counter);
}

int8_t minTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth)
{
    int8_t minTemp = 127;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (strcmp(pData[i].month, pMonth) == 0)
        {
            if (pData[i].temperature < minTemp)
                minTemp = pData[i].temperature;
        }
    }
    return minTemp;
}

int8_t maxTempCurMonth(struct tempTime *pData, uint32_t amount, const char *pMonth)
{
    int8_t maxTemp = -128;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (strcmp(pData[i].month, pMonth) == 0)
        {
            if (pData[i].temperature > maxTemp)
                maxTemp = pData[i].temperature;
        }
    }
    return maxTemp;
}

float middleTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year)
{
    float middleTemp = 0;
    uint32_t counter = 0;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (pData[i].year == year)
        {
            middleTemp += pData[i].temperature;
            counter++;
        }
    }

    if (counter == 0)
        return -273.0;
    else
        return (middleTemp / counter);
}

int8_t minTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year)
{
    int8_t minTemp = 127;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (pData[i].year == year)
        {
            if (pData[i].temperature < minTemp)
                minTemp = pData[i].temperature;
        }
    }
    return minTemp;
}

int8_t maxTempCurYear(struct tempTime *pData, uint32_t amount, uint32_t year)
{
    int8_t maxTemp = -128;

    for (uint32_t i = 0; i < amount; i++)
    {
        if (pData[i].year == year)
        {
            if (pData[i].temperature > maxTemp)
                maxTemp = pData[i].temperature;
        }
    }
    return maxTemp;
}

uint8_t addElement(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity,
                   uint16_t year, const char *pMonth, uint8_t day, uint8_t hour,
                   uint8_t min, int8_t temperature)
{
    if ((year < 0) || (year > 2026)) return 2;
    if ((day < 0) || (day > 31))     return 2;
    if ((hour < 0) || (hour > 24))   return 2;
    if ((min < 0) || (min > 60))     return 2;
    if ((temperature < -99) || (temperature > 99)) return 3;

    uint8_t correctMonth = 0;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(pMonth, pMonths[i]) == 0)
        {
            correctMonth = 1;
            break;
        }
    }
    if (!correctMonth) return 2;

    if (*pAmount >= *pCapacity)
    {
        uint32_t newCapacity = *pCapacity * 2;
        struct tempTime *temp = realloc(*ppData, newCapacity * sizeof(struct tempTime));
        if (temp == NULL)
            return 1;

        *ppData = temp;
        *pCapacity = newCapacity;
    }

    (*ppData)[*pAmount].year = year;
    strcpy((*ppData)[*pAmount].month, pMonth);
    (*ppData)[*pAmount].day = day;
    (*ppData)[*pAmount].hour = hour;
    (*ppData)[*pAmount].min = min;
    (*ppData)[*pAmount].temperature = temperature;

    (*pAmount)++;
    return 0;
}

uint8_t delElement(struct tempTime *pData, uint32_t *pAmount, uint32_t curNumber)
{
    if (*pAmount == 0) return 1;
    if (curNumber >= *pAmount) return 2;

    for (uint32_t i = curNumber; i < *pAmount - 1; i++)
    {
        pData[i] = pData[i + 1];
    }

    pData[*pAmount - 1].year = 0;
    pData[*pAmount - 1].hour = 0;
    strcpy(pData[*pAmount - 1].month, "");
    pData[*pAmount - 1].day = 0;
    pData[*pAmount - 1].min = 0;
    pData[*pAmount - 1].temperature = 0;

    (*pAmount)--;
    return 0;
}

void printAll(struct tempTime *pData, uint32_t amount)
{
    if (amount == 0)
    {
        printf("Empty\n");
        return;
    }

    for (uint32_t i = 0; i < amount; i++)
    {
        printf("Year: %04d, Month: %s, Day: %02d, ",
               pData[i].year, pData[i].month, pData[i].day);
        printf("Time: %02d:%02d, temp: %3d\n",
               pData[i].hour, pData[i].min, pData[i].temperature);
    }
}

uint8_t numberOfMonth(const char *pMonth)
{
    for (uint8_t i = 0; i < 12; i++)
    {
        if (strcmp(pMonth, pMonths[i]) == 0)
            return i + 1;
    }
    return 0;
}

const char *monthOfNumber(uint8_t num)
{
    if (num >= 1 && num <= 12)
        return pMonths[num - 1];
    return NULL;
}

int compareByDate(const void *x, const void *y)
{
    const struct tempTime *a = (const struct tempTime *)x;
    const struct tempTime *b = (const struct tempTime *)y;

    if ((a->year - b->year) != 0)
        return a->year - b->year;
    else if ((numberOfMonth(a->month) - numberOfMonth(b->month)) != 0)
        return numberOfMonth(a->month) - numberOfMonth(b->month);
    else if ((a->day - b->day) != 0)
        return a->day - b->day;
    else if ((a->hour - b->hour) != 0)
        return a->hour - b->hour;
    else if ((a->min - b->min) != 0)
        return a->min - b->min;

    return 0;
}

int compareByTemp(const void *x, const void *y)
{
    const struct tempTime *a = (const struct tempTime *)x;
    const struct tempTime *b = (const struct tempTime *)y;
    return a->temperature - b->temperature;
}

void sortByDate(struct tempTime *pData, uint32_t amount)
{
    qsort(pData, amount, sizeof(struct tempTime), compareByDate);
}

void sortByTemp(struct tempTime *pData, uint32_t amount)
{
    qsort(pData, amount, sizeof(struct tempTime), compareByTemp);
}