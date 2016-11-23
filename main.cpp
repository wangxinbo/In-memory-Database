#include <iostream>
#include <fstream>
#include <string>
#include "src/Database.hpp"
#include "src/Reader.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string line;
    auto db = std::shared_ptr<Database>(new Database());
    Reader reader(db);
    while(true) {
        std::getline(cin, line);
        reader.run(line);
        if(line.substr(0, 3) == "END") break;
    }
    return 0;
}
