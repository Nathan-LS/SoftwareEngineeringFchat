#ifndef FCHATC_CONVERSATION_H
#define FCHATC_CONVERSATION_H

#include <string>
#include <vector>
#include "FchatUser.h"
#include "FchatMessage.h"

class user;
class message;

class conversation {
public:
    conversation(); //default constructor
    void create(); //creates a new conversation if it does not yet exit
    void save(); //saves and sends any changes in the the conversation to the central server
    void load(); //loads the conversations data either from the API or local storage
    void addParticipant(user *); //adds a new user to the conversation
    void removeParticipant(user *); //removes the specific user from the conversation
    message * newMessage(std::string body); //returns a pointer to the created message
    void sendMessage(message *); // sends a created messaged to the API
private:
    std::vector<user *> participants_; //users involved in conversation
    std::vector<std::string> messages_; // messages belonging to the conversation
    std::string dateStarted_; //date and time that the conversation was created
    std::string lastMessageDate_; //date and time of the last message sent in the conversation
};


#endif //FCHATC_CONVERSATION_H
