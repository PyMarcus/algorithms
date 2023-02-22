//
// Created by Marcus on 22/02/2023.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

inline void insertion_sort(std::string str)
{
    int j, key, count = 0;

    for(size_t i = 0; i < str.size(); i++)
    {
        key = str.at(i);
        j = i - 1;

        while(j >= 0 and str.at(j) > key)
        {
            str[j + 1] = str[j];
            j--;
            count++;
        }
        str[j + 1] = key;
    }
    if(count > 0) std::cout << count + str.size() - 1 <<  '\n' << std::flush;
    else std::cout << count <<  '\n' << std::flush;
}

inline void problem4()
{
    std::string text {};
    int limit;

    std::cin >> limit;

    for(int i = 0; i < limit; i++){
        std::cin.ignore() >> text;
        insertion_sort(text);
    }

}

