#pragma once
#include <ios>
template <typename T>
class CompresorZip:public T{
    public:
        friend CompresorZip<T>&operator<<(CompresorZip<T>&ios,std::string & mensaje){
            for(int index=0;index<mensaje.size();index++){
                ios<<mensaje[index];
            }
            ios<<".zip";
            return ios;
        }   
};