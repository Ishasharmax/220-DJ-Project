//
// Created by Joel Jerez on 12/13/18.
//

//
// Created by Isha Sharma on 12/11/18.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <sstream>
#include "LinkedPlayList.h"
#include "PlayList.h"
#include "MasterPlayList.h"
#include "MasterSongList.h"


int main() {

    string fileName, userInput;
    cout << "Enter a file name you want: ";
    getline(cin, fileName);
    ofstream out(fileName);
    out << "Song List\n" << std::endl;

    //add songs, artists and duration

    int choice = 0;
    cout << "\n***************************************************\n"
            "*                                                 *\n"
            "*             Playlist Manager                    *\n"
            "*                                                 *\n"
            "***************************************************\n";
    cout << "Where would you like to start? \n\n"
            "1. Import Songs\n"
            "2. Remove Songs\n"
            "3. Song Information\n"
            "4. Import songs from a file\n"
            "5. Add New Playlist\n"
            "6. Play a Playlist\n"
            "7. Remove Playlist\n"
            "8. Add song in a Playlist\n"
            "9. Remove song in a Playlist\n"
            "10. View All Playlists \n"
            "11. Play Next song\n"
            "12. Artist's work\n"
            "13. Help \n"
            "14. Exit\n\n"
            "Enter Your Choice: ";
    cin>>choice;
    while (choice!=14) {
        if (choice == 1) {
            int initialCapacity = 0;
            cout << "How many songs do you want to add: ";
            cin >> initialCapacity;
            //MasterSongList myList = MasterSongList(initialCapacity);
            int YorN;
            cout << "Want to add songs? \n"
                    "1. Yes\n"
                    "2. No\n"
                    "Enter Your Choice: ";
            cin >> YorN;

            //importSong(Song songToAdd, int index); //imports a file to array
            while (YorN!=2) {
                string songName, artist;
                double song_duration;
                string songDuration;

                cout << "Enter the name of the song you want to add: ";
                cin.ignore();
                getline(cin, songName);
                out << "Song Title: \n" << songName << endl;

                cout << "Enter artist for this song: ";
                getline(cin, artist);
                out << "Artist: \n" << artist << endl;

                cout << "Enter duration (in mins) for this song: ";
                songDuration = to_string(song_duration);
                cin>> song_duration;
                out << "Song Duration: \n" << song_duration << endl;
                out << "_______________________________________\n";

                cout << "\nAdding " << "song \"" << songName
                     << "\" by " << artist << ". Running time: "
                     << song_duration << " mins \n\n";

                cout << "Want to add more songs? \n"
                        "1. Yes\n"
                        "2. No\n"
                        "Enter Your Choice: ";
                cin >> YorN;
            }
            cout << "_______________________________________\n\n";
            cout << "What you want to do now? \n"
                    "1. Import Songs\n"
                    "2. Remove Songs\n"
                    "3. Song Information\n"
                    "4. Import songs from a file\n"
                    "5. Add New Playlist\n"
                    "6. Play a Playlist\n"
                    "7. Remove Playlist\n"
                    "8. Add song in a Playlist\n"
                    "9. Remove song in a Playlist\n"
                    "10. View All Playlists \n"
                    "11. Play Next song\n"
                    "12. Artist's work\n"
                    "13. Help \n"
                    "14. Exit\n\n"
                    "Enter Your Choice: ";
            cin >> choice;
        }
        if (choice == 2) {
            string songToRemove;
            cout << "Name of the song you want to remove: ";
            cin.ignore();
            getline(cin,songToRemove);
            //MasterSongList myList = MasterSongList(initialCapacity);

            //remove the song
            cout << "You have successfully removed the song "<< songToRemove <<"\n from the song list.";
            cout << "_______________________________________\n\n";

            cout << "What you want to do now? \n"
                    "1. Import Songs\n"
                    "2. Remove Songs\n"
                    "3. Song Information\n"
                    "4. Import songs from a file\n"
                    "5. Add New Playlist\n"
                    "6. Play a Playlist\n"
                    "7. Remove Playlist\n"
                    "8. Add song in a Playlist\n"
                    "9. Remove song in a Playlist\n"
                    "10. View All Playlists \n"
                    "11. Play Next song\n"
                    "12. Artist's work\n"
                    "13. Help \n"
                    "14. Exit\n\n"
                    "Enter Your Choice: ";
            cin >> choice;
        }
        if (choice==3){
            Song songToLookFor;
            Song* songList =
            string songInfo;
            cout << "Enter the name of the song you want info about: \n";
            cin.ignore();
            getline(cin,songInfo);
            for(int x=0;x<songList.currentItemCount;x++){
                if(songList[x].name == songInfo){
                    songToLookFor=songList[x];
                }
                else{
                    x++;
                }
            }
            //use if statment to get the name from the song object and match it to the user input and get info.
            cout << " song \"" << "songName" << "\" by " << "artist" << ". Running time: "
                 << "song_duration" << " mins \n\n";
            //enter the artist, songName, and song_duration accordingly
        }
        if (choice==4){
            cout << "Import songs from a file \n";

            string InputFile, line;
            cout << "Enter the name file you want to import: \n";
            getline(cin,InputFile);

            ifstream infile;
            infile.open(InputFile);
            if (infile.fail()) {
                cout << "Unable to open file";
            } else {
                while (getline(infile, line)) {
                    cout << line << endl;
                }cout << "Enter the name song you want to import: \n";
                infile.close();
                infile.clear();
            }
        }
        if (choice == 5) {
            int initialCapacity = 0;
            cout << "How many playlists do you want to add: ";
            cin >> initialCapacity;
            //MasterPlayList myList = MasterPlayList(initialCapacity);
            int YorN = 0;
            cout << "Want to add playlists? \n"
                    "1. Yes\n"
                    "2. No\n"
                    "Enter Your Choice: ";
            cin >> YorN;
            string playListName;
            cout << "What you want to call your playlist: ";
            cin.ignore();
            getline(cin,playListName);

            cout << "\nYour new playlist " << playListName << " has been added! \n\n";
            out << "Playlist: " << playListName << endl;
            out << "-----------------------------\n";
            //importSong(Song songToAdd, int index); //imports a file to array
            while (YorN != 2) {
                cout << "Want to add any songs in the playlist? \n"
                        "1. Yes\n"
                        "2. No\n"
                        "Enter Your Choice: ";
                cin >> YorN;
                string songName, artist;
                double song_duration;
                while (YorN != 2) {
                    cout << "Enter the name of the song you want to add: ";
                    cin.ignore();
                    getline(cin,songName);
                    out << "Song Title: \n" << songName << endl;

                    cout << "Enter artist for this song: ";
                    cin.ignore();
                    getline(cin,artist);
                    out << "Artist: \n" << artist << endl;

                    cout << "Enter duration (in mins) for this song: ";
                    cin>> song_duration;
                    out << "Song Duration: \n" << song_duration << endl;
                    out << "-----------------------------\n";

                    cout << "\nAdding " << "song \"" << songName
                         << "\" by " << artist << " to the "<<playListName<<". Running time: "
                         << song_duration << " mins \n\n";

                    cout << "Want to add more songs? \n"
                            "1. Yes\n"
                            "2. No\n"
                            "Enter Your Choice: ";
                    cin >> YorN;
                }
                cout << "_______________________________________\n\n";
                cout << "What you want to do now? \n"
                        "1. Import Songs\n"
                        "2. Remove Songs\n"
                        "3. Song Information\n"
                        "4. Import songs from a file\n"
                        "5. Add New Playlist\n"
                        "6. Play a Playlist\n"
                        "7. Remove Playlist\n"
                        "8. Add song in a Playlist\n"
                        "9. Remove song in a Playlist\n"
                        "10. View All Playlists \n"
                        "11. Play Next song\n"
                        "12. Artist's work\n"
                        "13. Help \n"
                        "14. Exit\n\n"
                        "Enter Your Choice: ";
                cin >> choice;
            }

            cout << "Enter the name of the Playlist you want to add: ";
            cin.ignore();
            getline(cin, playListName);
            cout << "Want to add more playlists? \n"
                    "1. Yes\n"
                    "2. No\n"
                    "Enter Your Choice: ";
            cin >> YorN;
            cout << "_______________________________________\n\n";
            cout << "What you want to do now? \n"
                    "1. Import Songs\n"
                    "2. Remove Songs\n"
                    "3. Song Information\n"
                    "4. Import songs from a file\n"
                    "5. Add New Playlist\n"
                    "6. Play a Playlist\n"
                    "7. Remove Playlist\n"
                    "8. Add song in a Playlist\n"
                    "9. Remove song in a Playlist\n"
                    "10. View All Playlists \n"
                    "11. Play Next song\n"
                    "12. Artist's work\n"
                    "13. Help \n"
                    "14. Exit\n\n"
                    "Enter Your Choice: ";
            cin >> choice;
        }

        if (choice == 7) {
            string playListToRemove;
            cout << "Name of the playlist you want to remove: ";
            getline(cin, playListToRemove);
            //MasterPlayList myList = MasterPlayList(initialCapacity);
            //remove the playlist

            cout << "You have successfully removed the playlist \"" << playListToRemove << "\n\n";
            cout << "_______________________________________\n\n";

            cout << "What you want to do now? \n"
                    "1. Import Songs\n"
                    "2. Remove Songs\n"
                    "3. Song Information\n"
                    "4. Import songs from a file\n"
                    "5. Add New Playlist\n"
                    "6. Play a Playlist\n"
                    "7. Remove Playlist\n"
                    "8. Add song in a Playlist\n"
                    "9. Remove song in a Playlist\n"
                    "10. View All Playlists \n"
                    "11. Play Next song\n"
                    "12. Artist's work\n"
                    "13. Help \n"
                    "14. Exit\n\n"
                    "Enter Your Choice: ";
            cin >> choice;
        }if (choice==13) {
            cout << "Welcome to the Help section!" << endl;
            cout << "Through this program you can do the following things:\n";
            cout << "1. Import Songs\n"
                    "2. Remove Songs\n"
                    "3. Song Information\n"
                    "4. Import songs from a file\n"
                    "5. Add New Playlist\n"
                    "6. Play a Playlist\n"
                    "7. Remove Playlist\n"
                    "8. Add song in a Playlist\n"
                    "9. Remove song in a Playlist\n"
                    "10. View All Playlists \n"
                    "11. Play Next song\n"
                    "12. Artist's work\n"
                    "13. Help \n"
                    "14. Exit\n\n";


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
        }
    }
    if (choice==14){
        cout << "You have exited the program sucessfully \n"<<endl;
        cout << "Your file have been saved"<<endl;
        out<<"End of the file";
    }
    return 0;
}



