#include "dfa.h"
#include "state_list.h"
#include <stdexcept>
#include <format>

// implements maximal munch algorithm, converts text into tokens
void DFA::parse(std::string text) {
    // TODO: implement maximal munch algorithm 
    int idx = 0;
    // check for invalid characters first 
    for (char c : text) {
        if (alphabet.find(c) == alphabet.end()) {
            throw std::runtime_error(std::format("Invalid character: '{}'", c));
        }
    }
    while (idx < text.length()) {
        
    }
}

void DFA::process_identifiers() {
    for (auto& token : tokens) {
        if (token.first == IDENTIFIER) {
            auto new_token_type = keyword_dict.check_word(token.second);
            if (new_token_type.has_value()) {
                token.first = *new_token_type;
            }
        }
    }
}

std::vector<std::pair<TokenType, std::string>> DFA::get_result() {
    return tokens;
}

void DFA::populate_alphabet(std::string valid_chars) {
    for (char c : valid_chars) {
        alphabet.insert(c);
    }
}

void DFA::set_start_state(State* state) {
    start_state = state;
}

void DFA::add_state(State* state) {
    states.insert(state);
}

void DFA::add_accepting_states(std::vector<std::pair<State*, TokenType>> state_map) {
    for (auto& [state, token] : state_map) {
        accepting_states[state] = token;
    }
}

void DFA::add_keywords(std::vector<std::pair<std::string, TokenType>> keywords) {
    for (const auto& keyword_pair : keywords) {
        keyword_dict.add_word(keyword_pair.first, keyword_pair.second);
    }
}

DFA::DFA() : start_state{nullptr} {
    populate_state_list();
    populate_alphabet(goose_alphabet);
    add_accepting_states(goose_state_map);
    add_keywords(goose_keywords);
}