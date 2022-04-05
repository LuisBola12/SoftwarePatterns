#include "Mediador.hpp"

Mediador::Mediador() {}

Mediador::~Mediador() {}

void Mediador::broadcast(Colega_Abstracto* emisor, const std::string& mensaje) {
  for (Colega_Abstracto* x : get_usuarios())
    if (x != emisor) 
      x->recibir(emisor, mensaje);
}

void Mediador::enviar(Colega_Abstracto* destino, Colega_Abstracto* emisor,
                      const std::string& mensaje) {
  for (Colega_Abstracto* x : get_usuarios())
    if (x == destino) 
      x->recibir(emisor, mensaje);
}