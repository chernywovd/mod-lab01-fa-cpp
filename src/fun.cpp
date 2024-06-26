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
        if (isBeginOfWord
            && std::isupper(static_cast<unsigned char>(*str))) {
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
        }  else if (std::isspace(static_cast<unsigned char>(*str))
            || *(str + 1) == '\0')  {
        // Если текущий символ - пробел или конец строки
        // или следующий символ - конец строки,
        // то если слово имеет первую заглавную латинскую букву,
        // то увеличиваем счетчик таких слов
        // и снимаем признаки слова с первой
        //заглавной латинской буквой и начала слова
            if (isWordWithFirstCapitalLatinLetter) {
                NumberOfWordsWithFirstCapitalLatinLetter++;
            }
            isWordWithFirstCapitalLatinLetter = false;
            isBeginOfWord = true;
        } else {
        // В противном случае снимаем признаки слова
        //с первой заглавной латинской буквой и начала слова
            isWordWithFirstCapitalLatinLetter = false;
            isBeginOfWord = false;
        }
        str++;
    }
    return NumberOfWordsWithFirstCapitalLatinLetter;
}

unsigned int faStr3(const char *str) {
    //Игорь Чернышов. Переменная для
    //подсчета количества слов
    unsigned int CountOfWords = 0;

    // Переменная для подсчета длины предложения
    unsigned int LengthOfSentense = 0;

    // Переменная для подсчета длины слова
    unsigned int LengthOfWord = 0;

    // Цикл по строке
    while (*str != '\0') {
        // Если символ является буквой
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            // Увеличиваем длину слова
            LengthOfWord++;
        } else {
            // Если длина слова больше нуля
            if (LengthOfWord > 0) {
                // Значит, закончилось слово
                // Увеличиваем количество слов
                CountOfWords++;
                // Увеличиваем длину предложения на длину слова
                LengthOfSentense += LengthOfWord;
                // Обнуляем длину слова
                LengthOfWord = 0;
            }
        }
        // Переходим к следующему символу
        str++;
    }
    //  Если длина слова больше нуля
    if (LengthOfWord > 0) {
        // Значит, закончилось предложение
        // Увеличиваем количество слов
        CountOfWords++;
        // Увеличиваем длину предложения на длину слова
        LengthOfSentense += LengthOfWord;
    }
    // Подсчитываем среднюю длину слова
    float average;
    //  Если количество слов больше нуля
    if (CountOfWords > 0) {
        // Средняя длина слова равна длине
        //предложения, деленной на количество слов
        average = static_cast<float>(LengthOfSentense)
        / static_cast<float>(CountOfWords);
    } else {
        // Если количество слов равно нулю
        // Средняя длина слова равна нулю
        average = 0;
    }
    // Возвращаем среднюю длину слова,
    //округлённую до ближайшего целого
    return (unsigned int)(average + 0.5);
}
//тест2
