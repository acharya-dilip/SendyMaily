#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>
void displaySendyMaily();
void checkLogin();
void sendMail();



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
    gtk_entry_set_visibility(GTK_ENTRY(entryPassword),FALSE);
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
    //if (!curl) return;
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
        // char gmail[50];
        // strcpy(gmail,gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        // char password[50];
        // strcpy(password,gtk_editable_get_text(GTK_EDITABLE(entryPassword)));
        curl_easy_setopt(curl,CURLOPT_USERNAME,gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        //printf("%s",gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        curl_easy_setopt(curl,CURLOPT_PASSWORD,gtk_editable_get_text(GTK_EDITABLE(entryPassword)));
        //printf("%s",gtk_editable_get_text(GTK_EDITABLE(entryPassword)));

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            gtk_widget_set_visible(windowLoginScreen,FALSE);
            printf("HelloMOCO");
            displaySendyMaily();
        }
        curl_easy_cleanup(curl);
    }
}

GtkWidget *windowSendyMaily;
GtkWidget *entryGmailTo;
GtkWidget *entryGmailSubject;
GtkWidget *textviewGmailBody;
void displaySendyMaily() {

    GtkWidget *gridParent;
    GtkWidget *labelGmailTo;
    GtkWidget *labelGmailFrom;
    GtkWidget *entryGmailFrom;
    GtkWidget *buttonSendMail;
    //Implement the displaySendyMail Window
    windowSendyMaily = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(windowSendyMaily),"SendyMaily");
    gtk_window_set_default_size(GTK_WINDOW(windowSendyMaily),400,400);
    gtk_window_present(GTK_WINDOW(windowSendyMaily));

    //Implementation of gridparent
    gridParent =gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowSendyMaily),gridParent);

    //Margins & Paddings
    gtk_widget_set_halign(gridParent,GTK_ALIGN_CENTER);


    //Implement the To gmail label
    labelGmailTo=gtk_label_new("To:");
    gtk_grid_attach(GTK_GRID(gridParent),labelGmailTo,0,0,1,1);
    //Margins and Paddings
    gtk_widget_set_margin_start(labelGmailTo,10);
    gtk_widget_set_margin_top(labelGmailTo,10);
    gtk_widget_set_halign(labelGmailTo,GTK_ALIGN_START);


    //Implementation of the To Gmail Entry
    entryGmailTo=gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryGmailTo,1,0,1,1);
    //Margins & paddings
    gtk_widget_set_margin_end(entryGmailTo,10);
    gtk_widget_set_margin_start(entryGmailTo,10);
    gtk_widget_set_margin_top(entryGmailTo,10);
    gtk_widget_set_size_request(entryGmailTo,350,-1);



    //Implement the from gmail label
    labelGmailFrom=gtk_label_new("From:");
    gtk_grid_attach(GTK_GRID(gridParent),labelGmailFrom,0,1,1,1);
    gtk_widget_set_margin_start(labelGmailFrom,10);
    gtk_widget_set_margin_top(labelGmailFrom,10);
    gtk_widget_set_halign(labelGmailFrom,GTK_ALIGN_START);



    //Implementation of the from gmail entry
    entryGmailFrom=gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryGmailFrom,1,1,1,1);
    gtk_editable_set_text(GTK_EDITABLE(entryGmailFrom),gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
    gtk_editable_set_editable(GTK_EDITABLE(entryGmailFrom),FALSE);
    //Margins & Paddings
    gtk_widget_set_margin_end(entryGmailFrom,10);
    gtk_widget_set_margin_start(entryGmailFrom,10);
    gtk_widget_set_margin_top(entryGmailFrom,10);
    gtk_widget_set_size_request(entryGmailFrom,350,-1);

    //Implementation of entryGmailSubject
    entryGmailSubject = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryGmailSubject,0,2,2,1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryGmailSubject),"Enter Subject");

    //Margins & Paddings
    gtk_widget_set_margin_top(entryGmailSubject,10);
    gtk_widget_set_size_request(entryGmailSubject,380,-1);
    gtk_widget_set_margin_start(entryGmailSubject,10);
    gtk_widget_set_margin_end(entryGmailSubject,10);


    //Implementation of textviewGmailBody
    textviewGmailBody=gtk_text_view_new();
    gtk_grid_attach(GTK_GRID(gridParent),textviewGmailBody,0,3,2,1);
    gtk_widget_set_size_request(textviewGmailBody,380,380);
    //Margins & Paddings
    gtk_widget_set_margin_top(textviewGmailBody,10);
    gtk_widget_set_margin_start(textviewGmailBody,10);
    gtk_widget_set_margin_end(textviewGmailBody,10);

    //Implementation of buttonSendMail
    buttonSendMail=gtk_button_new_with_label("SEND");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSendMail,0,4,2,1);
    gtk_widget_set_size_request(buttonSendMail,380,-1);
    g_signal_connect(buttonSendMail,"clicked",G_CALLBACK(sendMail),NULL);
    //Margins & paddings
    gtk_widget_set_margin_start(buttonSendMail,10);
    gtk_widget_set_margin_end(buttonSendMail,10);
    gtk_widget_set_margin_top(buttonSendMail,10);
    gtk_widget_set_margin_bottom(buttonSendMail,10);


}



void sendMail() {
    CURL *curl=curl_easy_init();
    if (!curl) return;
    if (curl) {
        //Connecting to the smpt sevr
        curl_easy_setopt(curl,CURLOPT_URL,"smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl,CURLOPT_USE_SSL,(long)CURLUSESSL_ALL);

        curl_easy_setopt(curl,CURLOPT_USERNAME,gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        curl_easy_setopt(curl,CURLOPT_PASSWORD,gtk_editable_get_text(GTK_EDITABLE(entryPassword)));
    }
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

