#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <fstream>
#include <mutex>

#ifdef _WIN32
#ifdef LOGGER_BUILDING_DLL
#define LOGGER_API __declspec(dllexport)
#else
#define LOGGER_API __declspec(dllimport)
#endif
#else
#define LOGGER_API
#endif

LOGGER_API class Logger {
public:
    //获取单例
    static Logger& getInstance();
    //禁止拷贝和赋值
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    //记录日志
    void log(const std::string & message);
    ~Logger();
private:
    Logger();
    std::ofstream logFile;
    std::mutex mutex;
};

#endif //LOGGER_LOGGER_H
