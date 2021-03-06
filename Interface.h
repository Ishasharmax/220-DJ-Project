//
// Created by Isha Sharma on 12/11/18.
//
//

#ifndef INC_220_DJ_PROJECT_INTERFACE_H
#define INC_220_DJ_PROJECT_INTERFACE_H

#include "MasterSongList.h"
#include "LinkedPlayList.h"
#include "PlayList.h"

class Interface{
private:
    LinkedPlayList* playLists;

    /*libraryList* lib;*/

    /*PlayListMap* listOfPlaylist;
    libraryList* lib;*/

public:
    Interface();
    void importX(std::string fileToUse);
    void newPlaylist(std::string name);
    void addSong(std::string playList, std::string songName, std::string artist, float songDuration);
    void playNextSong(std::string name);
    //void createRandomPlaylist(std::string name, int duration);
    void createRandomPlaylist(std::string name);

    std::string fullLibrary();
    std::string viewPlaylist(std::string name);
    std::string viewAllPlaylist();
    std::string removeSong(std::string name);
    void addSongToLibrary(std::string artist, std::string song, int duration);
    std::string artistWork(std::string artist);
    std::string viewSong(std::string trackName);
    void removeSongFromPlaylist(std::string name, std::string artist, std::string title);
    void saveFile();
    void importSongs();
    void removeAPlaylist(std::string name);
    void discontinue(std::string fileName);
};
#endif //INC_220_DJ_PROJECT_INTERFACE_H
