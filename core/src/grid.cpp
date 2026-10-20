#include "grid.hpp"

Grid::Grid(std::size_t rows,std::size_t columns):
    rows_(rows),columns_(columns),cells_(rows*columns){}


