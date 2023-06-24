#include <iostream>
template<typename T>                                      ///Шаблон, позволяющий использовать любой тип данных
static void convert(T* source, T* destination, int size)  ///Функция принимает указатели на 2 массива и размер массивов
{
    const long long* pointer1 = (const long long*)source; ///Указатель на начало первого массива
    long long* t_pointer1 = (long long*)destination;      ///Указатель на начало второго массива
    int m = sizeof(int) * size / sizeof(long long);       ///Количество целых 8-байтовых участков, которые можно перенести
    for (int i = 0; i < m; i++)                           ///Цикл копирования
    {
        *(t_pointer1++) = *(pointer1++);                  ///После копирования указатели сдвигаются вправо на 1 элемент
    }
    char* pointer2 = (char*)pointer1;                     ///Указатель на оставшиеся данные в первом массиве
    char* t_pointer2 = (char*)t_pointer1;                 ///Указатель на второй массив
    m = (sizeof(int) * size) % sizeof(long long);         ///Остаток (если он есть) при переносе по 8 байтов
    for (int i = 0; i < m; i++)                           ///Байтовое копирование
    {
        *(t_pointer2++) = *(pointer2++);                  ///После копирования указатели сдвигаются вправо на 1 элемент
    }
}

int main()
{
    ///Пример работы программы (копируем из одного int-ового массива в другой, копируя сначала по 8 байт, а затем по байту)
    int source[5] = {1, 2, 3, 4, 5};
    int destination[5];
    convert(source, destination, 5);
    for (int i = 0; i < 5; i++)
    {
            std::cout << destination[i] << " ";
    }
    return 0;
}