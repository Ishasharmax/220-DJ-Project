//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "Playlist.h"
#include "song.h"
#include "LinkedPlaylist.h"
<<<<<<< HEAD
#include "LinkedPlaylist.h"
=======
#include "PlaylistNode.h"
>>>>>>> fa76b918428946b6fd9e39cdbc4b3421379b1c63
#include "DJTestLib.h"

void runPlayListNode_Test(){
    std::cout << "PlayList Node Test" << std:: endl;
    Song FineChina = Song("Fine China","Chris Brown",3.32);
    Song Overdue = Song("Overdue","Metro Boomin", 2.44);
    PlayListNode firstSong = PlayListNode(FineChina);
    PlayListNode secondSong = PlayListNode(Overdue);


    firstSong.getSong();



    firstSong.setNext(secondSong);

    firstSong.getNext();

    secondSong.getSong();
    




}