#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ScheduleEntry {
    char date[11];
    char startTime[6];
    char endTime[6];
    char classType[20];
    char instructor[50];
    char roomNumber[10];
    char courseTitle[50];
    char courseName[50];
};

void import_functionality(const char* file_path, struct ScheduleEntry **schedule, int *numOfEntries);
void export_functionality(const char* file_path, struct ScheduleEntry *schedule, int numOfEntries);
void view_functionality(struct ScheduleEntry *schedule, int numOfEntries);

#endif
