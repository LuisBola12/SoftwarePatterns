#pragma once

#include <iostream>
#include <string>

class Mediador_Abstracto;

class Colega_Abstracto {
    
 public:
  const std::string id;
  Mediador_Abstracto& mediador;

  Colega_Abstracto(const std::string& new_id, Mediador_Abstracto& new_mediador)
      : id(new_id), mediador(new_mediador) {}
  ~Colega_Abstracto() {}

  std::string get_id() const { return id; }

  virtual void comunicar(Colega_Abstracto* receptor,
                         const std::string& mensaje) = 0;
  virtual void global(const std::string& mensaje) = 0;

  virtual void recibir(Colega_Abstracto* emisor,
                       const std::string& mensaje) = 0;
};
