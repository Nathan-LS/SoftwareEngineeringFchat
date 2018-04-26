cmake_minimum_required(VERSION 3.10)
project(FchatC)

set(CMAKE_CXX_STANDARD 17)

add_executable(FchatC main.cpp classes/user.cpp classes/user.h classes/conversation.cpp classes/conversation.h classes/message.cpp classes/message.h)