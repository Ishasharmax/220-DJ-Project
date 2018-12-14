//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "DJTestLib.h"

void addPlaylistAtEndtoStringGetPlaylistTest(MasterPlayList* listToTest,int initialCapacity){
    std::cout << "-------addPlayListAndtoStringGetPlaylistTest---------" <<std::endl;
    try{
        listToTest->toStringGetPlaylist(0);
        std::cout << "FAIL: toStringGetPlaylist did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to toStringGetPlaylist: 0", e.what());
    }
    for (int i=0; i<initialCapacity; i++){
        listToTest->addPlayList(listToTest[i]);
        printAssertEquals(listToTest[i], listToTest->toStringGetPlaylist(i));
    }
    //once more now that the list is complete
    for (int i=0; i<initialCapacity; i++){
        printAssertEquals(listToTest[i], listToTest->toStringGetPlaylist(i));
    }

    try{
        listToTest->toStringGetPlaylist(5);
        std::cout << "FAIL: toStringGetPlaylist did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to toStringGetPlaylist: 5", e.what());
    }
    try{
        listToTest->toStringGetPlaylist(100);
        std::cout << "FAIL: toStringGetPlaylist did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to toStringGetPlaylist: 100", e.what());
    }
    try{
        listToTest->toStringGetPlaylist(-1);
        std::cout << "FAIL: toStringGetPlaylist did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to toStringGetPlaylist: -1", e.what());
    }
    std::cout << "--done--" <<std::endl;
}
void isEmptyTest(MasterPlayList* listToTest, int initialCapacity, int initialCapacity){
    std::cout << "-------isEmptyTest---------" <<std::endl;
    MasterPlaylist *listToTest = MasterPlaylist(initialCapacity);
    printAssertEquals(true, listToTest->isEmpty());

    for (int i=0; i<initialCapacity; i++){
        listToTest->addPlayList(listToTest[i]);
        printAssertEquals(false, listToTest->isEmpty());
    }
    std::cout << "--done--" <<std::endl;
}
void itemCountTest(int* listToTest, int initialCapacity, int initialCapacity){
    std::cout << "-------itemCountTest---------" <<std::endl;
    MasterPlaylist myList = MasterPlaylist(initialCapacity);
    for (int i=0; i<initialCapacity; i++){
        printAssertEquals(i, listToTest->itemCount());
        listToTest->addPlayList(listToTest[i]);
    }
    printAssertEquals(initialCapacity, listToTest->itemCount());
    std::cout << "--done--" <<std::endl;
}
void clearListTest(int* listToTest, int initialCapacity, int initialCapacity){
    std::cout << "-------clearListTest---------" <<std::endl;
    MastetPlayList myList = MastetPlayList(initialCapacity);
    printAssertEquals(0, listToTest->itemCount());
    listToTest->clearList();
    printAssertEquals(0, listToTest->itemCount());
    for (int i=0; i<initialCapacity; i++){
        listToTest->addPlayList(listToTest[i]);
    }
    printAssertEquals(initialCapacity, listToTest->itemCount());
    listToTest->clearList();
    printAssertEquals(0, listToTest->itemCount());

    //do it again
    for (int i=0; i<initialCapacity; i++){
        listToTest->addPlayList(listToTest[i]);
    }
    printAssertEquals(initialCapacity, listToTest->itemCount());
    listToTest->clearList();
    printAssertEquals(0, listToTest->itemCount());
    std::cout << "--done--" <<std::endl;
}

//assumes working addPlayList
void toStringTest(){
    std::cout << "-------toStringTest---------" <<std::endl;
    MastetPlayList myList = MastetPlayList(5);
    printAssertEquals("{}", listToTest->toString());

    int a1[5]{5, 6, 7, 8, 9};
    std::string toStringOutputs[5]{"{5}","{5, 6}","{5, 6, 7}","{5, 6, 7, 8}","{5, 6, 7, 8, 9}"};
    for (int i=0; i<5; i++){
        listToTest->addPlayList(a1[i]);
        printAssertEquals(toStringOutputs[i], listToTest->toString());
    }
    std::cout << "--done--" <<std::endl;
}

