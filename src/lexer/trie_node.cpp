#include "trie_node.h"

TrieNode::TrieNode() : children(26, nullptr), end_token {std::nullopt} {
    
}

TrieNode::~TrieNode() {
    for (auto child : children) {
        if (child != nullptr) {
            delete child;
        }
    }
}

void TrieNode::add_word(std::string word, TokenType token) {
    if (word.empty()) {
        end_token = token;
        return;
    }
    char first_char = word[0];
    if (!children[first_char - 'a']) {
        children[first_char - 'a'] = new TrieNode;
    }
    children[first_char - 'a']->add_word(word.substr(1), token);
}
