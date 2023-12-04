#include <iostream>
#include "Trie.h"

int main(int argc, char* argv[]) {
    int mode = std::stoi(argv[2]);
    std::string ifname = argv[1];
    std::ifstream ifs(ifname);

    std::string ofname = ifname.substr(0, ifname.rfind('.')) + "_output_" + std::to_string(mode) + ".dot";
    std::cout << ifname << std::endl;
    std::cout << ofname << std::endl;
    Trie tree;
    std::string line;

    std::getline(ifs, line);

    tree.insert(line);
    tree.print(ofname);
}
