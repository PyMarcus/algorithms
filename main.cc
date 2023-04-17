#include <iostream>
#include <string>
#include <vector>


// converte os bits em decimal para formar ip
void solve(std::string bits)
{
    std::vector<std::string> words;
    std::string word {""};
    int i {1};

    for(char c: bits)
    {
        word.push_back(c);
        if(i % 8 == 0 && i != 0)
        {
            words.push_back(word);
            word.clear();
        }
        ++i;
    }
    // resultado
    std::cout <<
      std::stoi(words.at(0), nullptr, 2) << "." <<
      std::stoi(words.at(1), nullptr, 2) << "." <<
      std::stoi(words.at(2), nullptr, 2) << "." <<
      std::stoi(words.at(3), nullptr, 2);

    std::cout << '\n';
}

// recebe a entrada dos binarios pelo teclado e chama funcao para calcular ip
void binary_to_ip(int cases)
{
    for(int i {0}; i < cases; i++)
    {
        std::string bits;
        std::getline(std::cin, bits);
        solve(bits);
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);

    int tests;
    std::cin >> tests;
    std::cin.ignore();
    binary_to_ip(tests);
    return EXIT_SUCCESS;
}
