// Lab #4 de diseño
/*
Desarrollado por:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/

#include <iostream>
#include <string>
using namespace std;

#include "Posfix.hpp"
#include "Posfix_Double.hpp"
#include "Posfix_Matriz.hpp"
#include "Posfix_Fraccion.hpp"

int main() {
  cout << "\n\nOperacion de matrices" << endl;
  Posfix_Matriz prueba(3, 3);
  Posfix_Matriz resultado = prueba.resolver_expresion("A B + C *");

  for (int i = 0; i < resultado.get_filas(); i++) {
    for (int j = 0; j < resultado.get_columnas(); j++) {
      cout << resultado(i, j) << "\t";
    }
    cout << endl;
  }

  cout << "\n\nOperacion de doubles" << endl;
  Posfix_Double prueba_double(0.0);
  Posfix_Double resultado_double =
      prueba_double.resolver_expresion("2.0 1.0 + 4.0 *");

  cout << to_string(resultado_double.numero) << endl;

    cout << "\n\nOperacion de fracciones" << endl;
  Posfix_Fraccion prueba_fraccion(0, 0);
  Posfix_Fraccion resultado_fraccion =
      prueba_fraccion.resolver_expresion("1l5 1l3 + 4l3 *");

  cout << to_string(resultado_fraccion.numerador) + " / " + to_string(resultado_fraccion.denominador) << endl;

  return 0;
}