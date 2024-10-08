#include<stdlib.h>
#include<gtk/gtk.h>
#include"gui.h"
#include"database.h"


char* itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

GtkApplication *app;

static GtkWidget *window, *grid, *form;
static GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5;
static GtkWidget *label2, *label3, *label4, *label5;
static GtkWidget *output2, *output3, *output4, *output5;

void clear_entry()
{
}

void add_book_submit_handler()
{
    BOOK bk;
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) strcpy(bk.id, buffer);
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry2)));
    if(strlen(buffer) < 50) strcpy(bk.name, buffer);
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry3)));
    if(strlen(buffer) < 50) strcpy(bk.author, buffer);
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry4)));
    if(strlen(buffer) < 50) strcpy(bk.pub, buffer);
    bk.price = atoi((char*)(gtk_entry_get_text(GTK_ENTRY(entry5))));
    insert_book(bk);
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

void find_book_submit_handler()
{
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) find_book(buffer);
    if(found)
    {
        printf("flag\n %s \n %s \n %d", found_book.name, found_book.author, found_book.price);
        gtk_container_remove(GTK_CONTAINER(form), label2);
        label2 = gtk_label_new("Name:");
        gtk_fixed_put(GTK_FIXED(form), label2, 10, 100);
        gtk_container_remove(GTK_CONTAINER(form), output2);
        output2 = gtk_label_new(found_book.name);
        gtk_fixed_put(GTK_FIXED(form), output2, 100, 100);
        gtk_container_remove(GTK_CONTAINER(form), label3);
        label3 = gtk_label_new("Author:");
        gtk_fixed_put(GTK_FIXED(form), label3, 10, 130);
        gtk_container_remove(GTK_CONTAINER(form), output3);
        output3 = gtk_label_new(found_book.author);
        gtk_fixed_put(GTK_FIXED(form), output3, 100, 130);
        gtk_container_remove(GTK_CONTAINER(form), label4);
        label4 = gtk_label_new("Publication:");
        gtk_fixed_put(GTK_FIXED(form), label4, 10, 160);
        gtk_container_remove(GTK_CONTAINER(form), output4);
        output4 = gtk_label_new(found_book.pub);
        gtk_fixed_put(GTK_FIXED(form), output4, 100, 160);
        gtk_container_remove(GTK_CONTAINER(form), label5);
        label5 = gtk_label_new("Price:");
        gtk_fixed_put(GTK_FIXED(form), label5, 10, 190);
        gtk_container_remove(GTK_CONTAINER(form), output5);
        output5 = gtk_label_new(itoa(found_book.price, 10));
        gtk_fixed_put(GTK_FIXED(form), output5, 100, 190);
    }
    else
    {
        gtk_container_remove(GTK_CONTAINER(form), label2);
        gtk_container_remove(GTK_CONTAINER(form), output2);
        gtk_container_remove(GTK_CONTAINER(form), label3);
        gtk_container_remove(GTK_CONTAINER(form), output3);
        gtk_container_remove(GTK_CONTAINER(form), label4);
        gtk_container_remove(GTK_CONTAINER(form), output4);
        gtk_container_remove(GTK_CONTAINER(form), label5);
        gtk_container_remove(GTK_CONTAINER(form), output5);
        label2 = gtk_label_new("Not found");
        gtk_fixed_put(GTK_FIXED(form), label2, 10, 100);
    }
    // Render gtk window
    gtk_widget_show_all(window);
}

void fbb_hnd(GtkWidget *fbb, gpointer data)
{
    GtkWidget *heading, *label1;
    GtkWidget *submit_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Find book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(find_book_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 100, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void delete_book_submit_handler()
{
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) del_book(buffer);
}

void dbb_hnd(GtkWidget *dbb, gpointer data)
{
    GtkWidget *heading, *label1;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Delete book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(delete_book_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void add_member_submit_handler()
{
    MEMBER m;
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) strcpy(m.id, buffer);
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry2)));
    if(strlen(buffer) < 50) strcpy(m.name, buffer);
    m.deposit = atoi((char*)(gtk_entry_get_text(GTK_ENTRY(entry3))));
    insert_member(m);
}

