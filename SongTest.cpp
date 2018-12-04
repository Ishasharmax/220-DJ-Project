//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "Song.h"
#include "SongLib.h"
#include "DJTestLib.h"

void runSongTests(){
    Song mySong =  Song("Love on Top", "Beyonce", 4.00);
    std::cout << mySong.toString() << std::endl;
    printAssertEquals(415, mySong.calcPotentialProfit(), 0.00001);

    mySong.getArtist();
    mySong.getTitle();
    printAssertEquals(300, mySong.calcPotentialProfit(), 0.00001);

   /* while (!qToTest->isEmpty()) {
        std::cout << qToTest->dequeueHighestPriorityItem() << std::endl;
    }*/
    std::cout << "---- done ----"<< std::endl;;
}

int main(){
    runSongTests();
    return 0;
}