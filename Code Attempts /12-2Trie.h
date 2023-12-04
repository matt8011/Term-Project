#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#ifndef Trie_h
#define Trie_h

class Trie {
public:
    Trie();

    void insert(std::string key, int mode);
    void fileWrite(std::string ofname);


    bool strSearch(std::string value);

    std::vector<std::string> autoComp(std::string val);
    void autoFileWrite(std::string ofname, std::vector< std::pair<std::string, std::vector<std::string>> > optionList);
    void searchFileWrite(std::string ofname,std::vector< std::pair<std::string, bool> > searchList) ;

private:
    struct node {
        char data;
        std::vector<node*> subs;
        bool word;

        node(char data) : data(data), word(false), subs({}) {}
    };
    std::stringstream stream;
    node* root;
    std::vector<std::string> compOptions;
    int autoSize;

    void filePrint(node* rootNode);

    void insert(std::string key);

    void compSearch(node *rootNode, int& index, std::string prefix);
    void countLeaves(node *rootNode);


//    std::string keyCheck(std::string key);



};

#endif //Trie_h
