#include "Clock.hpp"

template<typename Precision>
Clock<Precision>::Clock(){
    time = Clk::now();
}

template<typename Precision>
Precision Clock<Precision>::restart(){
    auto dur = Clk::now() - time ;
    time = Clk::now();
    return dur.count() / NANO;
}

template<typename Precision>
Precision Clock<Precision>::elapsed(){
    auto dur = Clk::now() - time;
    return dur.count() / NANO;
}