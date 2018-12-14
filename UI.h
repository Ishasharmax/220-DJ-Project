//
// Created by KandacePC on 12/14/2018.
//

#ifndef INC_220_DJ_PROJECT_USERINTERFACE_H
#define INC_220_DJ_PROJECT_USERINTERFACE_H

#include "Map.h"
#include "PlayListMap.h"
#include "List.h"
#include "libraryList.h"


class InterFace{
private:
    PlayListMap* listOfPlaylist;
    libraryList* lib;


public:
    InterFace();
    void neW(std::string name);
    void add(std::string name, std::string artist, std::string title);
    void playNext(std::string name);
    void neWRandomPlayList(std::string name, int duration);
    std::string displayLibrary();
    std::string diplayPlaylist(std::string name);
    std::string displayAllPlaylist();
    std::string removeSong(std::string name);
    void addSongToLibrary(std::string artist, std::string song, int duration);
    std::string displayArtist(std::string artist);
    std::string displaySong(std::string title, std::string artist);
    void removeSongFromPlaylist(std::string name, std::string artist, std::string title);
    void saveFile();
    void import(std::string fileName);
    void startingImport();
    void removePlaylist(std::string name);
    void discontinue(std::string fileName);
};


#endif //INC_220_DJ_PROJECT_USERINTERFACE_H
