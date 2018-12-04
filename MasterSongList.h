//
// Created by Isha Sharma on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_MASTERSONGLIST_H
#define INC_220_DJ_PROJECT_MASTERSONGLIST_H

#include "PlayListNode.h"
#include "Song.h"
#include <iostream>
#include<string.h>

class MasterSongList {
private:
    Song *songPtr;
    PlayListNode *songArray;
    int currItemCount;
    int currCapacity;

public:
    MasterSongList(int initialCapacity);
    ~MasterSongList(); //creates an array
    MasterSongList(const MasterSongList& songToCopy); //only copies item, next is set to nullptr
    MasterSongList& operator=(const MasterSongList& queueToCopy);
    void removeSong(Song songToRemove); //removes song from array
    void importSong(Song songToAdd, int index); //imports a file to array
    void doubleCapacity();

    };

#endif //INC_220_DJ_PROJECT_MASTERSONGLIST_H
