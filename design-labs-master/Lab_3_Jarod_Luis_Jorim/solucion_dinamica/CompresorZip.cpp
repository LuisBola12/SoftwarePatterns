#include "CompresorZip.hpp"

CompresorZip::CompresorZip(ostream& stream) : stream{stream}{
}

CompresorZip::~CompresorZip() {

}
ostream& CompresorZip::operator<<(string& mensaje){
  for(int i =0;i<mensaje.size();i++){
    this->stream<<mensaje[i];
  }
  this->stream << ".zip";
  return *this;
}
