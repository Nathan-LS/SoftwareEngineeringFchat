#include "FchatConversation.h"

conversation::conversation(std::vector<user *> &participants) {
    participants_ = participants;
}

void conversation::save() {

}

void conversation::load() {

}

void conversation::addParticipant(user *) {

}

void conversation::removeParticipant(user *) {

}

void conversation::newMessage(user *author, std::string &body) {
    std::cout << "\n\nconversation.newMessage - convo @ " << this << " received text='" << body << "' from author="
              << *author << "\n";
    std::cout << "conversation.newMessage - Check: are we sending message to convo with no participants?\n";
    if (getParticipants_().empty()) {
        std::cout
                << "\tconversation.newMessage - Check Condition True: We can't send a message to a convo with no participants. Show error popup and exit sendmessage.\n";
        exit(1); //todo remove with correct error handel call when adding more classes
    } else {
        std::cout
                << "\tconversation.newMessage - Checked Condition False: There are more than 0 participants. Participants ignoring author are:\n";
        for (auto i : participants_) {
            std::cout << "\t\t" << *i << "\n";
        }
        std::cout << "conversation.newMessage - calling constructor for a new message object\n";
        message *newMessage = new message(author, body); //our new message
        std::cout
                << "\n\nconversation.newMessage - created a message object. Add message pointer to conversation internal container of messages.\n";
        messages_.push_back(newMessage);
        std::cout << "conversation.newMessage - We will now call the message.post function to push our message @ "
                  << newMessage << " to server\n";
        newMessage->post();
    }
}

const std::vector<user *> &conversation::getParticipants_() const {
    return participants_;
}

std::ostream &operator<<(std::ostream &os, const conversation &c) {
    os << "Conversation between you and participants:\n";
    for (auto i: c.getParticipants_()) {
        os << *i << std::endl;
    }
    return os;
}

void conversation::deleteMessage(message *messageDel) {

}
