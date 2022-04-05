// Lab #3 de diseño
/*
Desarrollado por:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include "CompresorZip.hpp"
#include "CompresorRar.hpp"
using namespace std;
int main(){
    
    CompresorZip<stringstream>zip1;
    string men = "Compras: Harina, Arroz, Carne, Pan";
    zip1<<men;
    cout<<zip1.str()<<endl;

    CompresorZip<fstream>zip2;
    zip2.open("prueba1.txt",fstream::out);
    zip2<<men;
    zip2.close();

    CompresorRar<ostringstream>rar1;
    rar1<<men;
    cout<<rar1.str()<<endl;

    CompresorRar<ofstream>rar2;
    rar2.open("prueba2.txt",fstream::out);
    rar2<<men;
    rar2.close();

    return 0;
}