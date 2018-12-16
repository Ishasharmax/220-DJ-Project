//
// Created by Isha Sharma on 12/10/18.
//

#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <string.h>
#include "Interface.h"
#include "Song.h"
#include "MasterSongList.h"
#include "LinkedPlayList.h"
#include "LinkedPlayListNode.h"

Interface::Interface(){
    int initialCapacity;
    playLists= new LinkedPlayList();
    songList= new MasterSongList(initialCapacity ,"Library");
}

void Interface::newPlaylist(string name){
    cout<<"Make New Playlist\n";
    MasterPlayList* playlist1= new Playlist(name);
    playLists->put(*playlist1);
    cout<<"New Playlist made: " + name + "\n";
}

void Interface::playNextSong(string name){
    if(playLists->playListName(name)->isEmpty()==true){//masterLinkedList needed with the naem of the playlist
        playLists->removePlayList(name);
        cout << "Playlist " + name + " is removed!" << endl;
    }
    else {
        Song song = playLists->get(name)->playNextSong();
        lib->getSong(song.getTitle())->playSong();
        cout << "Song Removed: " + song.getTitle() + " " + song.getArtist() + " " +
                std::to_string(song.getDuration()) << std::endl;
        if (playLists->get(name)->isEmpty() == true) {
            playLists->removePlayList(name);
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

void Interface::addSong(string playList, string songName, string artist){
    try {
        playLists->get(playList);  //mastrePlayListNeeded
        List* p1=playLists->get(playList);     //mastrePlayListNeeded
        Song* song=lib->getSong(title);
        p1->addSongToEnd(*song);
        playLists->put(*p1);
        cout<<"Song "<< songName<< " by " << artist << " is added to "<< playList;
    }
    catch (std::invalid_argument &e) {
        ("Song not found");
        cout<<"Song not found\n";
    }
}

std::string Interface::fullLibrary(){
    std::cout<<"Display Library\n";
    return library->display();
}

void Interface::createRandomPlaylist(std::string name){
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

string Interface::viewPlaylist(string name){
    try {
        playLists->get(name);
        return name + ": "+ playLists->get(name)->display();
    }
    catch (std::invalid_argument &e) {
        ("PlayList is not present");
        return "Sorry Playlist does not exsist";
    }
}

std::string Interface::viewAllPlaylist(){
    std::cout<<"Display All Playlist\n";
    return playLists->display();
}

void Interface::addSongToLibrary(std::string artist, std::string song, int duration){
    std::cout<<"Add Song to Library\n";
    Song newSong = Song(artist, song,duration);

    lib->addSongToEnd(newSong);
    Song* testSong=lib->getSong(song);
    std::cout<<"Added " + testSong->getTitle() + " by "+ testSong->getArtist() + " with a duration of "+ std::to_string(testSong->getDuration()) + " to library\n";
}

std::string Interface::removeSong(std::string name){
    std::cout<<"Remove Song\n";
    try {
        playLists->getSong(name).getTitle();
        Song* song = lib->getSong(name);
        lib->goThroughList(name);

        playLists->goThrough(name);
        return "Song Removed: " + song.getTitle() + ", " + song.getArtist() + ", " + std::to_string(song.getSongLength());
    }
    catch (std::invalid_argument &e) {

        ("Song is not in Library");
        return "Song is not in Library";
    }
}

void Interface::removeSongFromPlaylist(string artistName, string songName, string playListName){
    bool playListpresent=true;
    try {
        playLists->get(name);
    }
    catch (std::invalid_argument &e) {
        ("There is no playlist");
        cout<<"There is no playlist named "<<playListName;
        playListpresent=false;
    }
    if(playListpresent==true){
        try {
            playLists->get(name)->getSong(title).getTitle();
            Song* song = lib->getSong(title);
            playLists->get(name)->goThroughList(title);
            cout<< "Song successfully: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration()) + "\n";
        }
        catch (std::invalid_argument &e) {
            ("Song is not in Library");
            std::cout<<"Song is not in Playlist :/ \n";
        }
    }
}

string Interface::artistWork(string artistName) {
    return playLists->displayArtist(artistName);
}//done

std::string Interface::viewSong(string trackName){
    cout<<"Song info\n";
    Song songInfo=playLists->getSong(trackName);
    string songName=songInfo.getTitle();
    string artist=songInfo.getArtist();
    double songDuration=songInfo.getSongLength();
    int songPlayCount=songInfo.getPlayCount();

    return "Song Name: "+songName +"\n"+"Artist: " + artist +"\n"+"Duration: " + to_string(songDuration) + "\n"+ " seconds  PlayCount: " + to_string(songPlayCount) + "\n";
}//done

void Interface::saveFile() {
    playLists->saveThePlayList();
    //library->saveSongs();
}//done


void Interface::importX(string fileName) {
    ifstream infile(fileName);
    if (infile.fail()) {
        cout << "Unable to open file " << fileName << endl;
    } else {
        while (infile) {
            for (int i = 0; i < 4; i++) {
                string songName, artist, duration, songPlayCount;
                int song_duration = 0;
                int played = 0;
                getline(infile, songName);
                getline(infile, artist);
                getline(infile, duration);
                stringstream songTime(duration);
                songTime >> song_duration;
                getline(infile, songPlayCount);
                stringstream count(playcount);
                count >> played;
                try {
                    library->getSong(title)->getTitle();
                    cout << "Song is in the library already.\n";
                }
                catch (std::invalid_argument &e) {
                    ("New song");
                    if (artist != "") {
                        Song songToAdd(songName, artist, song_duration);
                        cout << songToAdd.getArtist() << ", " + songToAdd.getTitle()
                             << ", " + std::to_string(songToAdd.getDuration()) << "\n";
                        library->addSongToEnd(songToAdd);
                        library->getSong(songToAdd.getTitle())->setPlaycount(played);
                    }
                }
            }
        }
        std::cout << "Library is updated \n";
    }
}


void Interface::importSongs() {
    ifstream infile;
    infile.open("sampleLibrary.txt");
    if (infile.fail()) {
        cout << "Unable to open file";
    } else {
        while (infile) {
            string playList;
            getline(infile, playList);
            if (playList != "") {
                ifstream newPlayList;
                string newX = newPlayList + ".txt";
                newPlayList.open(newX);
                if (!newPlayList) {
                    cout << "playlist couldn't be opened" << endl;
                    exit(1);
                }
                while (newPlayList) {
                    for (int i = 0; i < 3; i++) {
                        string artist, songName, duration;
                        int song_duration = 0;
                        getline(newPlayList, artist);
                        getline(newPlayList, songName);
                        if (artist != "") {
                            Song song(songName, artist, song_duration);
                            cout << song.getArtist() + ", " + song.getTitle() + ", " +
                                    std::to_string(song.getDuration()) +
                                    "\n";
                            playLists->get(playlist)->addSongToEnd(song);
                        }
                    }
                }
            }
        }cout << "Playlist updated\n";
    }
}

void Interface::removeAPlaylist(string playListName) {
    try {
        playLists->get(playListName);
        playLists->removePlayList(playListName);
        std::string str = playListName + ".txt";
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        if (remove(cstr) != 0) {
            perror("Error deleting file");
        } else {
            puts("File deleted");
        }
        std::cout << "Playlist " + playListName + " is removed!" << std::endl;
    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout << "Sorry Playlist does not exsist";
    }
}


void Interface::discontinue(string fileForUse) {
    ifstream infile(fileForUse);
    if (infile.fail()) {
        cout << "file cant be opened." << endl;
    }
    while (infile) {
        for (int i = 0; i < 4; i++) {
            string songName, artist, duration;
            double song_duration = 0;
            int played = 0;
            getline(infile, songName);
            getline(infile, artist);
            getline(infile, duration);
            stringstream (duration);
            stringstream songTime(duration);
            songTime >> song_duration;
            getline(infile, songPlayCount);
            stringstream count(playcount);
            count >> played;
            if (artist != "") {
                Song song(artist, songName, song_duration);
                cout << this->removeSong(songName) + "\n";
            }
        }
    }
}

int main(){
    string fileName, userInput;
    cout << "Enter a file name you want: ";
    getline(cin, fileName);
    ofstream out(fileName);
    out << "Song List\n" << std::endl;
    //add songs, artists and duration

    string choice;
    Interface newUserInterface = Interface();
    newUserInterface.importX("Sample.txt");

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
    cin >> choice;
    getline(cin, choice);

    while (choice != "18") {

        if (choice == "1") {
            string playList, songName, artist;
            cout << "Enter the name of the playlist: ";
            getline(cin, playList);
            cout << "Song name: ";
            getline(cin, songName);
            cout << "Artist: ";
            getline(cin, artist);
            newUserInterface.removeSongFromPlaylist(playList, artist, songName);
        } else if (choice == "2") {
            string fileName;
            cout << "Please enter file name: ";
            getline(std::cin, fileName);
            newUserInterface.discontinue(fileName);
        } else if (choice == "3") {
            std::cout << "Please enter Song name: ";
            std::string songTitle;
            std::getline(std::cin, songTitle);
            std::cout << "Please enter Artist: ";
            std::string artist;
            std::getline(std::cin, artist);
            std::cout << newUserInterface.viewSong(songTitle, artist) + "\n";
        } else if (choice == "4") {
            std::cout << newUserInterface.fullLibrary() + "\n";
        } else if (choice == "5") {
            cout << "Please enter Playlist, Song to add, and Artist \n";
            std::string song;
            std::string playlist;
            std::string artist;
            cout << "Please Enter Song: \n";
            std::getline(std::cin, song);
            cout << "Please Enter Artist: \n";
            std::getline(std::cin, artist);
            cout << "Please Enter Playlist: \n";
            std::getline(std::cin, playlist);
            newUserInterface.addSong(playlist, artist, song);
        } else if (choice == "6") {
            string song;
            cout << "Please enter song to remove from Playlist(s) and library: \n";
            getline(cin, song);
            cout << newUserInterface.removeSong(song) + "\n";
        } else if (choice == "7") {
            cout << "Enter name of new Playlist: ";
            string playListName;
            getline(cin, playListName);
            newUserInterface.newPlaylist(playListName);
            cout << "Playlist " << playListName << " made";
        } else if (choice == "8") {
            std::cout << "Please enter Artist name: ";
            std::string artist;
            std::getline(std::cin, artist);
            std::cout << newUserInterface.artistWork(artist) + "\n";
        } else if (choice == "9") {
            cout << "Name of the new playList: ";
            string playListNew, ;
            std::getline(cin, playListNew);
            newUserInterface.createRandomPlaylist(playListNew);
        } else if (choice == "10") {
            string playlist;
            cout << "Name of the playlist: ";
            getline(cin, playlist);
            cout << newUserInterface.viewPlaylist(playlist) + "\n";
        } else if (choice == "11") {
            string songName, duration, artist;
            int song_duration;
            cout << "Song name: \n";
            getline(std::cin, songName);
            cout << "Artist: \n";
            getline(std::cin, artist);
            cout << "Duration: \n";
            getline(cin, duration);
            stringstream songTime(duration);
            songTime >> song_duration;
            newUserInterface.addSongToLibrary(songName, artist, song_duration);
        } else if (choice == "12") {
            cout << "Please enter Playlist name: ";
            string playlist;
            getline(cin, playlist);
            newUserInterface.playNextSong(playlist);
        } else if (choice == "13") {
            std::cout << newUserInterface.viewAllPlaylist() + "\n";
        } else if (choice == "14") {
            cout << "No information in the file\n";
        } else if (choice == "15") {
            cout << "1. Import Songs\n"
                    "This option lets you to import a song from a file\n"
                    "2. Remove Songs\n"
                    "This option lets you to remove a song from the file\n"
                    "3. Song Information\n"
                    "This option lets you view info about a song\n"
                    "4. Import songs from a file\n"
                    "This option lets you to import a song from a file\n"
                    "5. Add New Playlist\n"
                    "This option lets you to create a new playlist\n"
                    "6. Play a Playlist\n"
                    "This option lets you to play a playlist\n"
                    "7. Remove Playlist\n"
                    "This option lets you to remove a playlist\n"
                    "8. Add song in a Playlist\n"
                    "This option lets you to add a song to a playlist\n"
                    "9. Remove song in a Playlist\n"
                    "This option lets you to remove a song from a playlist\n"
                    "10. View All Playlists \n"
                    "This option lets you view all the playlists present\n"
                    "11. Play Next song\n"
                    "This option allows you to play next song in a playlist\n"
                    "12. Artist's work\n"
                    "This option lets separates the work of an artist and shows you\n"
                    "13. Help \n"
                    "This is the help section\n"
                    "14. Exit\n"
                    "This option lets you to exit the program and saves your file for future use\n";
            cout << "_______________________________________\n\n";

        } else if (choice == "16") {
            string file;
            cout << "Enter file name: ";
            getline(cin, file);
            newUserInterface.importX(file);
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
        cin >> choice;
        getline(cin, choice);
        if (choice == "17") {
            newUserInterface.saveFile();
        }
    }
    return 0;
}
