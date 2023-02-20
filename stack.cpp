#include <iostream>
#include <cstring>


class InterfaceStack{
public:
    virtual void add(int value) = 0;
    virtual void remove() = 0;
};


class Stack: public InterfaceStack{
public:
    Stack()=default;

    void add(int v) override
    {
        if(this->SIZE < 3) this->SIZE++;
        if(this->value < 4){
            std::cout << "add into stack:" << v << std::endl;
            this->_stack[this->value] = v;
            this->value++;
        }else{
            std::cout << "The stack is full" << std::endl;
        }


    }
    void remove () override
    {
        if(this->value > 0){
            std::cout << "remove from stack:" << this->_stack[this->SIZE] << std::endl;
            this->value--;
            this->SIZE--;
        }else{
            std::cout << "The stack is empty" << std::endl;
        }
    }
    void run()
    {
        show();
    }

    ~Stack()
    {
        std::cout << "automatically clear the memory!";
        this->value = 0;
        this->SIZE = 3;
    }

private:
    int SIZE = 3;
    int value = 0;
    int _stack[3];

    void show()
    {
        for(int i = this->SIZE; i >= 0; i--){
            std::cout << this->_stack[i] << " ";
            std::cout  << std::flush;
        }
        std::cout << std::endl;
    }
};
/*
std::ifstream in("file.txt");
    std::string text;


    char content = in.get();

    while(in.good())
    {
        content = in.get();
        if(in.fail()) break;
        text.push_back(content);
    }
    std::cout << text;
    return 0;
*/


int main(int arg, char *argv[])
{
    if(arg == 1) std::cout << "please, type start to run the program" << std::endl;
    if(strcmp(argv[1], "start") == 0)
    {
        Stack stack;
        stack.add(2);
        stack.add(4);
        stack.add(1);
        stack.add(31);
        stack.add(32);
        stack.run();
        stack.remove();
        stack.remove();
        stack.remove();
        stack.remove();
        stack.remove();
        stack.run();
    }else{
        std::cout << "invalid option" << std::endl;
    }
    return EXIT_SUCCESS;
}
