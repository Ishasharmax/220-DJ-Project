//
// Created by Isha Sharma on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_MASTERSONGLIST_H
#define INC_220_DJ_PROJECT_MASTERSONGLIST_H

#include "SongList.h"


class MasterSongList {
private:
    PlaylistNode *Array;
public:
    MasterSongList();
    ~MasterSongList(); //creates an array
    MasterSongList(const MasterSongList& songToCopy); //only copies item, next is set to nullptr
    MasterSongList& operator=(const MasterSongList& queueToCopy);
    void removeSong(Song songs); //removes song from array
    void importSong (); //imports a file to array
};

#endif //INC_220_DJ_PROJECT_MASTERSONGLIST_H
