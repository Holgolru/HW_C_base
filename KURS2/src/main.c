#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
// #include <getopt.h>
#include "temp_api.h"

#define SIZE 1000
const char *months[] = {"Ja", "Fb", "Mr", "Ap", "My", "Jn", "Jl", "Ag", "Sp", "Oc", "Nv", "Dc"};

void createArray(struct tempTime *, uint16_t *);
void fillArray(struct tempTime *, uint16_t *);
void readFile(const char *, struct tempTime *, uint16_t *);

int main(int argc, char *argv[])
{
    struct tempTime data[SIZE];
    uint16_t amount = 0;

    createArray(data, &amount);

    // TODO: для работы с большими файлами
    // #define SIZE 1000000
    // uint32_t amount

    // TODO: PrintHelp()

    char *month = NULL;
    char *inputFile = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            // printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc)
        {
            inputFile = argv[++i];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc)
        {
            month = argv[++i];
        }
    }

    if (inputFile != NULL)
    {
        readFile(inputFile, data, &amount);
    }
    else
    {
        fillArray(data, &amount);
        printf("Testing data\n");
        printAll(data, amount);
        printf("\n");
        /*
        // Testing functions
        delElement(data, &amount, 1);
        delElement(data, &amount, 5);
        printAll(data, amount);
        printf("\n");
        sortByTemp(data, amount);
        printAll(data, amount);
        printf("\n");
        sortByDate(data, amount);
        printAll(data, amount);
        */
    }

    if (month != NULL)
    {
        printf("Statistic in %s:\n", month);
        printf("*** middle temperature = %.1f\n", middleTempCurMonth(data, amount, month));
        printf("*** min temperature =  %d\n", minTempCurMonth(data, amount, month));
        printf("*** max temperature =  %d\n\n", maxTempCurMonth(data, amount, month));
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            printf("Statistic in %s:\n", months[i]);
            printf("*** middle temperature = %.1f\n", middleTempCurMonth(data, amount, months[i]));
            printf("*** min temperature =  %d\n", minTempCurMonth(data, amount, months[i]));
            printf("*** max temperature =  %d\n\n", maxTempCurMonth(data, amount, months[i]));
        }
        sortByDate(data, amount);
        int currentYear = data[0].year;
        printf("Statistic in year %d:\n", currentYear);
        printf("*** middle temperature = %.1f\n", middleTempCurYear(data, amount, currentYear));
        printf("*** min temperature =  %d\n", minTempCurYear(data, amount, currentYear));
        printf("*** max temperature =  %d\n\n", maxTempCurYear(data, amount, currentYear));

        for (int i = 1; i < amount; i++)
        {
            if (data[i].year != currentYear)
            {
                currentYear = data[i].year;
                printf("Statistic in %d:\n", currentYear);
                printf("*** middle temperature = %.1f\n", middleTempCurYear(data, amount, currentYear));
                printf("*** min temperature =  %d\n", minTempCurYear(data, amount, currentYear));
                printf("*** max temperature =  %d\n\n", maxTempCurYear(data, amount, currentYear));
            }
        }
    }

    return 0;
}

void createArray(struct tempTime *data, uint16_t *amount)
{
    for (int i = 0; i < SIZE; i++)
    {
        data[i].year = 0;
        strcpy(data[i].month, "");
        data[i].day = 0;
        data[i].hour = 0;
        data[i].min = 0;
        data[i].temperature = 0;
    }
    *amount = 0;
}

// Test DATA
void fillArray(struct tempTime *data, uint16_t *amount)
{
    addElement(data, amount, SIZE, 2025, "Ja", 12, 10, 20, +10);
    addElement(data, amount, SIZE, 2025, "Fb", 04, 06, 10, +3);
    addElement(data, amount, SIZE, 2025, "Mr", 10, 10, 20, -5);
    addElement(data, amount, SIZE, 2020, "Ap", 04, 06, 10, -2);
    addElement(data, amount, SIZE, 2025, "My", 12, 10, 20, +33);
    addElement(data, amount, SIZE, 2025, "Jn", 30, 06, 10, +30);
    addElement(data, amount, SIZE, 2025, "Jl", 12, 10, 20, +75);
    addElement(data, amount, SIZE, 2025, "Ag", 05, 20, 10, +13);
    addElement(data, amount, SIZE, 2025, "Sp", 03, 01, 10, -3);
    addElement(data, amount, SIZE, 2025, "Oc", 12, 12, 20, -10);
    addElement(data, amount, SIZE, 2025, "Nv", 04, 06, 10, -5);
    addElement(data, amount, SIZE, 2025, "Dc", 03, 10, 20, -20);
    addElement(data, amount, SIZE, 2025, "Sp", 13, 01, 10, -30);
    addElement(data, amount, SIZE, 2026, "Oc", 13, 12, 20, +10);
    addElement(data, amount, SIZE, 2023, "Nv", 05, 06, 10, +5);
    addElement(data, amount, SIZE, 2025, "Dc", 01, 10, 20, +3);
    addElement(data, amount, SIZE, 2005, "Dc", 01, 11, 20, +20);
    addElement(data, amount, SIZE, 2019, "Dc", 13, 15, 20, -44);
}

void readFile(const char *filename, struct tempTime *data, uint16_t *amount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    char line[256];
    int lineNum = 0;
    
    while (fgets(line, sizeof(line), file)) {
        lineNum++;
        
        line[strcspn(line, "\n\r")] = 0;
        
        if (strlen(line) == 0) continue;
        
        uint16_t year;
        uint8_t monthNum, day, hour, min;
        int8_t temperature;
        char monthStr[3];
        
        if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", 
                   &year, &monthNum, &day, &hour, &min, &temperature) == 6) {
            
            if (monthNum >= 1 && monthNum <= 12) {
                strcpy(monthStr, months[monthNum - 1]);
            } else {
                strcpy(monthStr, "");
                //continue;
            }
            
            uint8_t codeOperation = addElement(data, amount,SIZE, year, monthStr, day, hour, min, temperature);
            if (codeOperation != 0) {
                printf("Error in line %d: invalid data (code %d)\n", lineNum, codeOperation);
            }
        } else {
            printf("Error in line %d: invalid format.\n", lineNum);
        }
    }
    
    fclose(file);
    printf("Total correct lines %d in %s\n", *amount, filename);
}