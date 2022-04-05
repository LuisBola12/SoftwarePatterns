// Lab #5 de diseño
/*
Desarrollado por:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/

#include <iostream>
#include <string>

#include "Colega.hpp"
#include "Colega_Abstracto.hpp"
#include "Mediador.hpp"
#include "Mediador_Abstracto.hpp"

int main() {
  Mediador mediador;

  Colega* colega1 = new Colega("Carlos", mediador);
  Colega* colega2 = new Colega("Jeremias", mediador);
  Colega* colega3 = new Colega("Felipe", mediador);

  // Los usuarios se unen al chat
  mediador.agregar_usuario(colega1);
  mediador.agregar_usuario(colega2);
  mediador.agregar_usuario(colega3);

  std::string mensaje = "Hola amigos, Como estan?";
  std::string mensaje_2 = "Viste que Carlos se quedo en quimica.";

  // Le envia un mensaje a un solo colega
  colega1->comunicar(colega3, mensaje_2);

  // Le manda un mensaje a todos sus colegas 
  colega2->global(mensaje);

  // Los usuarios se salen del chat
  mediador.remover_usuario(colega1);
  mediador.remover_usuario(colega2);
  mediador.remover_usuario(colega3);
  return 0;
}