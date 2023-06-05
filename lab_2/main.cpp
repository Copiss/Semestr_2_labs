#include <iostream>
//Подключение библиотеки
//Создание класса для работы сo строками
class String
{
private:
    size_t m_size;//Длина строки
    char* m_str;//Массив символов
public:
    //1.Базовые конструкторы
    String() : m_size(0), m_str(nullptr)
    {
        std::cout << "Basic constructor #0" << "\n";
    };

    String(char c, size_t size) : m_size(size), m_str(new char[m_size+1])
    {
        std::cout << "Basic constructor #1" << "\n";
        std::fill(m_str, m_str + m_size, c);
        m_str[m_size] = 0;
    }

    String(char* str) : m_size(sizeof(str)), m_str(new char[m_size+1])
    {
        std::cout << "Basic constructor #2" << "\n";
        std::copy(str, str + m_size, m_str);
        m_str[m_size] = 0;
    }
    //2.Конструктор копирования
    String(const String& other) : String(other.m_str)
    {
        std::cout << "Copy constructor" << "\n";
    }
    //3.Оператор присваивания копированием
    String& operator=(String temp)
    {
        std::cout << "Copy assignment operator" << "\n";
        std::swap(m_size, temp.m_size);
        std::swap(m_str, temp.m_str);
        return *this;
    }
    //4.Деструктор
    ~String()
    {
        std::cout << "Destructor" << "\n";
        if (m_str != nullptr)
        {
            delete[] m_str;
        }
    }
    //5.Операторы += и +
    String operator+=(const String c)
    {
        std::cout << "Operator +=" << "\n";
        size_t newSize = c.length();
        char* newStr = new char[m_size + newSize + 1];
        for (size_t i = 0; i < m_size; i++)
        {
            newStr[i] = m_str[i];
        }
        for (size_t i = 0; i < newSize; i++)
        {
            newStr[m_size + i] = c.m_str[i];
        }
        delete m_str;
        m_str = newStr;
        m_size += newSize;
        newStr[m_size] = '\0';
        return m_str;
    }

    String operator+(const String& c)
    {
        std::cout << "Operator +" << "\n";
        String a = *this;
        a += c;
        return a;
    }
    ///6.Оператор []
    char operator [] (const size_t i)
    {
        std::cout << "Operator []" << "\n";
        return m_str[i];
    }
    //7.Операторы <,>,==
    bool operator < (String& other) const
    {
        std::cout << "Operator <" << "\n";
        return (strcmp(this->m_str, other.m_str) < 0);
        //return m_size < other.m_size;
    }

    bool operator > (String& other) const
    {
        std::cout << "Operator >" << "\n";
        return (strcmp(this->m_str, other.m_str) > 0);
        //return m_size > other.m_size;
    }

    bool operator == (String& other) const
    {
        std::cout << "Operator ==" << "\n";
        return (strcmp(this->m_str, other.m_str) == 0);
        //return (m_size == other.m_size);
    }
    //9.Метод find - поиск первого вхождения в сторку слева
    int find(char c)
    {
        std::cout << "Method find" << "\n";
        for (int i = 0; i < m_size; i++)
            if (m_str[i] == c)
            {
                return i;
            }
    }
    //10.Метод length - длина сторки
    size_t length() const
    {
        std::cout << "length = " << (m_size) << "\n";
        return m_size;
    }
    //11.Метод c_str - получить массив char
    char* c_str()
    {
        std::cout << "Method c_str" << "\n";
        return m_str;
    }
    //12.Метод at для получения доступа к элементу строки с проверкой на выход за пределы строки
    char at(size_t i)
    {
        std::cout << "Method at" << "\n";
        if (i < m_size)
            return m_str[i];
        else
            std::cout << "out of range";
    }

    friend std::ostream& operator << (std::ostream& out, const String& s);
    friend std::istream& operator >> (std::istream& in, String& s);
};
//8.Операторы ввода и вывода в поток
std::istream& operator>> (std::istream& in, String& s)
{
    char d;
    while (in.get(d))
    {
        if (d == '\n' || d == ' ')
        {
            break;
        }
        char* f = new char[s.m_size + 1];
        std::copy(s.m_str, s.m_str + s.m_size, f);
        f[s.m_size] = d;
        delete[] s.m_str;
        std::copy(f, f + s.m_size + 1, s.m_str);
        s.m_size += 1;
        delete[] f;
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, const String& s)
{
    for (int i = 0; i < s.m_size; i++)
    {
        out << s.m_str[i];
    }
    return out;
}

int main()
{
    String s1('a', 5);
    String s2("Hello ");
    String s3("world!");
    String s4;
    String s5("Hello world!aaaaa");
    std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << "\n";
    s4 = s2 + s3;
    s4 += s1;
    std::cout << "s2 + s3 + s1 = " << s4 << "\n";
    std::cout << s3[2] << "\n";
    std::cout << (s4 == s5) << "\n";
    int f = s4.find('e');
    std::cout << f << "\n";
    std::cout << s2.c_str() << "\n";
    std::cout << s2.at(2) << "\n";
    std::cout << s1 << "; " << s2 << "; " << s3 << "; " << s4 << "; " << s5 << "\n";
    return 0;
}

