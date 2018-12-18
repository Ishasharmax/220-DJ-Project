//
// Created by Bobo on 12/16/2018.
//

#ifndef INC_220_DJ_PROJECT_MASTERPLAYLIST_H
#define INC_220_DJ_PROJECT_MASTERPLAYLIST_H

#include <string>
#include <stdexcept>
#include Playlist.h
#include LinkedPlayList.h
#include PlaylistPtr.h
class MasterPlayList{
private:
    int *arrayOfPlayList;
    int currItemCount;
    int currCapacity;
    PlaylistPointer* playlistPtr;
public:
    MasterPlayList(int intialCapacity);
    MasterPlayList(const MasterPlayList& arrayListToCopy);
    ~MasterPlayList();
    std::string getPlaylist();
    void addPlayList();
    void addPlayListAt(int index);
    std::string removePlayList();
    std::string findPlaylist();
    bool isEmpty();
};
#endif //INC_220_DJ_PROJECT_MASTERPLAYLIST_H
