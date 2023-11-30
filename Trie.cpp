#include "Trie.h"
Trie::Trie() {
    root = new node('\'');
}


void Trie::insert(std::string key) {
    //If there are multiple words in the input string
    //this calls insert for each individual word in the string
    bool many = false;
    for(int i =0; i<key.size(); i++){
        if(key[i] == ' '){
            many = true;
            break;
        }
    }
    if(many)for(int i =0; i<key.size(); i++){
        if(key[i] == ' '){
            insert(key.substr(0,i));
            key = key.substr(i+1);
        }
    }
    //now we can insert

    key = keyCheck(key);
    //temp is the parent node of the current char
    node* temp = root;
    for(int i =0; i<key.size(); i++) {
        bool found = false;
        for(int j =0; j<temp->subs.size(); j++){
            if(temp->subs[j]->data == key[i]){
                //if the char being added to the tree exists in the tree don't add it
                temp = temp->subs[j];
                found = true;
                //if the final char to be added exists in the tree tell the tree it's a word
                if(i == key.size()-1) temp->word = true;
                break;
            }
        }
        //if the char doesn't exist in the tree add it
        if(!found){
            temp->subs.push_back(new node(key[i]));
            //if this is the final char to be added, tell the tree it's a word
            if(i == key.size()-1) temp->subs[temp->subs.size()-1]->word = true;
        }
    }
}

bool Trie::search(int value) {
    return false;
}

void Trie::insert(char value, Trie::node *node) {

}

int Trie::search(std::string value) {
    return 0;
}

std::string Trie::keyCheck(std::string key){
    for(int i = 0; i<key.size(); i++) {
        if (int(key[i]) < 91) {
            if (int(key[i]) > 64) {
                //less than 91 and greater than 64 make lowercase
                key[i] = char(int(key[i] + 32));
                continue;
            } else {
                //less than or equal to 64 del
                key.erase(i);
                continue;
            }
        } else if (int(key[i]) < 97) {
            //greater than or equal to 91 and less than 97 del
            key.erase(i);
            continue;
        }
        if(int(key[i])>122){
            //greater than 122 del
            key.erase(i);
            continue;
        }
    }
    return key;
}

void Trie::print(std::string ofname){
    std::ofstream os(ofname);
    os << "digraph G {" << std::endl << std::endl;
    node* temp = root;
    for(int i= 0; i<temp->subs.size(); i++){
        char Schar;
        char Dchar;
        bool word = false;
        Schar = temp->subs[i]->data;
        for(int j= 0; j < temp->subs[i]->subs.size(); j++){
            Dchar = temp->subs[i]->subs[j]->data;
            word = temp->subs[i]->subs[j]->word;
            std::string color = "red";
            if(word) color = "blue";
            os << Schar << " -> " << Dchar << "[color=\"" << color << "\"];" << std::endl;
        }
    }
    os << std::endl << "}";
    os.close();
}

