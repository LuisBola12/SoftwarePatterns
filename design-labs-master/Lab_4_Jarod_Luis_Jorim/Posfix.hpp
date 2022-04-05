#pragma once

#include <string>
using namespace std;

class Posfix {
 public:
  Posfix() {}
  ~Posfix() {}

  virtual Posfix& resolver_expresion(string hilera) = 0;
  
  virtual Posfix& operator+(Posfix& operando) = 0;
  virtual Posfix& operator-(Posfix& operando) = 0;
  virtual Posfix& operator*(Posfix& operando) = 0;
  virtual Posfix& operator/(Posfix& operando) = 0;
};