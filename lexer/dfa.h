#ifndef __DFA_H__
#define __DFA_H__

#include <set>
#include <string>
#include "state.h"
#include "token.h"

class DFA {
public: 
    std::vector<std::pair<TokenType, std::string>> parse (std::string text);

private:
    std::set<char> alphabet;
    State* start_state;
    std::vector<State*> states;
    std::set<State*> accepting_states;
};

#endif 
