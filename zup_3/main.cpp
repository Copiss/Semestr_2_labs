#include <iostream> ///Подключение библиотек
#include <math.h>
///Создание класса для работы с роботом
class KinematicSolver
{
private:
    double m_alpha; ///Угол поворота первого двигателя (в радианах)
    double m_beta; ///Угол поворота второго двигателя (в радианах)
    double m_l1; ///Длина звена между двигателями
    double m_l2; ///Длина зфена между двигателем и фломастером(рабочий орган робота)
    double m_m[2] = { NULL }; ///Координаты пишущей части фломастера
public:
    ///Функция задания длин звеньев и координат точки
    void set()
    {
        std::cout<<"Enter the length of the link between the engines L1:"<< std::endl;
        std::cin >> m_l1;
        std::cout<<"Enter the length of the link between the motor and the marker pen L2:"<< std::endl;
        std::cin >> m_l2;
        std::cout<<"Enter the coordinates of the point M(x,y):"<< std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cin >> m_m[i];
        }
    }
    ///Функция проверки возможности операции
    int check()
    {
        if ((m_l1 == NULL) ||  (m_l2 == NULL)) ///Если l1 и l2 не введены - некорректный ввод
        {
            std::cout << "incorrect length" << std::endl;
            return 0;
        }
        if (m_m[0] == NULL || m_m[1] == NULL) ///Если не введены координаты точек - некорректный ввод
        {
            std::cout << "incorrect m(x,y)" << std::endl;
            return 0;
        }
        if (sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1])>m_l1+m_l2) ///Если точка находится дальше досягаемости - операция невозможна
        {
            std::cout << "coordinate far" << std::endl;
            return 0;
        }
        return 1;
    }
    ///Функция рассчитывания углов по заданным координатам
    void Solve()
    {
        double l3 = sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1]); ///Расстояние от начала координат до введённой точки
        double a3 = acos((pow(m_l2,2)+pow(m_l1,2)-pow(l3,2))/(2*m_l1*m_l2)); ///Угол между двумя звеньями находим по теореме косинусов
        m_beta = 180-(a3*180)/3.141592653589793; ///Ищем сопряжённый ему угол, переводя в градусы (он и будет углом beta)
        double a2 = acos((pow(l3,2)+pow(m_l1,2)-pow(m_l2,2))/(2*m_l1*l3)); ///Угол между первым звеном и отрезком l3
        double gamma = acos(m_m[0]/l3); ///Находим угол между осью Ox и отрезком l3
        m_alpha=(a2+gamma)*180/3.141592653589793; ///Находим угол alpha, складывая его из двух найденных углов
        std::cout <<"alpha: "<< m_alpha << " beta: " << m_beta; ///Выводим найденные углы
    }
};

int main()
{
    KinematicSolver a;
    a.set();
    if(a.check()==1)
        a.Solve();
    return 0;
}