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
<<<<<<< HEAD
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
=======
<<<<<<< HEAD
    MasterSongList(int initialCapacity);
=======
>>>>>>> b5a31536da121e1342383b6584e7575675ecaebf
    std::string nameOftheList;
    MasterSongList(int initialCapacity, std::string nameOftheList);
>>>>>>> 59d064f2ba0d474780a6c57c788c5052ec6760bf
    ~MasterSongList(); //creates an array
    MasterSongList(const MasterSongList& songToCopy); //only copies item, next is set to nullptr
    MasterSongList& operator=(const MasterSongList& queueToCopy);
    void removeSong(int index); //removes song from array
    void importSong(Song songToAdd, int index); //imports a file to array
    void doubleCapacity();
    std::string toString();
    void removeValueAtEnd();
    void insertAtEnd(Song songToAdd);
    int itemCount();
    bool isEmpty();
    int getValueAt(int index);
};

#endif //INC_220_DJ_PROJECT_MASTERSONGLIST_H
