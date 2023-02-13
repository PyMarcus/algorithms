#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


class [[maybe_unused]] StringManipulator{
public:
    // constructor
    StringManipulator() = default;

    [[maybe_unused]] explicit StringManipulator(std::string word)
    {
        this->word = word;
    }


    [[maybe_unused]] explicit StringManipulator(std::string word, std::string word2)
    {
        this->word = word;
        this->word2 = word2;
    }

    // methods
    [[maybe_unused]] int count_char()
    {
        int count {0};
        for(char c: this->word){
            count++;
        }
        return count;
    }

    [[maybe_unused]] std::string join()
    {
        this->word.append(" ");
        return this->word.append(this->word2);
    }

    [[maybe_unused]] std::string insert(int position, std::string word)
    {
        return this->word.insert(position, word);
    }

    [[maybe_unused]] char get_char(int position)
    {
        return this->word.at(position);
    }

    [[maybe_unused]] std::string remove_char(int position)
    {
        this->word.erase(this->word.begin() + position);
        return this->word;
    }

    [[maybe_unused]] std::string replace(int position, int how_many_chars, std::string substring)
    {
        this->word.replace(position, how_many_chars, substring);
        return this->word;
    }

    [[maybe_unused]] std::string get_substring(int init, int end)
    {
        return this->word.substr(init, end);
    }

    [[maybe_unused]] static std::vector<std::string> split(std::string word, char condition)
    {
        return _to_split(word, condition);
    }

    [[maybe_unused]] static std::string lower(std::string word)
    {
        return _lower(word);
    }

    [[maybe_unused]] static std::string upper(std::string word)
    {
        return _upper(word);
    }

private:
    std::string word;
    std::string word2;

    static std::vector<std::string> _to_split(std::string word, char condition)
    {
        std::vector<std::string> append;
        std::string aux;
        for(char substr : word)
        {
            if(substr != condition)
            {

                aux.push_back(substr);
            }else{
                append.push_back(aux);
                aux.clear();
            }
        }
        return append;
    }

    static std::string _lower(std::string word)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }

    static std::string _upper(std::string word)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
        return word;
    }

};




int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string word = "Hello";
    std::string word2 = "world!";

    std::cout << "word: " << word << " word2: " << word2 << '\n' << std::flush;

    StringManipulator manipulator = StringManipulator(word, word2);
    std::cout <<
    "count char at word: " << manipulator.count_char() << '\n' <<
    "join word and word2: " << manipulator.join() << '\n' <<
    "insert into position: " << 3 << ": " <<  manipulator.insert(3, "3") << '\n' <<
    "get char from position: " << 3 << ": " << manipulator.get_char(3) << '\n' <<
    "remove char from position: " << 3 << ": " << manipulator.remove_char(3) << '\n' <<
    "replace string ll to 11: " << manipulator.replace(word.find('l'), 2, "11") << '\n'<<
    "get substring from word[0:1]: " << manipulator.get_substring(0, 1) << '\n' <<
    "split chars into array: [";
    for(const std::string& item: StringManipulator::split("palavra", 'a'))
    {
        std::cout << item << ", " << std::flush;
    }
    std::cout << "]\n";

    std::cout << "lower: " << StringManipulator::lower(word) << '\n'<<
    "upper: " << StringManipulator::upper(word);
    return EXIT_SUCCESS;
}