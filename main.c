#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

struct values {
    long long a,b;
    double result;
    int operandType;
    char operand[5];
}val;


void numButPress(GtkButton *button,gpointer user_data);
void operandPress(GtkButton *button,gpointer operand);
void performCalculation();
void square();
//Jumpscares and quirks
void checkSixSeven(int x);
void sixSeven(); int sixSevenCondition;
void performSpooky(); int spookyThreshold;

void clearEntry();
//Globalised Variables
GtkWidget *entryCal;
static void activate (GtkApplication *app,gpointer user_data) {

    performSpooky();

    //Init of windowSpooky
    GtkWidget *windowSpooky = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowSpooky),"Calculator");
    //gtk_window_set_default_size(GTK_WINDOW(windowSpooky),600,600);
    gtk_window_present(GTK_WINDOW(windowSpooky));

    //init of gridParent
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSpooky),gridParent);

    //init of entryCal
    entryCal = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryCal,0,0,4,1);
    gtk_editable_set_editable(GTK_EDITABLE(entryCal),FALSE);

    //init of buttonClear
    GtkWidget *buttonClear = gtk_button_new_with_label("C");
    gtk_grid_attach(GTK_GRID(gridParent),buttonClear,0,1,3,1);
    g_signal_connect(buttonClear,"clicked",G_CALLBACK(clearEntry),NULL);
    gtk_widget_add_css_class(buttonClear,"spookyButton");

    //init of numbut7
    GtkWidget *numbut7 = gtk_button_new_with_label("7");
    gtk_grid_attach(GTK_GRID(gridParent),numbut7,0,2,1,1);
    g_signal_connect(numbut7,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(7));
    gtk_widget_add_css_class(numbut7,"spookyButton7");
    GtkWidget *pic7 = gtk_picture_new_for_filename("src/7.png");
    gtk_picture_set_can_shrink(GTK_PICTURE(pic7), TRUE);
    gtk_picture_set_content_fit(GTK_PICTURE(pic7), GTK_CONTENT_FIT_CONTAIN);
    gtk_button_set_child(GTK_BUTTON(numbut7),pic7);

    //init of numbut8
    GtkWidget *numbut8 = gtk_button_new_with_label("8");
    gtk_grid_attach(GTK_GRID(gridParent),numbut8,1,2,1,1);
    g_signal_connect(numbut8,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(8));
    gtk_widget_add_css_class(numbut8,"spookyButton8");



    //init of numbut9
    GtkWidget *numbut9 = gtk_button_new_with_label("9");
    gtk_grid_attach(GTK_GRID(gridParent),numbut9,2,2,1,1);
    g_signal_connect(numbut9,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(9));
    gtk_widget_add_css_class(numbut9,"spookyButton9");



    //init of numbut4
    GtkWidget *numbut4 = gtk_button_new_with_label("4");
    gtk_grid_attach(GTK_GRID(gridParent),numbut4,0,3,1,1);
    g_signal_connect(numbut4,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(4));
    gtk_widget_add_css_class(numbut4,"spookyButton4");



    //init of numbut5
    GtkWidget *numbut5 = gtk_button_new_with_label("5");
    gtk_grid_attach(GTK_GRID(gridParent),numbut5,1,3,1,1);
    g_signal_connect(numbut5,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(5));
    gtk_widget_add_css_class(numbut5,"spookyButton5");



    //init of numbut6
    GtkWidget *numbut6 = gtk_button_new_with_label("6");
    gtk_grid_attach(GTK_GRID(gridParent),numbut6,2,3,1,1);
    g_signal_connect(numbut6,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(6));
    gtk_widget_add_css_class(numbut6,"spookyButton6");



    //init of numbut1
    GtkWidget *numbut1 = gtk_button_new_with_label("1");
    gtk_grid_attach(GTK_GRID(gridParent),numbut1,0,4,1,1);
    g_signal_connect(numbut1,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(1));
    gtk_widget_add_css_class(numbut1,"spookyButton1");



    //init of numbut2
    GtkWidget *numbut2 = gtk_button_new_with_label("2");
    gtk_grid_attach(GTK_GRID(gridParent),numbut2,1,4,1,1);
    g_signal_connect(numbut2,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(2));
    gtk_widget_add_css_class(numbut2,"spookyButton2");



    //init of numbut3
    GtkWidget *numbut3 = gtk_button_new_with_label("3");
    gtk_grid_attach(GTK_GRID(gridParent),numbut3,2,4,1,1);
    g_signal_connect(numbut3,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(3));
    gtk_widget_add_css_class(numbut3,"spookyButton3");



    //init of buttonPoint
    GtkWidget *buttonPoint = gtk_button_new_with_label(".");
    gtk_grid_attach(GTK_GRID(gridParent),buttonPoint,0,5,1,1);
    gtk_widget_add_css_class(buttonPoint,"spookyButtonSkull");



    //init of numbut0
    GtkWidget *numbut0 = gtk_button_new_with_label("0");
    gtk_grid_attach(GTK_GRID(gridParent),numbut0,1,5,1,1);
    g_signal_connect(numbut0,"clicked",G_CALLBACK(numButPress),GINT_TO_POINTER(0));
    gtk_widget_add_css_class(numbut0,"spookyButton0");



    //init of buttonPercent
    GtkWidget *buttonAns= gtk_button_new_with_label("Ans");
    gtk_grid_attach(GTK_GRID(gridParent),buttonAns,2,5,1,1);
    gtk_widget_add_css_class(buttonAns,"spookyButtonAns");


    //For the operand buttons

    //init of buttonDiv
    GtkWidget *buttonDiv= gtk_button_new_with_label("/");
    gtk_grid_attach(GTK_GRID(gridParent),buttonDiv,3,1,1,1);
    g_signal_connect(buttonDiv,"clicked",G_CALLBACK(operandPress),"/");
    gtk_widget_add_css_class(buttonDiv,"spookyButtonDiv");



    //init of buttonProd
    GtkWidget *buttonProd= gtk_button_new_with_label("×");
    gtk_grid_attach(GTK_GRID(gridParent),buttonProd,3,2,1,1);
    g_signal_connect(buttonProd,"clicked",G_CALLBACK(operandPress),"×");
    gtk_widget_add_css_class(buttonProd,"spookyButtonProd");


    //init of buttonSub
    GtkWidget *buttonSub= gtk_button_new_with_label("-");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSub,3,3,1,1);
    g_signal_connect(buttonSub,"clicked",G_CALLBACK(operandPress),"-");
    gtk_widget_add_css_class(buttonSub,"spookyButtonSub");



    //init of buttonSum
    GtkWidget *buttonSum= gtk_button_new_with_label("+");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSum,3,4,1,1);
    g_signal_connect(buttonSum,"clicked",G_CALLBACK(operandPress),"+");
    gtk_widget_add_css_class(buttonSum,"spookyButtonSum");



    //For the result button

    //init of buttonResult
    GtkWidget *buttonResult = gtk_button_new_with_label("=");
    gtk_grid_attach(GTK_GRID(gridParent),buttonResult,3,5,1,1);
    g_signal_connect(buttonResult,"clicked",G_CALLBACK(performCalculation),NULL);
    gtk_widget_add_css_class(buttonResult,"spookyButtonRes");


}

