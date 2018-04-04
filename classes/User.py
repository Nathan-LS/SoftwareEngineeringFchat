from classes.Conversation import Conversation


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


