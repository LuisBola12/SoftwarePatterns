#pragma once
#include <ios>
template <typename T>
class CompresorRar:public T{
    public:
        friend CompresorRar<T>&operator<<(CompresorRar<T>&ios,std::string & mensaje){
            for(int index=0;index<mensaje.size();index++){
                ios<<mensaje[index];
            }
            ios<<".rar";
            return ios;
        }   
};