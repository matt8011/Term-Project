#include <iostream>
#include "trie.h"



int main(int argc, char* argv[]) {
    //declarations
    std::string ifname = argv[1];
    std::string secfname;

    std::string ofname = ifname.substr(0, ifname.rfind('.')) + "_output";
    std::cout << "Input File Name: " << ifname  << std::endl;
    std::cout << "Output File Name: " << ofname << "#_mode.dot" << std::endl<< std::endl;
    Trie tree;

    //infinite menu
    int iterations = 0;
    bool secondRound = false;

    std::vector<std::string> theEnd(1);

    while(true) {
        //start menu
        std::string menuChoice;
        bool user = false;
        bool oldFile = true;
        std::cout << "What Action Would You Like To Perform" ;
        if(secondRound){
            std::cout << "?: " << std::endl;
            std::cout << "0: Edit File" << std::endl;
            std::cout << "1: Perform Action On Tree" << std::endl;
            std::cout << "Type 0, or 1: ";
            menuChoice.clear();
            std::cin >> menuChoice;
            std::cout  << std::endl;
            bool wrongChoiceFU = true;
            if (menuChoice == "0" || menuChoice == "1") wrongChoiceFU = false;
            while (wrongChoiceFU) {
                if (menuChoice == "0" || menuChoice == "1" || menuChoice == "2"){
                    wrongChoiceFU = false;
                    break;
                }
                if (menuChoice == "Q" || menuChoice == "q") return 0;
                std::cout << "Type 0, or 1: ";
                menuChoice.clear();
                std::cin >> menuChoice;
            }
            std::cout << std::endl;
            if(menuChoice == "0"){
                std::cout << "FILE OPTIONS:" << std::endl;
                std::cout << "0: Use Existing File" << std::endl;
                std::cout << "1: Use New File" << std::endl;
                std::cout << "Type 0, or 1: ";
                std::string fileChoice;
                fileChoice.clear();
                std::cin >> fileChoice;
                std::cout  << std::endl;
                bool wrongChoiceSN = true;
                if (fileChoice == "0" || fileChoice == "1") wrongChoiceSN = false;
                while (wrongChoiceSN) {
                    if (fileChoice == "0" || fileChoice == "1" || fileChoice == "2"){
                        wrongChoiceSN = false;
                        break;
                    }
                    if (fileChoice == "Q" || fileChoice == "q") return 0;
                    std::cout << "Type 0, or 1: ";
                    fileChoice.clear();
                    std::cin >> fileChoice;
                }
                std::cout << std::endl;
                if(fileChoice == "1"){
                    oldFile = false;
                    std::cout << "New File Name: ";
                    std::cin >> secfname;
                    std::cout << std::endl;
                }
                std::cout << "NEW FILE OPTIONS: " << std::endl;
            }
            else if(menuChoice == "1"){
                std::cout << "USER OPTIONS:" << std::endl;
                user = true;
            }
            menuChoice.clear();
        }else std::cout << " On Your Input File?: " << std::endl;

        std::cout << "0: ";
        if(secondRound) std::cout << "Add Word To The Tree" << std::endl;
        else std::cout << "Fill The Tree"<< std::endl;
        std::cout << "1: Search ";
        if(secondRound) std::cout << "The Tree" << std::endl;
        else std::cout << "A Prefilled Tree" << std::endl;
        std::cout << "2: Autocomplete Text" << std::endl;
        std::cout << "Q: Quit Program" << std::endl << std::endl;

        std::cout << "Type 0, 1, or 2: ";
        menuChoice.clear();
        std::cin >> menuChoice;
        std::cout << std::endl;
        bool wrongChoiceMM = true;
        bool first = true;
        if (menuChoice == "0" || menuChoice == "1" || menuChoice == "2") wrongChoiceMM = false;
        while (wrongChoiceMM) {
            if (menuChoice == "0" || menuChoice == "1" || menuChoice == "2"){
                wrongChoiceMM = false;
                break;
            }
            if (menuChoice == "Q" || menuChoice == "q") return 0;
            if(first)std::cout << "Type Q To Quit" << std::endl;
            std::cout << "Type 0, 1, or 2: ";
            menuChoice.clear();
            std::cin >> menuChoice;
            first = false;
        }
        std::cout << std::endl;

        std::string userString;
        if(secondRound && user) {
            //fill
            if (std::stoi(menuChoice) == 0) {
                std::cout << "Type Word(s) To Add To Tree: " << std::endl;
            }

            //search
            if (std::stoi(menuChoice) == 1) {
                std::cout << "Type Word(s) To Be Searched: " << std::endl;
            }

            //auto
            if (std::stoi(menuChoice) == 2) {
                std::cout << "Type Word(s) To Be Autocompleted: " << std::endl;
            }
            std::cout << R"(Type One Word Per Line ["\exit" to exit] )" << std::endl;
            std::string word;
            while(std::cin >> word){
                if(word == "\\exit") break;
                userString+= " " + word;
            }
            std::cout << std::endl;

        }

        std::string currfname;
        if(secondRound && !user && !oldFile)currfname = secfname;
        else currfname = ifname;

        std::ifstream ifs(currfname);

        //fill:
        if (std::stoi(menuChoice) == 0) {
            std::string line;
            if(secondRound&& user){
                line = userString;
                tree.insert(line);
            }else while (std::getline(ifs, line)) {
                    if(line.empty())continue;

                    //fill tree
                    tree.insert(line);
                }
            std::cout << "The Tree Is Filled!" << std::endl;
            //creat DOT file
            if(!secondRound)tree.fileWrite(ofname + "_fill.dot");
            else{
                std::string ForU = "_by_file";
                if(user) ForU = "_by_user";
                tree.fileWrite(ofname + std::to_string(iterations) + ForU + "_fill.dot");
            }
        } else {
            std::string line;

            while (std::getline(tree.dictionary, line)) {
                //fill tree
                tree.insert(line);
            }
            tree.fileWrite("pre_fill.dot");
        }

        //search:
        if (std::stoi(menuChoice) == 1) {
            std::string line;
            std::vector<std::pair<std::string, int> > outy;

            if(secondRound&& user){
                line = userString;
                std::string str;
                std::stringstream ss(line);
                while (ss >> str) {
                    if (str[str.size() - 1] == ',' || str[str.size() - 1] == '.') str = str.substr(0, str.size() - 1);
                    outy.emplace_back(str, tree.strSearch(str));
                }
//                outy.emplace_back(line, tree.strSearch(line));
            }else while (std::getline(ifs, line)) {
                    if(line.empty())continue;

                    //If there are multiple words in the input string
                    //this calls insert for each individual word in the string
                    bool many = false;
                    for (int i = 0; i < line.size(); i++) {
                        if (line[i] == ' ') {
                            many = true;
                            break;
                        }
                    }
                    //if there are multiple words in the string{
                    if (many) {
                        std::string str;
                        //storing the string in a string stream lends to easy traversal
                        std::stringstream ss(line);
                        while (ss >> str) {
                            if (str[str.size() - 1] == ',' || str[str.size() - 1] == '.')
                                str = str.substr(0, str.size() - 1);
                            outy.emplace_back(str, tree.strSearch(str.substr(0, str.size())));
                        }
                    }
                        //if there aren't multiple words in the string{
                    else outy.emplace_back(line, tree.strSearch(line));
                }bool filesGood = true;
            if(outy.empty() || outy[0].first.empty()){
                for(int i = 0; i < outy.size(); i++){
                    if(!outy[i].first.empty()) break;
                }
                std::cout << "Autocomplete Yielded No Results"<< std::endl;
                filesGood = false;
            }
            if(filesGood) {
                if (!secondRound)tree.searchFileWrite(ofname + "search.txt", outy);
                else {
                    std::string ForU = "_by_file";
                    if (user) ForU = "_by_user";
                    tree.searchFileWrite(ofname + std::to_string(iterations) + ForU + "_search.txt", outy);
                }
                std::cout << "The Tree Has Been Searched!" << std::endl;
            }
        }

        //auto:
        if (std::stoi(menuChoice) == 2) {
            std::string line;
            std::vector<std::pair<std::string, std::vector<std::string>>> outy;

            if(secondRound && user){
                line = userString;
                std::string str;
                std::stringstream ss(line);
                while (ss >> str) {
                    if (str[str.size() - 1] == ',' || str[str.size() - 1] == '.') str = str.substr(0, str.size() - 1);
                    outy.emplace_back(str, (tree.autoComp(str)));
                }
            }else while (std::getline(ifs, line)) {
                    if(line.empty())continue;

                    //If there are multiple words in the input string
                    //this calls insert for each individual word in the string
                    bool many = false;
                    for (int i = 0; i < line.size(); i++) {
                        if (line[i] == ' ') {
                            many = true;
                            break;
                        }
                    }
                    //if there are multiple words in the string{
                    if (many) {
                        std::string str;
                        //storing the string in a string stream lends to easy traversal
                        std::stringstream ss(line);
                        while (ss >> str) {
                            if (str[str.size() - 1] == ',' || str[str.size() - 1] == '.')
                                str = str.substr(0, str.size() - 1);
                            outy.emplace_back(str.substr(0, str.size()), (tree.autoComp(str.substr(0, str.size()))));
                        }
                    }
                        //if there aren't multiple words in the string{
                    else outy.emplace_back(line, (tree.autoComp(line)));
                }bool filesGood = true;
            if(outy.empty() || outy[0].second[0].empty()){
                for(int i = 0; i < outy.size(); i++){
                    for(int j = 0; j < outy[i].second.size(); j++){
                        if(!outy[i].second[j].empty()) break;
                    }
                }
                std::cout << "Autocomplete Yielded No Results"<< std::endl;
                filesGood = false;
            }
            if(filesGood){
                if(!secondRound)tree.autoFileWrite(ofname + "_comp.txt", outy);
                else{
                    std::string ForU = "_by_file";
                    if(user) ForU = "_by_user";
                    tree.autoFileWrite(ofname + std::to_string(iterations) + ForU + "_comp.txt", outy);
                }

                std::cout << "The Text Is Complete!" << std::endl;
            }
        }

        std::cout << "Would You Like To Continue?" << std::endl;
        std::cout << "0: Yes" << std::endl;
        std::cout << "1: No" << std::endl;
        std::cout << "Type 0, or 1: ";
        theEnd.resize(theEnd.size()+1);
        std::cin >> theEnd[theEnd.size()-1];
        std::cout << std::endl;
        if (theEnd[theEnd.size()-1] == "1" || theEnd[theEnd.size()-1] == "q" || theEnd[theEnd.size()-1] == "Q") return 0;
        else{
            while(theEnd[theEnd.size()-1] != "0"){
                if (theEnd[theEnd.size()-1] == "1" || theEnd[theEnd.size()-1] == "q" || theEnd[theEnd.size()-1] == "Q") return 0;
                std::cout << "Type 0, or 1: ";
                std::cin >> theEnd[theEnd.size()-1];
            }
        }
        std::cout << std::endl;
        secondRound = true;
        iterations++;
    }
}
