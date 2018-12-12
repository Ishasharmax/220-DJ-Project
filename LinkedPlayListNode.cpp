//
// Created by Joel Jerez on 11/29/18.
//

#include "LinkedPlayListNode.h"
#include "Song.h"

LinkedPlayListNode::LinkedPlayListNode(Song *songIN) {
    this->song=songIN;
    this->next= nullptr;
}

LinkedPlayListNode::~LinkedPlayListNode(){
    delete this->song;
}

LinkedPlayListNode::LinkedPlayListNode(const LinkedPlayListNode& nodeToCopy){
    song=nodeToCopy.song;
    next= nullptr;
}

LinkedPlayListNode& LinkedPlayListNode::operator=(const LinkedPlayListNode& nodeToCopy){
    if (this!=nodeToCopy){
        this->song=nodeToCopy.song;
        this->next=nodeToCopy.next;
    }
    return *this;
}


Song LinkedPlayListNode:: getSong() {
    return *song;
}
void LinkedPlayListNode:: setSong(Song newSong){
    *song = newSong;
}
LinkedPlayListNode* LinkedPlayListNode:: getNext(){
    return next;
}

void LinkedPlayListNode::setNext(LinkedPlayListNode* newNode){
    next=newNode;
}



