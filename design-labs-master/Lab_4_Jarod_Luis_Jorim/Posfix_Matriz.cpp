#include "Posfix_Matriz.hpp"

Posfix_Matriz::Posfix_Matriz(int fila, int columna) {
  this->filas = fila;
  this->columnas = columna;

  this->matriz = new int*[filas];
  for (int i = 0; i < filas; i++) {
    this->matriz[i] = new int[columnas];
  }

  int contador = 1;
  for (int x = 0; x < filas; x++) {
    for (int y = 0; y < columnas; y++) {
      this->matriz[x][y] = contador;
      contador++;
    }
  }
}

int Posfix_Matriz::get_filas() { return this->filas; }
int Posfix_Matriz::get_columnas() { return this->columnas; }

int& Posfix_Matriz::operator()(const int& fila, const int& columna) {
  return this->matriz[fila][columna];
}

Posfix_Matriz::~Posfix_Matriz() {}

Posfix_Matriz& Posfix_Matriz::operator+(Posfix& nueva_matriz) {
  Posfix_Matriz* temp_matriz = dynamic_cast<Posfix_Matriz*>(&nueva_matriz);

  Posfix_Matriz* matriz_resultado =
      new Posfix_Matriz(this->filas, this->columnas);

  for (unsigned x = 0; x < filas; x++) {
    for (unsigned y = 0; y < columnas; y++) {
      matriz_resultado->operator()(x, y) =
          this->matriz[x][y] + temp_matriz->operator()(x, y);
    }
  }
  return *matriz_resultado;
}

Posfix_Matriz& Posfix_Matriz::operator-(Posfix& nueva_matriz) {
  Posfix_Matriz* temp_matriz = dynamic_cast<Posfix_Matriz*>(&nueva_matriz);
  Posfix_Matriz* matriz_resultado =
      new Posfix_Matriz(this->filas, this->columnas);

  for (unsigned x = 0; x < filas; x++) {
    for (unsigned y = 0; y < columnas; y++) {
      matriz_resultado->operator()(x, y) =
          this->matriz[x][y] - temp_matriz->operator()(x, y);
    }
  }
  return *matriz_resultado;
}

Posfix_Matriz& Posfix_Matriz::operator*(Posfix& nueva_matriz) {
  Posfix_Matriz* temp_matriz = dynamic_cast<Posfix_Matriz*>(&nueva_matriz);
  Posfix_Matriz* matriz_resultado =
      new Posfix_Matriz(this->filas, this->columnas);
  for (int x = 0; x < filas; x++) {
    for (int y = 0; y < columnas; y++) {
      matriz_resultado->operator()(x, y) = 0;
      for (int pivote = 0; pivote < filas; pivote++) {
        matriz_resultado->operator()(x, y) +=
            this->matriz[x][pivote] * temp_matriz->operator()(pivote, y);
      }
    }
  }
  return *matriz_resultado;
}

Posfix_Matriz& Posfix_Matriz::operator/(Posfix& nueva_matriz) { return *this; }

Posfix_Matriz& Posfix_Matriz::resolver_expresion(string hilera) {
  stack<Posfix_Matriz> resultado;
  string store;
 // A B + C * 
 // B A +
 // C D *
  for (int i = 0; hilera[i]; ++i) {
    if (hilera[i] == '+' || hilera[i] == '-' || hilera[i] == '*') {
      Posfix_Matriz valor_1(this->filas, this->columnas);
      valor_1 = resultado.top();
      resultado.pop();
      Posfix_Matriz valor_2(this->filas, this->columnas);
      valor_2 = resultado.top();
      resultado.pop();
      switch (hilera[i]) {
        case '+':
          resultado.push(valor_2 + valor_1);
          break;
        case '-':
          resultado.push(valor_2 - valor_1);
          break;
        case '*':
          resultado.push(valor_2 * valor_1);
          break;
      }
    } else {
      if (hilera[i] != ' ') {
        Posfix_Matriz matriz(this->filas, this->columnas);
        resultado.push(matriz);
      }
    }
  }
  Posfix_Matriz matriz_resultado(this->filas, this->columnas);
  matriz_resultado = resultado.top();
  Posfix_Matriz* temp_matriz = dynamic_cast<Posfix_Matriz*>(&matriz_resultado);
  return *temp_matriz;
}

/*
void imprimir(Posfix_Matriz resultado) {
  for (int i = 0; i < resultado.get_filas(); i++) {
    for (int j = 0; j < resultado.get_columnas(); j++) {
      cout << resultado(i, j) << "\t";
    }
    cout << endl;
  }
}
*/