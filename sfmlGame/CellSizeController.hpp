#ifndef CELL_SIZE_CONTROLLER_HPP
#define CELL_SIZE_CONTROLLER_HPP

#include <fstream>

struct CellSizeController
{
    static void changeCellSizeTo(int size_){
        std::fstream config("../Config/cell_size.txt");
        if(!config.is_open()){
            throw std::exception{"can not open file"};
        }
        config << size_;
        size = size_;
        config.close();
    };

    static int getCellSize() { return size; };

private:
    inline static int size;
};


#endif //CELL_SIZE_CONTROLLER_HPP