#include <cmath> 
#include <ctime>
#include "octagram/sampling/timer.hpp"

#include <iostream>

void Timer::start(){
    m_bRunning = true;
    m_StartTime = std::clock();
}

void Timer::stop(){
    m_EndTime = std::clock();
    m_bRunning = false;
}

double Timer::elapsedMilliseconds(){
    std::clock_t endTime;
    
    if(m_bRunning)
    {
        //endTime = std::chrono::system_clock::now();
        endTime = std::clock();
    }
    else
    {
        endTime = m_EndTime;
    }
    
    //return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    std::cout << "<-------------------->" << std::endl;
    std::cout << "st: " << std::clock()<< std::endl;
    std::cout << "ed: " << endTime<< std::endl;
    std::cout << "clock: " << CLOCKS_PER_SEC<< std::endl;
    return 1000.0 * (double)(endTime-m_StartTime) / CLOCKS_PER_SEC;
}

double Timer::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}
