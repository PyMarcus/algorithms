#include <iostream>
#include "customized_exception/Exception.h"


class Printer{
public:
    Printer()=default;

    static inline void printer(int div)
    {
        if(div == 0){
            throw Exception("Division by zero!");
        }

    }
};


int main()
{
    int value;
    std::cin >> value;
    Printer::printer(value);
    int value2 {3};

    try{
        std::cout << (value2 / value ) << std::endl;
        std::cin.ignore() >> value;
        Printer::printer(value);
    }catch (Exception e){
        std::cout << e.what();
    }
    return EXIT_SUCCESS;
}