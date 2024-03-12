#include <gtk/gtk.h>
#include "gui_interface/dashboard.h"

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;
    
    gchar *cwd = g_get_current_dir();
    g_print("Current working directory: %s\n", cwd);
    g_free(cwd);

    app = gtk_application_new("org.yourproject.dashboard", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
