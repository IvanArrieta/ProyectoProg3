#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include"Arbol/ArbolBinarioAVL.h"

using namespace std;

int main() {
    ArbolBinarioAVL<int> Cantidadtotart;
    class Producto {
    public:
        string grupo;
        string codigoDeBarra;
        string articulo;
        int deposito1;
        int deposito2;
        int deposito3;
        int deposito4;
        int deposito5;
        int totalDepositos; // Atributo para almacenar la suma de todos los depósitos

        // Constructor para inicializar los atributos del objeto Producto y calcular la suma de los depósitos
        Producto(string grupo, string codigoDeBarra, string articulo,
                 int deposito1, int deposito2, int deposito3, int deposito4, int deposito5)
                : grupo(grupo), codigoDeBarra(codigoDeBarra), articulo(articulo),
                  deposito1(deposito1), deposito2(deposito2), deposito3(deposito3),
                  deposito4(deposito4), deposito5(deposito5) {
            totalDepositos = deposito1 + deposito2 + deposito3 + deposito4 + deposito5;
        }
    };


    std::ifstream archivo("ProyectoProg3/Inventariado Fisico.csv"); // Reemplaza "archivo.csv" con el nombre de tu archivo CSV
    std::vector<Producto> productosvec;

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

            // Crea un objeto de la clase Producto usando el constructor
            Producto nuevoProducto(grupo, codigoDeBarra, articulo, deposito1, deposito2, deposito3, deposito4,
                                   deposito5);

            // Agrega el objeto al vector productosvec
            productosvec.push_back(nuevoProducto);

        }
    }
    archivo.close();
    cout<<productosvec[2].grupo;
    int i=0;
    for (const auto& product : productosvec) {
/*
        cout << "Grupo: " << product.grupo << endl;
        cout << "Codigo de Barra: " << product.codigoDeBarra << endl;
        cout << "Articulo: " << product.articulo << endl;
        cout << "Producto 1: " << product.deposito1 << endl;
        cout << "Producto 2: " << product.deposito2 << endl;
        cout << "Producto 3: " << product.deposito3 << endl;
        cout << "Producto 4: " << product.deposito4 << endl;
        cout << "Producto 5: " << product.deposito5 << endl;
        cout << "--------------------" << endl;*/

        Cantidadtotart.put(product.totalDepositos);
        i++;
    }
    Cantidadtotart.print();
    cout<< Cantidadtotart.contarNodos();


}