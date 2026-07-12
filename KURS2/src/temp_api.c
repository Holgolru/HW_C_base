#define _CRT_SECURE_NO_WARNINGS

#include "temp_api.h"
#include <stdio.h>
#include <string.h>

float middleTempCurMonth(struct tempTime* data, uint16_t amount, const char* month) {
    float middleTemp = 0;
    uint16_t counter = 0;

    for (uint16_t i = 0; i < amount; i++) {
        if (strcmp(data[i].month, month) == 0) {
            middleTemp += data[i].temperature;
            counter++;
        }
    }

    if (counter == 0) {
        return -273.0;
    }
    else {
        return (middleTemp / counter);
    }
}

int8_t minTempCurMonth(struct tempTime* data, uint16_t amount, const char* month) {
    int8_t minTemp = 127;

    for (uint16_t i = 0; i < amount; i++) {
        if (strcmp(data[i].month, month) == 0) {
            if (data[i].temperature < minTemp) {
                minTemp = data[i].temperature;
            }
        }
    }

    return minTemp;
}

int8_t maxTempCurMonth(struct tempTime* data, uint16_t amount, const char* month) {
    int8_t maxTemp = -128;

    for (uint16_t i = 0; i < amount; i++) {
        if (strcmp(data[i].month, month) == 0) {
            if (data[i].temperature > maxTemp) {
                maxTemp = data[i].temperature;
            }
        }
    }

    return maxTemp;
}

float middleTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year) {
    float middleTemp = 0;
    uint16_t counter = 0;

    for (int i = 0; i < amount; i++) {
        if (data[i].year == year) {
            middleTemp += data[i].temperature;
            counter++;
        }
    }

    if (counter == 0) {
        return -273.0;
    }
    else { return (middleTemp / counter); }
}

int8_t minTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year) {
    int8_t minTemp = 127;

    for (int i = 0; i < amount; i++) {
        if (data[i].year == year) {
            if (data[i].temperature < minTemp) {
                minTemp = data[i].temperature;
            }
        }
    }

    return minTemp;
}

int8_t maxTempCurYear(struct tempTime* data, uint16_t amount, uint16_t year) {
    int8_t maxTemp = -128;

    for (int i = 0; i < amount; i++) {
        if (data[i].year == year) {
            if (data[i].temperature > maxTemp) {
                maxTemp = data[i].temperature;
            }
        }
    }

    return maxTemp;
}

uint8_t addElement(struct tempTime* data, uint16_t* amount, const uint16_t SIZE,
    uint16_t year, const char* month, uint8_t day, uint8_t hour, uint8_t min, int8_t temperature)
{
    if (*amount >= SIZE)
        return 1;
    if ((year < 0) || (year > 2026))
        return 2;
    if ((day < 0) || (day > 31))
        return 2;
    if ((hour < 0) || (hour > 24))
        return 2;
    if ((min < 0) || (min > 60))
        return 2;
    if ((temperature < -99) || (temperature > 99))
        return 3;

    uint8_t correctMonth = 0;

    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month, months[i]) == 0)
        {
            correctMonth = 1;
            break;
        }
    }

    if (!correctMonth)
    {
        return 2;
    }

    data[*amount].year = year;
    data[*amount].hour = hour;
    strcpy(data[*amount].month, month);
    data[*amount].day = day;
    data[*amount].min = min;
    data[*amount].temperature = temperature;

    (*amount)++;
    return 0;
}

uint8_t delElement(struct tempTime* data, uint16_t* amount, uint16_t curNumber)
{
    if (*amount == 0) {
        return 1;
    }

    if (curNumber >= *amount) {
        return 2;
    }

    for (uint16_t i = curNumber; i < *amount - 1; i++) {
        data[i] = data[i + 1];
    }

    data[*amount - 1].year = 0;
    data[*amount - 1].hour = 0;
    strcpy(data[*amount - 1].month, "");
    data[*amount - 1].day = 0;
    data[*amount - 1].min = 0;
    data[*amount - 1].temperature = 0;

    (*amount)--;

    return 0;
}


void printAll(struct tempTime* data, uint16_t amount) {
    if (amount == 0) {
        printf("Empty\n");
        return;
    }
    for (uint16_t i = 0; i < amount; i++) {
        printf("Year: %04d, Month: %s, Day: %02d, ",
            data[i].year, data[i].month, data[i].day);
        printf("Time: %02d:%02d, temp: %3d\n",
            data[i].hour, data[i].min, data[i].temperature);
    }
}


void swap(struct tempTime* a, struct tempTime* b) {
    struct tempTime temp = *a;
    *a = *b;
    *b = temp;
}

void sortByTemp(struct tempTime* data, uint16_t amount) {
    for (uint16_t i = 0; i < amount - 1; i++) {
        for (uint16_t j = 0; j < amount - 1 - i; j++) {
            if (data[j].temperature > data[j + 1].temperature) {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

uint8_t numberOfMonth(const char* month) {
    for (uint8_t i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

const char* monthOfNumber(uint8_t num) {
    if (num >= 1 && num <= 12) {
        return months[num - 1];
    }
    return NULL;
}

void sortByDate(struct tempTime* data, uint16_t amount) {
    for (uint16_t i = 0; i < amount - 1; i++) {
        for (uint16_t j = 0; j < amount - 1 - i; j++) {
            if (data[j].year > data[j + 1].year) {
                swap(&data[j], &data[j + 1]);
            }
            else if (data[j].year == data[j + 1].year) {
                if (numberOfMonth(data[j].month) > numberOfMonth(data[j + 1].month)) {
                    swap(&data[j], &data[j + 1]);
                }
                else if (numberOfMonth(data[j].month) == numberOfMonth(data[j + 1].month)) {
                    if (data[j].day > data[j + 1].day) {
                        swap(&data[j], &data[j + 1]);
                    }
                }
            }
        }
    }
}