#pragma once

#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

#include "Colega_Abstracto.hpp"

class Mediador_Abstracto {
 private:
  std::vector<Colega_Abstracto*> usuarios;

 public:
  Mediador_Abstracto() {}
  ~Mediador_Abstracto() {}

  std::vector<Colega_Abstracto*>& get_usuarios() { return usuarios; }

  void agregar_usuario(Colega_Abstracto* colega) {
    std::cout << colega->get_id() << " se ha unido." << std::endl;
    usuarios.push_back(colega);
  }

  void remover_usuario(Colega_Abstracto* colega) {
    std::vector<Colega_Abstracto*>::iterator iter;
    iter = remove(this->usuarios.begin(), this->usuarios.end(), colega);
    std::cout << colega->get_id() << " ha dejado el chat." << std::endl;
  }

  virtual void enviar(Colega_Abstracto* destino, Colega_Abstracto* emisor,
                      const std::string& mensaje) = 0;

  virtual void broadcast(Colega_Abstracto* emisor,
                         const std::string& mensaje) = 0;
};