//helper function, assumes working constructor and addPlayList
//@return an MastetPlayList to be deleted by the user
MastetPlayList* createAndFillList(int* arr, int size){
    MastetPlayList* toReturn = new MastetPlayList(size);
    for (int i=0; i<size; i++){
        toReturn->addPlayList(arr[i]);
    }
    return toReturn;
}
void findTest(){
    std::cout << "-------findTest---------" <<std::endl;
    MastetPlayList *myListPtr = new MastetPlayList(6);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != myListPtr->findPlaylist(myListPtr[i]){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }
    delete myListPtr;
    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    myListPtr = createAndFillList(a2, 10);

    printAssertEquals(2, myListPtr->find(3));
    printAssertEquals(-1, myListPtr->find(500));
    printAssertEquals(-1, myListPtr->find(100));
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor, toStringGetPlaylist, toString, isEmpty, itemCount, clearList
void insertAtTest(){
    std::cout << "-------insertAtTest---------" <<std::endl;
    //copy of addPlayList
    int listToTest[5]{5, 6, 7, 8, 9};
    int initialCapacity = 5;
    MastetPlayList myList = MastetPlayList(5);

    for (int i=0; i<initialCapacity; i++){
        listToTest->insertAt(listToTest[i], i);
        printAssertEquals(listToTest[i], listToTest->toStringGetPlaylist(i));
    }

    try{
        listToTest->insertAt(100, 6);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 6", e.what());
    }
    try{
        listToTest->insertAt(100, 100);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 100", e.what());
    }
    try{
        listToTest->insertAt(100, -1);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }

    printAssertEquals("{9, 8, 7, 6, 5}", myList2.toString());
    printAssertEquals(false, myList2.isEmpty());
    printAssertEquals(5, myList2.itemCount());

    //empty it
    myList2.clearList();
    printAssertEquals(true, myList2.isEmpty());
    printAssertEquals("{}", myList2.toString());
    printAssertEquals(0, myList2.itemCount());

    //do it again
    for (int i=0; i<5; i++){
        myList2.insertAtFront(a1[i]);
    }
    printAssertEquals("{9, 8, 7, 6, 5}", myList2.toString());
    printAssertEquals(false, myList2.isEmpty());
    printAssertEquals(5, myList2.itemCount());

//    //insert everywhere in the middle and on ends
//    for(int i=5; i>=0; i++){
//        listToTest->insertAt(33, i);
//    }
//    printAssertEquals("{33, 9, 33, 8, 33, 7, 33, 6, 33, 5, 33}", listToTest->toString());
//    printAssertEquals(false, listToTest->isEmpty());
//    printAssertEquals(11, listToTest->itemCount());

    //insert at other locations
    std::cout << "--done--" <<std::endl;
}

void removePlayListTest(){
    std::cout << "-------removePlayListTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    MastetPlayList* myListPtr = createAndFillList(a1, 10);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (a1[9-i] != myListPtr->removePlayList()){
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
        myListPtr->removePlayList();
        std::cout << "FAIL: removePlayList did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("In removePlayList, List must have items", e.what());
    }
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

void removePlayListAtTest(){
    std::cout << "-------removePlayListAtTest---------" <<std::endl;
    int a1[]={10, 20, 30, 40, 50};
    MastetPlayList* myListPtr = createAndFillList(a1, 5);

    printAssertEquals(30, myListPtr->removePlayListAt(2));
    printAssertEquals(4, myListPtr->itemCount());
    printAssertEquals("{10, 20, 40, 50}", myListPtr->toString());

    printAssertEquals(40, myListPtr->removePlayListAt(2));
    printAssertEquals(3, myListPtr->itemCount());
    printAssertEquals("{10, 20, 50}", myListPtr->toString());

    printAssertEquals(50, myListPtr->removePlayListAt(2));
    printAssertEquals(2, myListPtr->itemCount());
    printAssertEquals("{10, 20}", myListPtr->toString());

    printAssertEquals(10, myListPtr->removePlayListAt(0));
    printAssertEquals(1, myListPtr->itemCount());
    printAssertEquals("{20}", myListPtr->toString());
    printAssertEquals(false, myListPtr->isEmpty());

    printAssertEquals(20, myListPtr->removePlayListAt(0));
    printAssertEquals(0, myListPtr->itemCount());
    printAssertEquals("{}", myListPtr->toString());
    printAssertEquals(true, myListPtr->isEmpty());
    std::cout << "--done--" <<std::endl;

}


//assume working addPlayList, insertAtFront, toString, itemCount, isEmpty, clearList
void doubleCapacityTest(){
    std::cout << "-------doubleCapacityTest---------" <<std::endl;
    try{
        MastetPlayList badList = MastetPlayList(0);
        std::cout << "FAIL: constructor did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        printAssertEquals("In MastetPlayList constructor, size must be > 0", e.what());
    }
    MastetPlayList myList = MastetPlayList(1);
    for(int i=0; i<10; i++){
        listToTest->insertAtFront(i);
        listToTest->addPlayList(i);
    }
    printAssertEquals("{9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}", listToTest->toString());
    printAssertEquals(20, listToTest->itemCount());
    printAssertEquals(false, listToTest->isEmpty());

    int a1[10]{5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    addPlayListAndtoStringGetPlaylistTest(a1, 5, 3);
    isEmptyTest(a1, 5, 3);
    itemCountTest(a1, 5, 3);
    clearListTest(a1, 5, 3);
    std::cout << "--done--" <<std::endl;

}

//assumes working doubleCapacity, addPlayList, removePlayListAt, toString
void testCopyConstructor(){
    std::cout << "-------testCopyConstructor---------" <<std::endl;
    int numErrors = 0;
    //create object, add some stuff
    MastetPlayList original = MastetPlayList(2);
    for (int i=0; i<4; i++){
        original.addPlayList(i);
    }
    //copy it
    MastetPlayList copy = MastetPlayList(original);
    //check they're the same
    if (!(original.toString() == copy.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removePlayListAt(0);
    original.removePlayListAt(0);
    original.addPlayList(4);
    original.addPlayList(5);
    //check that they're different
    if (!( original.toString() == "{2, 3, 4, 5}")){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( copy.toString() == "{0, 1, 2, 3}")){
        std::cout << "FAIL: error in copy after changes, it is now" << copy.toString() <<  std::endl;
        numErrors++;
    }
    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }
    //When this function ends, they'll both be deleted, which will check they don't have shared memory
    std::cout << "--done--" <<std::endl;

}

//assumes working doubleCapacity, addPlayList, removePlayListAt, toString
void testAssnOperator(){
    std::cout << "-------testAssnOperator---------" <<std::endl;
    int numErrors = 0;
    //create object, add some stuff
    MastetPlayList original = MastetPlayList(2);
    for (int i=0; i<4; i++){
        original.addPlayList(i);
    }
    //create a new list with its own data
    MastetPlayList listToSet = MastetPlayList(2);
    for (int i=10; i<14; i++){
        listToSet.addPlayList(i);
    }
    //assign the original to the new
    listToSet = original;

    //check they're the same
    if (!(original.toString() == listToSet.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removePlayListAt(0);
    original.removePlayListAt(1);
    original.addPlayList(4);
    original.addPlayList(5);
    //check that they're different
    if (!( original.toString() == "{2, 3, 4, 5}")){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( listToSet.toString() == "{0, 1, 2, 3}")){
        std::cout << "FAIL: error in copy after changes, it is now" << listToSet.toString() <<  std::endl;
        numErrors++;
    }

    //check that there is no bad effect if you set an object to itself
    original = original;
    listToSet = listToSet;

    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }
    //When this function ends, original and listToSet will both be deleted, which will check they don't have shared memory
    std::cout << "--done--" <<std::endl;

}

int main(){

    MastetPlayList *testList = new MastetPlayList(6);
    //LinkedPlayList *testPtr= new LinkedPlayList();

    addPlaylistAtEndtoStringGetPlaylistTest(testList,5 );
    isEmptyTest(testList, 5, 5);
    itemCountTest(testList, 5, 5);
    clearListTest(testList, 5, 5);

    toStringTest();
    findTest();

    insertAtTest();
    removePlayListTest();
    removePlayListAtTest();

    doubleCapacityTest();
    testCopyConstructor();
    testAssnOperator();

    return 0;
}