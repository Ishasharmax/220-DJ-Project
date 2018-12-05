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
        arraySong=new Song[initialCapacity];
    }
}

MasterSongList::~MasterSongList(){
    delete[] this->arraySong;
    this->arraySong= nullptr;
}

MasterSongList::MasterSongList(const MasterSongList& songToCopy){
    this->currCapacity=songToCopy.currCapacity;
    this->currItemCount=songToCopy.currItemCount;
    for (int i=0; i<songToCopy.currItemCount;i++){
        this->arraySong[i]=songToCopy.arraySong[i];
    }
}

MasterSongList&MasterSongList::operator=(const MasterSongList& songListToCopy){
    if (this !=&songListToCopy){
        delete[] this->arraySong;
        this->arraySong= nullptr;
        this->currItemCount=songListToCopy.currItemCount;
        this->currCapacity=songListToCopy.currCapacity;
        for (int i=0; i<songListToCopy.currItemCount;i++){
            this->arraySong[i]=songListToCopy.arraySong[i];
        }
    }
    return *this;
}


void MasterSongList::doubleCapacity(){
    currCapacity=currCapacity*2;
    Song *newArray= new Song[currCapacity];
    for (int i=0;i<currItemCount;i++){
        newArray[i]=arraySong[i];
    }delete [] arraySong;
    arraySong=newArray;
}


void MasterSongList::removeSong(int index){
    if (currItemCount<1) {
        throw std::out_of_range("error");
    }else{
        currItemCount--;
        for (int i=index;i<currItemCount;i++){
            arraySong[i]=arraySong[i+1];
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
            arraySong[i]=arraySong[i-1];
        }arraySong[index]=songToAdd;
    }
}

std::string MasterSongList::toString() {
    std::string str1 = "{";
    for (int i = 0; i < currItemCount; i++) {
        if (i != (currItemCount - 1)) {
            str1 += std::to_string(arraySong[i]) + ", ";
        } else if (i == (currItemCount - 1)) {
            str1 += std::to_string(arraySong[i]);
        }
    }
    str1 = str1 + "}";
    return str1;
}








