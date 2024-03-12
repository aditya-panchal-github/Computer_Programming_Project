#include <gtk/gtk.h>
#include "../core_features/core_functions.h"
#include "../core_features/core_functions.c"
#include "../resources/calender_structure.h"

GtkWidget *file_chooser;
GtkWidget *progress_bar;
GtkWidget *status_label;

// Function to perform the actual conversion
gboolean perform_conversion(const gchar *file_path) {
    // Call the conversion function from core_functions
    create_test_ics_file(file_path);
    return TRUE;
}

// Callback function for the "Import" button click event
void on_button_import_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open File",
                                                    NULL,
                                                    GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    "_Cancel",
                                                    GTK_RESPONSE_CANCEL,
                                                    "_Open",
                                                    GTK_RESPONSE_ACCEPT,
                                                    NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        gchar *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        // IMPORTANT NOTE: call the function fothe file here once functional code is done, things buggy
    }

    gtk_widget_destroy(dialog);
}

// Callback function for the "Convert" button click event
static void on_convert_button_clicked(GtkButton *button, gpointer user_data) {
    gchar *file_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
    
    // Perform the conversion here. This is just a placeholder.
    gboolean success = perform_conversion(file_path);
    
    if (success) {
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 1.0); // Set progress to 100%
        gtk_label_set_text(GTK_LABEL(status_label), "Status: Conversion completed successfully");
    } else {
        gtk_label_set_text(GTK_LABEL(status_label), "Status: Conversion failed");
    }
}

// Callback function for the "Export" button click event
void on_button_export_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Save File",
                                                    NULL,
                                                    GTK_FILE_CHOOSER_ACTION_SAVE,
                                                    "_Cancel",
                                                    GTK_RESPONSE_CANCEL,
                                                    "_Save",
                                                    GTK_RESPONSE_ACCEPT,
                                                    NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        gchar *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        // Export the schedule to the file here
    }

    gtk_widget_destroy(dialog);
}

// Callback function for the "View" button click event
static void on_button_view_clicked(GtkWidget *widget, gpointer data) {
    g_print("%s clicked\n", gtk_button_get_label(GTK_BUTTON(widget)));
    view_functionality((char*)data, 123);
}

// Callback function for the drag-and-drop eventt
void on_drag_data_received(GtkWidget *widget, GdkDragContext *context, int x, int y,
                           GtkSelectionData *data, guint info, guint time, gpointer user_data) {
    gchar *file_path = (gchar *)gtk_selection_data_get_data(data);
    //same thing as the import button, call the function for the file here once functional code is done (schedule)
}

// Function to create a custom button with programmatic styling
GtkWidget* create_custom_button(const gchar *label, GCallback callback, gpointer data) {
    char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
    GtkWidget *button = gtk_button_new_with_label(label);
    gtk_widget_set_margin_start(button, 10);
    gtk_widget_set_margin_end(button, 10);
    gtk_widget_set_margin_top(button, 5);
    gtk_widget_set_margin_bottom(button, 5);
    g_signal_connect(button, "clicked", callback, data);
    return button;
}

// Application activation callback
void activate(GtkApplication *app, gpointer user_data) {

    file_chooser = gtk_file_chooser_dialog_new("Open File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, "_Cancel", GTK_RESPONSE_CANCEL, "_Open", GTK_RESPONSE_ACCEPT, NULL);
    progress_bar = gtk_progress_bar_new();
    status_label = gtk_label_new("Status: Not started");
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "School Schedule Manager");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    /* CSS Provider */
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "/Users/adi/Documents/GitHub/Computer_Programming_Project/src/resources/style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(cssProvider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    GtkWidget *header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "Schedule Converter");
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

    /* Navigation */
    GtkWidget *nav_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *home_button = gtk_button_new_with_label("Home");
    GtkWidget *settings_button = gtk_button_new_with_label("Settings");
    GtkWidget *help_button = gtk_button_new_with_label("Help");
    gtk_box_pack_start(GTK_BOX(nav_box), home_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nav_box), settings_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nav_box), help_button, FALSE, FALSE, 0);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), nav_box);

    /* Grid layout */
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_container_add(GTK_CONTAINER(window), grid);

    /* Adding buttons to the grid */
    GtkWidget *button_import = create_custom_button("Import Schedule", G_CALLBACK(on_button_import_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_import, 0, 0, 1, 1);

    GtkWidget *button_export = create_custom_button("Export to iCalendar", G_CALLBACK(on_button_export_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_export, 1, 0, 1, 1);

    GtkWidget *button_view = create_custom_button("View Schedule", G_CALLBACK(on_button_view_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_view, 2, 0, 1, 1);

    /* Conversion Button */
    GtkWidget *convert_button = gtk_button_new_with_label("Convert");
    g_signal_connect(convert_button, "clicked", G_CALLBACK(on_convert_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), convert_button, 0, 5, 3, 1); // Attach to grid

    /* Progress Indicator */
    GtkWidget *progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.0); // initial progress to 0
    gtk_grid_attach(GTK_GRID(grid), progress_bar, 0, 1, 3, 1); // Attach to the grid

    GtkWidget *status_label = gtk_label_new("Status: Idle");
    gtk_grid_attach(GTK_GRID(grid), status_label, 0, 2, 3, 1); // Attach to grid

    /* File Upload Section */
    GtkWidget *file_chooser = gtk_file_chooser_button_new("Select a File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_grid_attach(GTK_GRID(grid), file_chooser, 0, 3, 3, 1); // Attach to grid

    GtkWidget *drag_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drag_area, 200, 200); // Set a a fixed size for the drag area
    gtk_drag_dest_set(drag_area, GTK_DEST_DEFAULT_ALL, NULL, 0, GDK_ACTION_COPY);
    gtk_drag_dest_add_text_targets(drag_area);
    g_signal_connect(drag_area, "drag-data-received", G_CALLBACK(on_drag_data_received), NULL);
    gtk_grid_attach(GTK_GRID(grid), drag_area, 0, 4, 3, 1); // Attach to grid

    gtk_widget_show_all(window);
}
