#ifndef CELL_SIZE_CONTROLLER_HPP
#define CELL_SIZE_CONTROLLER_HPP

#include <fstream>
#include <stdexcept>

struct CellSizeController
{
    static void changeCellSizeTo(int size_){
        size = size_;
    }
    static int getCellSize() { return size; };

private:
    inline static int size;
};


#endif //CELL_SIZE_CONTROLLER_HPP