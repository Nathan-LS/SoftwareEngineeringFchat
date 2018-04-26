#ifndef FCHATC_CONVERSATION_H
#define FCHATC_CONVERSATION_H

#include <string>
#include <iostream>
#include <vector>
#include "user.h"
#include "message.h"

class user;
class message;

class conversation {
public:
    conversation(std::vector<user *> &participants); //constructor
    void save(); //saves and sends any changes in the the conversation to the central server
    void load(); //loads the conversations data either from the API or local storage
    void addParticipant(user *u); //adds a new user to the conversation
    void removeParticipant(user *u); //removes the specific user from the conversation
    const std::vector<user *> &getParticipants_() const; //returns a list of participants in message

    void newMessage(user *author, std::string &body); //creates a new message instance and adds to convo message storage
    void deleteMessage(message *messageDel);//remove a selected message from internal container of conversations

    friend std::ostream &operator<<(std::ostream &os, const conversation &c); //prints participants
private:
    std::vector<user *> participants_; //users involved in conversation
    std::vector<message *> messages_; // messages belonging to the conversation
    std::string dateStarted_; //date and time that the conversation was created
    std::string lastMessageDate_; //date and time of the last message sent in the conversation
};


#endif //FCHATC_CONVERSATION_H
