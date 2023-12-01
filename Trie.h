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
    void print();

    int search(std::string value, int mode);

private:
    struct node {
        char data;
        std::vector<node*> subs;
        bool word;

        node(char data) : data(data), word(false), subs({}) {}
    };
    std::stringstream stream;
    node* root;

    void print(node* rootNode);

    void insert(std::string key);
    bool strSearch(std::string value);
    int subSearch(std::string value);
    std::string keyCheck(std::string key);



};

#endif //Trie_h
