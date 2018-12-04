//
// Created by KandacePC on 11/29/2018.
//

#include "LinkedPlayList.h"
#include <string>
#include "PlayList.h"
using namespace std;

LinkedPlayList::LinkedPlayList() {
    front= nullptr;
    end= nullptr;
}
LinkedPlayList::LinkedPlayList(const LinkedPlayList &playListToCopy) {

}
LinkedPlayList::~LinkedPlayList() {

}
LinkedPlayList& LinkedPlayList::operator=(const LinkedPlayList& playListToCopy){

}
float LinkedPlayList::calcPlayListDuartion() {
    if(front== nullptr){
        throw std::string("No songs in playlist");
    }
    else{
        float totalSongDuration=0;
        PlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            totalSongDuration=totalSongDuration+PlayListNode.getSongDuration();
        }
        return totalSongDuration;
    }

}
std::string LinkedPlayList::search(std::string item) {
    if(front==nullptr){
        throw std::out_of_range("Out of range");
    }
    else{
        PlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(copyPlayList.getSongName()==item){
                return "Song name:" +PlayListNode.getSongName()+" Artist:"+PlayListNode.getArtist()+" Song length"+ PlayListNode.getDuration();
            }
            else{
                if(copyPlayList.getNext()== nullptr){
                    if(copyPlayList.getSongName()!=item){
                        return "Song not found";
                    }
                }

                newPlayList=newPlayList.getNext();
            }
        }
    }

}
void LinkedPlayList::addSong(std::string artist, std::string songName, float duration) {
    if(front== nullptr){
        PlayListNode *newSong=new PlayListNode(artist,songName,duration);
        front=newSong;
        end=newSong;
    }
    else{
        int count=0;
        PlayListNode *copyPlayList=front;
        while(copyPlayList!= nullptr){
            if(songName!=copyPlayList.getSongName()){
                count++;
            }
        }
        if(count>0) {
            PlayListNode *newSong = PlayListNode(artist, songName, duration);
            end.setNext(newSong);
            end = newSong;
        }
    }
}

