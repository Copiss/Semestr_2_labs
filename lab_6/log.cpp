#include "log.h"
///Позволяет довавить статическую переменную внутрь класса
///(создаёт объект в статической памяти)
std::ofstream Log::m_out;
LogLevel Log::m_logLevel;