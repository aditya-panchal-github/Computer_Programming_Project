#include "course_parser.h"
#include <stdio.h>
#include <string.h>

GList *parse_course_schedule(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    GList *courses = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        if (is_course_start_line(line)) {
            char *course_data = extract_course_data(file, line);
            courses = g_list_append(courses, course_data);
        }
    }

    free(line);
    fclose(file);
    return courses;
}
