// #include<gtk/gtk.h>
#include"gui.h"

static void activate(GtkApplication *app, gpointer user_data)
{
    // Define gtk window, box, buttons and fixed container
    GtkWidget *window;
    GtkWidget *grid, *box, *fixed;
    GtkWidget *abb, *fbb, *dbb;
    GtkWidget *amb, *fmb, *dmb;
    GtkWidget *ib, *rb;
    GtkWidget *ml, *bl, *sel_op;

    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    fixed = gtk_fixed_new();

    // Create member label and button
    ml = gtk_label_new("Member");
    amb = gtk_button_new_with_label("Add member");
    fmb = gtk_button_new_with_label("Find member");
    dmb = gtk_button_new_with_label("Delete member");

    // Create book button
    bl = gtk_label_new("Book");
    abb = gtk_button_new_with_label("Add book");
    fbb = gtk_button_new_with_label("Find book");
    dbb = gtk_button_new_with_label("Delete book");
    ib = gtk_button_new_with_label("Issue book");
    rb = gtk_button_new_with_label("Return book");

    // Add member buttons to box
    gtk_box_pack_start(GTK_BOX(box), ml, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), amb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), fmb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), dmb, TRUE, TRUE, 0);

    // Add book buttons to box
    gtk_box_pack_start(GTK_BOX(box), bl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), abb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), fbb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), dbb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ib, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), rb, TRUE, TRUE, 0);

    // Add lable to empty container
    sel_op = gtk_label_new("Select an option");
    gtk_fixed_put(GTK_FIXED(fixed), sel_op, 100, 100);

    /*
    // Put buttons in member container
    gtk_fixed_put(GTK_FIXED(m_fixed), add_m_bt, 50, 100);
    gtk_fixed_put(GTK_FIXED(m_fixed), f_m_bt, 50, 200);
    gtk_fixed_put(GTK_FIXED(m_fixed), del_m_bt, 50, 300);

    // Put buttons in book container
    gtk_fixed_put(GTK_FIXED(bk_fixed), add_bk_bt, 50, 100);
    gtk_fixed_put(GTK_FIXED(bk_fixed), f_bk_bt, 50, 200);
    gtk_fixed_put(GTK_FIXED(bk_fixed), del_bk_bt, 50, 300);
    */

    // Add box and fixed to grid
    gtk_grid_attach(GTK_GRID(grid), box, 0, 0, 1, 10);
    gtk_grid_attach(GTK_GRID(grid), fixed, 1, 0, 10, 10);

    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Set window title
    gtk_window_set_title(GTK_WINDOW(window), "Library");

    // Render gtk window
    gtk_widget_show_all(window);
}

int start_app(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("dist.library", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    return status;
}
