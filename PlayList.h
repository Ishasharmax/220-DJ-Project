//
// Created by KandacePC on 11/29/2018.
//

#ifndef INC_220_DJ_PROJECT_PLAYLIST_H
#define INC_220_DJ_PROJECT_PLAYLIST_H

#include <string>
#include <stdexcept>
#include "Song.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


class PlayList {
public:

    virtual ~PlayList(){}


    virtual float calcPlayListDuration()=0;

    virtual std::string search(std::string item)=0;

    virtual void addSongAtEnd(std::string artist, std::string songName, float duration)=0;

    virtual void addSongAt(int index,std::string artist, std::string songName, float duration)=0;

    virtual std::string removeSongAt(int index)=0;

    virtual std::string removeSongAtEnd()=0;

    virtual std::string getAllSongs()=0;

    virtual int getSongCount()=0;

    virtual bool isEmpty()=0;

    virtual std::string nextSong()=0;

    virtual std::string previousSong()=0;

    virtual int getPlayCount(std::string songName)=0;

    virtual void replay()=0;

    virtual void saveThePlayList()=0;

    virtual void clearList()=0;

    virtual std::string displayArtist(std::string artist)=0;
};
#endif //INC_220_DJ_PROJECT_PLAYLIST_H
