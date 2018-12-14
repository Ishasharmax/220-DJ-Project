//
// Created by Isha Sharma on 12/13/18.
//

#include <string>
#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include<string.h>
using namespace std;

InterFace::InterFace(){
    allPlaylists= new PlayListMap();
    library= new libraryList("Library");
}

void InterFace::NewPlaylist(string name){
    cout<<"Make New Playlist\n";
    List* playlist= new Playlist(name);
    listOfPlaylist->put(*playlist);
    cout<<"New Playlist made: " + name + "\n";
}

void InterFace::playNext(string name){
    cout<<"Play Next Song in Playlist\n";
    if(listOfPlaylist->get(name)->isEmpty()==true){
        listOfPlaylist->removePlayList(name);
        cout << "Playlist " + name + " is removed!" << endl;
    }
    else {

        Song song = listOfPlaylist->get(name)->playNextSong();
        lib->getSong(song.getTitle())->playSong();
        cout << "Song Removed: " + song.getTitle() + " " + song.getArtist() + " " +
                std::to_string(song.getDuration()) << std::endl;
        if (listOfPlaylist->get(name)->isEmpty() == true) {
            listOfPlaylist->removePlayList(name);
            std::string str= name+".dat";
            char *cstr = new char[str.length() + 1];
            strcpy(cstr, str.c_str());
            if( remove( cstr ) != 0 ) {
                perror("Error deleting file");
            }
            else {
                puts("File successfully deleted");
            }
            std::cout << "Playlist " + name + " is removed!" << std::endl;
        }
    }
}

void InterFace::addSongToPlaylist(string playList, string songName, string artist){
    try {
        listOfPlaylist->get(playList);
        List* p1=listOfPlaylist->get(playList);
        Song* song=lib->getSong(title);
        p1->addSongToEnd(*song);
        listOfPlaylist->put(*p1);
        cout<<"Song"<< songName<< "by" << artist << "is added to"<< playList;
    }
    catch (std::invalid_argument &e) {
        ("Song not found");
        cout<<"Song not found\n";
    }
}

std::string InterFace::displayLibrary(){
    std::cout<<"Display Library\n";
    return library->display();
}

void InterFace::neWRandomPlayList(std::string name, int duration){
    std::cout<<"Make New Random Playlist\n";

    int tries=0;
    List* p1= new RandomPlaylist(name, duration);
    while(p1->getDuration()<duration && tries<3){
        Song songToAdd= lib->randomSong();
        tries=p1->fillRP(p1, duration, songToAdd, tries);
        p1->calcDuration();
    }

    listOfPlaylist->put(*p1);
    std::cout<<"New Random Playlist made: " + name + "\n";
}

std::string InterFace::diplayPlaylist(std::string name){
    std::cout<<"Display Playlist\n";

    try {
        listOfPlaylist->get(name);
        return name + ": "+ listOfPlaylist->get(name)->display();

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        return "Sorry Playlist does not exsist";
    }
}

std::string InterFace::displayAllPlaylist(){
    std::cout<<"Display All Playlist\n";
    return listOfPlaylist->display();
}

void InterFace::addSongToLibrary(std::string artist, std::string song, int duration){
    std::cout<<"Add Song to Library\n";
    Song newSong = Song(artist, song,duration);

    lib->addSongToEnd(newSong);
    Song* testSong=lib->getSong(song);
    std::cout<<"Added " + testSong->getTitle() + " by "+ testSong->getArtist() + " with a duration of "+ std::to_string(testSong->getDuration()) + " to library\n";
}

std::string InterFace::removeSong(std::string name){
    std::cout<<"Remove Song\n";

    try {
        lib->getSong(name)->getTitle();
        Song* song = lib->getSong(name);
        lib->goThroughList(name);

        listOfPlaylist->goThrough(name);
        return "Song Removed: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration());

    }
    catch (std::invalid_argument &e) {

        ("Song is not in Library");
        return "Song is not in Library";
    }
}

void InterFace::removeSongFromPlaylist(std::string name, std::string artist, std::string title){
    std::cout<<"Remove Song From Playlist \n";

    bool isValid=true;
    try {
        listOfPlaylist->get(name);


    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout<<"Sorry Playlist does not exist :p \n";
        isValid=false;

    }

    if(isValid==true){
        try {
            listOfPlaylist->get(name)->getSong(title).getTitle();
            Song* song = lib->getSong(title);
            listOfPlaylist->get(name)->goThroughList(title);
            std::cout<< "Song Removed: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration()) + "\n";

        }
        catch (std::invalid_argument &e) {

            ("Song is not in Library");
            std::cout<<"Song is not in Playlist :/ \n";
        }
    }
}

std::string InterFace::displayArtist(std::string artist) {
    std::cout<<"Display Artist \n";
    return lib->displayArtist(artist);

}

std::string InterFace::displaySong(string trackName){
    cout<<"Song info\n";
    Song* songInfo=lib->getSong(trackName);
    string songName=songInfo->getTitle();
    string artist=songInfo->getArtist();
    double songDuration=songInfo->getDuration();
    int songPlayCount=songInfo->getPlayCount();

    return "Song Name: "<< songName << "\n"<< "Artist: " << artist << "\n"<< "Duration: " << to_string(songDuration) << "\n"<< " seconds  PlayCount: " + to_string(songPlayCount) << "\n";
}

