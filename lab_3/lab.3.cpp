#include <iostream> //Подключение библиотеки

class Complex //Создание класса для работы с комплексными числами
{
private:
    double m_real_part;//Действительная часть
    double m_imag_part;//Мнимая часть
public:
    //1.Базовый конструктор
    Complex(double real_part = 0.0, double imag_part = 0.0) : m_real_part(real_part), m_imag_part(imag_part)
    {
        std::cout << "Basic constructor" << m_real_part << " " << m_imag_part << std::endl;
    }
    //2.Конструктор копирования
    Complex(const Complex& z)
    {
        std::cout << "Copy constructor" << std::endl;
        m_real_part = z.m_real_part;
        m_imag_part = z.m_imag_part;
    }
    //3.Оператор присваивания копирования
    Complex& operator=(Complex z)
    {
        std::cout << "Copy assigment operator" << std::endl;
        std::swap(m_real_part, z.m_real_part);
        std::swap(m_imag_part, z.m_imag_part);
        return *this;
    }
    //4.Деструктор
    ~Complex() 
    {
        std::cout << "Destructor" << std::endl;
    }
    //5.Операторы += и +, *= и *
    Complex& operator+=(const Complex& z)
    {
        std::cout << "operator += " << std::endl;
        (*this).m_real_part += z.m_real_part;
        (*this).m_imag_part += z.m_imag_part;
        return *this;
    }

    Complex operator+ (Complex& z)
    {
        std::cout << "operator + " << std::endl;
        double a = m_real_part + z.m_real_part;
        double b = m_imag_part + z.m_imag_part;
        Complex new_z(a, b);
        return new_z;
    }

    Complex& operator*= (Complex& z)
    {
        std::cout << "operator *= " << std::endl;
        double a = m_real_part * z.m_real_part - m_imag_part * z.m_imag_part;
        double b = m_real_part * z.m_imag_part + m_imag_part * z.m_real_part;
        m_real_part = a; m_imag_part = b;
        return *this;
    }

    Complex operator* (Complex& z) const
    {
        std::cout << "operator * " << std::endl;
        double a = m_real_part * z.m_real_part - m_imag_part * z.m_imag_part;
        double b = m_real_part * z.m_imag_part + m_imag_part * z.m_real_part;
        Complex new_z(a, b);
        return new_z;
    }
    //6.Оператор ++ префиксный и постфиксный (увеличение действительной части числа на 1)
    Complex& operator++()
    {
        m_real_part++;
        return *this;
    }

    Complex operator++(int)
    {
        Complex copy = *this;
        m_real_part++;
        return copy;
    }
    friend std::ostream& operator<< (std::ostream& out, const Complex& z);
    friend std::istream& operator>> (std::istream& in, Complex& z);
};
//7.Операторы ввода и вывода
std::ostream& operator<< (std::ostream& out, const Complex& z)
{
    out << z.m_real_part << "+" << z.m_imag_part << "i";
    return out;
}

std::istream& operator>> (std::istream& in, Complex& z)
{
    in >> z.m_real_part >> z.m_imag_part;
    return in;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Complex z; Complex z_7;
    Complex z_ = z + z_7;
    return 0;

    //Создание двух комплексных чисел (пример базового конструктора)
    Complex z_1(4, 7), z_2(3, 2), z_3(2, 4), z_4(1, 8); 

    //Вывод созданных чисел (также пример оператора вывода)
    std::cout << "Созданы числа " << z_1 << " " << z_2 << " " << z_3 << " " << z_4 << std::endl << std::endl;

    //Пример оператора +=
    z_3 += z_4; 
    std::cout << "Сумма 3 и 4 числа = " << z_3 << std::endl << std::endl;

    //Пример оператора +
    std::cout << "Сумма 1 и 2 числа = " << (z_4 = z_1 + z_2) << std::endl << std::endl;

    //Пример оператора *=
    z_1 *= z_2;
    std::cout << "Произведение 1 и 2 числа = " << z_1 << std::endl << std::endl;

    //Пример оператора *
    std::cout << "Произведение 2 и 3 числа = " << z_2 * z_3 << std::endl << std::endl; 

    return 0;
}
