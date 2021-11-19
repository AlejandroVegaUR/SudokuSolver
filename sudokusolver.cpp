#include "sudokusolver.hpp"

sudokusolver::sudokusolver(int i){
    
    grid = i;
    size = i * i;

}

bool sudokusolver::inCol(vector<vector<int>> tablero, int col, int num){ // funcion que verifica que el numero que se esta probando no esta en la misma columna

    for (int row = 0; row < size; row++){ // cicla por todas las filas de la columna dada
            
        if (tablero[row][col] == num){

                return false; // si encuentra el numero en esa columna, retorna falso

        }

    }

    return true;

}

bool sudokusolver::inRow(vector<vector<int>> tablero, int row, int num){ // funcion que verifica que el numero que se esta probando no esta en la misma fila

    for (int col = 0; col < size; col++){ // cicla por todas las columnas de la fila dada
        
        if (tablero[row][col] == num){

            return false; // si encuentra el numero en esa fila, retorna falso

        }

    }    

    return true;

}

bool sudokusolver::inCell(vector<vector<int>> tablero,int InicioCellRow, int InicioCellCol, int num){ // funcion que verifica que el numero que se esta probando no esta en la misma celda

    for (int row = 0; row < grid; row++){ 
                                            // cicla por todos los numeros en la celda que empieza por la fila y la columna dada
        for (int col = 0; col < grid; col++){

            if (tablero[InicioCellRow + row][InicioCellCol + col] == num){

                return false; // si encuentra el numero en la celda 3x3 retorna falso

            }
        }
    }

    return true;

}

bool sudokusolver::PosValida(vector<vector<int>> tablero, int row, int col, int num){ // funcion que verifica que no se repita el numero que se esta probando

    return inRow(tablero, row, num) && inCol(tablero, col, num) && inCell(tablero, row - row % grid, col - col % grid, num) && tablero[row][col] == 0;
// verifica que el numero no esta en la fila, la columna, ni la celda, y que la posicion dada no tenga un numero
}

bool sudokusolver::siguientePosVacia(vector<vector<int>> & tablero, int & row, int & col){ // funcion que encuentra la siguiente posicion vacia

    for (row = 0; row < size; row++){
                                        // cicla por cada posicion del tablero
        for (col = 0; col < size; col++){

            if (tablero[row][col] == 0){ // regresa true cuando encuentra la primera posicion en 0 y cambia los valores de col y row por los de esa posicion
                
                return true;

            }
                
        }
                
    }
    
    return false; // regresa falso si no hay ninguna posicion vacia

}

bool sudokusolver::solucion(vector<vector<int>> & tablero){ // funcion que soluciona el tablero de sudoku con backtracking, notese que debe ser un tablero que tenga solucion

    int row;
    int col;
 
    if (!siguientePosVacia(tablero, row, col)){ // si retorna falso, dentro de la funcion se cambian los valores de row y col y el resto del algoritmo trabaja con estos

        return true; // si ya no hay mas posiciones vacias, termina

    }
 
    for (int num = 1; num <= size; num++){ // ciclo desde 1 hasta el tamaño, que son los numeros utilizados en sudoku
         
        if (PosValida(tablero, row, col, num)){ // verifica si la posicion es valida para agregar el numero que se probo
             
            tablero[row][col] = num; // se asigna el numero en la posicion
 
            if (solucion(tablero)){ // verifica que se puedan asignar el resto de los numeros con la posicion que se acaba de cambiar
                
                return true; // termina el algoritmo porque logro asignar cada posicion vacia
 
            }

            tablero[row][col] = 0; // si el if anterior retorna falso, no se puede terminar el tablero con el numero que se probo, entonces se coloca como una posicion vacia de nuevo

        }

    }
    
    return false; // retornar falso ya que si llega hasta aqui no esta terminado el tablero, entonces se hace esto para que suceda el backtracking en el if

}

void sudokusolver::print(vector<vector<int>> tablero){ // funcion que imprime el tablero

    for(size_t fila = 0; fila < size; fila++){

        if( fila % grid == 0){

            if(grid == 3){

                cout << "-------------------------------------\n"; // imprime una linea horizontal dividir las celdas

            } else{

                cout << "-------------------\n";

            }

        }

        for(size_t columna = 0; columna < size; columna++){

            if( columna % grid == 0){

            cout << "|  "; // imprime una linea vertical para dividir las celdas

            }

            cout << tablero[fila][columna] << "  "; // imprime el valor de cada posicion en el tablero

        }

        cout << "| \n";

    }

    if(grid == 3){

        cout << "-------------------------------------\n"; // imprime una linea horizontal dividir las celdas

    } else{

        cout << "-------------------\n";

    }

}