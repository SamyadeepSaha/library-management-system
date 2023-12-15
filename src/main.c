#include<gtk/gtk.h>
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    // Creat window
    window = gtk_application_window_new(app);
    // Set title and size of window
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    // Render the window
    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    // Create app
    app = gtk_application_new("dist.library", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    // Clean app pointer
    g_object_unref(app);

    return status;
}
