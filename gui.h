#ifndef _GUI_H_
#define _GUI_H_

#include<gtk/gtk.h>

// Variables
GtkApplication *app;

int start_app(int argc, char **argv);

// Callback functions
static void activate(GtkApplication *app, gpointer user_data);

// Button handeler function
void abb_hnd(GtkWidget *abb, gpointer data);
void fbb_hnd(GtkWidget *fbb, gpointer data);
void dbb_hnd(GtkWidget *dbb, gpointer data);
void amb_hnd(GtkWidget *amb, gpointer data);
void fmb_hnd(GtkWidget *fmb, gpointer data);
void dmb_hnd(GtkWidget *dmb, gpointer data);
void ib_hnd(GtkWidget *ib, gpointer data);
void rb_hnd(GtkWidget *rb, gpointer data);

#endif
