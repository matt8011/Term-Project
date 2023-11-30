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

    void insert(std::string key);
    void print(std::string ofname);

    bool search(int value);

private:
    struct node {
        char data;
        std::vector<node*> subs;
        bool word;

        node(char data) : data(data), word(false), subs({}) {}
    };

    node* root;

    void insert(char value, node* node);
    int search(std::string value);
    std::string keyCheck(std::string key);



};

#endif //Trie_h
