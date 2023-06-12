//Подключение библиотек
#include <SFML/Graphics.hpp> 
#include <string>
#include <chrono>
#include <thread>
#include <iostream> 

class AnimatedText //Создание класса
{
private:

    float duration = 0; // Создание переменной времени выхода строки на экран
    float time_one_symbol = 0; //Создание переменной времени выхода одного символа на экран

public:

    std::string m_str; //Создание строки

    AnimatedText(const std::string& str, float time)
    {
        m_str = str; //Создание строки от позьзователя
        duration = time; //Задание времени вывода строки от пользователя
        time_one_symbol = (duration / m_str.length()); //Нахождение времени вывода одного символа
    }

    void Sleep() 
    {
        std::this_thread::sleep_for(std::chrono::seconds(int(time_one_symbol))); // функция приостановки программы на найденное время вывода одного символа.
    }

};

int main()
{

    std::string stroka;
    std::getline(std::cin, stroka); //Получение строки от пользователя

    int time;
    std::cin >> time; //Получение времени от пользователя

    AnimatedText text1(stroka, time);//Создание элемента класса AnimatedText (вывод в консоль)

    AnimatedText text2(stroka, time);//Создание элемента класса AnimatedText (вывод в окно sfml)

    std::string written_string = ""; //Создание строки выведенных элементов

    sf::Text text; //Создание элемента Text
    sf::Font font; //Объявление шрифта
    if (!font.loadFromFile("EnglishWd.ttf"))
    {
        // error...
    }
    text.setFont(font); //Задание шрифта для текста
    text.setPosition(200, 275);//Задание позиции текста
    text.setFillColor(sf::Color(252, 137, 172, 0xFF));//Задание цвета такста
    text.setCharacterSize(50); // Задание размера текста
    text.setString(text2.m_str); //Присвоение строке теккста

    int c = 0; // Счётчик выведенных символов

   sf::RenderWindow window(sf::VideoMode(800, 600), "animation text"); //Создание окна, установление разрешения, названия
   
    while (window.isOpen()) //До тех пор, пока открыто окно выполняется:
    {
        //Добавление работы окна
        window.setFramerateLimit(20);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //Прорисовка
        if (c < text2.m_str.length())
        {
            written_string += text1.m_str[c];
            text.setString(written_string);
            window.draw(text);
            text2.Sleep();
            window.display();
            window.clear();
        }
        c++; //переключаемся на следующий символ
    }
     //Вывод на консоль
    for (int i = 0; i < stroka.length(); i++)
    {
        std::cout << text1.m_str[i];
        text1.Sleep();
    }
    return 0;
}