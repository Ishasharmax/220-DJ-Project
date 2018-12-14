//
// Created by KandacePC on 11/29/2018.
//

#include "LinkedPlayList.h"
#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

LinkedPlayList::LinkedPlayList() {
    front= nullptr;
    end= nullptr;
    current= nullptr;
    currItems=0;
}
LinkedPlayList::LinkedPlayList(const LinkedPlayList &playListToCopy) {
    LinkedPlayListNode *copy=playListToCopy.front;
    this->front=new LinkedPlayListNode(*copy);
    LinkedPlayListNode *count=this->front;
    copy=copy->getNext();
    while(copy!= nullptr){
        LinkedPlayListNode *next= new LinkedPlayListNode(*copy);
        count->setNext(next);
        count=next;
        end=next;
        copy=copy->getNext();
    }
}//DONE

LinkedPlayList& LinkedPlayList::operator=(const LinkedPlayList& playListToCopy){
    if(this!=&playListToCopy){
        while(front!= nullptr){
            LinkedPlayListNode *song=front;
            front=front->getNext();
            delete song;
        }
        this->end= nullptr;
    }
    LinkedPlayListNode *copy=playListToCopy.front;
    this->front=new LinkedPlayListNode(*copy);
    LinkedPlayListNode *count=this->front;
    copy=copy->getNext();
    while(copy!= nullptr){
        LinkedPlayListNode *next= new LinkedPlayListNode(*copy);
        count->setNext(next);
        count=next;
        end=next;
        copy=copy->getNext();
    }
}//DONE

LinkedPlayList::~LinkedPlayList() {

    while(front!= nullptr){
        LinkedPlayListNode* song=front;
        front=front->getNext();
        delete song;
    }
    this->end= nullptr;
}//DONE

float LinkedPlayList::calcPlayListDuration() {
    if(front== nullptr){
        throw std::string("No songs in playlist");
    }else{
        float totalSongDuration=0;
        LinkedPlayListNode *copyPlayList=front;
        while(copyPlayList!=nullptr){
            totalSongDuration=totalSongDuration+copyPlayList->getSong().getSongLength();
            copyPlayList=copyPlayList->getNext();
        }
        return totalSongDuration;
    }

}//DONE

std::string LinkedPlayList::search(std::string item) {
    if(front==nullptr){
        throw std::out_of_range("Out of range");
    }
    else{
        LinkedPlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(copyPlayList->getSong().getTitle()== item){
                copyPlayList->getSong().addToPlayCount();
                current=copyPlayList;
                current->getSong().addToPlayCount();
                return "Song name: "+copyPlayList->getSong().getTitle()+" Artist:"+copyPlayList->getSong().getArtist()+" Song length:"+ to_string(copyPlayList->getSong().getSongLength());
            }
            else{
                if(copyPlayList->getNext()== nullptr){
                    if(copyPlayList->getSong().getTitle()!=item){
                        return "Song not found";
                    }
                }
                copyPlayList=copyPlayList->getNext();
            }
        }
    }

}//DONE

void LinkedPlayList::addSongAtEnd(std::string artist, std::string songName, float duration) {
    if(front== nullptr){
        Song newSong=Song(songName,artist ,duration);
        LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(&newSong);
        front=addToPlayList;
        end=addToPlayList;
        currItems++;
    }
    else{
        int count=-1;
        LinkedPlayListNode*copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(songName==copyPlayList->getSong().getTitle()){
                count++;
            }
            copyPlayList=copyPlayList->getNext();
        }
        if(count<0) {
            Song newSong=Song(songName,artist,duration);
            LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(&newSong);
            end->setNext(addToPlayList);
            end = addToPlayList;
            currItems++;
        }
    }
}//DONE

void LinkedPlayList::addSongAt(int index, std::string artist, std::string songName, float duration) {
    if (index < 0 || index >currItems) {
        throw std::out_of_range("Out of range");
    } else {
        if (index==0) {
            Song newSong = Song(songName, artist, duration);
            LinkedPlayListNode *addToPlayList = new LinkedPlayListNode(&newSong);
            if(front == nullptr) {
                front=addToPlayList;
                end=addToPlayList;
                currItems++;
            }
            else{
                currItems++;
                addToPlayList->setNext(front);
                front=addToPlayList;
            }
        }
        if(index == currItems) {
            addSongAtEnd(artist, songName, duration);
        }
        else {
            LinkedPlayListNode *copyPlayList = front;
            LinkedPlayListNode *copyPlayList2=front;
            int count=0;
            while(copyPlayList2!= nullptr){
                if(songName!=copyPlayList2->getSong().getTitle()){
                    count++;
                }
                copyPlayList=copyPlayList->getNext();
            }
            if(count<0) {
                Song newSong=Song(songName,artist,duration);
                LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(&newSong);
                for(int i =0;i<index-1;i++){
                    copyPlayList2=copyPlayList2->getNext();
                }
                addToPlayList->setNext(copyPlayList2->getNext());
                copyPlayList2->setNext(addToPlayList);
                front=copyPlayList2;
                currItems++;
            }
        }
    }
}//DONE

