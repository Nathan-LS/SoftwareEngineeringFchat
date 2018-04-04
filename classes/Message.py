from classes.User import User

class Message(object):
    def __init__(self, m_author, m_aud, m_body, new_message=False, message_id=None):
        self.id = message_id
        self.timeStamp = None
        self.messageText = None
        self.fileAttached = None
        self.fileSize = None
        self.fileLocation = None
        self.author = m_author
        self.audience = m_aud
        if new_message:
            self.__create()
            self.__load()
        else:
            self.__load()

    def __create(self):
        """creates a new message"""
        raise NotImplementedError

    def __load(self):
        """loads the message from the database for our user to view and populates class attributes"""
        raise NotImplementedError

    def __save(self):
        """saves the message to our server after it has been created or edited"""
        raise NotImplementedError

    def edit(self, new_text):
        """edits the message and changes it's text to equal new_text"""
        raise NotImplementedError

    def delete(self):
        """deletes the current message and reflects this on the server by saving"""
        raise NotImplementedError