#include <iostream>
#include "PlaylistNode.h"
using namespace std;
void PrintMenu(const string playlistTitle) {
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
      string id;
      string songName;
      string artistName;
      int songLength;
      
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      cin.ignore();
      
      cout << "Enter song's name:" << endl;
      getline(cin, songName);
      
      cout << "Enter artist's name:" << endl;
      getline(cin,artistName);
      
      cout << "Enter song's length (in seconds):" << endl;
      cin >> songLength;
      cout << endl;
      
      PlaylistNode* newNode = new PlaylistNode(id, songName, artistName, songLength);
         if(headNode == nullptr){
            headNode = newNode;
         }
         else{
            PlaylistNode* currentNode = headNode;
            while(currentNode->GetNext() != nullptr){
               currentNode = currentNode -> GetNext();
            }
            currentNode -> InsertAfter(newNode);
         }
   }
   else if(option == 'd'){
      cout << "REMOVE SONG" << endl;
      string idgone;
      cout << "Enter song's unique ID:" << endl;
      cin >> idgone;
      PlaylistNode* currentNode = headNode;
      PlaylistNode* lastNode = nullptr;
      
      while (currentNode != nullptr && currentNode ->GetID() != idgone){
         lastNode = currentNode;
         currentNode = currentNode->GetNext();
      }
      
         if(lastNode == nullptr){
            headNode = currentNode->GetNext();
         }
         else{
            lastNode -> SetNext(currentNode->GetNext());
         }
         
      cout << "\"" << currentNode -> GetSongName() << "\" removed." << endl; 
      cout << endl;
   }
   else if(option == 'c'){
   }
    else if(option == 's'){
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
   cout << "Enter artist's name:" << endl;
   cout << endl;
   string artistName;
   getline(cin, artistName);
   int position = 1;
  
   
   PlaylistNode* currentNode = headNode;
   
   while(currentNode != nullptr){
      if(currentNode->GetArtistName() == artistName){
         cout << position << "." << endl;
         currentNode ->PrintPlaylistNode();
         cout << endl;
      }
      currentNode = currentNode->GetNext();
      position = position +1;
   }
   }
    else if(option == 't'){
      cout <<  "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int times;
      times = 0;
      PlaylistNode* currentNode = headNode;
      
      while (currentNode != nullptr){
         times = times + currentNode->GetSongLength();
         currentNode = currentNode->GetNext();
      }
      
     cout << "Total time: " << times << " seconds" << endl;
     cout << endl;
   }
   else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      int position = 1;
      
      PlaylistNode* currentNode = headNode;
      
      while(currentNode != nullptr){
         cout << position << "." << endl;
         currentNode -> PrintPlaylistNode();
         cout << endl;
         currentNode = currentNode->GetNext();
         position = position + 1;
      }
      if(position == 1){
         cout << "Playlist is empty" << endl;
         cout << endl;
      
      }
   }
    else if(option == 'q'){
   }
   return headNode; 
}
int main() {
   string playlistTitle;
   cout << "Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, playlistTitle);

   PlaylistNode* headNode = nullptr;
   
   char option = ' ';

    while(option != 'q'){
      PrintMenu(playlistTitle);
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore();
      headNode = ExecuteMenu(option, playlistTitle, headNode);
   }

   return 0;
}
