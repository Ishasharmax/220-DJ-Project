cmake_minimum_required(VERSION 3.12)
project(220_DJ_Project)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(220_DJ_Project
        DJTestLib.cpp
        LinkedPlaylistNodeTest.cpp
        LinkedPlayList.cpp
        LinkedPlayListNode.cpp
<<<<<<< HEAD
        MasterPlayList.cpp
        MasterPlaylistLib.cpp
        MasterPlayList.cpp
=======
        LinkedPlaylistTest.cpp
>>>>>>> 59d064f2ba0d474780a6c57c788c5052ec6760bf
        MasterSongListTest.cpp
        MasterSongList.cpp
        SongLib.cpp
        SongTest.cpp
        Song.cpp
        MasterPlaylistTest.cpp
        MasterPlaylist.cpp
        MasterSongList.cpp
        Interface.cpp)