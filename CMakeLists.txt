cmake_minimum_required(VERSION 3.12)
project(220_DJ_Project)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(220_DJ_Project
        DJTestLib.cpp

        LinkedPlayList.cpp
        LinkedPlaylistTest.cpp
        LinkedPlayListNode.cpp
#        LinkedPlaylistNodeTest.cpp


        LinkedPlaylistTest.cpp
        MasterPlayList.cpp

        MasterPlayList.cpp
        MasterPlayListTest.cpp
        MasterSongList.cpp
        MasterSongListTest.cpp

        Song.cpp
        SongLib.cpp
        SongTest.cpp)


