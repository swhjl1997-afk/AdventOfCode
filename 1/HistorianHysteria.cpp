#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class HistorianHysteria
{
public:
    std::string data_private;
    HistorianHysteria(const std::string& input): data_private(input) {};
    ~HistorianHysteria() {};
    int first_part(std::string data_private);
    int second_part(std::string data_private);
};

int HistorianHysteria::first_part(std::string data_private){
    //try tomorrow
    return 0;
}

int HistorianHysteria::second_part(std::string data_private){
    //try tomorrow
    return 0;
}

int main() {
    std::string input;
    std::ifstream fin("input.txt");
    std::ostringstream ss;
    ss << fin.rdbuf();
    input = ss.str();
    
    HistorianHysteria historian(input);
    cout << historian.first_part(historian.data_private) << endl;
    cout << historian.second_part(historian.data_private) << endl;
}