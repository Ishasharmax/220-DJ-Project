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
    LinkedPlayList *playListPtr;
    int currItemCount;
    int currCapacity;
    void doubleCapacity();
public:
    MasterPlayList(int initialCapacity);
    MasterPlayList(const  MasterPlayList& arrayListToCopy);
    ~MasterPlayList();
    MasterPlayList& operator=(const MasterPlayList& arrayListToCopy);
    std::string toStringGetPlaylist(int index);
    void addPlayList(PlayList playlistToAdd);
    void addPlaylistAt(int itemToAdd, int index);
    void insertAt(int index);
    std::string removePlayList();
    std::string findPlaylist(int index);
    void clearList();
    bool isEmpty();

};


#endif //INC_220_DJ_PROJECT_MASTERPLAYLIST_H
