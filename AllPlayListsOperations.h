//
// Created by Isha Sharma on 12/15/18.
//

#ifndef INC_220_DJ_PROJECT_ALLPLAYLISTSOPERATIONS_H
#define INC_220_DJ_PROJECT_ALLPLAYLISTSOPERATIONS_H

class AllPlayListsOperations {
public:
    virtual ~AllPlayListsOperations(){}

    virtual float calcPlayListDuration()=0;

    virtual Song getSong(std::string title)=0;

    virtual void addSongAtEnd(std::string artist, std::string songName, float duration)=0;

    virtual std::string displayEverything()=0;

    virtual bool isEmpty()=0;

    virtual std::string nextSong()=0; //Song Data Type?

    virtual void saveSongs(std::string fileName)=0;

    //virtual void addSongAt(int index,std::string artist, std::string songName, float duration)=0;

    //virtual std::string removeSongAt(int index)=0;

    //virtual std::string search(std::string item)=0;


    //virtual std::string removeSongAtEnd()=0;

    //virtual std::string getAllSongs()=0;

    //virtual std::string getHelp()=0;

    //virtual int getSongCount()=0;

    //virtual std::string previousSong()=0;

    //virtual int getPlayCount(std::string song)=0;

    //virtual void replay()=0;
};

#endif //INC_220_DJ_PROJECT_ALLPLAYLISTSOPERATIONS_H
