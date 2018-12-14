//
//
// Created by Isha Sharma on 11/29/18.
//
#include "MasterSongList.h"
#include "LinkedPlayListNode.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

MasterSongList::MasterSongList(int initialCapacity, std::string nameOftheList){
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

std::string MasterSongList::toString(){
    std::string str1 = "{";
    str1 += arraySong->getTitle() + ", ";
    str1 += arraySong->getArtist() + ", ";
    str1 += to_string(arraySong->getSongLength());
    str1 += to_string(arraySong->getPlayCount()) + ", ";
    str1 = str1 + "}";
    return str1;
}

void MasterSongList::removeValueAtEnd(){
    if (currItemCount==0){
        throw std::out_of_range ("error");
    }else{
        currItemCount--;
    }
}

void MasterSongList::insertAtEnd(Song songToAdd){
    arraySong[currItemCount++]=songToAdd;
}










