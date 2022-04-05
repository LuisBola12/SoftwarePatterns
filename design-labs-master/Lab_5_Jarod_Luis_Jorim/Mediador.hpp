#pragma once

#include <iostream>
#include <string>

#include "Colega_Abstracto.hpp"
#include "Mediador_Abstracto.hpp"

class Mediador : public Mediador_Abstracto {
 public:
  Mediador();
  ~Mediador();

  void enviar(Colega_Abstracto* destino, Colega_Abstracto* emisor,
              const std::string& mensaje) override;
              
  void broadcast(Colega_Abstracto* emisor, const std::string& mensaje) override;
};