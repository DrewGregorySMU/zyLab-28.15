//https://github.com/DrewGregorySMU/zyLab-28.15 
//Drew Gregory
//Luke Berr
#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if(option == 'a'){
    //add a song to the end of the list
    //intialize variables to create a new song
    string id;
    string name;
    string artistName;
    int songLen;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> id;
    cout << "Enter song's name:" << endl;
    cin >> name;
    cout << "Enter artist's name:" << endl;
    cin >> artistName;
    cout << "Enter songs length (in seconds):" << endl;
    cin >> songLen;
    //creating new song and current node to add it to the back
    PlaylistNode* newSong = new PlaylistNode(id, name, artistName, songLen);
    PlaylistNode* currNode = headNode;
    while()

   }
   else if(option == 'd'){

   }
   else if(option == 'c'){
    
   }
   else if(option == 's'){
    
   }
   else if(option == 'o'){
    //outputs the full playlist
    if(headNode == nullptr){
        cout << "Playlist is empty";
        return headNode;
    }
    
    PlaylistNode* currentPointer = headNode;
    int songCount = 1;
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
    while(currentPointer != nullptr){
        cout << songCount <<  "." << endl;
        currentPointer->PrintPlaylistNode();
        currentPointer = currentPointer->GetNext();
        songCount++;
    }
    

   }

   return headNode;
}

int main() {
   string playlistTitle;
   char choice;
   PlaylistNode* head;


   cout << "Enter playlist's title: ";
   cin >> playlistTitle;

   PrintMenu(playlistTitle);

   cout << "Choose an option:" << endl;
   cin >> choice;
   while(choice != 'a' && choice != 'd' && choice != 'c' && choice != 's' && choice != 't' && choice != 'o' && choice != 'q'){
    cout << "Choose an option:" << endl;
    cin >> choice;
   }
   while(choice != 'q'){
    head = ExecuteMenu(char choice, string playlistTitle, PlaylistNode* head);
    cout << "Choose an option:" << endl;
    cin >> choice;
   }

   
   return 0;
}

