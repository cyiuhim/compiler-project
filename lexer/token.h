#ifndef __TOKEN_H__
#define __TOKEN_H__

enum token_type_t {
    START, // start
    END, // end
    SOF, // start of file
    EOF, // end of file
    FLAP, // flap (let)
    IDENTIFIER, // equals sign
    PERIOD, // end of statement
    HONK, // honk
    PARAM_OPEN_PARAN, // <<
    PARAM_CLOSE_PARAN, // >>
    FUNC_AT // function at symbol, @
};

#endif 