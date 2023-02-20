#include <iostream>
#include <iomanip>
#include <list>


template<class T>
class Queue{
private:
    std::list<T> queue;
    int position {0};

public:
    void insert(T value)
    {
        queue.push_back(value);
    }

    bool empty(){
        if(queue.empty()) return true;
        return false;
    }

    T remove()
    {
        if(empty()){
            std::cout << "queue is empty!" << std::endl;
            return NULL;
        }else{
            T value = queue.front();
            queue.pop_front();
            return value;
        }

    }

    void print()
    {
        for(T element: this->queue){
            std::cout << std::setw(1) << " " << element << " " << std::setw(5);
        }
        std::cout << std::endl;
    }
};


int main()
{
    Queue<int> queue;
    queue.insert(2);
    queue.insert(4);
    queue.insert(5);
    queue.print();
    std::cout << "removed: " << queue.remove() << std::endl;
    queue.print();
    return 0;
}