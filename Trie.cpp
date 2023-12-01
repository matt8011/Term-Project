#include "Trie.h"
Trie::Trie() {
    //initializing an "empty" root
    root = new node('\'');
}

//public insert
void Trie::insert(std::string inString, int mode) {
    //If there are multiple words in the input string
    //this calls insert for each individual word in the string
    bool many = false;
    for(int i =0; i<inString.size(); i++){
        if(inString[i] == ' '){
            many = true;
            break;
        }
    }
    //if there are multiple words in the string{
    if(many) {
        std::string str;
        //storing the string in a string stream lends to easy traversal
        std::stringstream ss(inString);
        while(ss >> str){
            if(str[str.size()-1] == ',')str = str.substr(0,str.size()-1);
            insert(str.substr(0,str.size()));
        }
    }
    //if there aren't multiple words in the string{
    else insert(inString);
}

//private insert
void Trie::insert(std::string key) {
//     key = keyCheck(key);
    //temp will be the parent node of the current char
    node* temp = root;
    for(int i =0; i<key.size(); i++) {
        bool found = false;
        unsigned int size = 0;
        if(!(temp->subs.empty())) size = temp->subs.size();
        for(int j =0; j<size; j++){
            if(temp->subs[j]->data == key[i]){
                //if the char being added to the tree exists in the tree don't add it
                //the parent node is changed to the found char
                temp = temp->subs[j];
                found = true;
                //if the final char to be added exists in the tree tell the tree it's a word
                if(i == key.size()-1) temp->word = true;
                break;
            }
        }
        //if the char doesn't exist in the tree add it
        if(!found){
            while(i<key.size()){
                temp->subs.push_back(new node(key[i]));
                temp = temp->subs[temp->subs.size()-1];
                i++;
            }
            temp->word = true;
            break;
        }
    }
}



//public search
int Trie::search(std::string value, int mode) {
    if (mode == 0) return strSearch(value);
    if (mode == 1) return subSearch(value);
    else return 0;
}

//private String search
bool Trie::strSearch(std::string value) {
    //temp is the parent node
    node* temp = root;
    for(int i =0; i<value.size(); i++) {
        bool found = false;
        for(int j =0; j<temp->subs.size(); j++){
            if(temp->subs[j]->data == value[i]){
                temp = temp->subs[j];
                found = true;
                //if the final char to be added exists in the tree tell the tree it's a word
                if(i == value.size()-1){
                    //if the final char doesnt dictate a word return 0
                    if(!temp->word)return 0;
                    else return 1;
                }
                break;
            }
        }
        //if the char doesn't exist in the tree
        if(!found)return 0;
    }
    return 0;
}

int Trie::subSearch(std::string value) {
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

void Trie::fileWrite(std::string ofname){
    std::ofstream os(ofname);
    os << "digraph G {" << std::endl << std::endl;
    node* temp = root;
    for(int i = 0; i< root->subs.size(); i++){
        temp = root->subs[i];
        print(temp);
    }
    os << stream.rdbuf();
    os << std::endl << "}";
    os.close();
}

//public print
void Trie::print(){
//    print(root, root->subs[0]);
}

//private print
void Trie::print(node* rootNode){
    if (!rootNode->subs.empty())for(int i = 0; i < rootNode->subs.size(); i++) {
        std::string color = "red";
        if(rootNode->subs[i]->word) color = "blue";
        stream << char(rootNode->data) << " -> " << char(rootNode->subs[i]->data) << "[color=\"" + color << "\"];" << std::endl;
        if(!rootNode->subs[i]->subs.empty()){
            print(rootNode->subs[i]);
        }
    }
}