#include <iostream>
using namespace std;

class PlaylistNode{

    public:
        PlaylistNode();
        PlaylistNode(string idName = "none", string sName = "none", string artName = "none", int sLength = 0, PlaylistNode* nextPtr = nullptr); 
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void InsertAfter(PlaylistNode* nodePtr);
        void SetNext(PlaylistNode* nodePtr);
        void PrintPlaylistNode();


    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;




};
