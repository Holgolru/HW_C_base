#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_api.h"

const char *pMonths[] = {"Ja", "Fb", "Mr", "Ap", "My", "Jn", "Jl", "Ag", "Sp", "Oc", "Nv", "Dc"};

void createArray(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity);
void fillArray(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity);
void readFile(const char *pFilename, struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity);
void printHelp();

int main(int argc, char *argv[])
{
    struct tempTime *pData = NULL;
    uint32_t amount = 0;
    uint32_t capacity = 0;

    createArray(&pData, &amount, &capacity);

    char *pMonth = NULL;
    char *pInputFile = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc)
        {
            pInputFile = argv[++i];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc)
        {
            pMonth = argv[++i];
        }
    }

    if (pInputFile != NULL)
    {
        readFile(pInputFile, &pData, &amount, &capacity);
    }
    else
    {
        fillArray(&pData, &amount, &capacity);
        printf("Testing data\n");
        printAll(pData, amount);
        printf("\n");
       
        // Testing functions
        /*
        delElement(pData, &amount, 1);
        delElement(pData, &amount, 5);
        printAll(pData, amount);
        printf("\n");
        sortByTemp(pData, amount);
        printAll(pData, amount);
        printf("\n");
        sortByDate(pData, amount);
        printAll(pData, amount);
        */
    }

    if (pMonth != NULL)
    {
        printf("Statistic in %s:\n", pMonth);
        printf("*** middle temperature = %.1f\n", middleTempCurMonth(pData, amount, pMonth));
        printf("*** min temperature = %d\n", minTempCurMonth(pData, amount, pMonth));
        printf("*** max temperature = %d\n\n", maxTempCurMonth(pData, amount, pMonth));
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            printf("Statistic in %s:\n", pMonths[i]);
            printf("*** middle temperature = %.1f\n", middleTempCurMonth(pData, amount, pMonths[i]));
            printf("*** min temperature = %d\n", minTempCurMonth(pData, amount, pMonths[i]));
            printf("*** max temperature = %d\n\n", maxTempCurMonth(pData, amount, pMonths[i]));
        }

        sortByDate(pData, amount);

        uint32_t iOld = 0;
        uint32_t currentYear = pData[0].year;

        for (uint32_t i = 1; i <= amount; i++)
        {
            if (i == amount || pData[i].year != currentYear)
            {
                printf("Statistic in %d:\n", currentYear);
                printf("*** middle temperature = %.1f\n", middleTempCurYear(pData + iOld, i - iOld, currentYear));
                printf("*** min temperature = %d\n", minTempCurYear(pData + iOld, i - iOld, currentYear));
                printf("*** max temperature = %d\n\n", maxTempCurYear(pData + iOld, i - iOld, currentYear));

                if (i < amount)
                {
                    currentYear = pData[i].year;
                    iOld = i;
                }
            }
        }
    }

    free(pData);
    return 0;
}

void createArray(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity)
{
    *pAmount = 0;
    *pCapacity = 10000;
    *ppData = malloc(*pCapacity * sizeof(struct tempTime));
    if (*ppData == NULL)
    {
        printf("Allocation failed\n");
        exit(1);
    }
}

// Test DATA
void fillArray(struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity)
{
    addElement(ppData, pAmount, pCapacity, 2025, "Ja", 12, 10, 20, +10);
    addElement(ppData, pAmount, pCapacity, 2025, "Fb", 04, 06, 10, +3);
    addElement(ppData, pAmount, pCapacity, 2025, "Mr", 10, 10, 20, -5);
    addElement(ppData, pAmount, pCapacity, 2020, "Ap", 04, 06, 10, -2);
    addElement(ppData, pAmount, pCapacity, 2025, "My", 12, 10, 20, +33);
    addElement(ppData, pAmount, pCapacity, 2025, "Jn", 30, 06, 10, +30);
    addElement(ppData, pAmount, pCapacity, 2025, "Jl", 12, 10, 20, +75);
    addElement(ppData, pAmount, pCapacity, 2025, "Ag", 05, 20, 10, +13);
    addElement(ppData, pAmount, pCapacity, 2025, "Sp", 03, 01, 10, -3);
    addElement(ppData, pAmount, pCapacity, 2025, "Oc", 12, 12, 20, -10);
    addElement(ppData, pAmount, pCapacity, 2025, "Nv", 04, 06, 10, -5);
    addElement(ppData, pAmount, pCapacity, 2025, "Dc", 03, 10, 20, -20);
    addElement(ppData, pAmount, pCapacity, 2025, "Sp", 13, 01, 10, -30);
    addElement(ppData, pAmount, pCapacity, 2026, "Oc", 13, 12, 20, +10);
    addElement(ppData, pAmount, pCapacity, 2023, "Nv", 05, 06, 10, +5);
    addElement(ppData, pAmount, pCapacity, 2025, "Dc", 01, 10, 20, +3);
    addElement(ppData, pAmount, pCapacity, 2005, "Dc", 01, 11, 20, +20);
    addElement(ppData, pAmount, pCapacity, 2019, "Dc", 13, 15, 20, -44);
}

void readFile(const char *pFilename, struct tempTime **ppData, uint32_t *pAmount, uint32_t *pCapacity)
{
    FILE *pFile = fopen(pFilename, "r");
    if (pFile == NULL)
    {
        printf("Error opening file %s\n", pFilename);
        return;
    }

    char line[256];
    int lineNum = 0;

    while (fgets(line, sizeof(line), pFile))
    {
        lineNum++;
        line[strcspn(line, "\n\r")] = 0;
        if (strlen(line) == 0)
            continue;

        uint16_t year;
        uint8_t monthNum, day, hour, min;
        int8_t temperature;
        char monthStr[3];

        if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                   &year, &monthNum, &day, &hour, &min, &temperature) == 6)
        {
            if (monthNum >= 1 && monthNum <= 12)
            {
                strcpy(monthStr, pMonths[monthNum - 1]);
            }
            else
            {
                strcpy(monthStr, "");
            }

            uint8_t codeOperation = addElement(ppData, pAmount, pCapacity, year, monthStr, day, hour, min, temperature);
            if (codeOperation != 0)
            {
                printf("Error in line %d: invalid data (code %d)\n", lineNum, codeOperation);
            }
        }
        else
        {
            printf("Error in line %d: invalid format.\n", lineNum);
        }
    }
    fclose(pFile);
    printf("Total correct lines %d in %s\n", *pAmount, pFilename);
}

void printHelp(){
    printf("****** Temperature statistics ****** \n");
    printf("Program read data from .cvs file or test data. \n");
    printf("Key -h: HELP \n");
    printf("Key -m arg: information of current month \n");
    printf("Key -f arg: file source \n");
}