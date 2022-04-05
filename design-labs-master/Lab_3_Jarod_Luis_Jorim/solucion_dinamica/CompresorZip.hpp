#include <ostream>
#include <sstream>
#include <string>
using namespace std;
class CompresorZip : public ostream{
    public:
    explicit CompresorZip(ostream& stream);
    ~CompresorZip();
    ostream& operator<<(string& mensaje);
    private:
    ostream& stream;
};