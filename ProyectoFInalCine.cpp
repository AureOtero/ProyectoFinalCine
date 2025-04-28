// Aurelis Otero Y00616640
// Edward Navarreto Y00665183
// 28 de Abril de 2025
// Programacion Estructurada COMP2315
// Proyecto Recibo de Cine 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Constante para el precio de taquilla
const double PRECIO = 7.00;
// Constante para el tax
const double TAX = 0.115;

// Vector para realizar seguimiento de los asientos reservados
vector<int> asientosReservados;

// Hecho por Edward
// Determina que sillas son las que estan disponibles en la sala
void asientosDisponibles() {
    // Loop de sillas desde el 1 al 50
    for (int i = 1; i <= 50; i++) {
        // Verifica si la silla actual no esta reservada
        if (find(asientosReservados.begin(), asientosReservados.end(), i) == asientosReservados.end()) {
            cout << i << " "; // Imprime el numero de la silla disponible
        }
    }
    cout << endl;   // Imprime nueva linea
}

// Hecho por Edward
//Indica al usuario para escoger y reservar sillas en la sala del cine.
vector<int> sillas() {
    vector<int> sillasEsco; // Vector para guardar las sillas seleccionadas 
    int silla;              // Variable que aguanta la seleccion de silla del usuario
    char masSillas;         // Variable que verifica si el usario quiere seleccionar mas sillas 

    do {
        cout << "Ingrese el numero de asiento (1-50): ";
        cin >> silla;        // Le pide al usuario para un numero de silla

        //Verifica si la silla entrada esta en rango
        if (silla >= 1 && silla <= 50) {
            //Verifica si la silla esta disponible y no reservada
            if (find(asientosReservados.begin(), asientosReservados.end(), silla) == asientosReservados.end()) {
                sillasEsco.push_back(silla); // Añade silla seleccionada a la lista
                asientosReservados.push_back(silla); // Marca la silla  como reservada
            }
            else {
                cout << "Silla Reservada, Intente de nuevo \n"; // Informa al usuario que la silla esta reservada
            }

        }
        else {
            cout << "Silla Invalida, Intente de nuevo \n"; // Informa al usuario que el numero de la silla es invalido
        }

        cout << "Desea escoger otra silla? (y/n): ";
        cin >> masSillas;                                 // Le pregunta al usuario si quiere añadir otra silla
    } while (masSillas == 'y' || masSillas == 'Y');      // Sigue si el usuario quiere seleccionar mas sillas
    cout << "\n";

    return sillasEsco;    //Devuelve la lista de las sillas seleccionadas

}

//Hecho por Aurelis 
// Permite al usuario seleccionar la pelicula, dia y tanda de las opciones disponibles
string estreno(int& opcionM, int& opcionD, int& opcionT) {

    //Lista de las peliculas disponibles
    vector<string> movie = { "Harry Potter", "Cars", "One Piece", "Annabelle", "Oceans 8" };

    // Mostrar opciones de peliculas
    cout << "************ Peliculas ************" << endl;

    // Referencia: BLACKBOX.AI. (2025). Size de vectores en C++. Lineas 86-87, 107-108, 128-129

    // Recorre el vector de la película y muestra cada película con su índice correspondiente
    for (size_t i = 0; i < movie.size(); ++i) {
        cout << i + 1 << " " << movie[i] << endl;
    }

    // Le indica al usuario a seleccionar la pelicula y verifica su entrada
    do {
        cout << "Elige una pelicula:  [1-" << movie.size() << "] ";
        cin >> opcionM;   // Guarda la seleccion del usuario en opcionM

        if (opcionM < 1 || opcionM > movie.size()) {
            cout << "Opcion no valida. Intente de nuevo." << endl;   // Le informa al usuario que es una opcion invalida
        }
    } while (opcionM < 1 || opcionM > movie.size());  // Repite hasta que escoja una opcion valida

    // Lista de los dias disponibles
    vector<string> day = { "Abril 30", "Mayo 2", "Mayo 3", "Mayo 4", "Mayo 5" };

    // Mostrar opciones de dias
    cout << "************ Dias ************" << endl;

    // Recorre el vector del dia y muestra cada dia con su índice correspondiente
    for (size_t i = 0; i < day.size(); ++i) {
        cout << i + 1 << " " << day[i] << endl;
    }

    // Le indica al usuario a seleccionar el dia y verifica su entrada
    do {
        cout << "Elige un dia:  [1-" << day.size() << "] ";
        cin >> opcionD;   //Guarda la seleccion del usuario en opcionD

        if (opcionD < 1 || opcionD > day.size()) {
            cout << "Opcion no valida. Intente de nuevo." << endl;  //Le informa al usuario que es una opcion invalida
        }
    } while (opcionD < 1 || opcionD > day.size()); // Repite hasta que escoja una opcion valida

    // Lista de las tandas disponibles
    vector<string> tanda = { "12:00 PM ", "2:30 PM", "4:50 PM", "7:00 PM", "9:10 PM" };

    // Mostrar opciones de tandas
    cout << "************ Tandas ************" << endl;

    // Recorre el vector de la tanda y muestra cada tanda con su índice correspondiente
    for (size_t i = 0; i < tanda.size(); ++i) {
        cout << i + 1 << " " << tanda[i] << endl;
    }
        // Le indica al usuario a seleccionar la tanda y verifica su entrada
        do {
            cout << "Elige una tanda:  [1-" << tanda.size() << "] ";
            cin >> opcionT; //Guarda la seleccion del usuario en opcionT

            //Verifica si la opcion es valida
            if (opcionT < 1 || opcionT > tanda.size()) {
                cout << "Opcion no valida. Intente de nuevo." << endl; //Le informa al usuario que es una opcion invalida
            }
        } while (opcionT < 1 || opcionT > tanda.size());  // Repite hasta que escoja una opcion valida

        return movie[opcionM - 1];  // Imprime titulo de la pelicula escogida


}

