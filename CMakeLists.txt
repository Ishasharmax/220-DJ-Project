cmake_minimum_required(VERSION 3.12)
project(220_DJ_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(220_DJ_Project
        DJTestLib.cpp

        LinkedPlayList.cpp
        LinkedPlaylistNodeTest.cpp
        LinkedPlaylistTest.cpp
        MasterListTest.cpp
        MasterPlaylist.cpp

        MasterPlaylistTest.cpp
        MasterSongList.cpp

        MasterSongListTest.cpp
        PlayListNode.cpp

        Song.cpp

        SongLib.cpp

        SongTest.cpp)
