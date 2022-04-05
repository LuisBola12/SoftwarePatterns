// Lab #3 de diseño
/*
Desarrollado por:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

#include "CompresorZip.hpp"
#include "CompresorRar.hpp"
using namespace std;

int main() {
  //stringstream
  stringstream ss;
  string prueba_ss = "Menu: Papas $4, Pollo Frito $5, Hamburguesas $7";
  CompresorZip css(ss);
  css<<prueba_ss;
  cout<<ss.str()<<endl;
  //ostringstream
  ostringstream os;
  string prueba_os = "Compras: Harina, Arroz, Carne, Pan";
  CompresorRar css3(os);
  css3<<prueba_os;
  cout<<os.str()<<endl;
  //fstream
  fstream stream;
  string prueba_fs = "La pajara pinta estaba sentada en su verde limon";
  stream.open("prueba1.txt",fstream::out);
  CompresorZip zipStream(stream);
  zipStream<<prueba_fs;
  //Ofstream
  ofstream ofs;
  string prueba_ofs = "Pinpon es un muneco muy guapo y de carton";
  ofs.open("prueba2.txt",fstream::out);
  CompresorRar css4(ofs);
  css4<<prueba_ofs;
}