bool LinkedPlayList::isEmpty(){
    if(front== nullptr){
        return true;
    }
    else{
        return false;
    }
}//DONE

std::string LinkedPlayList::removeSongAtEnd(){
    if(isEmpty()){
        throw std::out_of_range("out of range");
    }
    else {
        Song deleteSong;
        LinkedPlayListNode *toDelete = new LinkedPlayListNode(&deleteSong);
        LinkedPlayListNode *copyPlayList = front;
        for (int i = 0; i < currItems - 1; i++) {
            copyPlayList = copyPlayList->getNext();
        }
        if (currItems == 1) {
            deleteSong = front->getSong();
            front = nullptr;
            end = nullptr;
        } else {
            deleteSong = copyPlayList->getSong();
            end = copyPlayList;
            deleteSong;
            toDelete;
        }
        currItems--;
        return "Removed song: " + deleteSong.getTitle();

    }
}//DONE

std::string LinkedPlayList::removeSongAt(int index) {
    if (index < 0 || index >= currItems) {
        throw std::out_of_range("out of range");
    }
    else{
        if(currItems== (index+1)){
            removeSongAtEnd();
        }
        else if(index==0){
            if(isEmpty()){
                throw std::out_of_range("out of range");
            }
            Song deleteSong=front->getSong();
            LinkedPlayListNode *toDelete=new LinkedPlayListNode(&deleteSong);
            front=front->getNext();
            delete toDelete;
            currItems --;
            return "Removed song: "+ deleteSong.getTitle();
        }
        else{
            Song deleteSong;
            LinkedPlayListNode *copy=front;
            LinkedPlayListNode *copy2;
            LinkedPlayListNode *toDelete;
            for(int i =0;i<index-1;i++){
                copy=copy->getNext();
            }
            toDelete=copy->getNext();
            deleteSong=toDelete->getSong();
            copy2=copy->getNext()->getNext();
            copy->setNext(copy2);
            delete toDelete;
            currItems--;
            return "Removed song: "+ deleteSong.getTitle();
        }
    }
}//DONE

int LinkedPlayList::getSongCount() {
    return currItems;
}//DONE

std::string LinkedPlayList::getAllSongs() {
    LinkedPlayListNode *copyPlayList=front;
    string allSongs="";
    while(copyPlayList!= nullptr){
        allSongs=allSongs+"Song name: "+copyPlayList->getSong().getTitle()+" Artist:"+copyPlayList->getSong().getArtist()+" Song length:"+ to_string(copyPlayList->getSong().getSongLength())+"\n";
        copyPlayList=copyPlayList->getNext();
    }
    return allSongs;
}//DONE

std::string LinkedPlayList::nextSong() {
    if(isEmpty()){
        throw std::out_of_range("Out of range");
    }
    else{
        if(current== nullptr){
            current=front->getNext();
            current->getSong().addToPlayCount();
            return "Now playing first song: "+current->getSong().getTitle();
        }
        else if(current->getNext()!= nullptr){
            current=current->getNext();
            current->getSong().addToPlayCount();
            return "Now playing the song: "+current->getSong().getTitle();
        }
        else{
            return "No more songs in play list";
        }
    }
}//DONE

std::string LinkedPlayList::previousSong() {
    if(current== nullptr || isEmpty()){
        throw std::out_of_range("Out of range");
    }
    else{
        LinkedPlayListNode *copyPlayList=front;
        if(copyPlayList->getSong().getTitle()==current->getSong().getTitle()){
            current->getSong().addToPlayCount();
            return "This is the first song in the play list. Cannot play previous";
        }
        else {
            while (copyPlayList != nullptr) {
                if (copyPlayList->getNext()==current){
                    current=copyPlayList;
                    current->getSong().addToPlayCount();
                    return "Now playing: "+ current->getSong().getTitle()+ " by: "+ current->getSong().getArtist();
                }
                else{
                    copyPlayList=copyPlayList->getNext();
                }
            }
        }

    }
}//DONE

std::string LinkedPlayList::getHelp() {
    return"You have the option to: \n 1-add a song 2-remove a song 3-search and play a song 4-check is play list is empty \n 5-get song count 6-"
          "get play count 7-get number of songs in the list 8-get name of all songs \n 9-play next song 10-play previous song 11-get play list duration";
}//DONE

void LinkedPlayList::replay() {
    current->getSong().addToPlayCount();
}//DONE

int LinkedPlayList::getPlayCount(std::string song) {
    if(isEmpty()){
        throw std::out_of_range("out of range");
    }
    else {
        if (song == current->getSong().getTitle()) {
            return current->getSong().getPlayCount();
        } else {
            LinkedPlayListNode *copyPlayList = front;
            LinkedPlayListNode *copySong;
            bool TorF = false;
            while (copyPlayList != nullptr) {
                if (copyPlayList->getSong().getTitle() != song) {
                    copySong = copyPlayList;
                    return copyPlayList->getSong().getPlayCount();
                }
                copyPlayList = copyPlayList->getNext();
            }
            if(copyPlayList== nullptr){
                return -1;
            }
        }
    }

}//DONE