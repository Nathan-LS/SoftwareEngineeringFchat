from classes.Conversation import Conversation
from classes.Message import Message

class User(object):
    def __init__(self, token=None):
        self.Username = None
        self.fName = None
        self.lName = None
        self.passHash = None #will remain none if user class represents a user other than the currently logged in user
        self.bio = None
        self.contacts = []
        self.conversations = []
        self.birthDay = None
        self.status = None
        self.statusType = None
        self.currentTheme = None

        if token == None:
            self.__create()
        self.__setup() #loads user information when a user is requested

    def __setup(self):
        """pulls and sets information from the server regarding our user."""
        raise NotImplementedError

    def __create(self):
        """operation for when a user needs to first be created before populating their data into the user class"""
        raise NotImplementedError

    def __save(self):
        """saves a user's information by sending updated changes to the server"""
        raise NotImplementedError

    def changeBio(self):
        """starts the operation which allows a user to change information about themselves"""
        raise NotImplementedError

    def changePass(self):
        """changes a user password"""
        raise NotImplementedError

    def start_conversation(self, *others):
        """begins a new conversation among multiple other users"""
        newConvo = Conversation(new_convo=True)
        for u in others: #add all selected particpants to convo
            assert isinstance(u, User)
            newConvo.addParticipant(u)
        self.conversations.append(newConvo)  # append to our current conversations a new conversation

    def sendMessage(self):
        """sends a new message"""
        raise NotImplementedError

    def editMessage(self, target_message, edited_text): #target message is the message selected to perform actions on by user
        """passes a message instance with the intended text edit"""
        assert isinstance(target_message, Message)
        target_message.edit(new_text=edited_text)
        raise NotImplementedError

    def deleteMessage(self, target_message): #target message is the message selected to perform actions on by user
        """forwards delete message to a message instance"""
        assert isinstance(target_message, Message)
        target_message.delete()
        raise NotImplementedError





