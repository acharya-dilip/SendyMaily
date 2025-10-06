

# SendyMaily
This is a custom email client built in C using the GTK4 Library for GUI &
CURL for handling the authentication with gmail and also sending the mail.<br>
It includes a login window & an option to autosave your login information. With a main window consisting of entries and text 
view to write the email of the recipient and the subject of the mail along with the body of the mail
# How to use?
- Login using your gmail and the app password
 (You can obtain your app password by going into manage your google account and searching it there and create a new one for this usage"
- Toggle the Save Login info checkbox after writing your credentials to save them for persistant use
- After logging in type the recipients email in the entry beside To: 
- Enter the Subject in the subject entry and the body of the mail in the text view
- After writing your mail hit the send button to send the email
- To logout and quit press the LogOut button at the start of the titlebar of the window
# LIUNX BUILD INSTRUCTIONS

| FOR DEBIAN/UBUNTU                | For ARCH                    |      
|----------------------------------|-----------------------------|      
| Install Dependencies             | Install Dependencies        |      
| sudo apt install gtk             | sudo pacman -S gtk          |
| sudo apt install curl            | sudo pacman -S curl         |
| sudo apt install build-essential | sudo pacman -S base-devel   |
| sudo apt install cmake           | sudo pacman -S cmake        |

### Clone into the Github repo

| Command                                                   |
|-----------------------------------------------------------|
| git clone https://github.com/acharya-dilip/SendyMaily.git |
### Navigate to project directory
| Command       |
|---------------|
| cd SendyMaily |
### Create the build directory
| Command  |
|--------------------------|
| mkdir build              |
### Navigate into the build directory
| Command   |
|----------------------------------|
| cd build                         |
###  Execute the Build Commands
| Commands   |
|----------------------------|
| cmake ..                   |
| cmake --build .            |

### Run the Program

| Command      |
|--------------|
| ./SendyMaily |


