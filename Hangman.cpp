#include <iostream>
#include <list>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

//Here we get string by index from the list of strings
string getByIndex(list<string> myList, int index){
    list<string>::iterator it = myList.begin();
    for(int i=0; i<index; i++){
        ++it;
    }
    return *it;
}

//Here we return random word from words list
string getWord(list<string> words){
    if(words.empty()) return "";
    srand (time(NULL));
    int index = rand() % words.size();
    return getByIndex(words, index);
}

//This method is for converting word to dashes : apple --> _____
string wordToDashes(string word){
    string wordWithDashes = "";
    for(int i=0; i<word.length(); i++){
        wordWithDashes += '_';
    }
    return wordWithDashes;
}

//This method returns dashed string with guessed characters
void findIndexes(string word, string usersChar, string &wordWithDashes){
    for(int i=0; i<word.size(); i++){
        if(word.at(i) == usersChar.at(0)){
            wordWithDashes[i] = usersChar.at(0);
        }
    }
}

//Here we have all logics for players turn
void playersTurn(string guessingWord, string wordWithDashes, int mistakes){
    while(mistakes > 0){
        if(mistakes == 1){
            cout<<"You have left " << mistakes << " life" <<endl;
        } else {
            cout<<"You have left " << mistakes << " lives" <<endl;
        }
        cout<<"Please enter character: ";
        string usersChar = "";
        cin>>usersChar;
        transform(usersChar.begin(), usersChar.end(),usersChar.begin(), ::tolower);
        if(!(usersChar.length()==1 && usersChar >= "a" && usersChar <= "z")){
            cout<<"You entered illegal character"<<endl;
            continue;
        }
        if (guessingWord.find(usersChar) != std::string::npos) {
            cout<<"found"<<endl;
            findIndexes(guessingWord, usersChar, wordWithDashes);
            cout<<wordWithDashes<<endl;
            if(wordWithDashes.compare(guessingWord) == 0){
                cout<<"You Won!"<<endl;
                return;
            }
        } else {
            if(mistakes==1){
                cout<<"You lost"<<endl;
                return;
            }
            cout<<"this character is not in word, try again"<<endl;
            mistakes--;
        }
    }   
}

int main(){
    list<string> words = {"banana", "apple", "mango"}; // You can have any number of words here
    string guessingWord = getWord(words);
    cout<<guessingWord<<endl;
    string wordWithDashes = wordToDashes(guessingWord);
    cout<<wordWithDashes<<endl;

    int mistakes = 3;
    playersTurn(guessingWord, wordWithDashes, mistakes);
    return 0;
}