#ifndef CLOCK_HPP
#define CLOCK_HPP


#include <chrono>

template<typename Precision>
class Clock
{
public:
    using Clk = std::chrono::steady_clock;

    Clock();

    Precision restart();
    Precision elapsed();

private:
    Clk::time_point time;

    constexpr static auto NANO = 10e8;
};

#include "Clock.impl.hpp"

using PreciseClock = Clock<double>;
using RegularClock = Clock<float>;

#endif //CLOCK_HPP