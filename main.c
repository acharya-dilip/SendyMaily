#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>
void displaySendyMaily();




static void activate (GtkApplication *app,gpointer user_data) {
    GtkWidget *windowLoginScreen;
    GtkWidget *parentGridLoginScreen;
    GtkWidget *entryGmail;
    GtkWidget *entryPassword;
    GtkWidget *buttonLogin;


    //Implementation of the login screen window
    windowLoginScreen = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowLoginScreen),"LOGIN");
    gtk_window_set_default_size(GTK_WINDOW(windowLoginScreen),350,150);
    gtk_window_present(GTK_WINDOW(windowLoginScreen));

    //Implementation of the parent grid for login Window
    parentGridLoginScreen = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowLoginScreen),parentGridLoginScreen);
    //Margins & Paddings
    gtk_widget_set_halign(parentGridLoginScreen, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(parentGridLoginScreen, GTK_ALIGN_CENTER);






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

