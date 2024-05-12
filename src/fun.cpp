// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int NumberOfWordsWithoutDigits = 0;
    bool ContainsDigit = false;
    bool ContainsLetter = false;
    while (*str != '\0') {
        //Чернышов И. идем по строка пока не дойдем до ее конца
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            // Функция isalpha проверяет аргумент,
            //передаваемый через параметр сharacter,
            //является ли он строчной или прописной буквой алфавита
            if (!ContainsLetter) {
                ContainsLetter = true;
            }
        } else if (std::isdigit(static_cast<unsigned char>(*str))) {
            ContainsDigit = true;
        } else {
            if (ContainsLetter && !ContainsDigit) {
                NumberOfWordsWithoutDigits++;
            }
            ContainsLetter = false;
            ContainsDigit = false;
        }
        str++;
    }
    if (ContainsLetter && !ContainsDigit) {
        NumberOfWordsWithoutDigits++;
    }
    return NumberOfWordsWithoutDigits;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
//тест2
