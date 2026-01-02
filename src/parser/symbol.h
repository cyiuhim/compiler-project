#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include <set>

enum SymbolType {
    // non-terminals
    Start,
    FuncDfn,
    FuncDfns,

};

inline std::set<SymbolType> terminals = {};

#endif 
