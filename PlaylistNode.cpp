#include "PlaylistNode.h"
PlaylistNode::PlaylistNode(){
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string songID, string songsName, string songArtist, int songsLength){
   uniqueID = songID;
   songName = songsName;
   artistName = songArtist;
   songLength = songsLength;
   nextNodePtr = nullptr;
}
string PlaylistNode::GetID(){
   return uniqueID;
}
string PlaylistNode::GetSongName(){
   return songName;
}
string PlaylistNode::GetArtistName(){
   return artistName;
}
int PlaylistNode::GetSongLength(){
   return songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
   return nextNodePtr;
}
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
   PlaylistNode* tempNext = nextNodePtr;
   nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tempNext;
}
void PlaylistNode::SetNext(PlaylistNode* nodePtr){
   nextNodePtr = nodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}

