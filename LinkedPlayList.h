//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#define INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
#include <string>
#include <stdexcept>
#include "PlayList.h"

class LinkedPlayList {
private:
    PlayListNode *front;
    PlayListNode *end;
public:
    LinkedPlayList();

    LinkedPlayList(const LinkedPlayList &playListToCopy);

    LinkedPlayList &operator=(const LinkedPlayList &playListToCopy);

    ~LinkedPlayList();

    std::string search(std::string item);

    void addSong(std::string artist, std::string songName, float duration);

    std::string getHelp();

    float calcPlayListDuartion();
};
#endif //INC_220_DJ_PROJECT_LINKEDPLAYLIST_H
