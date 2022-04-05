#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;
class CompresorRar : public ostream{
    public:
    explicit CompresorRar(ostream& stream);
    ~CompresorRar();
    ostream& operator<<(string& mensaje);
    private:
    ostream& stream;
};