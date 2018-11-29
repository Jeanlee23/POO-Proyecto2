#include "matriz.h"

int main() {
    matriz imagen;
    cout << endl << "-- BIENVENIDO --" << endl << endl;
    imagen.imprimir();
    numerico opcion;
    do {
        cout << "Elije una opcion para modificar la imagen --" << endl;
        cout << "1: Invertir colores" << endl;
        cout << "2: Ensachar" << endl;
        cout << "3: Alargar" << endl;
        cout << "4: Agrandar" << endl;
        cout << "5: Rotar 90 grados a la izquierda" << endl;
        cout << "6: Rotar 90 grados a la derecha" << endl;
        cout << "7: Rotar 180 grados" << endl;
        cout << "8: Volver tamanno original" << endl;
        cout << "0: Salir [x]" << endl;
        cin >> opcion;
        cout << endl;
        switch (opcion){
            numerico respuesta;
            case 0:
                break;
            case 1:
                imagen.invertir();
                imagen.imprimir();
                break;
            case 2:
                cout << "Ensanchar por: ";
                cin >> respuesta;
                imagen.ensanchar(respuesta);
                imagen.imprimir();
                break;
            case 3:
                cout << "Alargar por: ";
                cin >> respuesta;
                imagen.alargar(respuesta);
                imagen.imprimir();
                break;
            case 4:
                cout << "Agrandar por: ";
                cin >> respuesta;
                imagen.agrandar(respuesta);
                imagen.imprimir();
                break;
            case 5:
                imagen.rotar90izquierda();
                imagen.imprimir();
                break;
            case 6:
                imagen.rotar90derecha();
                imagen.imprimir();
                break;
            case 7:
                imagen.rotar180();
                imagen.imprimir();
                break;
            case 8:
                imagen.volverTamannoOriginal();
                imagen.imprimir();
                break;
            default:
                cout << "La entrada no es valida" << endl << endl;
        }
    } while (opcion != 0);
    cout << "-- HASTA LA PROXIMA --";
    return 0;
}
