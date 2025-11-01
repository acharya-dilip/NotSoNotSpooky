#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

struct values {
    int a,b,result;
    char operand[5];
}val;

static void activate (GtkApplication *app,gpointer user_data) {


    //COnnects the styles.css stylesheet
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "styles.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    //Init of windowSpooky
    GtkWidget *windowSpooky = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowSpooky),"Calculator");
    gtk_window_set_default_size(GTK_WINDOW(windowSpooky),600,600);
    gtk_window_present(GTK_WINDOW(windowSpooky));

    //init of gridParent
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSpooky),gridParent);

    //init of numbut7
    GtkWidget *numbut7 = gtk_button_new_with_label("7");
    gtk_grid_attach(GTK_GRID(gridParent),numbut7,0,1,1,1);

    //init of numbut8
    GtkWidget *numbut8 = gtk_button_new_with_label("7");
    gtk_grid_attach(GTK_GRID(gridParent),numbut8,1,1,1,1);





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