#include <iostream> //подключение библиотек
#include <string>
#include "head.hpp" //подключение файла

int main(){
    Pressmark cipher(0); //Создание элемента класса
    cipher.Encode(); //Шифрование
    cipher.Decode(); //Дешифровка

    return 0;
}
