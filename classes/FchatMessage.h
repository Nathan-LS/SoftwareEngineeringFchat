#ifndef FCHATC_FCHATMESSAGE_H
#define FCHATC_FCHATMESSAGE_H

#include <string>
#include <vector>
#include "FchatUser.h"

class user;

class message {
public:
    message(user *author, std::string &body); //creates a new message with body text
    void save(); //saves any changes made to the message and calls the proper API function to update the server
    void load(); //load existing message from api
    void edit(std::string &editText); //allows for editing the message after it has been sent
    void deleteM(); //delete message object
    void displayMessage(); //displays the message
    void post(); //pushes message to server

private:
    std::string messageText_; //the message text/body
    std::string timeStamp_; //timestamp of the message
    user *author_; //user author of the message
    bool fileAttached_; //bool for if we have a file attached
    double fileSize_; //file size of attachment
    std::string fileLocation_; //location of the file on the user's HD

};


#endif //FCHATC_FCHATMESSAGE_H
