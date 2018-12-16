//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#define INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#include <string>
#include <stdexcept>
#include "PlayList.h"
#include "LinkedPlayListNode.h"
#include "Song.h"

class LinkedPlayList : PlayList {
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

    float calcPlayListDuration();

    void addSongAtEnd(std::string artist, std::string songName, float duration);

    void addSongAt(int index,std::string artist, std::string songName, float duration);

    std::string removeSongAt(int index);

    std::string removeSongAtEnd();

    std::string getAllSongs();

    std::string getHelp();

    int getSongCount();

    bool isEmpty();

    std::string nextSong();

    std::string previousSong();

    int getPlayCount(std::string song);

    void replay();

    void saveThePlayList();

    Song getSong(std::string songName);

    void clearList();

    std::string displayArtist(std::string artist);

};
#endif //INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