void amb_hnd(GtkWidget *amb, gpointer data)
{
    GtkWidget *heading, *label1, *label2, *label3;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Add member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    label2 = gtk_label_new("Name");
    gtk_fixed_put(GTK_FIXED(form), label2, 10, 90);
    entry2 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry2, 100, 90);
    label3 = gtk_label_new("Deposit");
    gtk_fixed_put(GTK_FIXED(form), label3, 10, 130);
    entry3 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry3, 100, 130);

    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(add_member_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void find_member_submit_handler()
{
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) find_member(buffer);
    if(found)
    {
        printf("%s \n %d", found_member.name, found_member.deposit);
        gtk_container_remove(GTK_CONTAINER(form), label2);
        label2 = gtk_label_new("Name:");
        gtk_fixed_put(GTK_FIXED(form), label2, 10, 100);
        gtk_container_remove(GTK_CONTAINER(form), output2);
        output2 = gtk_label_new(found_member.name);
        gtk_fixed_put(GTK_FIXED(form), output2, 100, 100);
        //printf("flag");
        gtk_container_remove(GTK_CONTAINER(form), label3);
        label3 = gtk_label_new("Deposit:");
        gtk_fixed_put(GTK_FIXED(form), label3, 10, 130);
        gtk_container_remove(GTK_CONTAINER(form), output3);
        output3 = gtk_label_new(itoa(found_member.deposit, 10));
        gtk_fixed_put(GTK_FIXED(form), output3, 100, 130);
    }
    else
    {
        gtk_container_remove(GTK_CONTAINER(form), label2);
        gtk_container_remove(GTK_CONTAINER(form), output2);
        gtk_container_remove(GTK_CONTAINER(form), label3);
        gtk_container_remove(GTK_CONTAINER(form), output3);
        label2 = gtk_label_new("Not found");
        gtk_fixed_put(GTK_FIXED(form), label2, 10, 100);
    }
    // Render gtk window
    gtk_widget_show_all(window);
}

void fmb_hnd(GtkWidget *fmb, gpointer data)
{
    GtkWidget *heading, *label1;
    GtkWidget *submit_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Find member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(find_member_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 100, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void delete_member_submit_handler()
{
    char *buffer;
    buffer = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    if(strlen(buffer) < 6) del_member(buffer);
}

void dmb_hnd(GtkWidget *dmb, gpointer data)
{
    GtkWidget *heading, *label1;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Delete member");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(delete_member_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void issue_book_submit_handler()
{
    char *buffer1, *buffer2;
    buffer1 = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    buffer2 = (char*)(gtk_entry_get_text(GTK_ENTRY(entry2)));
    if(strlen(buffer1) < 6 && strlen(buffer2) < 6) issue_book(buffer1, buffer2);
}

void ib_hnd(GtkWidget *ib, gpointer data)
{
    GtkWidget *heading, *label1, *label2;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Issue book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("Book ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    label2 = gtk_label_new("Member ID");
    gtk_fixed_put(GTK_FIXED(form), label2, 10, 90);
    entry2 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry2, 100, 90);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(issue_book_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

    // Attach form to grid
    gtk_grid_attach(GTK_GRID(grid), form, 1, 0, 10, 10);
    // Render gtk window
    gtk_widget_show_all(window);
}

void return_book_submit_handler()
{
    char *buffer1, *buffer2;
    buffer1 = (char*)(gtk_entry_get_text(GTK_ENTRY(entry1)));
    buffer2 = (char*)(gtk_entry_get_text(GTK_ENTRY(entry2)));
    if(strlen(buffer1) < 6 && strlen(buffer2) < 6) return_book(buffer1, buffer2);
}

void rb_hnd(GtkWidget *rb, gpointer data)
{
    GtkWidget *heading, *label1, *label2;
    GtkWidget *submit_button, *clear_button;
    // Remove previous form
    gtk_container_remove(GTK_CONTAINER(grid), form);
    form = gtk_fixed_new();
    // Add lable to empty container
    heading = gtk_label_new("Return book");
    gtk_fixed_put(GTK_FIXED(form), heading, 10, 10);
    label1 = gtk_label_new("Book ID");
    gtk_fixed_put(GTK_FIXED(form), label1, 10, 50);
    entry1 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry1, 100, 50);
    label2 = gtk_label_new("Member ID");
    gtk_fixed_put(GTK_FIXED(form), label2, 10, 90);
    entry2 = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(form), entry2, 100, 90);
    submit_button = gtk_button_new_with_label("Submit");
    g_signal_connect(submit_button, "clicked", G_CALLBACK(return_book_submit_handler), NULL);
    gtk_fixed_put(GTK_FIXED(form), submit_button, 50, 280);
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_entry), NULL);
    gtk_fixed_put(GTK_FIXED(form), clear_button, 150, 280);

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

