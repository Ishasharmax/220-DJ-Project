//
// Created by Joel Jerez on 11/29/18.
//

#ifndef INC_220_DJ_PROJECT_SONG_H
#define INC_220_DJ_PROJECT_SONG_H

#include <string>

class Song{
private:
    std::string title;
    std::string artist;
    float songLength;
    int playcount;

public:
    Song();

    Song( std::string titleIn, std::string artistIn, float songLengthIn);

    Song(const Song& songToCopy);

    Song& operator=(const Song& songToCopy);
    void addToPlayCount();

    std::string getTitle();

    std::string getArtist();

    float getSongLength();

    int getPlayCount();
};

#endif //INC_220_DJ_PROJECT_SONG_H
