#pragma once

#include <iostream>
#include <string>

#include "Colega_Abstracto.hpp"
#include "Mediador_Abstracto.hpp"

class Colega : public Colega_Abstracto {
  
 public:
  using Colega_Abstracto::Colega_Abstracto;
  void comunicar(Colega_Abstracto* receptor, const std::string&) override;
  void global(const std::string& mensaje) override;

 private:
  void recibir(Colega_Abstracto* emisor, const std::string&) override;
};