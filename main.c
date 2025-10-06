#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>
void displaySendyMaily();




static void activate (GtkApplication *app,gpointer user_data) {
    GtkWidget *windowLoginScreen;
    GtkWidget *gridParentLoginScreen;
    GtkWidget *labelGmail;
    GtkWidget *entryGmail;
    GtkWidget *labelPassword;
    GtkWidget *entryPassword;
    GtkWidget *buttonLogin;


    //Implementation of the login screen window
    windowLoginScreen = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowLoginScreen),"LOGIN");
    gtk_window_set_default_size(GTK_WINDOW(windowLoginScreen),350,150);
    gtk_window_present(GTK_WINDOW(windowLoginScreen));

    //Implementation of the parent grid for login Window
    gridParentLoginScreen = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowLoginScreen),gridParentLoginScreen);
    //Margins & Paddings
    gtk_widget_set_halign(gridParentLoginScreen, GTK_ALIGN_START);
    gtk_widget_set_valign(gridParentLoginScreen, GTK_ALIGN_CENTER);


    //Implementation of label Gmail
    labelGmail = gtk_label_new("GMail:");
    gtk_grid_attach(GTK_GRID(gridParentLoginScreen),labelGmail,0,0,1,1);
    //Margins & Paddings
    gtk_widget_set_halign(labelGmail,GTK_ALIGN_END);
    gtk_widget_set_margin_start(labelGmail,10);
    gtk_widget_set_margin_bottom(labelGmail,10);
    gtk_widget_set_margin_top(labelGmail,10);



    //Implementation of entry Gmail
    entryGmail = gtk_entry_new();
    //gtk_entry_set_placeholder_text(GTK_ENTRY(entryGmail),"ENTER GMAIL");
    gtk_grid_attach(GTK_GRID(gridParentLoginScreen),entryGmail,1,0,3,1);
    //Margins & Paddings
    gtk_widget_set_size_request(entryGmail,270,-1);
    gtk_widget_set_margin_bottom(entryGmail,10);
    gtk_widget_set_margin_top(entryGmail,10);
    gtk_widget_set_margin_start(entryGmail,10);



    //Implementation of Label Password
    labelPassword = gtk_label_new("Pass:");
    gtk_grid_attach(GTK_GRID(gridParentLoginScreen),labelPassword,0,1,1,1);
    //Margins & Paddings
    gtk_widget_set_halign(labelPassword,GTK_ALIGN_END);
    gtk_widget_set_margin_start(labelPassword,10);
    gtk_widget_set_margin_bottom(labelPassword,10);




    //Implementation of entry Password
    entryPassword = gtk_entry_new();
    //gtk_entry_set_placeholder_text(GTK_ENTRY(entryPassword),"ENTER PASSWORD");
    gtk_grid_attach(GTK_GRID(gridParentLoginScreen),entryPassword,1,1,3,1);
    //Margins & Paddings
    gtk_widget_set_size_request(entryPassword,270,-1);
    gtk_widget_set_margin_bottom(entryPassword,10);
    gtk_widget_set_margin_start(entryPassword,10);








}


void displaySendyMaily() {
    GtkWidget *windowSendyMaily;
    GtkWidget *gridParent;
    GtkWidget *entryGmailFrom;
    GtkWidget *entryGmailTo;
    GtkWidget *entryGmailSubject;
    GtkWidget *textviewGmailBody;
    GtkWidget *buttonSendMail;


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

