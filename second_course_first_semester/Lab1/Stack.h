//
// Created by Sergey on 25.11.2020.
//

#ifndef LAB1_STACK_H
#define LAB1_STACK_H


#include <iostream>
#include <vector>

template <typename T>
struct Elem{
    T info;
    Elem *next;

    explicit Elem(T information){
        info = information;
        next = nullptr;
    }


    Elem(Elem const &el){
        info = el.info;
        next = nullptr;
    }
};


template <typename T>
class Queue;

template <typename T>
class Stack{

private:
    T *stack;
    int size, capacity;
    void resize(int size);

public:
    Stack() noexcept;
    ~Stack() noexcept;
    Stack(const std::initializer_list<T> &list);
    Stack(const Stack& copy);

    T pop();
    void push(const T& elem);
    T check_pop();
    bool empty() noexcept;
    int size_length() noexcept;
    void clear() noexcept;
    Stack<T> &operator =(const Stack<T> &copy);
    template<typename Type>
    friend std::ostream& operator <<(std::ostream& out, const Stack<Type> &st);
    template<typename Type>
    friend Queue<Type> StackToQueue(const Stack<Type> &st);
};


template<typename T>
Stack<T>::Stack() noexcept {
    stack = nullptr;
    size = capacity = 0;
}


template<typename T>
Stack<T>::Stack(const std::initializer_list<T> &list){
    capacity = list.size() + 2;
    size = list.size();
    stack = new T[capacity];
    int i = 0;
    for(auto& elem : list){
        stack[i++] = elem;
    }


}


template<typename T>
Stack<T>::Stack(const Stack& copy){
    size = copy.size;
    capacity = copy.capacity;
    stack = new T[capacity];
    if(stack == nullptr)
        throw std::logic_error("Copy stack is empty");

    for(int i = 0; i < size; i++)
        stack[i] = copy.stack[i];
}

template<typename T>
Stack<T>::~Stack<T>() noexcept {
    delete[] stack;
    stack = nullptr;
    size = 0;
    capacity = 0;

}


template<typename T>
void Stack<T>::resize(int sizeofst){
    Stack temp(*this);
    if(empty() && capacity != 0)
        delete[] stack;
    capacity = sizeofst;
    stack = new T[capacity];
    if(stack == nullptr)
        throw std::logic_error("Stack overflow!");
    for(int i = 0; i < size; i++)
        stack[i] = temp.stack[i];
}


template<typename T>
void Stack<T>::push(const T &elem) {
    if(size == capacity)
        resize(capacity + 5);
    size++;
    stack[size - 1] = elem;
}


template<typename T>
T Stack<T>::pop() {
    size--;
    T temp = stack[size];
    T *copy = stack;
    stack = new T[size];
    if(stack == nullptr)
        throw std::logic_error("Memory error!");
    for(int i = 0; i < size; i++)
        stack[i] = copy[i];
    delete[] copy;
    return temp;
}

template<typename T>
T Stack<T>::check_pop(){
    if(empty())
        throw std::logic_error("\nStack is empty!");
    return stack[size - 1];
}

template<typename T>
bool Stack<T>::empty() noexcept {
    return size == 0;
}

template<typename T>
int Stack<T>::size_length() noexcept {
    return size;
}

template<typename T>
void Stack<T>::clear() noexcept {
    delete[] stack;
    stack = nullptr;
    size = 0;
}

template<typename Type>
std::ostream& operator <<(std::ostream& out, const Stack<Type> &stack){
    for(int i = 0; i < stack.size; i++)
        out << stack.stack[i] << " ";
    return out;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &copy) {
    if(&copy != this){
        if(!empty())
            clear();
        size = copy.size;
        stack = new T[capacity];
        if(stack == nullptr)
            throw std::logic_error("Memory error!");
        for(int i = 0; i < size; i++)
            stack[i] = copy.stack[i];
    }
    return *this;
}


#endif //LAB1_STACK_H





