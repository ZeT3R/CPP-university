//
// Created by Sergey on 25.11.2020.
//

#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H

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
class Stack;

template <typename T>
class Queue;

template<typename T>
class Queue{
private:
    Elem<T> *head;
    int size;

public:
    Queue() noexcept;
    ~Queue() noexcept;
    Queue(const std::initializer_list<T> &list);
    Queue(const Queue &copy);

    T pop();
    void push(const T& elem);

    T check_pop();
    bool empty() noexcept;
    int size_length() noexcept;

    void clear() noexcept;
    Queue<T> &operator =(const Queue<T> &copy);
    template<typename Type>
    friend std::ostream& operator <<(std::ostream& out, const Queue<Type> &qu);
    template<typename Type>
    friend Stack<T> QueueToStack(const Queue<T> &qu);
};


template<typename Type>
Queue<Type> StackToQueue(const Stack<Type> &stack){
    Queue<Type> qu;
    for(int i = 0; i < stack.size; i++)
        qu.push(stack.stack[i]);
    return qu;
}


template<typename Type>
Queue<Type>::Queue() noexcept {
    head = nullptr;
    size = 1;
}


template<typename Type>
Queue<Type>::Queue(const std::initializer_list<Type> &list){
    head = nullptr;
    size = 1;
    for(auto& i : list)
        push(i);

}

template<typename Type>
Queue<Type>::Queue(const Queue<Type> &copy) {
    size = copy.size();
    for(Elem<Type>* i = copy.head; i != nullptr; i = i->next)
        push(i->info);
}

template<typename Type>
Queue<Type>::~Queue<Type>() noexcept {
    clear();
}

template<typename Type>
Type Queue<Type>::pop() {
    if(head == nullptr)
        throw std::logic_error("Queue is empty");
    Type tempinfo = head->info;
    Elem<Type>* delete_ = head;
    head = head->next;
    delete delete_;
    size--;
    return tempinfo;
}

template<typename Type>
void Queue<Type>::push(const Type &elem) {
    auto* el = new Elem<Type>(elem);
    if(el == nullptr)
        throw std::logic_error("Out of memory");
    if(head == nullptr){
        head = el;
        return;
    }
    Elem<Type>* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = el;
    size++;
}


template<typename Type>
Type Queue<Type>::check_pop() {
    if(empty())
        throw std::logic_error("Queue is empty!");
    return head->info;
}

template<typename Type>
bool Queue<Type>::empty() noexcept {
    return head == nullptr;
}

template<typename Type>
int Queue<Type>::size_length() noexcept {
    return size;
}

template<typename Type>
void Queue<Type>::clear() noexcept {
    Elem<Type>* p = head;
    Elem<Type>* delete_;
    while(p != nullptr){
        delete_ = p;
        p = p->next;
        delete delete_;
    }
    head = nullptr;
    size = 0;
}

template<typename Type>
Queue<Type> & Queue<Type>::operator=(const Queue<Type> &copy) {
    clear();
    if(&copy != this) {
        for (Elem<Type> *i = copy.head; i != nullptr; i = i->next)
            push(i->info);
    }
    return *this;
}

template<typename Type>
std::ostream& operator<<(std::ostream& out, const Queue<Type>& qu){
    for(Elem<Type>* i = qu.head; i != nullptr; i = i->next)
        out << i->info << " ";
    return out;
}

template<typename T>
Stack<T> QueueToStack(const Queue<T> &qu){
    Stack<T> stack_;
    for(Elem<T>* i = qu.head; i != nullptr; i = i->next)
        stack_.push(i->info);
    return stack_;
}


#endif //LAB2_QUEUE_H
