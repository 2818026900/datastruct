cmake_minimum_required(VERSION 3.17)
project(datastruct C)

set(CMAKE_C_STANDARD 99)

add_executable(datastruct main.c linerList/LinerList.h linerList/SequenceList.c menu/Menu.h menu/MainMenu.c menu/LineList/LineListMenu.c tools/Tools.h tools/ReadFile.c linerList/SingleLinkList.c menu/LineList/SeqListMenu.c)