// Hecho por Aurelis y Edward
int main() {

    vector<int> sillasEsco; //Vector para almacenar los números de asientos seleccionados
    double subtotal = 0.0; // Variable para mantener el subtotal antes de impuestos
    int opcionM, opcionD, opcionT; // Variables para almacenar selecciones del usuario para película, día y hora del espectáculo
    srand(time(0));  // Siembra el generador de números aleatorios con la hora actual
    int randomSala = (rand() % 9) + 1;  // Generar un número de habitación aleatorio entre 1 y 10

    // Llama la funcion de estreno para conseguir la pelicula, dia y tanda selecionada
    string seleccion = estreno(opcionM, opcionD, opcionT);

    // Llama la funcion de sillas para buscar las sillas selecionadas
    sillasEsco = sillas();

    // Calcula el subtotal basado en el numero de asientos
    subtotal = sillasEsco.size() * PRECIO;

    // Calcula el costo total con tax
    double total = subtotal * (1 + TAX);

    // Imprime el header del recibo
    cout << "*****************ENAO Cinema*****************\n";
    cout << "************Gracias por visitarnos***********\n";
    cout << "***Aqui tiene su recibo con su informacion***\n";

    // Lista la película, el día y la hora de la función seleccionados
    vector<string> movie = { "Harry Potter", "Cars", "One Piece", "Annabelle", "Oceans 8" };
    cout << "Pelicula: " << movie[opcionM - 1] << endl;

    vector<string> day = { "Abril 30", "Mayo 2", "Mayo 3", "Mayo 4", "Mayo 5" };
    cout << "Dia: " << day[opcionD - 1] << endl;

    vector<string> tanda = { "12:00 PM ", "2:30 PM", "4:50 PM", "7:00 PM", "9:10 PM" };
    cout << "Tanda: " << tanda[opcionT - 1] << endl;

    // Imprime la sala aleatoriamente
    cout << "Sala " << randomSala << endl;

    //Imprime las sillas seleccionada
    cout << "Sus asientos son: ";
    for (int silla : sillasEsco) {
        cout << silla << " ";  // Imprime cada silla seleccionada
    }
    cout << "\n";

    // Imprime el subtotal y el total
    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;


    // Hecho por Edward
    //Funcion que crea y guarda el recibo en un archivo de texto
    ofstream receiptFile("ENAO recibo.txt"); // Abre el archivo y guarda el recibo
    if (receiptFile.is_open()) {             // Verifica si el archivo abrio correctamente

        //Escribe los detalles del recibo en el archivo
        receiptFile << "*****************ENAO Cinema*****************\n";
        receiptFile << "************Gracias por visitarnos***********\n";
        receiptFile << "***Aqui tiene su recibo con su informacion***\n";
        receiptFile << "Pelicula: " << movie[opcionM - 1] << endl;
        receiptFile << "Dia: " << day[opcionD - 1] << endl;
        receiptFile << "Tanda: " << tanda[opcionT - 1] << endl;
        receiptFile << "Sala " << randomSala << endl;
        receiptFile << "Sus asientos son: ";
        for (int silla : sillasEsco) {
            receiptFile << silla << " ";  // Escribe cada silla seleccionada al archivo
        }
        receiptFile << "\n";
        receiptFile << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
        receiptFile << "Total: $" << fixed << setprecision(2) << total << endl;

        receiptFile.close();  // Cierra el archivo despues de escribir en el 
        cout << "Recibo Guardado en 'ENAO recibo.txt'. \n";  // Informa al usuario que el recibo se guardo en el archivo

    }
    else {
        cout << "Error al abrir el archivo para guardar recibo. \n"; // Informa que hubo error para abrir y guardar el archivo
    }

    return 0;  // Indica que el programa termino correctamente 
}
