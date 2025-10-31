#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>


static void activate (GtkApplication *app,gpointer user_data) {
    GtkWidget
    *windowSpooky,
    *gridParent,
    *frameCandies,
    *labelBlueCandy,
    *labelRedCandy,
    *labelPurpleCandy,
    *buttonCandy,
    *buttonGhost;

    //Init of windowSpooky
    windowSpooky = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(windowSpooky),"SpookyClicky");
    gtk_window_set_default_size(GTK_WINDOW(windowSpooky),600,600);
    gtk_window_present(GTK_WINDOW(windowSpooky));

    //init of gridParent
    gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSpooky),gridParent);





}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}