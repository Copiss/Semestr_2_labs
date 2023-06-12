#pragma once
#include <iostream> ///Подключение библиотек
#include <fstream>
#include <chrono>
///Различные уровни ведения журнала
enum class LogLevel
{
    DEBUG,
    RELEASE
};
///Создание класса для логирования
class Log
{
private:
    static std::ofstream m_out; ///Запись в файл
    static LogLevel m_logLevel; ///Уровень журнала
public:
    ///Функция, задающая уровень журнала
    static void SetLogLevel(LogLevel logLevel)
    {
        m_logLevel = logLevel;
    }
    ///Функция, устанавливающая путь для записи логов (открывает файл)
    static void SetLogPath(const std::string& path)
    {
        m_out.open(path);
    }
    ///Метод вывода сообщения в файл, получающий на вход какое-либо сообщение
    static void Write(const std::string& msg)
    {
        time_t now = time(0); ///Вычисление времени вывода ошибки
        char* dt = ctime(&now); ///Преобразование времени в стандартный формат
        if (m_logLevel == LogLevel::DEBUG)
        {
            std::cerr << dt << msg << std::endl; ///Вывод времени и сообщения в консоль

        }
        m_out<< dt <<msg<<std::endl; ///Вывод времени и сообщения в файл
        m_out.flush();
    }
    ///Медод, выводящий информацию (работает как и Write)
    static void Info(const std::string& msg)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::RELEASE)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
    ///Медод, выводящий Debug (работает как и Write)
    static void Debug(const std::string& msg)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
    ///Медод, выводящий ошибки (работает как и Write)
    static void Error(const std::string& msg)
    {time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
};