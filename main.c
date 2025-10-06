#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>
void displaySendyMaily();
void checkLogin();



GtkWidget *entryGmail;
GtkWidget *entryPassword;
GtkWidget *windowLoginScreen;
static void activate (GtkApplication *app,gpointer user_data) {

    GtkWidget *gridParentLoginScreen;
    GtkWidget *labelGmail;
    GtkWidget *labelPassword;
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
    gtk_widget_set_halign(gridParentLoginScreen, GTK_ALIGN_CENTER);
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
    gtk_widget_set_margin_end(entryGmail,10);




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
    gtk_widget_set_margin_end(entryPassword,10);
    gtk_widget_set_margin_bottom(entryPassword,10);
    gtk_widget_set_margin_start(entryPassword,10);



    //Implementation of button login
    buttonLogin = gtk_button_new_with_label("LOGIN");
    gtk_grid_attach(GTK_GRID(gridParentLoginScreen),buttonLogin,1,2,4,1);
    g_signal_connect(buttonLogin,"clicked",G_CALLBACK(checkLogin),NULL);
    //Margins & Paddings
    gtk_widget_set_halign(buttonLogin,GTK_ALIGN_END);
    gtk_widget_set_size_request(buttonLogin,270,-1);
    gtk_widget_set_margin_start(buttonLogin,10);
    gtk_widget_set_margin_end(buttonLogin,10);
    gtk_widget_set_margin_bottom(buttonLogin,10);


}

void checkLogin() {
    CURL *curl=curl_easy_init();
    CURLcode res;
    if (!curl) return;
    if (curl) {
        //conectin to the google smtp server to send credentials
        curl_easy_setopt(curl,CURLOPT_URL,"smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl,CURLOPT_USE_SSL,(long)CURLUSESSL_ALL);

        //To ignore other steps only do the handshake
        curl_easy_setopt(curl,CURLOPT_NOBODY,1L);
        curl_easy_setopt(curl,CURLOPT_HEADER,0L);
        curl_easy_setopt(curl,CURLOPT_UPLOAD,0L);
        curl_easy_setopt(curl,CURLOPT_READFUNCTION,NULL);

        //sending the credentials
        curl_easy_setopt(curl,CURLOPT_USERNAME,gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        curl_easy_setopt(curl,CURLOPT_USERNAME,gtk_editable_get_text(GTK_EDITABLE(entryPassword)));

        res=curl_easy_perform(curl);

        if (res==CURLE_OK) {
            gtk_widget_set_visible(windowLoginScreen,FALSE);
            displaySendyMaily();
        }
        curl_easy_cleanup(curl);
    }
}


void displaySendyMaily() {
    GtkWidget *windowSendyMaily;
    GtkWidget *gridParent;
    GtkWidget *entryGmailFrom;
    GtkWidget *entryGmailTo;
    GtkWidget *entryGmailSubject;
    GtkWidget *textviewGmailBody;
    GtkWidget *buttonSendMail;

    windowSendyMaily = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(windowSendyMaily),"SendyMaily");


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

