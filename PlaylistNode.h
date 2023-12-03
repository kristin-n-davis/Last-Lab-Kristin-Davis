#define PLAYLISTNODE_H
#include <iostream>
#include <string>
using namespace std;
class PlaylistNode{
private:
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
}
