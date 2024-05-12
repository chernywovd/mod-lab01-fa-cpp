// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    int NumberOfWordsWithoutDigits = 0;
    bool ContainsDigit = false;
    bool ContainsLetter = false;
    while (*str != '\0') {
        //Игорь Чернышов. Идем по строка пока не дойдем до ее конца
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            // Проверяем аргумент,
            //передаваемый через параметр сharacter,
            //является ли он строчной или прописной буквой алфавита
            if (!ContainsLetter) {
                ContainsLetter = true;
            }
        } else if (std::isdigit(static_cast<unsigned char>(*str))) {
        // Проверяем, если текущий символ является цифрой
            ContainsDigit = true;
        } else {
            if (ContainsLetter && !ContainsDigit) {
        //Если слово содержит буквы и
        //не содержит цифры, увеличиваем счетчик
                NumberOfWordsWithoutDigits++;
            }
            ContainsLetter = false;
            ContainsDigit = false;
        }
        str++;
    }
    if (ContainsLetter && !ContainsDigit) {
    //Если последнее слово содержит буквы
    //и не содержит цифры, увеличиваем счетчик
        NumberOfWordsWithoutDigits++;
    }
    return NumberOfWordsWithoutDigits;
    //Возвращаем итоговое количество слов без цифр
}

unsigned int faStr2(const char *str) {
       // Игорь Чернышов. Количество слов с первой заглавной латинской буквой
    unsigned int NumberOfWordsWithFirstCapitalLatinLetter = 0;
    // Признак начала слова
    bool isBeginOfWord = true;
    // Признак слова с первой заглавной латинской буквой
    bool isWordWithFirstCapitalLatinLetter = false;
    while (*str) {
        // Если начато слово и текущий символ - заглавная латинская буква,
        // то помечаем слово как имеющее первую заглавную латинскую букву
        // и снимаем признак начала слова
        if (isWordStart && std::isupper(static_cast<unsigned char>(*str))) {
            isWordWithFirstCapitalLatinLetter = true;
            isBeginOfWord = false;
        } else if (std::islower(static_cast<unsigned char>(*str))) {
        // Если текущий символ - строчная латинская буква,
        // то если слово не было начато или 
        //слово не имеет первую заглавную латинскую букву,
        // то снимаем признак слова с первой заглавной латинской буквой
            if (!isBeginOfWord && !isWordWithFirstCapitalLatinLetter) {
                isWordWithFirstCapitalLatinLetter = false;
            }
        } 
        // Если текущий символ - пробел или конец строки
        // или следующий символ - конец строки,
        // то если слово имеет первую заглавную латинскую букву,
        // то увеличиваем счетчик таких слов
        // и снимаем признаки слова с первой заглавной латинской буквой и начала слова
        else if (*(str + 1) == '\0')
            || std::isspace(static_cast<unsigned char>(*str)) {
            if (isWordWithFirstCapitalLatinLetter) {
                NumberOfWordsWithFirstCapitalLatinLetter++;
            }
            isWordWithFirstCapitalLatinLetter = false;
            isBeginOfWord = true;            
        } 
        // В противном случае снимаем признаки слова с первой заглавной латинской буквой и начала слова
        else {
            isWordWithFirstCapitalLatinLetter = false;
            isBeginOfWord = false;
        }
        str++;
    }
    return NumberOfWordsWithFirstCapitalLatinLetter;
}

unsigned int faStr3(const char *str) {
    return 0;
}
//тест2