void InterFace::saveFile() {
    listOfPlaylist->savePlaylist();
    lib->saveSongs();
}


void InterFace::import(string fileName) {
    ifstream infile(fileName);
    if (infile.fail()) {
        cout << "Unable to open file "<< filename<<endl;
    }
    else {
        while (infile) {
            for(int i=0;i<4; i++) {
                string songName, artist, duration, songPlayCount;
                int song_duration=0;
                int played=0;
                getline(infile, songName);
                getline(infile, artist);
                getline(infile,duration);
                stringstream songTime(duration);
                songTime>>song_duration;
                getline(infile,songPlayCount);
                stringstream count(playcount);
                count>>played;
                try {
                    library->getSong(title)->getTitle();
                    cout<<"Song is in the library already.\n";
                }
                catch (std::invalid_argument &e) {
                    ("New song");
                    if(artist != "" ) {
                        Song songToAdd(songName, artist, song_duration);
                        cout << songToAdd.getArtist() << ", " + songToAdd.getTitle() << ", " + std::to_string(songToAdd.getDuration()) << "\n";
                        library->addSongToEnd(songToAdd);
                        library->getSong(songToAdd.getTitle())->setPlaycount(played);
                    }
                }
            }
        }
        std::cout<<"Library is updated \n";
    }


    void InterFace::startingImport(){
        ifstream infile;
        infile.open("Playlist.dat");
        if (infile.fail()) {
            cout << "Playlist can't be opened" << endl;
        }
        while (infile) {
            string playList;
            getline(infile, playList);
            if (playList != "") {
                ifstream newPlayList;
                string newX=newPlayList+".dat";
                newPlayList.open(newX);
                if (!newPlayList) {
                    cout << "playlist couldn't be opened" << endl;
                    exit(1);
                }
                while (newPlayList) {
                    for (int i = 0; i < 3; i++) {
                        string artist, songName, duration;
                        int song_duration=0;
                        getline(newPlayList, artist);
                        getline(newPlayList, songName);
                        getline(newPlayList, duration);
                        stringstream songTime(duration);
                        songTime>>song_duration;
                        if (artist != "") {
                            Song song(songName, artist, song_duration);
                            cout << song.getArtist() + ", " + song.getTitle() + ", " + std::to_string(song.getDuration()) + "\n";
                            listOfPlaylist->get(playlist)->addSongToEnd(song);
                        }
                    }
                }
            }
        }
        cout<<"Playlist updated\n";
    }


    void InterFace::removePlaylist(string name) {
        try {
            listOfPlaylist->get(name);
            listOfPlaylist->removePlayList(name);
            std::string str= name+".dat";
            char *cstr = new char[str.length() + 1];
            strcpy(cstr, str.c_str());
            if( remove( cstr ) != 0 ) {
                perror("Error deleting file");
            }
            else {
                puts("File successfully deleted");
            }
            std::cout << "Playlist " + name + " is removed!" << std::endl;
        }
        catch (std::invalid_argument &e) {
            //printAssertEquals("PlayList is not present", e.what());
            ("PlayList is not present");
            std::cout<<"Sorry Playlist does not exsist";
        }
    }


    void InterFace::discontinue(string fileForUse){
        ifstream infile(fileForUse);
        if (infile.fail()){
            cout << "file cant be opened."<< endl;
        }
        while (infile) {
            for(int i=0;i<4; i++) {
                string songName, artist, duration;
                double song_duration=0;
                int played=0;
                getline(infile, songName);
                getline(infile, artist);
                getline(infile, duration);
                stringstream (duration);
                stringstream songTime(duration);
                songTime>>song_duration;
                getline(infile,songPlayCount);
                stringstream count(playcount);
                count>>played;
                if(artist != "") {
                    Song song(artist, songName, song_duration);
                    cout<<this->removeSong(songName) + "\n";
                }
            }
        }
    }


    int main(){
        string choice;
        InterFace newUserInterface= InterFace();
        newUserInterface.startingImport();
        newUserInterface.import("hello.dat");

        cout << "\n***************************************************\n"
                "*                                                 *\n"
                "*             Playlist Manager                    *\n"
                "*                                                 *\n"
                "***************************************************\n";
        cout << "Where would you like to start? \n\n"
                "1. Import a Song from library to playlist\n"
                "2. Remove a song from song list\n"
                "3. Remove a song from playlist\n"
                "4. Song Information\n"
                "5. Import song to the library from a file\n"
                "5. Import song to the library from a playlist\n"
                "6. Add New Playlist\n"
                "7. Play a Playlist\n"
                "8. Make random Playlist\n"
                "9. Add song in a Playlist\n"
                "10. Remove song in a Playlist\n"
                "11. View all Playlists \n"
                "12. View a Playlist \n"
                "13. Play Next song in playlist\n"
                "14. Artist's work\n"
                "15. Help \n"
                "16. Discontinue \n"
                "17. Library \n"
                "18. Exit\n\n"
                "Enter Your Choice: ";
        cin>>choice;
        getline(cin,choice);
        while(choice!="18"){

            if(choice=="1"){
                cout<<"Please enter Playlist/RandomPlaylist name: ";
                string name;
                getline(std::cin, name);
                cout<<"Please enter Song title: ";
                string title;
                getline(std::cin, title);
                cout<<"Please enter Song artist: ";
                string artist;
                getline(std::cin, artist);
                ui.removeSongFromPlaylist(name,artist,title);
            }
            else if(choice=="2"){
                string fileName;
                cout<<"Please enter file name: ";
                getline(std::cin,fileName);
                ui.discontinue(fileName);
            }
            else if(choice=="3"){
                std::cout<<"Please enter Song name: ";
                std::string songTitle;
                std::getline(std::cin, songTitle);
                std::cout<<"Please enter Artist: ";
                std::string artist;
                std::getline(std::cin,artist);
                std::cout<<ui.displaySong(songTitle,artist) + "\n";
            }
            else if(choice=="4"){
                std::cout<<newUserInterface.displayLibrary() + "\n";
            }
            else if(choice=="5"){
                cout<<"Please enter Playlist, Song to add, and Artist \n";
                std::string song;
                std::string playlist;
                std::string artist;
                cout<<"Please Enter Song: \n";
                std::getline(std::cin,song);
                cout<<"Please Enter Artist: \n";
                std::getline(std::cin,artist);
                cout<<"Please Enter Playlist: \n";
                std::getline(std::cin,playlist);
                ui.add(playlist,artist,song);
            }
            else if(choice=="6"){
                string song;
                cout<<"Please enter song to remove from Playlist(s) and library: \n";
                getline(cin,song);
                cout<<ui.removeSong(song) + "\n";
            }
            else if(choice=="7"){
                std::cout<<"Please enter new Playlist name: ";
                std::string playListName;
                std::getline(std::cin, playListName);
                ui.neW(playListName);
                std::cout<<"Playlist " + playListName + " made";
            }
            else if(choice=="8"){
                std::cout << "Please enter Artist name: ";
                std::string artist;
                std::getline(std::cin, artist);
                std::cout<<ui.displayArtist(artist) +"\n";
            }
            else if(choice=="9"){
                std::cout<<"Please enter new Random Playlist name: ";
                std::string randPlayListName;
                std::getline(std::cin, randPlayListName);
                std::cout<<"Please enter new Random Playlist duration: ";
                std::string duration;
                std::getline(std::cin,duration);
                std::stringstream geek(duration);
                int x=0;
                geek>>x;
                ui.neWRandomPlayList(randPlayListName,x);
            }
            else if(choice=="10"){
                string playlist;
                cout<<"Name of the playlist: ";
                getline(cin,playlist);
                cout<<ui.diplayPlaylist(playlist) + "\n";
            }

            else if(choice=="11"){
                cout<<"Please enter Song to add, Artist, and Duration \n";
                string song;
                string duration;
                string artist;
                cout<<"Please Enter Song: \n";
                getline(std::cin,song);
                cout<<"Please Enter Artist: \n";
                getline(std::cin,artist);
                cout<<"Please Enter Duration(seconds): \n";
                getline(std::cin,duration);
                stringstream geek(duration);
                int x=0;
                geek>>x;
                ui.addSongToLibrary(artist,song,x);
            }
            else if(choice=="12") {
                cout << "Please enter Playlist name: ";
                string playlist;
                getline(std::cin, playlist);
                ui.playNext(playlist);
            }
            else if(choice=="13"){
                std::cout<<ui.displayAllPlaylist() + "\n";
            }
            else if(choice=="14"){
                cout<<"No information in the file\n";
            }
            else if(choice=="15"){
                string name;
                cout<<"Please enter Playlist name: ";
                getline(std::cin, name);
                ui.removePlaylist(name);
            }else if(choice=="16"){
                string file;
                cout<<"Please enter file name: ";
                getline(std::cin, file);
                ui.import(file);
            }

            cout << "Where would you like to start? \n\n"
                    "1. Import a Song from library to playlist\n"
                    "2. Remove a song from song list\n"
                    "3. Remove a song from playlist\n"
                    "4. Song Information\n"
                    "5. Import song to the library from a file\n"
                    "5. Import song to the library from a playlist\n"
                    "6. Add New Playlist\n"
                    "7. Play a Playlist\n"
                    "8. Make random Playlist\n"
                    "9. Add song in a Playlist\n"
                    "10. Remove song in a Playlist\n"
                    "11. View all Playlists \n"
                    "12. View a Playlist \n"
                    "13. Play Next song in playlist\n"
                    "14. Artist's work\n"
                    "15. Help \n"
                    "16. Discontinue \n"
                    "17. Library \n"
                    "18. Exit\n\n"
                    "Enter Your Choice: ";
            cin>>choice;
            getline(cin,choice);
            if(choice=="17"){
                newUserInterface.saveFile();
            }
        }
        return 0;
    }
