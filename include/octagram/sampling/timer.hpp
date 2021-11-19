#pragma once
#include <ctime>

class Timer
{
public:
    void start();
    void stop();
    double elapsedMilliseconds();
    double elapsedSeconds();
private:
    std::clock_t m_StartTime;
    std::clock_t m_EndTime;
    bool m_bRunning = false;
};