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
}
