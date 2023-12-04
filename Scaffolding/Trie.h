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
    std::stringstream dictionary;

    int insert(std::string key);
    void fileWrite(std::string ofname);


    int strSearch(std::string value);

    std::vector<std::string> autoComp(std::string val);
    void autoFileWrite(std::string ofname, std::vector< std::pair<std::string, std::vector<std::string>> > optionList);
    void searchFileWrite(std::string ofname,std::vector< std::pair<std::string, int> > searchList) ;

private:
    struct node {
        char data;
        std::vector<node*> subs;
        std::pair<bool, int> word;

        node(char data) : data(data), word(false, 0), subs({}) {}
    };
    std::stringstream stream;
    node* root;
    std::vector<std::string> compOptions;
    int autoSize;

    void filePrint(node* rootNode);

    void insert(std::string key, bool priv);

    void compSearch(node *rootNode, int& index, std::string prefix);
    void countLeaves(node *rootNode);



};

#endif //Trie_h
