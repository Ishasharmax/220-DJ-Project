//
// Created by Isha Sharma on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_MASTERSONGLIST_H
#define INC_220_DJ_PROJECT_MASTERSONGLIST_H

#include "LinkedPlayListNode.h"
#include "Song.h"
#include <iostream>
#include<string.h>
#include "SongLib.h"

class MasterSongList {
private:
    Song *arraySong;
    int currItemCount;
    int currCapacity;

public:
    MasterSongList(int initialCapacity, std::string nameOftheList);
    ~MasterSongList(); //creates an array
    MasterSongList(const MasterSongList& songToCopy); //only copies item, next is set to nullptr
    MasterSongList& operator=(const MasterSongList& queueToCopy);
    void removeSong(int index); //removes song from array
    void importSong(Song songToAdd, int index); //imports a file to array
    void doubleCapacity();
    std::string toString();
    void removeValueAtEnd();
    void insertAtEnd(Song songToAdd);
    bool isEmpty();
    int getValueAt(Song songToAdd);
};

#endif //INC_220_DJ_PROJECT_MASTERSONGLIST_H
