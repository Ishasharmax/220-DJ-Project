cmake_minimum_required(VERSION 3.12)
project(220_DJ_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(220_DJ_Project  DJTestLib.cpp LinkedPlayList.cpp MasterSongList.cpp MasterPlaylist.cpp PlayListNode.cpp Song.cpp SongTest.cpp LinkedPlaylistNodeTest.cpp LinkedPlaylistTest.cpp MasterPlaylistTest.cpp MasterSongListTest.cpp)

