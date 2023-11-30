//https://github.com/DrewGregorySMU/zyLab-28.15 
//Drew Gregory
//Luke Berridge
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

   //loop to get to the last node in the playlist
    while(currNode->GetNext() != nullptr){
        currNode = currNode->GetNext();
    }
    //add song to the end of the playlist
    currNode->InsertAfter(newSong);

      
      

   }
   else if(option == 'd'){
    //prompting user for ID to locate song which needs to be deleted
    string ID;
    cout << "Enter song's unique ID: " << endl;
    cin >> ID;
    //intialize a count to see if the head node is deleted
    int count = 0;

    //create a node to loop through and find deleted song
    PlaylistNode* currSong = headNode;
    
    //create a node before the match to store for deletion
    PlaylistNode* lastSong = nullptr;


    //loops until current song matches the ID
    while(currSong->GetID != ID){
        lastSong = currSong;
        currSong = currSong->GetNext();

    }
    //links the song before deletion to the song after the deleted song
    lastSong->SetNext(currSong->GetNext());

    //deallocates memory for the song that matches the ID
    delete currSong;
    
      
   }
   else if(option == 'c'){
    //Luke function
   }
   else if(option == 's'){
    //Luke function
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;

    string artistToSearch;
    cin >> artistToSearch;

    PlaylistNode* currentPointer = headNode;
    int songCount = 1;
    
    while (currentPointer != nullptr) {
        if (currentPointer->GetArtistName() == artistToSearch) {
            cout << songCount << "." << endl;
            currentPointer->PrintPlaylistNode();
        }
        currentPointer = currentPointer->GetNext();
        songCount++;
   }
   }
   else if(option == 't'){
      //function to output time
   //Luke function

      
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

