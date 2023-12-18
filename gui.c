// #include<gtk/gtk.h>
#include"gui.h"

int start_app(int argc, char **argv)
{
    int status;

    app = gtk_application_new("dist.library", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    return status;
}

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

    // Add function to buttons
    g_signal_connect(abb, "clicked", G_CALLBACK(abb_hnd), NULL);

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


void abb_hnd(GtkWidget *abb, gpointer data)
{
    GtkWidget *window, *grid;
    GtkWidget *id, *name, *author, *pub, *price;
    GtkWidget *add, *cancel;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    id = gtk_entry_new();
    name = gtk_entry_new();
    author = gtk_entry_new();
    pub = gtk_entry_new();
    price = gtk_entry_new();
    add = gtk_button_new_with_label("Add");
    cancel = gtk_button_new_with_label("Cancel");
    // Add widgets to grid
    gtk_grid_attach(GTK_GRID(grid), id, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), name, 1, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), author, 1, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), pub, 1, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), price, 1, 9, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), add, 1, 11, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), cancel, 1, 13, 2, 1);
    // Add grid to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Add book");
    gtk_widget_show_all(window);
}

void fbb_hnd(GtkWidget *fbb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Find book");
    gtk_widget_show_all(window);
}

void dbb_hnd(GtkWidget *dbb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Delete book");
    gtk_widget_show_all(window);
}

void amb_hnd(GtkWidget *amb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Add member");
    gtk_widget_show_all(window);
}

void fmb_hnd(GtkWidget *fmb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Find member");
    gtk_widget_show_all(window);
}

void dmb_hnd(GtkWidget *dmb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Delete member");
    gtk_widget_show_all(window);
}

void ib_hnd(GtkWidget *ib, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Issue book");
    gtk_widget_show_all(window);
}

void rb_hnd(GtkWidget *rb, gpointer data)
{
    GtkWidget *window, *grid;
    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_window_set_title(GTK_WINDOW(window), "Return book");
    gtk_widget_show_all(window);
}

