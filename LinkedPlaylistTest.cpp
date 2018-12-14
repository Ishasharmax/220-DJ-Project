//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "Playlist.h"
#include "LinkedPlaylist.h"
#include "DJTestLib.h"


void runLinkedPlaylistTests(){
    LinkedPlayList *playList1 = new LinkedPlayList();

    std::cout << "-------AddToTests---------" <<std::endl;
    //void addSongAtEnd(std::string artist, std::string songName, float duration);

    try{
        playList1->addSongAt(1,"Paramore", "That's What You Get", 3.00);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 6", e.what());
    }
    try{
        playList1->addSongAt(2,"Cardi B", "Money", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 100", e.what());
    }
    try{
        playList1->addSongAt(3,"Pink Floyd", "Comfortably Numb", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    try{
        playList1->addSongAt(4,"Maleek Berry", "Confidence", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    try{
        playList1->addSongAt(5,"Travis Scott", "CANT SAY", 3.44);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }
    playList1->addSongAtEnd("kand", "jah",2.44);
    std::cout<<playList1->getAllSongs();
    printAssertEquals("{9, 8, 7, 6, 5}", playList1->getAllSongs());
    printAssertEquals(false, playList1->isEmpty());



    /*//do it again
    for (int i=0; i<5; i++){
        myList.addSongAt(a1[i], 0);
    }*/

   /* //insert everywhere in the middle and on ends
    for(int i=5; i>=0; i--){
        myList.addSongAt(33, i);
    }*/

    //insert at other locations
    std::cout << "--done--" <<std::endl;

    std::cout << "-------IsEmptyTests---------" <<std::endl;
    //empty it
    printAssertEquals(true, playList1->isEmpty());
    printAssertEquals("{}", playList1->getAllSongs());
    printAssertEquals(0, playList1->getSongCount());

    std::cout << "-------ItemGetTests---------" <<std::endl;
    printAssertEquals(6, playList1->getSongCount());
    printAssertEquals("You have the option to: \n 1-add a song 2-remove a song 3-search and play a song 4-check is play list is empty \n 5-get song count 6-"
                      "get play count 7-get number of songs in the list 8-get name of all songs \n 9-play next song 10-play previous song 11-get play list duration",playList1->getHelp());
    printAssertEquals("text", playList1->getAllSongs());


    std::cout << "-------toStringTests---------" <<std::endl;
    playList1->getAllSongs();
    printAssertEquals("{9, 8, 7, 6, 5}", playList1->getAllSongs());



    //std::cout << "-------SearchTests---------" <<std::endl;
    //std::string search(std::string item);


    std::cout << "-------RemoveTests---------" <<std::endl;
    std::string removeSongAt(int removeIndex);
    std::string removeSongAtEnd();
    while (!playList1->isEmpty()){
        std::cout << playList1->removeSongAtEnd() << std::endl;
    }
    printAssertEquals(false, playList1->isEmpty());

}
int main() {
    runLinkedPlaylistTests();
    //delete playList1;
    return 0;
}
