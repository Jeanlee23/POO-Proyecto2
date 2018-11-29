//
// Created by jeanl on 22/11/2018.
//

#include "matriz.h"
using namespace std;

line** matriz::crear(int filas, int columnas) {
    line **p = new line*[filas];
    for (int i = 0; i < (filas); ++i)
        p[i] = new line[columnas];
    return p;
}

matriz::matriz() {
    string mifila, micolumna;
    ifstream matriz("../Imagen.txt");
    getline(matriz,mifila);
    getline(matriz,micolumna);
    filas = stoi(mifila);
    columnas = stoi(micolumna);
    imagen = crear(filas, columnas);
    if (matriz.is_open()){
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                matriz >> imagen[i][j];
    } else
        cout << "No se pudo abrir el archivo" << endl;
    matriz.close();
}

void matriz::invertir() {
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j) {
            if (imagen[i][j]=='0')
                imagen[i][j]='1';
            else if (imagen[i][j]=='1')
                imagen[i][j]='0';
        }
}

void matriz::ensanchar(numerico x) {
    ancho*=x;
    line **p = new line*[filas];
    for (int i = 0; i < filas; ++i) {
        p[i] = new line[(columnas*x)];
    }
    for(int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j) {
            for (int k = 0; k < x; ++k)
                p[i][x*j+k] = imagen[i][j];
        }
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = p;
    columnas*=x;
}

void matriz::alargar(numerico x){
    alto*=x;
    line **p = new line*[filas*x];
    for (int i = 0; i < (filas*x); ++i) {
        p[i] = new line[columnas];
    }
    for(int i = 0; i < filas; ++i){
        for (int j = 0; j < x; ++j) {
            for (int k = 0; k < columnas; ++k)
                p[i*x+j][k]=imagen[i][k];
        }
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = p;
    filas*=x;
}

void matriz::agrandar(numerico x) {
    matriz::ensanchar(x);
    matriz::alargar(x);
}

void matriz::rotar90derecha() {
    line **p = crear(columnas,filas);
    for (int i = 0; i < columnas ; ++i){
        for (int j = 0; j < filas; ++j)
            p[i][j] = imagen[filas-j-1][i];
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = p;
    numerico aux = columnas;
    columnas = filas;
    filas = aux;
}

void matriz::rotar90izquierda() {
    line **p = crear(columnas,filas);
    for (int i = 0; i < columnas ; ++i){
        for (int j = 0; j < filas; ++j)
            p[i][j] = imagen[j][columnas-i-1];
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = p;
    numerico aux = columnas;
    columnas = filas;
    filas = aux;
}

void matriz::rotar180() {
    line **p = crear(filas,columnas);
    for (int i = 0; i < columnas ; ++i){
        for (int j = 0; j < filas; ++j)
            p[j][i] = imagen[filas-j-1][columnas-i-1];
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = p;
}

void matriz::volverTamannoOriginal() {
    filas/=alto;
    columnas/=ancho;
    line** original = crear(filas,columnas);
    if (ancho > 0 || alto > 0){
        for(int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                original[i][j] = imagen[alto*i][ancho*j];
    }
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
    imagen = original;
    ancho = 1;
    alto = 1;
}

void const matriz::imprimir() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << imagen[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

matriz::~matriz() {
    for (int l = 0; l < filas; ++l) {
        delete[] imagen[l];
    }
    delete[] imagen;
}
