#ifndef Printer_hpp
#define Printer_hpp

#include <iostream>

/**
 * This class is a singleton class, responsible for showing results to users.
 */
class Printer {
public:
    static Printer& getInstance() {
        static Printer printer;
        return printer;
    }

    template <typename T>
    void print(const T& value) {
        std::cout << value << std::endl;
    }
    
private:
    Printer() {}
    Printer(const Printer& printer);
    Printer& operator=(const Printer& printer);
};


#endif /* Printer_hpp */
