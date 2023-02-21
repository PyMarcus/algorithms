//
// Created by Marcus on 21/02/2023.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


inline void count(std::vector<int> numbers)
{
    std::vector<std::string> v;
    std::string response;
    int c {0};
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = 0; j < numbers.size(); j++)
        {
            if(numbers.at(i) == numbers.at(j))
            {
                c++;
            }
        }
        response.append(std::to_string(numbers[i]));
        response.append(", ");
        response.append(std::to_string(c));
        if(std::find(v.begin(), v.end(), response) == v.end()){
            v.push_back(response);
        }
        response.clear();
        c = 0;
    }
    for(const std::string& w: v)
    {
        std::cout << w << '\n';
    }

}



inline void problem3()
{
    std::vector<int> numbers;
    std::string line;
    std::string content;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    while(ss >> content)
    {
        numbers.push_back(std::stoi(content));
    }
    std::sort(numbers.begin(), numbers.end());
    count(numbers);
}