void numButPress(GtkButton *button,gpointer user_data) {
    spookyThreshold += 5;
    int n = GPOINTER_TO_INT(user_data);
    checkSixSeven(n);
    if (strcmp(val.operand,"")==0){
        val.a = val.a*10+n;
        char temp[50];
        snprintf(temp,sizeof(temp),"%lld",val.a);
        gtk_editable_set_text(GTK_EDITABLE(entryCal),temp);
    }
    else {
        val.b = val.b*10+n;
        char temp[50];
        snprintf(temp,sizeof(temp),"%s%lld",val.operand,val.b);
        gtk_editable_set_text(GTK_EDITABLE(entryCal),temp);
    }
    if (spookyThreshold>=100) {
        performSpooky();
    }
}
void checkSixSeven(int x) {
    if (x==7){
        if (sixSevenCondition == 1) {
            sixSeven();
            spookyThreshold += 20;
        }
    }
    if (x==6) {
        sixSevenCondition = 1;
    }else {
        sixSevenCondition = 0;
    }
}
void operandPress(GtkButton *button,gpointer operand) {
    strcpy(val.operand,operand);
    gtk_editable_set_text(GTK_EDITABLE(entryCal),operand);
    //sets the operandType variable
    if (strcmp(operand,"/")==0) {
        val.operandType = 1;
    }
    if (strcmp(operand,"×")==0) {
        val.operandType = 2;
    }
    if (strcmp(operand,"-")==0) {
        val.operandType = 3;
    }
    if (strcmp(operand,"+")==0) {
        val.operandType = 4;
    }
}

void performCalculation() {
    // operandType meaning
    // 1 = div
    // 2 = product
    // 3 = subtract
    // 4 = sum
    int result;//This vaaariable is used to store 0 or 1 from the below switch
    //0 indicates successful
    //1 indicates failure
    switch(val.operandType) {
        case 1:
            val.result = val.a/val.b;
            result = 0;
            break;
        case 2:
            val.result = val.a*val.b;
            result = 0;
            break;
        case 3:
            val.result = val.a-val.b;
            result = 0;
            break;
        case 4:
            val.result = val.a+val.b;
            result = 0;
            break;
        default:
            result = 1;
    }
    if (result==0) {
        char temp[50];
        snprintf(temp,sizeof(temp),"%3.lf",val.result);
        gtk_editable_set_text(GTK_EDITABLE(entryCal),temp);
    }
    else {
        gtk_editable_set_text(GTK_EDITABLE(entryCal),"Error!");
        system("gst-launch-1.0 playbin uri=\"https://hc-cdn.hel1.your-objectstorage.com/s/v3/8c5dfc16bc6f376ef4fd6a1569c921f6b60eec29_6ix9ine_stoopid__sound_effect__audio.mp4\" >/dev/null 2>&1 &");
    }

    val.a = 0;
    val.b = 0;
    val.result = 0;
    val.operandType = 0;
    strcpy(val.operand,"");
}

void clearEntry() {
    gtk_editable_set_text(GTK_EDITABLE(entryCal),"");
    val.a = 0;
    val.b = 0;
    val.result = 0;
    strcpy(val.operand,"");
}

void performSpooky() {
    //COnnects the styles.css stylesheet
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "styles.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );;
}

void sixSeven(){
    printf("SiXsEvEn");
    system("gst-launch-1.0 playbin uri=\"https://hc-cdn.hel1.your-objectstorage.com/s/v3/b0115ef0df6139a69e9e67c4dc8a0fcc50e57e07_67._sound_effect._audio.mp4\" >/dev/null 2>&1 &");
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