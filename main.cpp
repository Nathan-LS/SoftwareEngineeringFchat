#include <iostream>
#include <vector>
#include "classes/FchatUser.h"

void demo_sendmessage(std::string &message_input) { //demo function for sending a message
    user LoggedIn("Me"); //simulate complete authentication somewhere else
    user Contact1("Adam"); //simulate available contacts to LoggedIn user
    user Contact2("Bob");
    user Contact3("Crystal");
    std::vector<user *> selected_contacts; //simulate logged in user selected participants from contact list for new convo
    selected_contacts.push_back(&Contact1); //user selected contact 1
    selected_contacts.push_back(&Contact2); //user selected contact 2
    selected_contacts.push_back(&Contact3); //user selected contact 3
    conversation *selected_convo = LoggedIn.newConvo(
            selected_contacts); //user clicked finalize and now a new convo is created with selected contacts
    LoggedIn.newMessage(selected_convo, message_input); //<<--start of swimlane diagram for send message function
    //user has typed their message and clicked send for a given convo
}

int main() {
    std::cout << "Message text to send:\n";
    std::string input_text;
    std::getline(std::cin, input_text, '\n');
    demo_sendmessage(input_text);
    return 0;
}