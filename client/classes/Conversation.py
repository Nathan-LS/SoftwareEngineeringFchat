import classes.User
from classes.Message import Message


class Conversation(object):
    def __init__(self, convo_creator, new_convo = False, convo_id = None):
        """handles a conversation among multiple users"""
        assert isinstance(convo_creator, classes.User.User)
        self.id = convo_id #conversation ID will be none if new convo otherwise we use this convo id to fetch data from server
        self.creator = convo_creator
        self.participants = []
        self.messages = []
        self.dateStarted = None
        self.lastMessageDate = None
        if new_convo:
            self.__create() #if new convo flag is passed we create the convo first and update it on the server
            self.__load()
        else: #no need to create convo as we can already load it from the database
            self.__load()

    def __create(self):
        """creates a new conversation and saves it on the server"""
        raise NotImplementedError

    def __save(self):
        """saves the conversation to the server"""
        raise NotImplementedError

    def __load(self):
        """loads the conversation and populates Conversation attributes"""
        raise NotImplementedError

    def newMessage(self, message_text):
        """creates a new within the conversation"""
        raise NotImplementedError

    def addParticipant(self, participant):
        """adds a user to our conversation"""
        assert isinstance(participant, classes.User.User)
        raise NotImplementedError

    def removeParticipant(self, participant):
        assert isinstance(participant, classes.User.User)
        raise NotImplementedError

    def sendMessage(self, text, sender):
        """creates a new message and appends in to our current conversation messages"""
        assert isinstance(sender, classes.User.User)
        new_message = Message(m_author=sender, m_aud=self.participants, new_message=True, m_body=text)
        self.messages.append(new_message)
        raise NotImplementedError
