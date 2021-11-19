#include "sudokusolver.hpp"

int main(){
    
    vector<vector<int>> tablero2x2 { // tablero 2x2 por resolver

        { 0 , 0 , 3 , 2 },
        { 3 , 0 , 0 , 4 },
        { 4 , 3 , 2 , 0 },
        { 0 , 0 , 0 , 3 }
    
    };

    vector<vector<int>> solnesperada2x2 { // tablero 2x2 ya resuelto para verificar el algoritmo

        { 1 , 4 , 3 , 2 },
        { 3 , 2 , 1 , 4 },
        { 4 , 3 , 2 , 1 },
        { 2 , 1 , 4 , 3 }

    };

    vector<vector<int>> tablero3x3 { // tablero 3x3 por resolver

        { 1 , 0 , 0 , 0 , 0 , 7 , 0 , 9 , 0 },
        { 0 , 3 , 0 , 0 , 2 , 0 , 0 , 0 , 8 },
        { 0 , 0 , 9 , 6 , 0 , 0 , 5 , 0 , 0 },
        { 0 , 0 , 5 , 3 , 0 , 0 , 9 , 0 , 0 },
        { 0 , 1 , 0 , 0 , 8 , 0 , 0 , 0 , 2 },
        { 6 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 },
        { 3 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
        { 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 7 },
        { 0 , 0 , 7 , 0 , 0 , 0 , 3 , 0 , 0 }

    };

    vector<vector<int>> solnesperada3x3 { // tablero 3x3 ya resuelto para verificar el algoritmo

        { 1 , 6 , 2 , 8 , 5 , 7 , 4 , 9 , 3 },
        { 5 , 3 , 4 , 1 , 2 , 9 , 6 , 7 , 8 },
        { 7 , 8 , 9 , 6 , 4 , 3 , 5 , 2 , 1 },
        { 4 , 7 , 5 , 3 , 1 , 2 , 9 , 8 , 6 },
        { 9 , 1 , 3 , 5 , 8 , 6 , 7 , 4 , 2 },
        { 6 , 2 , 8 , 7 , 9 , 4 , 1 , 3 , 5 },
        { 3 , 5 , 6 , 4 , 7 , 8 , 2 , 1 , 9 },
        { 2 , 4 , 1 , 9 , 3 , 5 , 8 , 6 , 7 },
        { 8 , 9 , 7 , 2 , 6 , 1 , 3 , 5 , 4 }

    };

    sudokusolver solver(3); // se crea la clase, para usar el sudoku 2x2 se cambia por un dos este valor y se utilizan los tableros 2x2 en el resto del codigo

    cout << "tablero por resolver: \n";
    solver.print(tablero3x3);

    cout << "solucion esperada: \n";
    solver.print(solnesperada3x3);

    solver.solucion(tablero3x3); // se llama la funcion para resolver el tablero

    cout << "tablero resuelto: \n";
    solver.print(tablero3x3);

    if(tablero3x3 == solnesperada3x3){

        cout << "si se llego a la solucion\n";

    } else{ // se verifica que el tablero resuelto sea igual a la solucion
        
        cout << "no se llego a la solucion\n";
        
    }

    return 0;

}
