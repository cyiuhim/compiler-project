#include "dfa.h"
#include "state_list.h"
#include <stdexcept>
#include <format>

// implements maximal munch algorithm, converts text into tokens
void DFA::parse(std::string text) {
    // TODO: implement maximal munch algorithm 
    size_t idx = 0;
    // check for invalid characters first 
    for (char c : text) {
        if (alphabet.find(c) == alphabet.end()) {
            throw std::runtime_error(std::format("Invalid character: '{}'", c));
        }
    }
    while (idx < text.length()) {
        State* cur_state = start_state;
        const size_t start_idx = idx;
        std::pair<size_t, State*> backtrack = {-1, nullptr};
        while (idx < text.length()) {
            if (accepting_states.contains(cur_state)) {
                backtrack = {idx, cur_state};
            }
            State* next_state = cur_state->get_next_state(text[idx]);
            if (!next_state) break;
            cur_state = next_state;
            idx++;
        } 
        if (!backtrack.second) {
            throw std::runtime_error("error parsing somewhere.");
        }
        TokenType token_type = accepting_states.at(cur_state);
        tokens.emplace_back(token_type, text.substr(start_idx, idx - start_idx));
    }
    process_identifiers();
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