//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#define INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#include <string>
#include <stdexcept>
#include "PlayList.h"
#include "PlayListNode.h"

class LinkedPlayList {
private:
    PlayListNode *front;
    PlayListNode *end;
    PlayListNode *current;
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

    std::string removeSongAt(int removeIndex);

    std::string removeSongAtEnd();

    std::string getAllSongs();

    std::string getHelp();

    int getSongCount();
    bool isEmpty();
};
#endif //INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
