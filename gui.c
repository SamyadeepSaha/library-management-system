#include<gtk/gtk.h>
#include"gui.h"

GtkApplication *app;

static GtkWidget *window, *grid, *form;
static GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5;

void clear_entry()
{
}

void add_book_submit_handler()
{
}

void abb_hnd(GtkWidget *abb, gpointer data)
{
    GtkWidget *heading, *label1, *label2, *label3, *label4, *label5;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Add book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    label2 = gtk_label_new("Name");
    gtk_fixed_put(GTK_FIXED(form), label2, 10, 90);
    entry2 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry2, 100, 90);
    label3 = gtk_label_new("Author");
    gtk_fixed_put(GTK_FIXED(form), label3, 10, 130);
    entry3 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry3, 100, 130);
    label4 = gtk_label_new("Publication");
    gtk_fixed_put(GTK_FIXED(form), label4, 10, 170);
    entry4 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry4, 100, 170);
    label5 = gtk_label_new("Price");
    gtk_fixed_put(GTK_FIXED(form), label5, 10, 210);
    entry5 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry5, 100, 210);

    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(add_book_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void fbb_hnd(GtkWidget *fbb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Find book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void dbb_hnd(GtkWidget *dbb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Delete book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void amb_hnd(GtkWidget *amb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Add member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void fmb_hnd(GtkWidget *fmb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Find member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void dmb_hnd(GtkWidget *dmb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Delete member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void ib_hnd(GtkWidget *ib, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Issue book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void rb_hnd(GtkWidget *rb, gpointer data)
{
    GtkWidget *heading;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Return book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}


static void activate(GtkApplication *app, gpointer user_data)
{
    // Define gtk window, box, buttons and fixed container
    GtkWidget *box;
    GtkWidget *abb, *fbb, *dbb;
    GtkWidget *amb, *fmb, *dmb;
    GtkWidget *ib, *rb;
    GtkWidget *ml, *bl, *sel_op;

    // Create window and container
    window = gtk_application_window_new(app);
    grid = gtk_grid_new();
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    form = gtk_fixed_new();

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
    gtk_fixed_put(GTK_FIXED(form), sel_op, 10, 10);

    // Add function to buttons
    g_signal_connect(amb, "clicked", G_CALLBACK(amb_hnd), NULL);
    g_signal_connect(fmb, "clicked", G_CALLBACK(fmb_hnd), NULL);
    g_signal_connect(dmb, "clicked", G_CALLBACK(dmb_hnd), NULL);
    g_signal_connect(abb, "clicked", G_CALLBACK(abb_hnd), NULL);
    g_signal_connect(fbb, "clicked", G_CALLBACK(fbb_hnd), NULL);
    g_signal_connect(dbb, "clicked", G_CALLBACK(dbb_hnd), NULL);
    g_signal_connect(ib, "clicked", G_CALLBACK(ib_hnd), NULL);
    g_signal_connect(rb, "clicked", G_CALLBACK(rb_hnd), NULL);

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
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);

    // Add box to window
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Set window title
    gtk_window_set_title(GTK_WINDOW(window), "Library");

    // Render gtk window
    gtk_widget_show_all(window);
}

int start_app(int argc, char **argv)
{
    int status;

    app = gtk_application_new("dist.library", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    return status;
}

