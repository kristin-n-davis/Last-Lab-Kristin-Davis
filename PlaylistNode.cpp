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
