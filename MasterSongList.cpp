//
// Created by Isha Sharma on 11/29/18.
//
#include "MasterSongList.h"
#include "PlayListNode.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include "Song.h"
using namespace std;

MasterSongList::MasterSongList(int initialCapacity){
    if (initialCapacity<1){
        throw std::invalid_argument("error");
    }else{
        this->currCapacity=initialCapacity;
        currItemCount=0;
        songPtr=new int[currCapacity];
        this->songArray= songPtr;
    }
}

MasterSongList::~MasterSongList(){
    delete[] this->songArray;
    this->songArray= nullptr;

}

MasterSongList::MasterSongList(const MasterSongList& songToCopy){
    this->currCapacity=songToCopy.currCapacity;
    this->songArray= new int[songToCopy.currCapacity];
    this->currItemCount=songToCopy.currItemCount;
    for (int i=0; i<songToCopy.currItemCount;i++){
        this->songArray[i]=songToCopy.songArray[i];
    }
}

MasterSongList& MasterSongList::operator=(const MasterSongList& songListToCopy){
    if (this !=&songListToCopy){
        delete[] this->songArray;
        this->songArray= nullptr;

        this->currItemCount=songListToCopy.currItemCount;
        this->currCapacity=songListToCopy.currCapacity;
        this->songArray=new int[songListToCopy.currCapacity];
        for (int i=0; i<songListToCopy.currItemCount;i++){
            this->songArray[i]=songListToCopy.songArray[i];
        }
    }
    return *this;
}


void MasterSongList::doubleCapacity(){
    currCapacity=currCapacity*2;
    int *newArray= new int[currCapacity];
    for (int i=0;i<currItemCount;i++){
        newArray[i]=songArray[i];
    }delete [] songArray;
    songArray=newArray;
}

void MasterSongList::removeSong(Song songToRemove){
    if (currItemCount<1) {
        throw std::out_of_range("error");
    }else{
        currItemCount--;
        for (int i=songToRemove;i<currItemCount;i++){
            songArray[i]=songArray[i+1];
        }
    }
}

void MasterSongList::importSong(Song songToAdd, int index){
    if (index<0 || currItemCount<index) {
        throw std::out_of_range("error");
    }
    else{
        currItemCount++;
        if (currItemCount+1>=currCapacity){
            doubleCapacity();
        }
        for (int i=currItemCount;i>index;i--){
            songArray[i]=songArray[i-1];
        }songArray[index]=songToAdd;
    }
}






