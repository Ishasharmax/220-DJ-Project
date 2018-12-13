//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "MasterSongList.h"
#include "DJTestLib.h"
void importSongAndGetValueAtTest(int numsToTestSize, int initialCapacity){
    std::cout << "-------importSongAndGetValueAtTest---------" <<std::endl;
    MasterSongList myList = MasterSongList(initialCapacity);
    try{
        myList.getValueAt(0);
        std::cout << "FAIL: getValueAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to getValueAt: 0", e.what());
    }
    for (int i=0; i<numsToTestSize; i++){
        myList.importSong(numsToTestSize[i]);
        printAssertEquals(numsToTestSize[i], myList.getValueAt(i));
    }
    //once more now that the list is complete
    for (int i=0; i<numsToTestSize; i++){
        printAssertEquals(numsToTestSize[i], myList.getValueAt(i));
    }

    try{
        myList.getValueAt(5);
        std::cout << "FAIL: getValueAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to getValueAt: 5", e.what());
    }
    try{
        myList.getValueAt(100);
        std::cout << "FAIL: getValueAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to getValueAt: 100", e.what());
    }
    try{
        myList.getValueAt(-1);
        std::cout << "FAIL: getValueAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to getValueAt: -1", e.what());
    }
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor and importSong
void isEmptyTest(int numsToTestSize, int initialCapacity){
    std::cout << "-------isEmptyTest---------" <<std::endl;
    MasterSongList myList = MasterSongList(initialCapacity);
    printAssertEquals(true, myList.isEmpty());

    for (int i=0; i<numsToTestSize; i++){
        myList.importSong(numsToTest[i]);
        printAssertEquals(false, myList.isEmpty());
    }
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor and importSong
void itemCountTest(int numsToTestSize, int initialCapacity){
    std::cout << "-------itemCountTest---------" <<std::endl;
    MasterSongList myList = MasterSongList(initialCapacity);
    for (int i=0; i<numsToTestSize; i++){
        printAssertEquals(i, myList.itemCount());
        myList.importSong(numsToTestSize[i]);
    }
    printAssertEquals(numsToTestSize, myList.itemCount());
    std::cout << "--done--" <<std::endl;
}

//assumes working importSong
void toStringTest(){
    std::cout << "-------toStringTest---------" <<std::endl;
    MasterSongList myList = MasterSongList(5);
    printAssertEquals("{}", myList.toString());

    int a1[5]{5, 6, 7, 8, 9};
    std::string toStringOutputs[5]{"{5}","{5, 6}","{5, 6, 7}","{5, 6, 7, 8}","{5, 6, 7, 8, 9}"};
    for (int i=0; i<5; i++){
        myList.importSong(a1[i]);
        printAssertEquals(toStringOutputs[i], myList.toString());
    }
    std::cout << "--done--" <<std::endl;
}
void removeSongTest(int numsToTestSize, int initialCapacity){
    std::cout << "-------removeSongTest---------" <<std::endl;
    MasterSongList* myListPtr = MasterSongList(initialCapacity);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (a1[9-i] != myListPtr->removeSong()){
            failCount++;
        }
        printAssertEquals(9-i, myListPtr->itemCount());
    }
    printAssertEquals(true, myListPtr->isEmpty());
    printAssertEquals(0, myListPtr->itemCount());
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    try{
        myListPtr->removeSong();
        std::cout << "FAIL: removeSong did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("In removeSong, List must have items", e.what());
    }
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}


int main() {

    importSongAndGetValueAtTest(5, 5);
    isEmptyTest(5, 5);
    itemCountTest(5, 5);
    toStringTest();
    removeSongTest(5,5);
    return 0;
}