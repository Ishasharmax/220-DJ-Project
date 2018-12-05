//
// Created by KandacePC on 11/29/2018.
//

#include "LinkedPlayList.h"
#include <string>
#include "PlayList.h"
#include "Song.h"
using namespace std;

LinkedPlayList::LinkedPlayList() {
    front= nullptr;
    end= nullptr;
    current= nullptr;
    currItems=0;
}
LinkedPlayList::LinkedPlayList(const LinkedPlayList &playListToCopy) {

}
LinkedPlayList::~LinkedPlayList() {

}
LinkedPlayList& LinkedPlayList::operator=(const LinkedPlayList& playListToCopy){

}
float LinkedPlayList::calcPlayListDuration() {
    if(front== nullptr){
        throw std::string("No songs in playlist");
    }else{
        float totalSongDuration=0;
        PlayListNode *copyPlayList=front;
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
        PlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(copyPlayList->getSong().getTitle()==item){
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
        Song newSong=Song(songName,artist,duration);
        PlayListNode *addToPlayList=new PlayListNode(&newSong);
        front=addToPlayList;
        end=addToPlayList;
        currItems++;
    }
    else{
        int count=0;
        PlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(songName!=copyPlayList->getSong().getTitle()){
                count++;
            }
        }
        if(count>0) {
            Song newSong=Song(songName,artist,duration);
            PlayListNode *addToPlayList=new PlayListNode(&newSong);
            end->setNext(addToPlayList);
            end = addToPlayList;
            currItems++;
        }
    }
}//DONE

void LinkedPlayList::addSongAt(int index, std::string artist, std::string songName, float duration) {
    if (index < 0 || index > currItems) {
        throw std::out_of_range("Out of range");
    } else {
        if (front == nullptr) {
            Song newSong = Song(songName, artist, duration);
            PlayListNode *addToPlayList = new PlayListNode(&newSong);
            front = addToPlayList;
            end = addToPlayList;
        }
        else {
            int count = 0;
            PlayListNode *copyPlayList = front;
            if (index == currItems) {
                addSongAtEnd(artist, songName, duration);
            }
            else {
                for(int i=0;i<index;i++){

                }
            }
        }
    }
}
