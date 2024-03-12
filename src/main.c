#include "gui_interface/dashboard.h"
#include "core_features/core_functions.h"
#include "course_parser.h"
#include <string.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    struct ScheduleEntry *schedule;
    int numOfEntries;

    if (argc > 2) {
        const char* command = argv[1];
        const char* file_path = argv[2];

        if (strcmp(command, "import") == 0) {
            GList *courses = parse_course_schedule(file_path);
            schedule = convert_to_schedule_entry(courses, &numOfEntries);
            g_list_free_full(courses, g_free);
        } else if (strcmp(command, "export") == 0) {
            export_functionality(file_path, schedule, numOfEntries);
        } else if (strcmp(command, "view") == 0) {
            view_functionality(schedule, numOfEntries);
        } else {
            printf("Unknown command.\n");
        }
    } else if (argc == 1) {
        gtk_init(&argc, &argv);
        activate_dashboard();
        gtk_main();
    } else {
        printf("Usage: app <command> <file_path> or just app for GUI\n");
    }

    free(schedule);

    return 0;
}
