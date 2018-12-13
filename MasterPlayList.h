//
// Created by Bobo on 11/29/2018.
//
#ifndef INC_220_DJ_PROJECT_MASTERPLAYLIST_H
#define INC_220_DJ_PROJECT_MASTERPLAYLIST_H

#include <string>
#include <stdexcept>
#include "LinkedPlayList.h"
class MasterPlayList {
private:
    int *arrayOfPlayList;
    MasterPlayList *playListPtr;
    int currItemCount;
    int currCapacity;
    std::string *arrayOfPlayListNameas;
    int currentNames;
    void doubleCapacity();
public:
    MasterPlayList(int initialCapacity);
    MasterPlayList(const  MasterPlayList& arrayListToCopy);
    ~MasterPlayList();
    MasterPlayList& operator=(const MasterPlayList& arrayListToCopy);
    void setNext(LinkedPlayList* newNode);
    void addPlayListName(std::string playListName);
    std::string toStringGetPlaylist(int index);
    void addPlayList(LinkedPlayList *playlistToAdd);
    void addPlayListAt(LinkedPlayList *playlistToAddi, int index);
    std::string getPlayListAt(int index);
    std::string toString();
    LinkedPlayList removePlayList();
    LinkedPlayList removePlayListAt(int index);
    LinkedPlayList findPlaylist(int index);
    int  getitemCount();
    void clearList();
    bool isEmpty();

};


#endif //INC_220_DJ_PROJECT_MASTERPLAYLIST_H
