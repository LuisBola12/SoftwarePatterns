#pragma once

#include "Posfix.hpp"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Posfix_Fraccion : public Posfix {
 public:
  Posfix_Fraccion(int numero1, int numero2);
  ~Posfix_Fraccion();

  Posfix_Fraccion& resolver_expresion(string hilera) override;
  Posfix_Fraccion& operator+(Posfix& nuevo_double) override;
  Posfix_Fraccion& operator-(Posfix& nuevo_double) override;
  Posfix_Fraccion& operator*(Posfix& nuevo_double) override;
  Posfix_Fraccion& operator/(Posfix& nuevo_double) override;

  int numerador;
  int denominador;
};