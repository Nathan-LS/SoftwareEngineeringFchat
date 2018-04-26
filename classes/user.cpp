#include "user.h"

user::user(std::string username) {
    username_ = username;
}

void user::registerUser() {

}

void user::save() {

}

void user::changeBio() {

}

void user::changePass() {

}

conversation *user::newConvo(std::vector<user *> &users) {
    conversation *newConvo = new conversation(users); //creates a new convo with our selected users
    //todo add convo to users
    return newConvo; //passes new convo back
}

void user::newMessage(conversation *to_convo, std::string &message_text) {
    std::cout << "user.newMessage method received text to send to a particular convo at address " << to_convo
              << " with text=\"" << message_text << "\"\n";
    std::cout << "user.newMessage passing message text to selected convo at address: " << to_convo << std::endl;
    to_convo->newMessage(this, message_text); //pass message to selected convo
}

std::ostream &operator<<(std::ostream &os, const user &u) {
    os << u.getUsername();
    return os;
}

const std::string &user::getUsername() const {
    return username_;
}

void user::changeStatus(int statusCode, std::string &statusMessage) {

}

void user::addContact(user *contact) {

}

void user::removeContact(user *contact) {

}

void user::editMessage(message *messageEdit) {

}

void user::deleteMessage(message *messageDel) {

}

void user::load() {

}
