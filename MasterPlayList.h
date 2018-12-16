//
// Created by Bobo on 12/16/2018.
//

#ifndef INC_220_DJ_PROJECT_MASTERPLAYLIST_H
#define INC_220_DJ_PROJECT_MASTERPLAYLIST_H

#include <string>
#include <stdexcept>
#include Playlist.h
#include LinkedPlayList.h
class MasterPlayList{
private:
    int *array;
    int currItemCount;
    int currCapacity;
    MasterPlayList* playlistPointer;
public:
    MasterPlayList(int intialCapacity);
    MasterPlayList(const MasterPlayList& arrayListToCopy);
    ~MasterPlayList();
    std::string getPlaylist();
    void addPlayList();
    std::string removePlayList();
    std::string findPlaylist();
    bool isEmpty();
};
#endif //INC_220_DJ_PROJECT_MASTERPLAYLIST_H
