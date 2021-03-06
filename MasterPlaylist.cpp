//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "MasterPlayList.h"
#include "LinkedPlayList.h"
#include "MasterPlayListLib.h"

#include <stdexcept>
#include <string>

int numLinesEmpty=0;

MasterPlayList::MasterPlayList(int initialCapacity) {
    if(initialCapacity<1){
        throw std::invalid_argument("Size is less than 1");
    }
    else{
        this->currCapacity=initialCapacity;
        this->arrayOfPlayList=new int[currCapacity];
        currItemCount=0;
        this->playListPtr=nullptr;
    }

}
//Copy Constructor
MasterPlayList::MasterPlayList(const MasterPlayList& MasterPlayListToCopy){
    this->currCapacity=MasterPlayListToCopy.currCapacity;
    this->arrayOfPlayList= new int [MasterPlayListToCopy.currCapacity];
    this->currItemCount=MasterPlayListToCopy.currItemCount;
    for(int i=0;i<MasterPlayListToCopy.currItemCount;i++){
        this->arrayOfPlayList[i]=MasterPlayListToCopy.arrayOfPlayList[i];
    }
}

//Overloaded Assignment Operator
MasterPlayList&  MasterPlayList::operator=(const MasterPlayList& MasterPlayListToCopy){
    if (this != &MasterPlayListToCopy ) {
        delete arrayOfPlayList;
        this->arrayOfPlayList= nullptr;
        this->currCapacity=MasterPlayListToCopy.currCapacity;
        this->arrayOfPlayList= new int [MasterPlayListToCopy.currCapacity];
        this->currItemCount=MasterPlayListToCopy.currItemCount;
        for(int i=0;i<MasterPlayListToCopy.currItemCount;i++){
            this->arrayOfPlayList[i]=MasterPlayListToCopy.arrayOfPlayList[i];
        }
    }
    return *this;
}

//Destructor
MasterPlayList::~MasterPlayList(){
    delete[] this ->arrayOfPlayList;
    this ->arrayOfPlayList= nullptr;

}

void  MasterPlayList::doubleCapacity(){
    if(currCapacity<1){
        throw std::invalid_argument("Size is less than 1");
    }
    else{
        currCapacity=currCapacity*2;
        int * temp=new int [currCapacity];
        for(int i=0; i<currItemCount;i++){
            temp[i]=arrayOfPlayList[i];
        }
        delete[] arrayOfPlayList;
        arrayOfPlayList=temp;
    }
}

void  MasterPlayList::addPlayList(LinkedPlayList *playlistToAdd) {
    arrayOfPlayList[currItemCount++];
    playListPtr->setNext(playlistToAdd);

    //arrayOfPlayList[currItemCount++]=playlistToAdd;
}

void  MasterPlayList::addPlayListAt(LinkedPlayList *playlistToAdd, int index) {
    if(index<0 || currCapacity<index){
        throw std::out_of_range("Size is less than 1");
    }
    else{
        currItemCount++;
        if(currItemCount+1>=currCapacity){
            doubleCapacity();
        }
        for(int i=currItemCount;i>index;i--){
            arrayOfPlayList[i]=arrayOfPlayList[i-1];
        }
        arrayOfPlayList[index]=playListPtr->setNext(playlistToAdd);
    }
}

std::string  MasterPlayList::getPlayListAt(int index){
    if(index<0 || index>=currItemCount){
        throw std::out_of_range("Size is less than 1");
    }
    else{
        return ::toString(arrayOfPlayList[index],currCapacity);
    }
}

std::string MasterPlayList::toString(){
    return  ::toString(arrayOfPlayList,currCapacity);
}

bool  MasterPlayList::isEmpty(){
    if(currItemCount==0){
        return true;
    }
    else{
        return false;
    }
}

int  MasterPlayList::getitemCount(){
    if(isEmpty()){
        return 0;
    }
    else{
        return currItemCount;
    }
}

void  MasterPlayList::clearList(){
    if(isEmpty()){
        throw std::invalid_argument("Size is already 0");
    }
    else{
        currItemCount=0;
    }
}

LinkedPlayList MasterPlayList::findPlaylist(int numToFind){
    return  ::find(arrayOfPlayList,currCapacity,numToFind,numLinesEmpty);
}



LinkedPlayList MasterPlayList::removePlayList() {
    if (currItemCount < 1) {
        throw std::out_of_range("List is empty");
    } else {
        currItemCount--;
        int remove=arrayOfPlayList[currItemCount];
        return remove;
    }
}


LinkedPlayList MasterPlayList::removePlayListAt(int index) {
    if (currItemCount < 1) {
        throw std::invalid_argument("Size is less than 1");
    } else {
        currItemCount--;
        int remove=arrayOfPlayList[index];
        for(int i=index; i<currItemCount;i++ ){
            arrayOfPlayList[i]=arrayOfPlayList[i+1];
        }
        return remove;
    }
}
