#include "grid.hpp"

Grid::Grid(std::size_t rows,std::size_t columns):
    rows_(rows),columns_(columns),cells_(rows*columns){}


std::size_t Grid::rows() const {return rows_;}
std::size_t Grid::columns() const {return columns_;}

