#include <iostream>

int main()
{
    system("chcp 65001");
    const int N = 7; ///константная переменная, количество элементов в массиве
    int mas_a [N] = {1,2,3,4,5}; ///Заполняем первый массив

    std::cout<<"То, что нужно скопировать: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << mas_a[i];
    }
    std::cout << "\n";

    int mas_b[N] = {0}; ///Создаём второй массив (для примера, нулевой)

    std::cout << "До: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << mas_b[i];
    }
    std::cout << "\n";

    std::copy(std::begin(mas_a),std::end(mas_a),mas_b); /// copy копирует машинные слова(т.е 4 или 8 байт)

    std::cout << "После: ";
    for (int i = 0; i < N; i++)
        std::cout << mas_b[i];
    return 0;
}

///for(int i = 0; i < N; ++i)
///    mas_b[i] = mas_a[i];
///Таким образом, процессор копирует по 1 байту и придется выполнить N копирований