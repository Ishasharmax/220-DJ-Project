//
// Created by Joel Jerez on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_PLAYLISTNODE_H
#define INC_220_DJ_PROJECT_PLAYLISTNODE_H


#include <string>
#include "Song.h"

class LinkedPlayListNode{
private:
    Song* song;
    LinkedPlayListNode* next= nullptr;

public:

    LinkedPlayListNode(Song* songIN);

    ~LinkedPlayListNode();

    LinkedPlayListNode(const LinkedPlayListNode& nodeToCopy);

    LinkedPlayListNode& operator=(const LinkedPlayListNode& nodeToCopy);

    Song getSong();

    LinkedPlayListNode* getNext();

    void setNext(LinkedPlayListNode* newNode);

    void setSong(Song newSong);
};




#endif //INC_220_DJ_PROJECT_PLAYLISTNODE_H
