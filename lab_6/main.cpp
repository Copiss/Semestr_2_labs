#include <iostream>
#include "log.h"

int main()
{
    Log::SetLogPath("log.txt");
    Log::SetLogLevel(LogLevel::DEBUG);
    /// Log::SetLogLevel(LogLevel::RELEASE);///отключение всех логов
    Log::Write("Hello, World!");
    Log::Info("Laboratory #6");
    Log::Debug("Work is done");
    Log::Error("ERROR!!");
    return 0;
}
