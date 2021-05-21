/**
* @file MyClass.h
* @author Самборский И.С.
* @version 1.0
* @brief Описание класса MarshCipher
* @date 21.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <locale>
#include <cmath>
#include <exception>
#include <cctype>
#include <vector>
using namespace std;
///@brief Класс зашифрования и расшифрования текста методом табличной маршрутной перестановки.
///@warning Реализация только для русского и английского языка.
class MarshCipher
{
private:
///@brief Ключ шифрования методом табличной маршрутной перестановки.
///@details Ключ определяет количество столбцов таблицы,по которой будет производиться работа с текстом.
    int key;
    /**@brief Метод, вычисляющий число строк таблицы.
     * @param text - текст, введенный пользователем для выполнения операций зашифрования/расшифрования.
     * @details Это приватный метод, включенный в методы Encryct и Decryct.
     * @return Целое число строк.
     **/
    int StrNum(const wstring &text);
    /**
     * @brief Метод, вычисляющий число пробелов в таблице.
     * @param text - текст, введенный пользователем для выполнения операций зашифрования/расшифрования.
     * @details Это приватный метод, включенный в метод Decryct.
     * @return Целое число пробелов.
     *
    **/
    int SpaceNum(const wstring&text);
public:
    /**
        * @brief Конструктор ключа строкой.
        * @param key - ключ, вводимый в виде строки С++.
        * @details Полученный ключ в виде строки проверяется методом CheckKey на корректность ввода.
        * Далее с помощью функции stoi строка переводится в целое число и присваивается полю key.
        **/
    MarshCipher(const wstring &key);
    /**
    * @brief Функция зашифрования методом табличной маршрутной перестановки.
    * @param text - текст, введенный пользователем для выполнения операции зашифрования.
    * @details <p>Первончально осуществляется проверка текста на корректность ввода.
    * Формируется двумерный массив (таблица) с помощью метода StrNum.
    * Далее текст записывается в массив по маршруту записи: слева-направо, сверху-вниз.</p><br>
    * @code
    int t=0;
    int size = text.size();
    for (int i=0; i<str; i++) {
        for (int k=0; k<key; k++,t++) {
            if (i*key+k<size+1) {
                arr[i][k] = text [t];
            } else {
                arr[i][k] = '\0';
            }
        }
    }
    * @endcode
      <p>Далее из заполненного массива текст выписывается в строку по маршруту считывания: справа-налево, сверху-вниз. 
    * Это и есть зашифрованная строка.</p><br>
    * @code
    int l=0;
    for (int k=key-1; k>-1; k--) {
        for (int i=0; i<str; i++,l++) {
            if (arr[i][k]!='\0') {
                newtext[l]=arr[i][k];
            } else {
                break;
            }
        }
    }
    * @endcode
    * @return Зашифрованная методом табличной машрутной перестановки строка.
    **/
    wstring Encryct(const wstring&text);
    /**
     * @brief Функция расшифрования методом табличной маршрутной перестановки.
     * @param text - текст, введенный пользователем для выполнения операции расшифрования.
     * @details Первончально осуществляется проверка текста на корректность ввода.
     * Формируется двумерный массив (таблица) с помощью методов StrNum и SpaceNum.
     * Далее текст записывается в массив по маршруту считывания: справа-налево, сверху-вниз.
     * Spacenum - счетчик пробелов в цикле. Пока он не равен 0 в нижнем элементе столбца будет ставиться пробел.
     * @code
     int l=0;
     for (int k=key-1; k>-1; k--) {
        if (spacenum == 0) {
            for (int i=0; i<str; i++,l++) {
                arr[i][k]=text[l];
            }
        } else {
            for (int i=0; i<str-1; i++,l++) {
                arr[i][k]=text[l];
                arr[str-1][k] = '\0';
            }
            spacenum--;
        }
     }
     * @endcode
     Далее из заполненного массива текст выписывается в строку по маршруту записи: слева-направо, сверху-вниз. Это и есть расшифрованная строка.
     *@code
     int t=0;
     for (int i=0; i<str; i++) {
         for (int k=0; k<key; k++,t++) {
             if (arr[i][k]!='\0') {
                 newtext[t] = arr[i][k];
             } else {
                 break;
             }
         }
     }
     *@endcode
     * @return Рашифрованная методом табличной машрутной перестановки строка.
     **/
    wstring Decryct(const wstring&text);
};
