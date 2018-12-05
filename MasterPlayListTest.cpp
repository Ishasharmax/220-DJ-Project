//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "MasterPlayList.h"
#include "DJTestLib.h"

void insertAtEndAndGetValueAtTest(int* numsToTest, int numsToTestSize, int initialCapacity){
    std::cout << "-------insertAtEndAndGetValueAtTest---------" <<std::endl;
    MasterPlayList myList = MasterPlaylist(initialCapacity);
    try{
        myList.getValueAt(0);
        std::cout << "FAIL: getValueAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to getValueAt: 0", e.what());
    }
    for (int i=0; i<numsToTestSize; i++){
        myList.insertAtEnd(numsToTest[i]);
        printAssertEquals(numsToTest[i], myList.getValueAt(i));
    }
    //once more now that the list is complete
    for (int i=0; i<numsToTestSize; i++){
        printAssertEquals(numsToTest[i], myList.getValueAt(i));
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
void isEmptyTest(int* numsToTest, int numsToTestSize, int initialCapacity){
    std::cout << "-------isEmptyTest---------" <<std::endl;
    MasterPlaylist myList = MasterPlaylist(initialCapacity);
    printAssertEquals(true, myList.isEmpty());

    for (int i=0; i<numsToTestSize; i++){
        myList.insertAtEnd(numsToTest[i]);
        printAssertEquals(false, myList.isEmpty());
    }
    std::cout << "--done--" <<std::endl;
}
void itemCountTest(int* numsToTest, int numsToTestSize, int initialCapacity){
    std::cout << "-------itemCountTest---------" <<std::endl;
    MasterPlaylist myList = MasterPlaylist(initialCapacity);
    for (int i=0; i<numsToTestSize; i++){
        printAssertEquals(i, myList.itemCount());
        myList.insertAtEnd(numsToTest[i]);
    }
    printAssertEquals(numsToTestSize, myList.itemCount());
    std::cout << "--done--" <<std::endl;
}
void clearListTest(int* numsToTest, int numsToTestSize, int initialCapacity){
    std::cout << "-------clearListTest---------" <<std::endl;
    MasterPlaylist myList = MasterPlaylist(initialCapacity);
    printAssertEquals(0, myList.itemCount());
    myList.clearList();
    printAssertEquals(0, myList.itemCount());
    for (int i=0; i<numsToTestSize; i++){
        myList.insertAtEnd(numsToTest[i]);
    }
    printAssertEquals(numsToTestSize, myList.itemCount());
    myList.clearList();
    printAssertEquals(0, myList.itemCount());

    //do it again
    for (int i=0; i<numsToTestSize; i++){
        myList.insertAtEnd(numsToTest[i]);
    }
    printAssertEquals(numsToTestSize, myList.itemCount());
    myList.clearList();
    printAssertEquals(0, myList.itemCount());
    std::cout << "--done--" <<std::endl;
}

//assumes working insertAtEnd
void toStringTest(){
    std::cout << "-------toStringTest---------" <<std::endl;
    MasterPlaylist myList = MasterPlaylist(5);
    printAssertEquals("{}", myList.toString());

    int a1[5]{5, 6, 7, 8, 9};
    std::string toStringOutputs[5]{"{5}","{5, 6}","{5, 6, 7}","{5, 6, 7, 8}","{5, 6, 7, 8, 9}"};
    for (int i=0; i<5; i++){
        myList.insertAtEnd(a1[i]);
        printAssertEquals(toStringOutputs[i], myList.toString());
    }
    std::cout << "--done--" <<std::endl;
}

//helper function, assumes working constructor and insertAtEnd
//@return an MasterPlaylist to be deleted by the user
MasterPlaylist* createAndFillList(int* arr, int size){
    MasterPlaylist* toReturn = new MasterPlaylist(size);
    for (int i=0; i<size; i++){
        toReturn->insertAtEnd(arr[i]);
    }
    return toReturn;
}
void findTest(){
    std::cout << "-------findTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    MasterPlaylist* myListPtr = createAndFillList(a1, 10);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != myListPtr->find(a1[i])){
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

//assumes working constructor and insertAtEnd
void findLastTest(){
    std::cout << "-------findLastTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    MasterPlaylist* myListPtr = createAndFillList(a1, 10);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != myListPtr->findLast(a1[i])){
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

    printAssertEquals(8, myListPtr->findLast(3));
    printAssertEquals(-1, myListPtr->findLast(500));
    printAssertEquals(-1, myListPtr->findLast(100));
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor and insertAtEnd
void findMaxIndexTest(){
    std::cout << "-------findMaxIndexTest---------" <<std::endl;
    //{3, 2, 5, 12, 16, 10} added in one at a time
    MasterPlaylist myList = MasterPlaylist(6);
    myList.insertAtEnd(3);
    printAssertEquals(0, myList.findMaxIndex());
    myList.insertAtEnd(2);
    printAssertEquals(0,  myList.findMaxIndex());
    myList.insertAtEnd(5);
    printAssertEquals(2,  myList.findMaxIndex());
    myList.insertAtEnd(12);
    myList.insertAtEnd(16);
    myList.insertAtEnd(10);
    printAssertEquals(4, myList.findMaxIndex());

    MasterPlaylist myList2 = MasterPlaylist(6);
    std::cout << "negatives:"<< std::endl;
    // {-300000, -200000, -500000, -1200, -160, -1000000} added one at a time
    myList2.insertAtEnd(-30000);
    printAssertEquals(0, myList2.findMaxIndex());
    myList2.insertAtEnd(-20000);
    printAssertEquals(1,  myList2.findMaxIndex());
    myList2.insertAtEnd(-50000);
    printAssertEquals(1,  myList2.findMaxIndex());
    myList2.insertAtEnd(-1200);
    printAssertEquals(3,  myList2.findMaxIndex());
    myList2.insertAtEnd(-160);
    myList2.insertAtEnd(-1000000);
    printAssertEquals(4, myList2.findMaxIndex());

    std::cout << "Multiple occurrences of max:"<< std::endl;
    int a1[]={3, 2, 5, 1, 5, 1};
    MasterPlaylist* myListPtr = createAndFillList(a1, 6);
    printAssertEquals(2, myListPtr->findMaxIndex());
    //expect an exception to be thrown when size < 1
    std::cout << "Throws exception:"<< std::endl;
    delete myListPtr;
    myListPtr = new MasterPlaylist(5);
    try{
        myListPtr->findMaxIndex();
        std::cout << "FAIL: find maxIndex did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        printAssertEquals("In findMaxIndex, List must have items", e.what());
    }
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor, toString, isEmpty, itemCount, clearList
void insertAtFrontTest(){
    std::cout << "-------insertAtFrontTest---------" <<std::endl;
    int a1[5]{5, 6, 7, 8, 9};
    MasterPlaylist myList = MasterPlaylist(5);
    for (int i=0; i<5; i++){
        myList.insertAtFront(a1[i]);
    }
    printAssertEquals("{9, 8, 7, 6, 5}", myList.toString());
    printAssertEquals(false, myList.isEmpty());
    printAssertEquals(5, myList.itemCount());

    //empty it
    myList.clearList();
    printAssertEquals(true, myList.isEmpty());
    printAssertEquals("{}", myList.toString());
    printAssertEquals(0, myList.itemCount());

    //do it again
    for (int i=0; i<5; i++){
        myList.insertAtFront(a1[i]);
    }
    printAssertEquals("{9, 8, 7, 6, 5}", myList.toString());
    printAssertEquals(false, myList.isEmpty());
    printAssertEquals(5, myList.itemCount());
    std::cout << "--done--" <<std::endl;
}

//assumes working constructor, getValueAt, toString, isEmpty, itemCount, clearList
void insertAtTest(){
    std::cout << "-------insertAtTest---------" <<std::endl;
    //copy of insertAtEnd
    int numsToTest[5]{5, 6, 7, 8, 9};
    int numsToTestSize = 5;
    MasterPlaylist myList = MasterPlaylist(5);

    for (int i=0; i<numsToTestSize; i++){
        myList.insertAt(numsToTest[i], i);
        printAssertEquals(numsToTest[i], myList.getValueAt(i));
    }

    try{
        myList.insertAt(100, 6);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 6", e.what());
    }
    try{
        myList.insertAt(100, 100);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: 100", e.what());
    }
    try{
        myList.insertAt(100, -1);
        std::cout << "FAIL: insertAt did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Bad index given to insertAt: -1", e.what());
    }

    //copy of insertAtFront
    int a1[5]{5, 6, 7, 8, 9};
    MasterPlaylist myList2 = MasterPlaylist(11);
    for (int i=0; i<5; i++){
        myList2.insertAt(a1[i], 0);
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
//        myList.insertAt(33, i);
//    }
//    printAssertEquals("{33, 9, 33, 8, 33, 7, 33, 6, 33, 5, 33}", myList.toString());
//    printAssertEquals(false, myList.isEmpty());
//    printAssertEquals(11, myList.itemCount());

    //insert at other locations
    std::cout << "--done--" <<std::endl;
}

void removeValueAtEndTest(){
    std::cout << "-------removeValueAtEndTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    MasterPlaylist* myListPtr = createAndFillList(a1, 10);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (a1[9-i] != myListPtr->removeValueAtEnd()){
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
        myListPtr->removeValueAtEnd();
        std::cout << "FAIL: removeValueAtEnd did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("In removeValueAtEnd, List must have items", e.what());
    }
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

void removeValueAtFrontTest(){
    std::cout << "-------removeValueAtFrontTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    MasterPlaylist* myListPtr = createAndFillList(a1, 10);
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (a1[i] != myListPtr->removeValueAtFront()){
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
        myListPtr->removeValueAtEnd();
        std::cout << "FAIL: removeValueAtFront did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("In removeValueAtFront, List must have items", e.what());
    }
    delete myListPtr;
    std::cout << "--done--" <<std::endl;
}

void removeValueAtTest(){
    std::cout << "-------removeValueAtTest---------" <<std::endl;
    int a1[]={10, 20, 30, 40, 50};
    MasterPlaylist* myListPtr = createAndFillList(a1, 5);

    printAssertEquals(30, myListPtr->removeValueAt(2));
    printAssertEquals(4, myListPtr->itemCount());
    printAssertEquals("{10, 20, 40, 50}", myListPtr->toString());

    printAssertEquals(40, myListPtr->removeValueAt(2));
    printAssertEquals(3, myListPtr->itemCount());
    printAssertEquals("{10, 20, 50}", myListPtr->toString());

    printAssertEquals(50, myListPtr->removeValueAt(2));
    printAssertEquals(2, myListPtr->itemCount());
    printAssertEquals("{10, 20}", myListPtr->toString());

    printAssertEquals(10, myListPtr->removeValueAt(0));
    printAssertEquals(1, myListPtr->itemCount());
    printAssertEquals("{20}", myListPtr->toString());
    printAssertEquals(false, myListPtr->isEmpty());

    printAssertEquals(20, myListPtr->removeValueAt(0));
    printAssertEquals(0, myListPtr->itemCount());
    printAssertEquals("{}", myListPtr->toString());
    printAssertEquals(true, myListPtr->isEmpty());
    std::cout << "--done--" <<std::endl;

}


//assume working insertAtEnd, insertAtFront, toString, itemCount, isEmpty, clearList
void doubleCapacityTest(){
    std::cout << "-------doubleCapacityTest---------" <<std::endl;
    try{
        MasterPlaylist badList = MasterPlaylist(0);
        std::cout << "FAIL: constructor did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        printAssertEquals("In MasterPlaylist constructor, size must be > 0", e.what());
    }
    MasterPlaylist myList = MasterPlaylist(1);
    for(int i=0; i<10; i++){
        myList.insertAtFront(i);
        myList.insertAtEnd(i);
    }
    printAssertEquals("{9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}", myList.toString());
    printAssertEquals(20, myList.itemCount());
    printAssertEquals(false, myList.isEmpty());

    int a1[10]{5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    insertAtEndAndGetValueAtTest(a1, 5, 3);
    isEmptyTest(a1, 5, 3);
    itemCountTest(a1, 5, 3);
    clearListTest(a1, 5, 3);
    std::cout << "--done--" <<std::endl;

}

//assumes working doubleCapacity, insertAtEnd, removeValueAt, toString
void testCopyConstructor(){
    std::cout << "-------testCopyConstructor---------" <<std::endl;
    int numErrors = 0;
    //create object, add some stuff
    MasterPlaylist original = MasterPlaylist(2);
    for (int i=0; i<4; i++){
        original.insertAtEnd(i);
    }
    //copy it
    MasterPlaylist copy = MasterPlaylist(original);
    //check they're the same
    if (!(original.toString() == copy.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removeValueAt(0);
    original.removeValueAt(0);
    original.insertAtEnd(4);
    original.insertAtEnd(5);
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

//assumes working doubleCapacity, insertAtEnd, removeValueAt, toString
void testAssnOperator(){
    std::cout << "-------testAssnOperator---------" <<std::endl;
    int numErrors = 0;
    //create object, add some stuff
    MasterPlaylist original = MasterPlaylist(2);
    for (int i=0; i<4; i++){
        original.insertAtEnd(i);
    }
    //create a new list with its own data
    MasterPlaylist listToSet = MasterPlaylist(2);
    for (int i=10; i<14; i++){
        listToSet.insertAtEnd(i);
    }
    //assign the original to the new
    listToSet = original;

    //check they're the same
    if (!(original.toString() == listToSet.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removeValueAt(0);
    original.removeValueAt(1);
    original.insertAtEnd(4);
    original.insertAtEnd(5);
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

    MasterPlayList testList[5]{5, 6, 7, 8, 9};

    insertAtEndAndGetValueAtTest(testList, 5, 5);
    isEmptyTest(testList, 5, 5);
    itemCountTest(testList, 5, 5);
    clearListTest(testList, 5, 5);

    toStringTest();
    findTest();

    insertAtFrontTest();
    insertAtTest();
    removeValueAtEndTest();
    removeValueAtTest();

    doubleCapacityTest();
    testCopyConstructor();
    testAssnOperator();

    return 0;
}