#include "FchatMessage.h"

#define max_length 250

message::message(user *author, std::string &body) {
    author_ = author;
    messageText_ = body;
    std::cout << "\n\nmessage.constructor - received textbody='" << body << "' from author= " << *author
              << ". Variables are now set for message class\n";
    std::cout << "message.constructor - Check: does the message length exceed maximum char limit?\n";
    if (messageText_.length() >= max_length) {
        std::cout
                << "\tmessage.constructor - Check Condition True: Message is too long, display error message and exit function.\n";
        exit(1); //todo remove with correct error handel call when adding more classes
    } else {
        std::cout << "\tmessage.constructor - Check Condition False: Message length is below limit, continue\n";
    }

}

void message::create() {

}

void message::save() {

}

void message::load() {

}

void message::edit() {

}

void message::post() {
    std::cout << "\n\nmessage.post - Received call to push message object @ " << this
              << ". Now message is pushed to server at this point.\n";
    std::cout << "\n\nComplete message sent:\nMessage author: " << *author_ << ", message text= '" << messageText_
              << "'\nFunction sendMessage is now complete!";
}
