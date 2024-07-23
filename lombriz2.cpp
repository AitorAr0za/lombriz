#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

int suma (int matriz[3][3], int X, int Y) {

    int sumaVertical = 0;
    int sumaHorizontal = 0;

    for (int i = 0; i < 3; i++) {

        sumaVertical = sumaVertical + matriz[Y][i];
        sumaHorizontal = sumaHorizontal + matriz[i][X];

    }

    if (sumaVertical > sumaHorizontal) {

        return sumaVertical;
    }

    else return sumaHorizontal;

}

int main() {

    srand(time(0));
    int menu;
    int valor1 = 0;
    int valor2 = 0;
    int valor3 = 0;
    int valor4 = 0;
    int valor5 = 0;
    int valor6 = 0;
    char granjaMayorProd[20] = "";
    int mayorPrecio = 0;

    do {

    cout << "Ingrese 1, 2 o 3 para las siguientes funciones:" << endl << endl << "1 para dar precios a los tipos de lombrices." << endl << "2 para el analisis de granjas." << endl << "3 para salir del programa." << endl;
    cout << "(tenga en cuenta que si no da los precios a las lombrices y comienza a analizar las granjas, los precios de todos los tipos de lombrices sera de 0$)." << endl << endl;
    cin >> menu;

        switch (menu) {

    case 1: {

        cout << endl << "A continuacion, ingresaras los valores de todos los tipos de lombrices..." << endl << endl;

        for (int i = 0; i < 6; i++) {

                int valorsito;

                cout << "valor del " << i+1 << "esimo tipo de lombriz: ";
                cin >> valorsito;
                switch (i) {

            case 0:

                valor1 = valorsito;
                break;

            case 1:

                valor2 = valorsito;
                break;

            case 2:

                valor3 = valorsito;
                break;

            case 3:

                valor4 = valorsito;
                break;

            case 4:

                valor5 = valorsito;
                break;

            case 5:

                valor6 = valorsito;
                break;

                }

        }

        cout << endl;

        break;
    }

    case 2: {

        int cantidadGranjas = rand() % 4;

        cout << endl << "Se analizaran " << cantidadGranjas+1 << " granjas." << endl << endl;

        for (int i = 0; i < cantidadGranjas+1; i++) {

            char nombre[20];
            int tipoTemp;
            int valorTemp;
            int granjaTemp[3][3];
            int coordY;
            int coordX;
            int celdaRef;
            int resultado;
            int swich = 1;

            cout << "Ingrese el nombre de la granja n" << i+1 << ": ";
            cin >> nombre;

            cout << endl << "Ahora ingrese el tipo de lombrices que se encuentran en la granja " << nombre << ": " << endl << "tipo 1 = " << valor1 << endl << "tipo 2 = " << valor2 << endl << "tipo 3 = " << valor3 << endl << "tipo 4 = " << valor4 << endl << "tipo 5 = " << valor5 << endl << "tipo 6 = " << valor6 << endl << endl;
            cin >> tipoTemp;

            if (tipoTemp < 1 || tipoTemp > 6) {

                while (swich) {

                    cout << "Has ingresado un tipo de lombriz inexistente, por favor ingrese un tipo de lombriz del 1 al 6:" << endl;
                    cin >> tipoTemp;

                    if (tipoTemp >= 1 && tipoTemp <= 6) swich = 0;

                }

            }

            swich = 1;

            switch (tipoTemp) {

            case 1:
                valorTemp = valor1;
                break;

            case 2:
                valorTemp = valor2;
                break;

            case 3:
                valorTemp = valor3;
                break;

            case 4:
                valorTemp = valor4;
                break;

            case 5:
                valorTemp = valor5;
                break;

            case 6:
                valorTemp = valor6;
                break;

            }

            cout << endl << "Ahora vas a ingresar la cantidad de lombrices en cada celda de la granja " << nombre << "..." << endl << endl;

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < 3; j++) {

                    cout << "Cantidad de lombrices en la celda " << i+1 << "-" << j+1 << ": ";
                    cin >> granjaTemp[i][j];

                }

            }

            cout << endl << "Asi se ve la granja " << nombre << ":" << endl << endl;

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < 3; j++) {

                    cout << granjaTemp[i][j] << " | ";

                }

                cout << endl;

            }

            cout << endl << "Ahora, para la celda de referencia, ingrese la coordenada Y de la misma: ";
            cin >> coordY;

            cout << "Y la coordenada X: ";
            cin >> coordX;

            if (coordX < 1 || coordX > 3 || coordY < 1 || coordY > 3) {

                while (swich) {

                    cout << "Has ingresado coordenadas imposibles, por favor ingrese coordenadas que esten dentro del rango de la granja (3x3)" << endl;
                    cout << "Ingrese la coordenada Y: ";
                    cin >> coordY;
                    cout << "Ingrese la coordenada X: ";
                    cin >> coordX;

                    if ((coordX >= 1 && coordX <= 3) && (coordY >= 1 && coordY <= 3)) swich = 0;

                }

            }

            resultado = suma(granjaTemp, coordX-1, coordY-1);

            resultado = resultado * valorTemp;

            cout << endl << "a la granja " << nombre << " se le debera abonar un total de " << resultado << "$." << endl << endl;

            if (resultado > mayorPrecio) {

                strcpy(granjaMayorProd, nombre);
                mayorPrecio = resultado;

            }

        }

        cout << "Tras analizar todas las granjas, la que tiene mayor produccion es la granja " << granjaMayorProd << endl;

        break;

        }

    case 3: {

        cout << "Saliendo del programa...";
        break;

            }
        }

    } while (menu != 3);

    return 0;

}
