//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "PlayList.h"
#include "Song.h"
#include "LinkedPlayList.h"
#include "LinkedPlayListNode.h"
#include "DJTestLib.h"
#include <string>

void runPlayListNode_Test(){
    std::cout << "PlayList Node Test" << std:: endl;
    Song FineChina = Song("Fine China","Chris Brown",3.32);
    Song Overdue = Song("Overdue","Metro Boomin", 2.44);
    LinkedPlayListNode *firstSong = new LinkedPlayListNode(&FineChina);
    LinkedPlayListNode  *secondSong = new LinkedPlayListNode(&Overdue);

    std::cout << firstSong->getSong().getTitle() << std:: endl;
    firstSong->setNext(secondSong);

    std::cout << firstSong->getNext()<< std:: endl;
    std::cout << secondSong->getSong().getTitle()<< std:: endl;
}

int main(){
    runPlayListNode_Test();
}