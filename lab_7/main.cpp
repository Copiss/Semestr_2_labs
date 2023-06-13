#include <iostream>
#include <vector>
#include <math.h>

///Базовый класс фигур (родитель)
class Figyrie
{
protected:
    std::string m_color;      ///Цвет фируры
    double m_area;            ///Площадь фигуры
    std::vector <int> m_size; ///Размеры фигуры
    int X, Y;                 ///Координаты центра фигуры
public:
    ///Конструктор
    Figyrie (const std::string& color, std::vector<int>* size, int x, int y) : m_color(color), m_size(*size), X(x), Y(y)
    {
        std::cout << "Figyrie constructor" << "\n";
    }
    ///Вывод площади
    void Area()
    {
        std::cout << "The area of figure is " << m_area << "\n";
    }
    ///Деструктор
    virtual ~Figyrie()
    {
        std::cout << "Figyrie destructor" << "\n";
    }
};
///Дочерний класс кругoв (потомок)
class Circle : public Figyrie
        {
        public:
            ///Конструктор круга
            Circle(const std::string& color, std::vector<int>* size, int x, int y) : Figyrie(color, size, x, y)
            {
                std::cout << "Circle constructor" << "\n";
            }
            ///Деструктор круга
            virtual ~Circle()
            {
                std::cout << "Circle destructor" << "\n";
            }
            ///Площадь круга - пи * радиус в квадрате
            double getArea()
            {
                m_area = acos(-1)*pow(m_size[0],2);
            }
        };
///Дочерний класс треугольиков
class Trangle : public Figyrie
{
public:
    ///Конструктор треугольника
    Trangle(const std::string& color, std::vector<int>* size, int x, int y) : Figyrie(color, size, x, y)
    {
        std::cout << "Trangle constructor" << "\n";
    }
    ///Деструктор треугольника
    virtual ~Trangle()
    {
        std::cout << "Trangle destructor" << "\n";
    }
    ///Площадь прямоугольника по формуле Герона
    double getArea()
    {
        double pp = (m_size[0] + m_size[1] + m_size[2]) / 2; ///Полупериметр
        m_area = sqrt(pp*(pp - m_size[0])*(pp - m_size[1])*(pp - m_size[2]));
    }
};
///Дочерний класс прямоугольников
class Rectangle : public Figyrie
{
public:
    ///Конструктор прямоугольника
    Rectangle(const std::string& color, std::vector<int>* size, int x, int y) : Figyrie(color, size, x, y)
    {
        std::cout << "Rectangle constructor" << "\n";
    }
    ///Деструктор прямоугольника
    virtual ~Rectangle()
    {
        std::cout << "Rectangle destructor" << "\n";
    }
    ///Площадь прямоугольника - перемножение двух сторон
    double getArea()
    {
        m_area = m_size[0] * m_size[1];
    }
};
int main()
{
    std::vector<int> t = {4,3,5};
    Trangle treug("Blue", &t, 12, 13);
    std::vector<int> p = {2,8};
    Rectangle pram("Pink", &p, - 1, 8);
    std::vector<int> k = {6};
    Circle krug("Green", &k, 9, 0);
    treug.getArea();
    treug.Area();
    pram.getArea();
    pram.Area();
    krug.getArea();
    krug.Area();
}