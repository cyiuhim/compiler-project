#ifndef __TOKEN_H__
#define __TOKEN_H__

enum TokenType {
    START, // start
    END, // end
    SOF, // start of file
    _EOF, // end of file
    IDENTIFIER, // any identifier
    NUMBER, // number
    ASSIGN, // =
    PERIOD, // end of statement
    PARAM_OPEN_PARAN, // <<
    PARAM_CLOSE_PARAN, // >>
    FUNC_AT, // function at symbol, @
    COMMENT, // comment
    SPACES, // one or more spaces

    // keywords
    FLAP, // flap (let)
    HONK // honk
};

#endif 