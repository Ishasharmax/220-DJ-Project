//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#define INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#include <string>
#include <stdexcept>
#include "LinkedPlayListNode.h"
#include "Song.h"
#include "PlayList.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

class LinkedPlayList:PlayList  {
private:
    LinkedPlayListNode *front;
    LinkedPlayListNode *end;
    LinkedPlayListNode *current;
    int currItems;
public:
    LinkedPlayList();

    LinkedPlayList(const LinkedPlayList &playListToCopy);

    LinkedPlayList &operator=(const LinkedPlayList &playListToCopy);

    ~LinkedPlayList();

    std::string search(std::string item);

    float calcPlayListDuration() ;

    void addSongAtEnd(std::string artist, std::string songName, float duration);
    void addSongAt(int index,std::string artist, std::string songName, float duration);

    std::string removeSongAt(int index);

    std::string removeSongAtEnd();

    std::string getAllSongs();

    int getSongCount();

    bool isEmpty();

    std::string nextSong();

    std::string previousSong();

    int getPlayCount(std::string songName);

    void replay();

    void saveThePlayList();

    void clearList();

    std::string displayArtist(std::string artist);


};
#endif //INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
