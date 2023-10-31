#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Arbol/ArbolBinarioAVL.h"

using namespace std;



// Definición de la estructura Producto
struct Producto {
    string grupo;
    string codigoDeBarra;
    string articulo;
    int deposito1;
    int deposito2;
    int deposito3;
    int deposito4;
    int deposito5;
    int totalDepositos;

    // Constructor por defecto para inicializar los atributos
    Producto() : grupo(""), codigoDeBarra(""), articulo(""), deposito1(0), deposito2(0),
                 deposito3(0), deposito4(0), deposito5(0), totalDepositos(0) {}

    // Constructor para inicializar los atributos del objeto Producto y calcular la suma de los depósitos
    Producto(string grupo, string codigoDeBarra, string articulo,
             int deposito1, int deposito2, int deposito3, int deposito4, int deposito5)
            : grupo(grupo), codigoDeBarra(codigoDeBarra), articulo(articulo),
              deposito1(deposito1), deposito2(deposito2), deposito3(deposito3),
              deposito4(deposito4), deposito5(deposito5) {
        totalDepositos = deposito1 + deposito2 + deposito3 + deposito4 + deposito5;
    }
};

int main() {


    ArbolBinarioAVL<pair<int, string >> Cantidadtotart;
    ArbolBinarioAVL<pair<int, string >> ardeposito1;
    ArbolBinarioAVL<pair<int, string >> ardeposito2;
    ArbolBinarioAVL<pair<int, string >> ardeposito3;
    ArbolBinarioAVL<pair<int, string >> ardeposito4;
    ArbolBinarioAVL<pair<int, string >> ardeposito5;
    pair<int, string> total_articulo;
    pair<int, string> Deposito1;
    pair<int, string> Deposito2;
    pair<int, string> Deposito3;
    pair<int, string> Deposito4;
    pair<int, string> Deposito5;

    std::ifstream archivo("C:\\Users\\geronimo\\OneDrive\\Escritorio\\proyectopro3git\\ProyectoProg3\\ProyectoProg3\\Inventariado Fisico.csv");
    std::vector<Producto> productosvec;


int i=0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream stream(linea);
            std::string grupo, codigoDeBarra, articulo;
            int deposito1, deposito2, deposito3, deposito4, deposito5;

            // Lee los valores de la línea separados por comas
            std::getline(stream, grupo, ',');
            std::getline(stream, codigoDeBarra, ',');
            std::getline(stream, articulo, ',');

            // Lee los depósitos y asigna cero si están vacíos
            std::string deposito1Str, deposito2Str, deposito3Str, deposito4Str, deposito5Str;
            std::getline(stream, deposito1Str, ',');
            std::getline(stream, deposito2Str, ',');
            std::getline(stream, deposito3Str, ',');
            std::getline(stream, deposito4Str, ',');
            std::getline(stream, deposito5Str, ',');

            deposito1 = deposito1Str.empty() ? 0 : std::stoi(deposito1Str);
            deposito2 = deposito2Str.empty() ? 0 : std::stoi(deposito2Str);
            deposito3 = deposito3Str.empty() ? 0 : std::stoi(deposito3Str);
            deposito4 = deposito4Str.empty() ? 0 : std::stoi(deposito4Str);
            deposito5 = deposito5Str.empty() ? 0 : std::stoi(deposito5Str);

            // Crea un objeto de la estructura Producto usando el constructor
            Producto nuevoProducto(grupo, codigoDeBarra, articulo, deposito1, deposito2, deposito3, deposito4,
                                   deposito5);


            // Agrega el objeto a la lista de productos
            productosvec.push_back(nuevoProducto);
        total_articulo.first= productosvec[i].totalDepositos;
        total_articulo.second= productosvec[i].articulo;
        Deposito1.first= productosvec[i].deposito1;
        Deposito1.second= productosvec[i].articulo;
        Deposito2.first= productosvec[i].deposito2;
        Deposito2.second= productosvec[i].articulo;
        Deposito3.first= productosvec[i].deposito3;
        Deposito3.second= productosvec[i].articulo;
        Deposito4.first= productosvec[i].deposito4;
        Deposito4.second= productosvec[i].articulo;
        Deposito5.first= productosvec[i].deposito5;
        Deposito5.second= productosvec[i].articulo;

            Cantidadtotart.put(total_articulo);
            ardeposito1.put(Deposito1);
            ardeposito2.put(Deposito2);
            ardeposito3.put(Deposito3);
            ardeposito4.put(Deposito4);
            ardeposito5.put(Deposito5);
            i++;
        }
    }
    archivo.close();


/*

    cout << Cantidadtotart.contarNodos() << endl;
    cout<<Cantidadtotart.sumarNodos()<<endl;
    cout<<Cantidadtotart.contarNodosMenoresAlValor(1)<<endl;
    cout<<ardeposito4.contarNodosMenoresAlValor(1)<<endl;
    cout<<Cantidadtotart.contarNodosMayoresAlValor(84)<<endl;





*/
     int opcion;
     do {
         cout << "\nMENU:" << endl;
         cout << "1. Cantidad total de articulos diferentes." << endl;
         cout << "2. Cantidad total de articulos." << endl;
         cout << "3. Listado de articulos que estan en el minimo de stock." << endl;
         cout << "4. Listado de articulos que estan en el minimo de stock y por deposito." << endl;
         cout << "5. Listado de articulos que igualan o superan determinada cantidad en stock." << endl;
         cout << "6. Salir." << endl;
         cout << "Seleccione una opcion: ";
         cin >> opcion;

         if (opcion == 1) {
             cout << "Cantidad total de articulos diferentes: " << Cantidadtotart.contarNodos() << endl;
         } else if (opcion == 2) {
             int suma = Cantidadtotart.sumarNodos();
             cout << "Suma de todos los articulos: " << suma << endl;
         } else if (opcion == 3) {
             int valor;
             cout << "Ingrese el valor minimo de stock: ";
             cin >> valor;
             int cont = Cantidadtotart.contarNodosMenoresAlValor(valor);
             cout << "Cantidad de articulos en el minimo de stock: " << cont << endl;
         } else if (opcion == 4) {
             int deposi, min;
             cout << "Ingrese el deposito: ";
             cin >> deposi;
             cout << "Ingrese el valor minimo: ";
             cin >> min;
             int contDeposito = 0;

             if (deposi == 1) {
                 contDeposito = ardeposito1.contarNodosMenoresAlValor(min);
             } else if (deposi == 2) {
                 contDeposito = ardeposito2.contarNodosMenoresAlValor(min);
             } else if (deposi == 3) {
                 contDeposito = ardeposito3.contarNodosMenoresAlValor(min);
             } else if (deposi == 4) {
                 contDeposito = ardeposito4.contarNodosMenoresAlValor(min);
             } else if (deposi == 5) {
                 contDeposito = ardeposito5.contarNodosMenoresAlValor(min);
             }

             cout << "Cantidad de articulos en el mínimo de stock para el deposito " << deposi << ": " << contDeposito << endl;
         } else if (opcion == 5) {
             int cantidadMinima;
             cout << "Ingrese la cantidad de stock: ";
             cin >> cantidadMinima;
             int conmayores = Cantidadtotart.contarNodosMayoresAlValor(cantidadMinima);
             cout << "Cantidad de artículos que igualan o superan la cantidad ingresada: " << conmayores << endl;
         } else if (opcion == 6) {
             cout << "Saliendo del programa. ¡Hasta luego!" << endl;
         } else {
             cout << "Opcion invalida. Intente nuevamente." << endl;
         }

                }while (opcion != 0);

}