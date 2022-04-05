#pragma once

#include "Posfix.hpp"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Posfix_Double : public Posfix {
 public:
  Posfix_Double(double fila);
  ~Posfix_Double();

  Posfix_Double& resolver_expresion(string hilera) override;
  Posfix_Double& operator+(Posfix& nuevo_double) override;
  Posfix_Double& operator-(Posfix& nuevo_double) override;
  Posfix_Double& operator*(Posfix& nuevo_double) override;
  Posfix_Double& operator/(Posfix& nuevo_double) override;

  double numero;
};
