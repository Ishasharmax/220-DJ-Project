//
// Created by Joel Jerez on 11/29/18.
//

#include "Song.h"
#include <string>

Song::Song(std::string titleIn, std::string artistIn, float songLengthIn){
    this->title= titleIn;
    this->artist = artistIn;
    this->songLength = songLengthIn;
    this->playcount = 0;
}

Song::Song(const Song& songToCopy){
    this->title=songToCopy.title;
    this->artist=songToCopy.artist;
    this->songLength=songToCopy.songLength;
    this->playcount=songToCopy.playcount;
}

Song& Song::operator= (const Song& songToCopy){
    if (this != &songToCopy){
        this->title=songToCopy.title;
        this->artist=songToCopy.artist;
        this->songLength=songToCopy.songLength;
        this->playcount=songToCopy.playcount;
    }
    return *this;
}

void Song::addToPlayCount(){
    playcount++;
}

std::string Song:: getTitle(){
    return title;
}

std::string Song::getArtist() {
    return artist;
}

float Song::getSongLength() {
    return songLength;
}

int Song::getPlayCount() {
    return playcount;
}


