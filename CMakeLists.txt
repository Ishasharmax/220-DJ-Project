cmake_minimum_required(VERSION 3.12)
project(220_DJ_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(220_DJ_Project main.cpp MasterSongList.cpp SongLib.cpp Song.cpp PlayListNode.cpp)