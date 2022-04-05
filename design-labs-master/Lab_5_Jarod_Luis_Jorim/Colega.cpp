#include "Colega.hpp"

void Colega::comunicar(Colega_Abstracto* receptor, const std::string& mensaje) {
  this->mediador.enviar(receptor, this, mensaje);
}

void Colega::recibir(Colega_Abstracto* emisor, const std::string& mensaje) {
  std::cout << get_id() << " recibio el mensaje de " << emisor->get_id() << ": "
            << mensaje << std::endl;
}

void Colega::global(const std::string& mensaje) {
  this->mediador.broadcast(this, mensaje);
}