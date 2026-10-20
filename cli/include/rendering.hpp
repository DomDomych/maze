#pragma once

#include "grid.hpp"

#include <string>
#include <vector>

template<typename T>
std::string renderMaze(
    const Grid<T>& maze,
    const std::vector<Position>& path = {}
) {
    std::vector<std::string> drawing(
        maze.rows() * 2 + 1,
        std::string(maze.columns() * 2 + 1, '#')
    );

    for (std::size_t row = 0; row < maze.rows(); ++row) {
        for (std::size_t column = 0; column < maze.columns(); ++column) {
            Position current{row, column};

            std::size_t y = row * 2 + 1;
            std::size_t x = column * 2 + 1;

            drawing[y][x] = ' ';

            if (column + 1 < maze.columns() &&
                maze.hasPassage(current, Position{row, column + 1})) {
                drawing[y][x + 1] = ' ';
            }

            if (row + 1 < maze.rows() &&
                maze.hasPassage(current, Position{row + 1, column})) {
                drawing[y + 1][x] = ' ';
            }
        }
    }

    for (std::size_t i = 0; i < path.size(); ++i) {
        Position current = path[i];

        drawing[current.row * 2 + 1][current.column * 2 + 1] = '.';

        if (i > 0) {
            Position previous = path[i - 1];

            drawing[previous.row + current.row + 1]
                   [previous.column + current.column + 1] = '.';
        }
    }

    if (!path.empty()) {
        Position start = path.front();
        Position finish = path.back();

        drawing[start.row * 2 + 1][start.column * 2 + 1] = 'S';
        drawing[finish.row * 2 + 1][finish.column * 2 + 1] =
            start == finish ? 'B' : 'E';
    }

    std::string result;
    for (const std::string& line : drawing) {
        result += line;
        result += '\n';
    }

    return result;
}