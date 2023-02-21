//
// Created by Marcus on 21/02/2023.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>



inline void less_lexicographical(std::vector<std::string> words)
{
    std::sort(words.begin(), words.end());
    for(std::string w: words)
        std::cout << w << "";
}


inline std::vector<std::string> split(std::string text)
{
    std::string str;
    std::stringstream ss(text);
    std::vector<std::string> result;
    int z = 0, limit = 0;

    while(ss >> str)
    {
        if(z == 0){
            z = std::stoi(str);
        }else{
            result.push_back(str);
        }
        if(limit == z)break;
        limit++;
    }
    return result;
}

inline void problem2()
{
    std::string word;
    int limit;
    std::cin >> limit;
    for(size_t i = 0; i < limit; i++)
    {
        std::getline(std::cin.ignore(), word);
        less_lexicographical(split(word));
    }
}