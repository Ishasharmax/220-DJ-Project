//
// Created by Bobo on 12/3/2018.
//
#include <stdexcept>
#include <iostream>
#include "Playlist.h"
#include "LinkedPlaylist.h"
#include "DJTestLib.h"


void addTests () {
    LinkedPlayList *playList1 = new LinkedPlayList();

    std::cout << "-------AddToTests---------" << std::endl;
    //void addSongAtEnd(std::string artist, std::string songName, float duration);

    try {
        playList1->addSongAt(1, "Paramore", "That's What You Get", 3.00);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch (std::out_of_range &e) {
        printAssertEquals("Bad index given to insertAt: 6", e.what());
    }
    try {
        playList1->addSongAt(2, "Cardi B", "Money", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch (std::out_of_range &e) {
        printAssertEquals("Bad index given to insertAt: 100", e.what());
    }
    try {
        playList1->addSongAt(3, "Pink Floyd", "Comfortably Numb", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch (std::out_of_range &e) {
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    try {
        playList1->addSongAt(4, "Maleek Berry", "Confidence", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch (std::out_of_range &e) {
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    try {
        playList1->addSongAt(5, "Travis Scott", "CANT SAY", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch (std::out_of_range &e) {
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    playList1->addSongAtEnd("Sade", "Sweetest Taboo", 4.40);
    playList1->addSongAtEnd("Travis Scott", "CANT SAY", 3.44);
    printAssertEquals("Sweetest Taboo, CANT SAY", playList1->getAllSongs());
    printAssertEquals(false, playList1->isEmpty());
    playList1->addSongAt(2,"Kanye West", "Love Lockdown", 3.28);
    playList1->addSongAt(0,"ABRA","Roses",3.24);
    playList1->addSongAt(1,"SZA", "Broken Clocks",3.53);
    playList1->addSongAt(1,"SZA", "Broken Clocks",3.53);
    printAssertEquals("Roses, Broken Clocks, Sweetest Taboo, CANT SAY, Love Lockdown",playList1->getAllSongs());
    delete playList1;
    playList1 = nullptr;

    /*//do it again
    for (int i=0; i<5; i++){
        myList.addSongAt(a1[i], 0);
    }*/

    /* //insert everywhere in the middle and on ends
     for(int i=5; i>=0; i--){
         myList.addSongAt(33, i);
     }*/

    //insert at other locations
    std::cout << "--done--" << std::endl;
}
void isEmptyAndClearListTests() {
    std::cout << "-------IsEmptyTests---------" << std::endl;
    LinkedPlayList *playList2 = new LinkedPlayList();

    playList2->addSongAtEnd("Sade", "Is it a Crime", 3.00);
    playList2->addSongAtEnd("BTS", "Love is Not Over", 3.25);
    playList2->addSongAtEnd("Beyonce", "Ring the Alarm", 3.02);
    playList2->addSongAtEnd("Drake", "In My Feelings", 4.10);

    printAssertEquals(false, playList2->isEmpty());
    playList2->clearList();
    printAssertEquals(true, playList2->isEmpty());
    printAssertEquals("Playlist empty", playList2->getAllSongs());
    printAssertEquals(0, playList2->getSongCount());
    delete playList2;
    playList2 = nullptr;
    std::cout << "--done--" << std::endl;
}
void getTests() {
    std::cout << "-------ItemGetTests---------" << std::endl;
    LinkedPlayList *playList3 = new LinkedPlayList();
    printAssertEquals(0, playList3->getSongCount());
    playList3->addSongAtEnd("Sade", "Is it a Crime", 3.00);
    playList3->addSongAtEnd("BTS", "Love is Not Over", 3.25);
    playList3->addSongAtEnd("Beyonce", "Ring the Alarm", 3.02);
    playList3->addSongAtEnd("Drake", "In My Feelings", 4.10);
    printAssertEquals("Is it a Crime, Love is Not Over, Ring the Alarm, In My Feelings", playList3->getAllSongs());
    std::cout<<playList3->search("Is it a Crime");
    printAssertEquals(1,playList3->getPlayCount("Is it a Crime"));
    delete playList3;
    playList3 = nullptr;
    std::cout << "--done--" << std::endl;
}
void toStringAndSearchTest() {
    std::cout << "-------toStringTests---------" << std::endl;
    LinkedPlayList *playList4 = new LinkedPlayList();

    printAssertEquals("Playlist empty", playList4->getAllSongs());
    playList4->addSongAtEnd("Sade", "Is it a Crime", 3.00);
    playList4->addSongAtEnd("BTS", "Love is Not Over", 3.25);
    playList4->addSongAt(1,"Beyonce", "Ring the Alarm", 3.02);
    playList4->addSongAtEnd("Drake", "In My Feelings", 4.10);

    printAssertEquals("Is it a Crime, Ring the Alarm, Love is Not Over, In My Feelings", playList4->getAllSongs());
    std::cout << "--done--" << std::endl;

    //std::cout << "-------SearchTests---------" <<std::endl;
    //std::string search(std::string item);
    std::cout << "--done--" << std::endl;

}
void removeTests(){
    std::cout << "-------RemoveTests---------" <<std::endl;
    LinkedPlayList *playList5 = new LinkedPlayList();
    playList5->addSongAtEnd("Beyonce", "Ring the Alarm",3.20);
    std::string removeSongAtEnd();
    while (!playList5->isEmpty()){
        std::cout << playList5->removeSongAtEnd() << std::endl;
    }
    printAssertEquals(true, playList5->isEmpty());
    playList5->addSongAtEnd("Sade", "Is it a Crime", 3.00);
    playList5->addSongAtEnd("BTS", "Love is Not Over", 3.25);
    playList5->addSongAt(1,"Beyonce", "Ring the Alarm", 3.02);
    playList5->addSongAtEnd("Drake", "In My Feelings", 4.10);
    while (!playList5->isEmpty()){
        std::cout << playList5->removeSongAtEnd() << std::endl;
    }
    playList5->addSongAtEnd("Sade", "Is it a Crime", 3.00);
    playList5->addSongAtEnd("BTS", "Love is Not Over", 3.25);
    playList5->addSongAt(1,"Beyonce", "Ring the Alarm", 3.02);
    playList5->addSongAtEnd("Drake", "In My Feelings", 4.10);
    std::cout << playList5->removeSongAtEnd() << std::endl;
    std::cout << playList5->getAllSongs() << std::endl;
    std::cout << "--done--" << std::endl;

}
int main() {
    //addTests();
    //isEmptyAndClearListTests();
    //getTests();
    //toStringAndSearchTest();
    removeTests();


    return 0;
}
