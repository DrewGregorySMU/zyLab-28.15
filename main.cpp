//https://github.com/DrewGregorySMU/zyLab-28.15 
//Drew Gregory
//Luke Berridge
#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << endl;
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
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
    getline(cin, id);
    cout << "Enter song's name:" << endl;
    getline(cin, name);
    cout << "Enter artist's name:" << endl;
    getline(cin, artistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> songLen;
    
    
    //creating new song and current node to add it to the back
    PlaylistNode* newSong = new PlaylistNode(id, name, artistName, songLen);
    if(headNode == nullptr){
        headNode = newSong;
        return headNode;
    }

    PlaylistNode* currNode = headNode;
    
    //loop to get to the last node in the playlist
    
    while(currNode->GetNext() != nullptr){
        currNode = currNode->GetNext();
    }
    currNode->InsertAfter(newSong);

    
    return headNode;


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
    while(currSong->GetID() != ID){
        lastSong = currSong;
        currSong = currSong->GetNext();
        count++;

    }
    //checks if the deleted node is the head node
    if(count == 0){
        PlaylistNode* newHead = headNode->GetNext();
        delete headNode;
        return newHead;
    }
    //links the song before deletion to the song after the deleted song
    lastSong->SetNext(currSong->GetNext());

    //deallocates memory for the song that matches the ID
    delete currSong;
    
    

    return headNode;


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
   return headNode;
   }
   else if(option == 't'){
       //function to output time
   //Luke function
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    int totalTime = 0;
    PlaylistNode* currentPointer = headNode;
    while (currentPointer != nullptr) {
        totalTime += currentPointer->GetSongLength();
        currentPointer = currentPointer->GetNext();
    }
    cout << "Total time: " << totalTime << " seconds" << endl;

    return headNode;
      
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
        if(currentPointer != nullptr){
            cout << endl;
        }
        songCount++;
    }
    

   }
   else if(option == 'q')

   return headNode;
}

int main() {
   string playlistTitle;
   char choice;
   PlaylistNode* head = nullptr;


   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);

   PrintMenu(playlistTitle);

   cout << "Choose an option:" << endl;
   cin >> choice;

   cin.ignore();
   
   
   while(choice != 'q'){
    if(choice == 'a' || choice == 'd' || choice == 'c' || choice == 's' || choice == 't' || choice == 'o'){
        head = ExecuteMenu(choice, playlistTitle, head);
        PrintMenu(playlistTitle);
        cout << "Choose an option:" << endl;
        cin >> choice;
        cin.ignore();
        
    }
    else{
        cout << "Choose an option:" << endl;
        cin >> choice;
    }
   }

   
   return 0;
}



   
   return 0;
}

