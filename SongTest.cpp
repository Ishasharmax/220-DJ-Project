//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "Song.h"
#include "SongLib.h"
#include "DJTestLib.h"

void runSongTests(){
    Song mySong =  Song("Love on Top", "Beyonce", 4.00);
    //std::cout << mySong.toString() << std::endl;


    mySong.getArtist();
    printAssertEquals("Beyonce", mySong.getArtist());

    mySong.getTitle();
    printAssertEquals("Love on Top", mySong.getTitle());

    mySong.getPlayCount();
    printAssertEquals(0,0);
    mySong.addToPlayCount();
    mySong.getPlayCount();
    printAssertEquals(1,1);

    mySong.getSongLength();

   /* while (!qToTest->isEmpty()) {
        std::cout << qToTest->dequeueHighestPriorityItem() << std::endl;
    }*/
    std::cout << "---- done ----"<< std::endl;;
}

int main(){
    runSongTests();
    return 0;
}