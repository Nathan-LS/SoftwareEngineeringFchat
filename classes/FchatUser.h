
#ifndef FCHATC_USER_H
#define FCHATC_USER_H

#include <vector>
#include <string>
#include <iostream>
#include "FchatConversation.h"

class conversation;
class message;

class user{
public:
    user(std::string username); //temp set username
    void create(); //create a new user function ie register function
    void save(); //saves user details to the server calling the api method
    void changeBio(); //function to change information about the user's bio
    void changePass(); //function to begin the process of prompting the user to change their password
    void setup(); //prompt for biography changes

    const std::string &getUsername() const;

    conversation *newConvo(std::vector<user *> &users); //create convo and return pointer to it
    void newMessage(conversation *to_convo,
                    std::string &message_text); //create a new message given a convo instance and text
    friend std::ostream &operator<<(std::ostream &os, const user &u);

private:
    std::string username_; //user's username
    std::string fName_; //fname
    std::string LName_; //lanem
    std::string email_; //email
    std::string passHash_; //password hash
    std::string bio_; //short user biography message
    std::vector<conversation *> conversations_; //container of multiple conversation pointers that the user participates in
    int birthDay_; //birthday
    int statusType_; //status code IE 0 for offline, 1 away, 2 online
    std::string statusMessage_; //text status message to appear alongside status type
    int currentTheme_; //user's current theme id for appearance
};


#endif //FCHATC_USER_H
