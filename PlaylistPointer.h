//
// Created by Joel Jerez on 12/14/18.
//

#include "LinkedPlayList.h"

#ifndef INC_220_DJ_PROJECT_PLAYLISTPOINTER_H
#define INC_220_DJ_PROJECT_PLAYLISTPOINTER_H



class PlaylistPointer{
private:
    LinkedPlayList* playlist;


public:
    PlaylistPointer(LinkedPlayList* PlaylistIN);

    ~PlaylistPointer();

    PlaylistPointer(const PlaylistPointer& ptrToCopy);

    PlaylistPointer& operator=(const PlaylistPointer& ptrToCopy);

    LinkedPlayList getPlaylist();

    void setPlaylist(LinkedPlayList* newPlaylist);

};

#endif //INC_220_DJ_PROJECT_PLAYLISTPOINTER_H
