#include "Posfix_Double.hpp"

Posfix_Double::Posfix_Double(double numero) { this->numero = numero; }

Posfix_Double::~Posfix_Double() {}

Posfix_Double& Posfix_Double::operator-(Posfix& nuevo_double) {
  Posfix_Double* temp_double = dynamic_cast<Posfix_Double*>(&nuevo_double);
  Posfix_Double* resultado = new Posfix_Double(0.0);
  resultado->numero = this->numero - temp_double->numero;

  return *resultado;
}

Posfix_Double& Posfix_Double::operator*(Posfix& nuevo_double) {
  Posfix_Double* temp_double = dynamic_cast<Posfix_Double*>(&nuevo_double);
  Posfix_Double* resultado = new Posfix_Double(0.0);
  resultado->numero = this->numero * temp_double->numero;

  return *resultado;
}

Posfix_Double& Posfix_Double::operator+(Posfix& nuevo_double) {
  Posfix_Double* temp_double = dynamic_cast<Posfix_Double*>(&nuevo_double);
  Posfix_Double* resultado = new Posfix_Double(0.0);

  resultado->numero = this->numero + temp_double->numero;

  return *resultado;
}

Posfix_Double& Posfix_Double::operator/(Posfix& nuevo_double) {
  Posfix_Double* temp_double = dynamic_cast<Posfix_Double*>(&nuevo_double);
  Posfix_Double* resultado = new Posfix_Double(0.0);

  resultado->numero = this->numero / temp_double->numero;

  return *resultado;
}

Posfix_Double& Posfix_Double::resolver_expresion(string hilera) {
  stack<Posfix_Double> resultado;
  string store;

  for (int i = 0; hilera[i]; ++i) {
    if (hilera[i] == '+' || hilera[i] == '-' || hilera[i] == '*' ||
        hilera[i] == '/') {
      Posfix_Double valor_1(0.0);
      valor_1 = resultado.top();
      resultado.pop();
      Posfix_Double valor_2(0.0);
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
        case '/':
          resultado.push(valor_2 / valor_1);
          break;
      }
    } else {
      if (hilera[i] != ' ' || hilera[i - 1] == '+' || hilera[i - 1] == '-' ||
          hilera[i - 1] == '*' || hilera[i - 1] == '/') {
        store += hilera[i];
      } else {
        Posfix_Double numero_double(std::stod(store));
        resultado.push(numero_double);
        store = "";
      }
    }
  }

  Posfix_Double double_resultado(0.0);
  double_resultado = resultado.top();
  Posfix_Double* temp_double = dynamic_cast<Posfix_Double*>(&double_resultado);
  return *temp_double;
}