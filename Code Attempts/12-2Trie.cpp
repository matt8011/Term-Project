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
            if(str[str.size()-1] == ',' || str[str.size()-1] == '.')str = str.substr(0,str.size()-1);
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
                    if(!temp->word)return false;
                    else return true;
                }
                break;
            }
        }
        //if the char doesn't exist in the tree
        if(!found)return false;
    }
    return false;
}



void Trie::fileWrite(std::string ofname){
    //creating the DOT file
    std::ofstream os(ofname);
    os << "digraph G {" << std::endl << std::endl;
    node* temp = root;
    //callling file print for all of the first layer of the tree
    //if called with node prints a little wacky
    for(int i = 0; i< root->subs.size(); i++){
        temp = root->subs[i];
        filePrint(temp);
    }
    //putting the filePrint output into the out file
    os << stream.rdbuf();
    os << std::endl << "}";
    os.close();
}


//private print
void Trie::filePrint(node* rootNode){
    //iterating through all chars that the rootNode points too
    if (!rootNode->subs.empty())for(int i = 0; i < rootNode->subs.size(); i++) {
        std::string color = "red";
        //if the char is the last of a word the color is blue
        if(rootNode->subs[i]->word) color = "blue";
        stream << char(rootNode->data) << " -> " << char(rootNode->subs[i]->data) << "[color=\"" + color << "\"];" << std::endl;
        if(!rootNode->subs[i]->subs.empty()){
            //recursive step to check all nodes
            filePrint(rootNode->subs[i]);
        }
    }
}

std::vector<std::string> Trie::autoComp(std::string val) {
    //temp is the parent node
    node* temp = root;
    int valdex = val.size();
    for(int i =0; i<val.size(); i++) {
        bool found = false;
        for(int j =0; j<temp->subs.size(); j++){
            if(temp->subs[j]->data == val[i]){
                temp = temp->subs[j];
                found = true;
                break;
            }
        }
        //if the char doesn't exist in the tree
        if(!found){
            valdex = i;
            if(i == 0) return {};
            break;
        }
    }
    countLeaves(temp);
    compOptions = std::vector<std::string> (autoSize, val.substr(0,valdex));
    autoSize = 0;
    compSearch(temp, autoSize, val.substr(0,valdex));
    return compOptions;
}

void Trie::compSearch(Trie::node* rootNode, int& index, std::string prefix) {
    // Check if the current node is the end of a word
    if (rootNode->word) {
        compOptions[index] = prefix;
        index++;
    }

    // Iterate through all characters that the rootNode points to
    for (int i = 0; i < rootNode->subs.size(); i++) {
        std::string newPrefix = prefix + rootNode->subs[i]->data;

        // Recursive step to check all nodes
        compSearch(rootNode->subs[i], index, newPrefix);
    }
}


void Trie::countLeaves(Trie::node *rootNode) {
    //iterating through all chars that the rootNode points too
    if (!rootNode->subs.empty())for(int i = 0; i < rootNode->subs.size(); i++) {
        if(rootNode->subs[i]->word)autoSize++;
        if(!rootNode->subs[i]->subs.empty()){
            //recursive step to check all nodes
            countLeaves(rootNode->subs[i]);
        }
    }
}

void Trie::autoFileWrite(std::string ofname, std::vector<std::pair<std::string, std::vector<std::string>>> optionList) {
    //creating the DOT file
    std::ofstream os(ofname);
    os << "Auto-completions:" << std::endl << std::endl;
    for(int i = 0; i<optionList.size(); i++){
        os << optionList[i].first << ":" << std::endl;
        for(int j = 0; j<optionList[i].second.size(); j++){
            if(optionList[i].first != optionList[i].second[j])os << char(9) << optionList[i].second[j] << std::endl;
        }
    }
    os.close();
}

void Trie::searchFileWrite(std::string ofname, std::vector< std::pair<std::string, bool> > searchList) {
    //creating the DOT file
    std::ofstream os(ofname);
    os << "Search Queries and results" << std::endl << std::endl;
    for(int i = 0; i<searchList.size(); i++){
        std::string wasIt = "not found";
        if(searchList[i].second) wasIt = "found";
        os << searchList[i].first << " was " << wasIt << std::endl;
    }
    os.close();
}



/*
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
 */
