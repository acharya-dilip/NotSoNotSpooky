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
    //gtk_window_set_default_size(GTK_WINDOW(windowSpooky),600,600);
    gtk_window_present(GTK_WINDOW(windowSpooky));

    //init of gridParent
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSpooky),gridParent);

    //init of entryCal
    GtkWidget *entryCal = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryCal,0,0,4,1);

    //init of buttonClear
    GtkWidget *buttonClear = gtk_button_new_with_label("C");
    gtk_grid_attach(GTK_GRID(gridParent),buttonClear,0,1,1,1);

    //init of buttonSquare
    GtkWidget *buttonSquare = gtk_button_new_with_label("x²");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSquare,1,1,1,1);

    //init of buttonSqrt
    GtkWidget *buttonSqrt = gtk_button_new_with_label("√x");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSqrt,2,1,1,1);

    //init of numbut7
    GtkWidget *numbut7 = gtk_button_new_with_label("7");
    gtk_grid_attach(GTK_GRID(gridParent),numbut7,0,2,1,1);

    //init of numbut8
    GtkWidget *numbut8 = gtk_button_new_with_label("8");
    gtk_grid_attach(GTK_GRID(gridParent),numbut8,1,2,1,1);

    //init of numbut9
    GtkWidget *numbut9 = gtk_button_new_with_label("9");
    gtk_grid_attach(GTK_GRID(gridParent),numbut9,2,2,1,1);

    //init of numbut6
    GtkWidget *numbut6 = gtk_button_new_with_label("6");
    gtk_grid_attach(GTK_GRID(gridParent),numbut6,0,3,1,1);

    //init of numbut5
    GtkWidget *numbut5 = gtk_button_new_with_label("5");
    gtk_grid_attach(GTK_GRID(gridParent),numbut5,1,3,1,1);

    //init of numbut4
    GtkWidget *numbut4 = gtk_button_new_with_label("4");
    gtk_grid_attach(GTK_GRID(gridParent),numbut4,2,3,1,1);

    //init of numbut1
    GtkWidget *numbut1 = gtk_button_new_with_label("1");
    gtk_grid_attach(GTK_GRID(gridParent),numbut1,0,4,1,1);

    //init of numbut2
    GtkWidget *numbut2 = gtk_button_new_with_label("2");
    gtk_grid_attach(GTK_GRID(gridParent),numbut2,1,4,1,1);

    //init of numbut3
    GtkWidget *numbut3 = gtk_button_new_with_label("3");
    gtk_grid_attach(GTK_GRID(gridParent),numbut3,2,4,1,1);

    //init of buttonPoint
    GtkWidget *buttonPoint = gtk_button_new_with_label(".");
    gtk_grid_attach(GTK_GRID(gridParent),buttonPoint,0,5,1,1);

    //init of numbut0
    GtkWidget *numbut0 = gtk_button_new_with_label("0");
    gtk_grid_attach(GTK_GRID(gridParent),numbut0,1,5,1,1);

    //init of buttonPercent
    GtkWidget *buttonPercent= gtk_button_new_with_label("%");
    gtk_grid_attach(GTK_GRID(gridParent),buttonPercent,2,5,1,1);

    //For the operand buttons
    //init of buttonDiv
    GtkWidget *buttonDiv= gtk_button_new_with_label("/");
    gtk_grid_attach(GTK_GRID(gridParent),buttonDiv,3,0,1,1);

    //init of buttonProd
    GtkWidget *buttonProd= gtk_button_new_with_label("×");
    gtk_grid_attach(GTK_GRID(gridParent),buttonProd,3,1,1,1);

    //init of buttonSub
    GtkWidget *buttonSub= gtk_button_new_with_label("-");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSub,3,2,1,1);



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