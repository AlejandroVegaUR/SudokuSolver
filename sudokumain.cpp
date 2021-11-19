#include "sudokusolver.hpp"

int main(){
    
    // vector<vector<int>> tablero {

    //     { 0 , 0 , 3 , 2 },
    //     { 3 , 0 , 0 , 4 },
    //     { 4 , 3 , 2 , 0 },
    //     { 0 , 0 , 0 , 3 }
    
    // };

    // vector<vector<int>> solnesperada {

    //     { 1 , 4 , 3 , 2 },
    //     { 3 , 2 , 1 , 4 },
    //     { 4 , 3 , 2 , 1 },
    //     { 2 , 1 , 4 , 3 }

    // };

    vector<vector<int>> tablero { // tablero por resolver

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

    vector<vector<int>> solnesperada { // tablero ya resuelto para verificar el algoritmo

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

    sudokusolver solver(3); // se crea la clase

    cout << "tablero por resolver: \n";
    solver.print(tablero);

    cout << "solucion esperada: \n";
    solver.print(solnesperada);

    solver.solucion(tablero); // se llama la funcion para resolver el tablero

    cout << "tablero resuelto: \n";
    solver.print(tablero);

    if(tablero == solnesperada){

        cout << "si se llego a la solucion\n";

    } else{ // se verifica que el tablero resuelto sea igual a la solucion
        
        cout << "no se llego a la solucion\n";
        
    }

    return 0;

}
