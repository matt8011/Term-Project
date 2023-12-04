#include <iostream>
#include "Trie.h"

int main(int argc, char* argv[]) {
    //declarations
    int mode = std::stoi(argv[2]);
    std::string ifname = argv[1];
    std::ifstream ifs(ifname);

    std::string ofname = ifname.substr(0, ifname.rfind('.')) + "_output";
    std::cout << "Input file name: " << ifname  << std::endl;
    std::cout << "Output file name: " << ofname << "_mode.dot" << std::endl<< std::endl;
    Trie tree;

    //start menu
    std::string menuChoice;
    std::cout << "What would you like to do with your input file?: " << std::endl;
    std::cout << "0: fill the tree" << std::endl;
    std::cout << "1: search the tree" << std::endl;
    std::cout << "2: autocomplete text" << std::endl;
    std::cout << "Type 0, 1, or 2: ";
    std::cin >> menuChoice;
    std::cout << std::endl;

    bool wrongChoice = true;
    if(menuChoice == "0" || menuChoice == "1" || menuChoice == "2") wrongChoice = false;
    while(wrongChoice){
        if(menuChoice == "0" || menuChoice == "1" || menuChoice == "2") wrongChoice = false;
        if(menuChoice == "Q" || menuChoice == "q") return 0;
        std::cout << "If you'd like to quit Type Q" << std::endl;
        std::cout << "Type 0, 1, or 2: ";
        std::cin >> menuChoice;
        std::cout << std::endl;
    }

    //fill:
    if(std::stoi(menuChoice) == 0){
        std::string line;

        while(std::getline(ifs, line)){
            //fill tree
            tree.insert(line, 0);
        }
        std::cout << "The tree is filled!" << std::endl;
        //creat DOT file
        tree.fileWrite(ofname+"0.dot");
    }else{
        std::ifstream dict("dictionary.txt");
        std::string line;

        while(std::getline(dict, line)){
            //fill tree
            tree.insert(line, 0);
        }

    }

    //search:
    if(std::stoi(menuChoice) == 1){
        std::string line;
        std::vector< std::pair<std::string, bool> > outy;

        while(std::getline(ifs, line)){
            //If there are multiple words in the input string
            //this calls insert for each individual word in the string
            bool many = false;
            for(int i =0; i<line.size(); i++){
                if(line[i] == ' '){
                    many = true;
                    break;
                }
            }
            //if there are multiple words in the string{
            if(many) {
                std::string str;
                //storing the string in a string stream lends to easy traversal
                std::stringstream ss(line);
                while(ss >> str){
                    if(str[str.size()-1] == ',' || str[str.size()-1] == '.')str = str.substr(0,str.size()-1);
                    outy.emplace_back(str, tree.strSearch(str.substr(0,str.size())));
                }
            }
                //if there aren't multiple words in the string{
            else outy.emplace_back(line, tree.strSearch(line));
        }
        tree.searchFileWrite(ofname+"1.dot", outy);
        std::cout << "The tree has been searched!" << std::endl;
    }

    //auto:
    if(std::stoi(menuChoice) == 2){
        std::string value;
        // { [aut, {auto,autocomplete,...}], []}
        std::vector< std::pair<std::string, std::vector<std::string>> > outy;

        while(std::getline(ifs, value)){
            //If there are multiple words in the input string
            //this calls insert for each individual word in the string
            bool many = false;
            for(int i =0; i<value.size(); i++){
                if(value[i] == ' '){
                    many = true;
                    break;
                }
            }
            //if there are multiple words in the string{
            if(many) {
                std::string str;
                //storing the string in a string stream lends to easy traversal
                std::stringstream ss(value);
                while(ss >> str){
                    if(str[str.size()-1] == ',' || str[str.size()-1] == '.')str = str.substr(0,str.size()-1);
                    outy.emplace_back(str.substr(0,str.size()), (tree.autoComp(str.substr(0,str.size()))));
                }
            }
                //if there aren't multiple words in the string{
            else outy.emplace_back(value, (tree.autoComp(value)));
        }
        tree.autoFileWrite(ofname+"2.dot", outy);
        std::cout << "The text is complete!" << std::endl;
    }

}
