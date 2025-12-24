#include <iostream>
#include <fstream>
#include <string>

#include <dfa.h>

int main(int argc, char* argv[]) {
    // usage: goose basic.goose
    if (argc != 2) {
        std::cerr << "Usage: goose basic.goose" << std::endl;
        return 1;
    }
    std::string file_name {argv[1]};
    if (file_name.length() < 7 || file_name.substr(file_name.length() - 6) != ".goose") {
        std::cerr << "Invalid file name provided" << std::endl;
        return 1;
    }
    std::ifstream in {file_name};
    if (in.fail()) {
        std::cerr << "File doesn't exist" << std::endl;
        return 2;
    }
    std::string text;
    std::string line;
    while (in >> line) {
        text += line;
        text += '\n';
    }
    DFA dfa;
    auto tokens = dfa.parse(text);
}