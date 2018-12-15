//
// Created by Isha Sharma on 12/11/18.
//
//

#ifndef INC_220_DJ_PROJECT_INTERFACE_H
#define INC_220_DJ_PROJECT_INTERFACE_H

#include "MasterSongList.h"
#include "LinkedPlayList.h"

class UserInterFace{
private:
    MasterPlayListMap* arrayOfPlaylist;
    libraryList* lib;

public:
    interfaceMain();
    void import(std::string fileToUse);
    void newPlaylist(std::string name);
    void addSong(std::string name, std::string artist, std::string title);
    void playNextSong(std::string name);
    void createRandomPlaylist(std::string name, int duration);
    std::string fullLibrary();
    std::string viewPlaylist(std::string name);
    std::string viewAllPlaylist();
    std::string removeaSong(std::string name);
    void addSongtoFile(std::string artist, std::string song, int duration);
    std::string artistWork(std::string artist);
    std::string viewSong(std::string title, std::string artist);
    void removeSongFromPlaylist(std::string name, std::string artist, std::string title);
    void saveFile();
    void importSongs();
    void removeAPlaylist(std::string name);
    void discontinue(std::string fileName);
};
#endif //INC_220_DJ_PROJECT_INTERFACE_H
