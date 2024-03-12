#include "core_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/Users/adi/Documents/GitHub/Computer_Programming_Project/src/resources/calender_structure.h"

void create_test_ics_file(const char* file_path) //Lines should be limited to 75 octets (not characters) long.
{
    FILE *icsFile = fopen(file_path, "w");
    if (icsFile == NULL) {
        perror("Error creating .ics file");
        exit(EXIT_FAILURE);
    }

    ICalEvent event;
    event.uid = "uid1@example.com";
    event.dtstamp = "20220401T170000Z";
    event.organizer = "MAILTO:john.doe@example.com";
    event.dtstart = "20220401T170000Z";
    event.dtend = "20220401T180000Z";
    event.summary = "Test Event";

    fprintf(icsFile, "BEGIN:VCALENDAR\n");
    fprintf(icsFile, "VERSION:2.0\n");
    fprintf(icsFile, "PRODID:-//hacksw/handcal//NONSGML v1.0//EN\n");
    fprintf(icsFile, "BEGIN:VEVENT\n");
    fprintf(icsFile, "UID:%s\n", event.uid);
    fprintf(icsFile, "DTSTAMP:%s\n", event.dtstamp);
    fprintf(icsFile, "ORGANIZER;CN=John Doe:%s\n", event.organizer);
    fprintf(icsFile, "DTSTART:%s\n", event.dtstart);
    fprintf(icsFile, "DTEND:%s\n", event.dtend);
    fprintf(icsFile, "SUMMARY:%s\n", event.summary);
    fprintf(icsFile, "END:VEVENT\n");
    fprintf(icsFile, "END:VCALENDAR\n");

    fclose(icsFile);
}

struct ScheduleEntry parseCSVEntry(char *csvEntry) {
    struct ScheduleEntry entry;
    sscanf(csvEntry, "%[^,],%[^,],%[^,],%[^,],%[^\n]", entry.courseName, entry.classType,
           entry.startTime, entry.endTime, entry.roomNumber);
    strcpy(entry.date, "2024-01-08");  // Start date
    return entry;
}

void import_functionality(const char* file_path, struct ScheduleEntry **schedule, int *numOfEntries) {
    FILE *csvFile = fopen(file_path, "r");
    if (csvFile == NULL) {
        perror("Error opening CSV file");
        exit(EXIT_FAILURE);
    }

    char header[256];
    fgets(header, sizeof(header), csvFile);

    *numOfEntries = 0;
    char csvEntry[256];
    while (fgets(csvEntry, sizeof(csvEntry), csvFile) != NULL) {
        (*numOfEntries)++;
    }

    *schedule = malloc(*numOfEntries * sizeof(struct ScheduleEntry));

    fseek(csvFile, 0, SEEK_SET);
    fgets(header, sizeof(header), csvFile);

    for (int i = 0; i < *numOfEntries; i++) {
        fgets(csvEntry, sizeof(csvEntry), csvFile);
        (*schedule)[i] = parseCSVEntry(csvEntry);
    }

    fclose(csvFile);
}

void export_functionality(const char* file_path, struct ScheduleEntry *schedule, int numOfEntries) {
    FILE *icsFile = fopen(file_path, "w");
    if (icsFile == NULL) {
        perror("Error creating .ics file");
        exit(EXIT_FAILURE);
    }

    fprintf(icsFile, "BEGIN:VCALENDAR\n");

    for (int i = 0; i < numOfEntries; i++) {
        fprintf(icsFile, "BEGIN:VEVENT\n");
        fprintf(icsFile, "DTSTART:%sT%s\n", schedule[i].date, schedule[i].startTime);
        fprintf(icsFile, "DTEND:%sT%s\n", schedule[i].date, schedule[i].endTime);

        if (strstr(schedule[i].classType, "Mo")) {
            fprintf(icsFile, "RRULE:FREQ=WEEKLY;BYDAY=MO\n");
        } else if (strstr(schedule[i].classType, "Tu")) {
            fprintf(icsFile, "RRULE:FREQ=WEEKLY;BYDAY=TU\n");
        } else if (strstr(schedule[i].classType, "We")) {
            fprintf(icsFile, "RRULE:FREQ=WEEKLY;BYDAY=WE\n");
        } else if (strstr(schedule[i].classType, "Th")) {
            fprintf(icsFile, "RRULE:FREQ=WEEKLY;BYDAY=TH\n");
        } else if (strstr(schedule[i].classType, "Fr")) {
            fprintf(icsFile, "RRULE:FREQ=WEEKLY;BYDAY=FR\n");
        }
        
        fprintf(icsFile, "SUMMARY:%s - %s\n", schedule[i].courseName, schedule[i].classType);
        fprintf(icsFile, "LOCATION:%s\n", schedule[i].roomNumber);
        fprintf(icsFile, "DESCRIPTION:Instructor - %s\n", schedule[i].instructor);

        fprintf(icsFile, "END:VEVENT\n");
    }

    fprintf(icsFile, "END:VCALENDAR\n");

    fclose(icsFile);
}

void view_functionality(struct ScheduleEntry *schedule, int numOfEntries) {
    for (int i = 0; i < numOfEntries; i++) {
        printf("Course: %s\n", schedule[i].courseName);
        printf("Class Type: %s\n", schedule[i].classType);
        printf("Start Time: %s\n", schedule[i].startTime);
        printf("End Time: %s\n", schedule[i].endTime);
        printf("Room Number: %s\n", schedule[i].roomNumber);
        printf("\n");
    }
}
