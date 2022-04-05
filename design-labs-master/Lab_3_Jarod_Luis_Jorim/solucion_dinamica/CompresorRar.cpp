#include "CompresorRar.hpp"

CompresorRar::CompresorRar(ostream& stream) : stream{stream}{
}

CompresorRar::~CompresorRar() {
}
ostream& CompresorRar::operator<<(string& mensaje){
  for(int i =0;i<mensaje.size();i++){
    this->stream<<mensaje[i];
  }
  this->stream << ".rar";
  return *this;
}