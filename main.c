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
    *imgCandy,
    *buttonGhost;

    //COnnects the styles.css stylesheet
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "styles.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    //Init of windowSpooky
    windowSpooky = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowSpooky),"SpookyClicky");
    gtk_window_set_default_size(GTK_WINDOW(windowSpooky),600,600);
    gtk_window_present(GTK_WINDOW(windowSpooky));

    //init of gridParent
    gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSpooky),gridParent);

    //init of buttonCandy
    buttonCandy = gtk_button_new_with_label("BUTTONCANDYY!!");
    gtk_grid_attach(GTK_GRID(gridParent),buttonCandy,0,0,150,150);
    //Margins & Paddings
    gtk_widget_set_size_request(buttonCandy,150,150);






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