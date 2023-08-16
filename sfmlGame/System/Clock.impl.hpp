#include "Clock.hpp"

template<typename Precision>
Clock<Precision>::Clock(){
    t1 = Clk::now();
}

template<typename Precision>
Precision Clock<Precision>::restart(){
    auto dur = Clk::now() - t1 ;
    t1 = Clk::now();
    return dur.count() / NANO;
}

template<typename Precision>
Precision Clock<Precision>::elapsed(){
    auto dur = Clk::now() - t1;
    return dur.count() / NANO;
}