#include "Posfix_Fraccion.hpp"

Posfix_Fraccion::Posfix_Fraccion(int numero1, int numero2) { this->numerador = numero1; this->denominador = numero2; }

Posfix_Fraccion::~Posfix_Fraccion() {}

Posfix_Fraccion& Posfix_Fraccion::operator-(Posfix& nueva_fraccion) {
  Posfix_Fraccion* temp_double = dynamic_cast<Posfix_Fraccion*>(&nueva_fraccion);
  Posfix_Fraccion* resultado = new Posfix_Fraccion(0, 0);
  resultado->numerador = (this->numerador * temp_double->denominador) - (this->denominador * temp_double->numerador);
  if(this->denominador == temp_double->denominador){
    resultado->denominador = this->denominador;
  }else{
    resultado->denominador = this->denominador * temp_double->denominador;
  }
  return *resultado;
}

Posfix_Fraccion& Posfix_Fraccion::operator*(Posfix& nueva_fraccion) {
  Posfix_Fraccion* temp_double = dynamic_cast<Posfix_Fraccion*>(&nueva_fraccion);
  Posfix_Fraccion* resultado = new Posfix_Fraccion(0, 0);
  resultado->numerador = this->numerador * temp_double->numerador;
  resultado->denominador = this->denominador * temp_double->denominador;

  return *resultado;
}

Posfix_Fraccion& Posfix_Fraccion::operator+(Posfix& nueva_fraccion) {
  Posfix_Fraccion* temp_double = dynamic_cast<Posfix_Fraccion*>(&nueva_fraccion);
  Posfix_Fraccion* resultado = new Posfix_Fraccion(0, 0);
  
  resultado->numerador = (this->numerador * temp_double->denominador) + (this->denominador * temp_double->numerador);
  if(this->denominador == temp_double->denominador){
    resultado->denominador = this->denominador;
  }else{
    resultado->denominador = this->denominador * temp_double->denominador;
  }
  return *resultado;
}

Posfix_Fraccion& Posfix_Fraccion::operator/(Posfix& nueva_fraccion) {
  Posfix_Fraccion* temp_double = dynamic_cast<Posfix_Fraccion*>(&nueva_fraccion);
  Posfix_Fraccion* resultado = new Posfix_Fraccion(0, 0);

  resultado->numerador = this->numerador * temp_double->denominador;
  resultado->denominador = this->denominador * temp_double->numerador;

  return *resultado;
}

Posfix_Fraccion& Posfix_Fraccion::resolver_expresion(string hilera) {
  stack<Posfix_Fraccion> resultado;
  string store1;
  string store2;

  for (int i = 0; hilera[i]; ++i) {
    if (hilera[i] == '+' || hilera[i] == '-' || hilera[i] == '*' ||
        hilera[i] == '/') {
      Posfix_Fraccion valor_1(0, 0);
      valor_1 = resultado.top();
      resultado.pop();
      Posfix_Fraccion valor_2(0, 0);
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
          if(hilera[i] == 'l'){
            store1 += hilera[i-1];
            store2 += hilera[i+1];
            
          }
      } else {
        Posfix_Fraccion numero_double(std::stoi(store1), std::stoi(store2));
        resultado.push(numero_double);
        store1 = "";
        store2 = "";
      }
    }
  }

  Posfix_Fraccion double_resultado(0, 0);
  double_resultado = resultado.top();
  Posfix_Fraccion* temp_double = dynamic_cast<Posfix_Fraccion*>(&double_resultado);
  return *temp_double;
}