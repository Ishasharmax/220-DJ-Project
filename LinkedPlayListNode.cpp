//
// Created by Joel Jerez on 11/29/18.
//

#include "LinkedPlayListNode.h"
#include "Song.h"

PlayListNode::PlayListNode(Song *songIN) {
    this->song=songIN;
    this->next= nullptr;
}

PlayListNode::~PlayListNode(){
    delete this->song;
}

PlayListNode::PlayListNode(const PlayListNode& nodeToCopy){
    song=nodeToCopy.song;
    next= nullptr;
}

PlayListNode& PlayListNode::operator=(const PlayListNode& nodeToCopy){
    if (this!=nodeToCopy){
        this->song=nodeToCopy.song;
        this->next=nodeToCopy.next;
    }
    return *this;
}


Song PlayListNode:: getSong() {
    return *song;
}
void PlayListNode:: setSong(Song newSong){
    *song = newSong;
}
PlayListNode* PlayListNode:: getNext(){
    return next;
}

void PlayListNode::setNext(PlayListNode* newNode){
    next=newNode;
}



