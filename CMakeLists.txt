cmake_minimum_required(VERSION 3.10)
project(FchatC)

set(CMAKE_CXX_STANDARD 17)

add_executable(FchatC main.cpp classes/FchatUser.cpp classes/FchatUser.h classes/FchatConversation.cpp classes/FchatConversation.h classes/FchatMessage.cpp classes/FchatMessage.h)