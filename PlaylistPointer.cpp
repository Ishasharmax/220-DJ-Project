//
// Created by Joel Jerez on 12/14/18.
//

#include "PlayListPointer.h"
#include "LinkedPlayList.h"
#include "PlayList.h"

PlaylistPointer::PlaylistPointer(LinkedPlayList* playlistIN){
    this->playlist=playlistIN;
}

PlaylistPointer::~PlaylistPointer(){
    delete this->playlist;
}

PlaylistPointer::PlaylistPointer(const PlaylistPointer& ptrToCopy){
    playlist = ptrToCopy.playlist;
}

PlaylistPointer& PlaylistPointer::operator= (const PlaylistPointer& ptrToCopy){
    if(this != &ptrToCopy){
        this->playlist = ptrToCopy.playlist;
    }
    return *this;
}

LinkedPlayList PlaylistPointer:: getPlaylist(){
    return *playlist;
}

void PlaylistPointer::setPlaylist(LinkedPlayList *newPlaylist) {
    this->playlist=newPlaylist;
}


