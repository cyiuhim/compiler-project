#ifndef __TOKEN_H__
#define __TOKEN_H__

enum TokenType {
    START, // start
    END, // end
    SOF, // start of file
    _EOF, // end of file
    IDENTIFIER, // equals sign
    PERIOD, // end of statement
    PARAM_OPEN_PARAN, // <<
    PARAM_CLOSE_PARAN, // >>
    FUNC_AT, // function at symbol, @

    // keywords
    FLAP, // flap (let)
    HONK // honk
};

#endif 