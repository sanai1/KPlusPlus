#pragma once

enum class TokenTypeEnum {
    SERVICE_WORD,
    ID,

    // операция
    PLUS,
    PLUSPLUS,

    MINUS,
    MINUSMINUS,

    MULTIPLY,
    MULTIPLYMULTIPLY,

    DIVISION,

    PERCENT,

    ASSIGN,
    PLUSASSIGN,
    MINUSASSIGN,
    MULTIPLYASSIGN,
    DIVISIONASSIGN,
    ASSIGNASSIGN,
    PERCENTASSIGN,

    // сравнения
    MORE,
    MOREASSIGN,
    LESS,
    LESSASSIGN,
    EXCLAMATIONMARK,
    EXCLAMATIONMARKASSIGN,

    // скобки
    LPAREN, // круглые
    RPAREN,

    LSQUAREBRACKET, // квадратные
    RSQUAREBRACKET,

    LCURLYBRACE, // фигурные
    RCURLYBRACE,


    SEMICOLON, // точка с запятой
    COLON, // двоеточие
    COMMA, // запятая
    POINT, // точка

    // литералы
    NUMBER_LITERAL,
    STRING_LITERAL,


    // встроенные функции
    PRINT,
    PRINTLN,
    INPUT,

    OTHER,
    END
};