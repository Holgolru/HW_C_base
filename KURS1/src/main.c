#include <stdint.h>
#include <string.h>
#include <temp_api.h>

#define SIZE 10

static uint8_t number = 0;

const char *months[] = {
    "Jn", "Fb", "Mr", "Ap", "My", "Jn", "Jl", "Ag", "Sp", "Oc", "Nv", "Dc"};

uint8_t AddRecord(struct tempTime *data,
                  uint16_t year, const char *month, uint8_t day,
                  uint8_t hour, uint8_t min, int8_t temperature)
{
    if (number >= SIZE)
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

    data[number].year = year;
    data[number].hour = hour;
    strcpy(data[number].month, month);
    data[number].day = day;
    data[number].min = min;
    data[number].temperature = temperature;

    number++;
    return 0;
}

int main(void)
{
    struct tempTime data[SIZE];

    AddRecord(data, 2025, "Jn", 12, 10, 20, 10);
    AddRecord(data, 2025, "Fb", 4, 6, 10, 3);

    middleTempCurMonth(data, number, "Jn");
    minTempCurMonth(data, number, "Jn");
    maxTempCurMonth(data, number, "Jn");
    middleTempCurYear(data, number, 2025);
    minTempCurYear(data, number, 2025);
    maxTempCurYear(data, number, 2025);

    return 0;
}