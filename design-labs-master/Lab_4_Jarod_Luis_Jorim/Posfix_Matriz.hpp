#pragma once

#include "Posfix.hpp"

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Posfix_Matriz : public Posfix {
 private:
  int** matriz;
  int filas;
  int columnas;

 public:
  Posfix_Matriz(int fila, int columna);
  ~Posfix_Matriz();
  int get_filas();
  int get_columnas();

  Posfix_Matriz& resolver_expresion(string hilera) override;
  Posfix_Matriz& operator+(Posfix& nueva_matriz) override;
  Posfix_Matriz& operator-(Posfix& nueva_matriz) override;
  Posfix_Matriz& operator*(Posfix& nueva_matriz) override;
  Posfix_Matriz& operator/(Posfix& nueva_matriz) override;

  int& operator()(const int& fila, const int& columna);
};