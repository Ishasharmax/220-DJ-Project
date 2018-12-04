//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_PLAYLIST_H
#define INC_220_DJ_PROJECT_PLAYLIST_H

#include <string>
class PlayList {
public:
    virtual ~PlayList(){}

    virtual std::string search(std::string item)=0;
    virtual std::string getHelp()=0;
    virtual void addSong(std::string artist, std::string songName, float duration)=0;
};
#endif //INC_220_DJ_PROJECT_PLAYLIST_H
