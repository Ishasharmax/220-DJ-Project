//
// Created by KandacePC on 11/29/2018.
//

#include "LinkedPlayList.h"
#include <string>
#include <iostream>

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
                current=copyPlayList;
                current->getSong().addToPlayCount();
                return to_string(current->getSong().getPlayCount());//"Title:"+copyPlayList->getSong().getTitle()+" Artist:"+copyPlayList->getSong().getArtist()+" Length:"+ to_string(copyPlayList->getSong().getSongLength());
            }
            /*
            else{
                if(copyPlayList->getNext()== nullptr){
                    if(copyPlayList->getSong().getTitle()!=item){
                        return "Song not found";
                    } else{
                        current=copyPlayList;
                        current->getSong().addToPlayCount();
                        return "Title:"+copyPlayList->getSong().getTitle()+" Artist:"+copyPlayList->getSong().getArtist()+" Length:"+ to_string(copyPlayList->getSong().getSongLength());

                    }
                }*/
                copyPlayList=copyPlayList->getNext();
            }
        }


}//DONE

void LinkedPlayList::addSongAtEnd(std::string artist, std::string songName, float duration) {
    if(front== nullptr){
        Song *newSong= new Song(songName, artist, duration);
        LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(newSong);
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
            Song *newSong=new Song(songName,artist,duration);
            LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(newSong);
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
            Song *newSong = new Song(songName, artist, duration);
            LinkedPlayListNode *addToPlayList = new LinkedPlayListNode(newSong);
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
            int count=-1;
            while(copyPlayList!= nullptr){
                if(songName==copyPlayList->getSong().getTitle()){
                    count++;
                }
                copyPlayList=copyPlayList->getNext();
            }
            if(count<0) {
                Song *newSong= new Song(songName,artist,duration);
                LinkedPlayListNode *addToPlayList=new LinkedPlayListNode(newSong);
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
        string deleteSong;
        LinkedPlayListNode *copyPlayList = front;

        if (currItems == 1) {
            deleteSong=front->getSong().getTitle();
            front = nullptr;
            end = nullptr;

        } else {
            for(int i =0;i<currItems-1;i++){
                copyPlayList= copyPlayList->getNext();
            }
            deleteSong=copyPlayList->getSong().getTitle();
            delete copyPlayList;
        }
        currItems--;
        return "Removed song: " + deleteSong;

    }
}//FIX

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

            LinkedPlayListNode *toDelete=front;
            string deleteSong=toDelete->getSong().getTitle();
            front=front->getNext();
            delete toDelete;
            currItems --;
            return "Removed song: "+ deleteSong;
        }
        else{
            LinkedPlayListNode *copy=front;
            LinkedPlayListNode *copy2;
            LinkedPlayListNode *toDelete;
            for(int i =0;i<index-1;i++){
                copy=copy->getNext();
            }
            toDelete=copy->getNext();
            string deleteSong=toDelete->getSong().getTitle();
            copy2=copy->getNext()->getNext();
            copy->setNext(copy2);
            delete toDelete;
            currItems--;
            return "Removed song: "+ deleteSong;
        }
    }
}//FIX

int LinkedPlayList::getSongCount() {
    return currItems;
}//DONE

std::string LinkedPlayList::getAllSongs() {
    if(front== nullptr){
        return "Playlist empty";
    }
    LinkedPlayListNode *copyPlayList=front;
    string allSongs="";
    while(copyPlayList!= nullptr){
        if(copyPlayList->getNext()== nullptr){
            allSongs=allSongs+copyPlayList->getSong().getTitle();
            copyPlayList=copyPlayList->getNext();
        }
        else {
            allSongs = allSongs + copyPlayList->getSong().getTitle() + ", ";
            copyPlayList = copyPlayList->getNext();
        }
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
            while (copyPlayList != nullptr) {
                if (copyPlayList->getSong().getTitle() == song) {
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

void LinkedPlayList::saveThePlayList() {
    LinkedPlayListNode *temp = front;
    ofstream inFile("SampleLibrary.txt");

    if (!inFile) {
        cout << "File cant be opened" << endl;
        exit(1);
    }
    while (temp != nullptr) {
        inFile << temp->getSong().getTitle() << endl;
        inFile << temp->getSong().getArtist() << endl;
        inFile << std::to_string(temp->getSong().getSongLength()) << endl;
        inFile << std::to_string(temp->getSong().getPlayCount()) << endl;
        temp = temp->getNext();
    }
}

void LinkedPlayList::clearList() {
    while(front!= nullptr){
        LinkedPlayListNode* song=front;
        front=front->getNext();
        delete song;
    }
    this->front= nullptr;
    this->end= nullptr;
    currItems=0;
    delete current;
    this->current= nullptr;
}



std::string LinkedPlayList::displayArtist(std::string artist) {
    LinkedPlayListNode *temp = front;
    std::string artistWork = artist+" work: ";
    while (temp != nullptr) {
        if (temp != nullptr) {
            if (temp->getSong().getArtist() == artist) {
                artistWork = artistWork + temp->getSong().getTitle() + ", ";
            }
            temp = temp->getNext();
        }
    }return artistWork;
}




