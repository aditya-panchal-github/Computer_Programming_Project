#ifndef CALENDER_STRUCTURE_H
#define CALENDER_STRUCTURE_H
#include <stdbool.h>

#define MAX_ATTENDEES 100
#define MAX_CATEGORIES 60
#define MAX_RESOURCES 60
#define MAX_EVENTS 100

typedef struct {
    char *dtstart;
    char *dtend;
    char *dtstamp;
    char *uid;
    char *summary;
    char *description;
    char *location;
    char *url;
    char *status;
    char *class;
    char *transp;
    char *sequence;
    char *priority;
    char *organizer;
    char *attendees[MAX_ATTENDEES];
    char *categories[MAX_CATEGORIES];
    char *resources[MAX_RESOURCES];
    char *rrule;
    char *exdate;
    char *rdate;
    char *created;
    char *last_modified;
    char *geo;
    char *latitude;
    char *longitude;
    char *tzid;
    char *tzname;
    char *tzo;
    char *comment;
    char *contact;
    char *related;
    char *uid_property;
    char *recurrence_id;
    char *action;
    char *repeat;
    char *duration;
    char *attach;
    char *attendee;
    char *trigger;
    char *x_prop[MAX_ATTENDEES]; // X- properties
    bool has_alarm;
} ICalEvent;

typedef struct {
    char *version;
    char *prodid;
    char *calscale;
    char *method;
    char *name;
    char *description;
    char *refresh_interval;
    char *source;
    char *color;
    char *timezone;
    char *tzid;
    char *tzurl;
    char *tzoffsetfrom;
    char *tzoffsetto;
    char *tzname;
    char *x_wr_calname;
    char *x_wr_caldesc;
    char *x_wr_timezone;
    char *x_prop[MAX_CATEGORIES]; // X- properties
    ICalEvent events[MAX_EVENTS]; // Array of events
    
} ICalendar;


#endif 
