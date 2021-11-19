#ifndef _SUDOKU_HPP
#define _SUDOKU_HPP

#include <iostream>
#include <vector>

using namespace std;

class sudokusolver{

private:
    
    int grid;
    int size;

    bool inCol(vector<vector<int>> tablero, int col, int num);
    bool inRow(vector<vector<int>> tablero, int row, int num);
    bool inCell(vector<vector<int>> tablero,int CellRow, int CellCol, int num);

    bool siguientePosVacia(vector<vector<int>> & tablero, int & row, int & col);
    bool PosValida(vector<vector<int>> tablero, int row, int col, int num);

public:

    sudokusolver(int i);
    bool solucion(vector<vector<int>> & tablero);
    void print(vector<vector<int>> tablero);

};



#endif