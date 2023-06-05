#include <fstream> ///Подкючение библиотеки для работы с файлами

class Pressmark /// Создание класса для шифрования
{
private:
    unsigned int m_fibb[30]; ///Числа Фиббоначи
    std::string words[30] = {}; ///Массив строк
    int t; ///Счётчик

    void Fibonacci_numbers() ///Функция для присваивания чисел Фиббоначи словам
    {
        m_fibb[0]=1;
        m_fibb[1]=2;
        for (int i=2; i<30; i++)
        {
            m_fibb[i]=m_fibb[i-2]+m_fibb[i-1];
        }
    }

public:
    ///Базовый конструктор
    Pressmark(int unless)
    {
        Fibonacci_numbers();
    }
    ///Функция кодирования
    void Encode()
    {
        std::ifstream in ("C:/Users/user/Desktop/Prog-frog/zup_1/text.txt", std::ios::in);
        t = 0;
        std::string word;
        if (!in)
            std::cout<<"Error";
        while (in >> word)
        {
            words[t] = word;
            t++;
        }
        in.close();
    }
    ///Функция декодирования
    void Decode()
    {
        int key[30];
        for(int i=0; i < t; i++)
        {
            std::cin>>key[i];
        }
        for (int p = 0; p < t; p++)
        {
            for (int l = 0; l < 30; l++)
            {
                if (key[p] == m_fibb[l])
                {
                    std::cout << words[l] << " ";
                }
            }
        }
        for (int j = 0; j < t-1; j++)
        {
            for(int k = j+1; k < t; k++)
            {
                if (key[j] > key[k])
                {
                    std::swap(key[k], key[j]);
                }
            }
        }
        std::cout << "\n";
        for (int p=0; p<t; p++)
        {
            for(int l=0; l<30; l++)
            {
                if (key[p] == m_fibb[l])
                {
                    std::cout << words[l] << " ";
                }
            }
        }
    }

};