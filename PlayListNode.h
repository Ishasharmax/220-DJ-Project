//
// Created by Joel Jerez on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_PLAYLISTNODE_H
#define INC_220_DJ_PROJECT_PLAYLISTNODE_H


#include <string>
#include "Song.h"

class PlayListNode{
private:
    Song* song;
    PlayListNode* next= nullptr;

public:

    PlayListNode(Song* songIN);

    ~PlayListNode();

    PlayListNode(const PlayListNode& nodeToCopy);

    PlayListNode&operator=(const PlayListNode& nodeToCopy);

    Song getSong();

    PlayListNode* getNext();

    void setNext(PlayListNode* newNode);

    void setSong(Song newSong);

};




#endif //INC_220_DJ_PROJECT_PLAYLISTNODE_H
