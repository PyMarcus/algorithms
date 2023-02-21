//
// Created by Marcus on 21/02/2023.
//
#include <iostream>
#include <string>
#include <algorithm>


bool prime(int number)
{
    int count {0};
    for(size_t i = 1; i <= number; i++)
    {
        if(number % i == 0) ++count;
        if(count > 2) return false;
    }
    return true;
}


void inverse(std::string *str, int size)
{
    std::string response;
    for(int i = size - 1; i >= 0; i--)
    {
        response.push_back(str->at(i));
    }
    str->clear();
    str->append(response);
}


int emipr(int number)
{
    std::string cast_number, to_compare;

    if(!prime(number)) return 2;
    cast_number.append(std::to_string(number));
    to_compare.append(std::to_string(number));
    //std::reverse(cast_number.begin(), cast_number.end());
    inverse(&cast_number, cast_number.size());
    if(to_compare==cast_number) return 1;
    return 3;
}


void problem1()
{
    //while(!std::cin.eof())
    int number;
    for(size_t i = 0; i < 5; i++){
        std::cin >> number;
        switch (emipr(number)) {
            case 1:
                std::cout << number << " primo" << '\n' << std::flush;
                break;
            case 2:
                std::cout << number << " nao primo" << '\n' << std::flush;
                break;
            case 3:
                std::cout << number << " omipr" << '\n' << std::flush;
                break;
        }
    }
}

