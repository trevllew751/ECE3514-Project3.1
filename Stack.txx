#include "Stack.hpp"

#define INITIAL_CAPACITY 100

template<typename T>
Stack<T>::Stack() {
    items = new T[INITIAL_CAPACITY];
    Top = 0;
    capacity = INITIAL_CAPACITY;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] items;
}

template<typename T>
Stack<T>::Stack(const Stack &rhs) {
    Top = rhs.Top;
    capacity = rhs.capacity;
    items = new T[rhs.capacity];
    std::copy(rhs.items, rhs.items + rhs.Top, items);
}

template<typename T>
size_t Stack<T>::size() const {
    return Top;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return Top == 0;
}

template<typename T>
bool Stack<T>::push(const T &newItem) {
    if (Top + 1 >= capacity) {
        capacity *= 2;
        T *temp = new T[capacity];
        std::copy(items, items + Top, temp);
        delete[] items;
        items = temp;
    }
    Top++;
    items[Top] = newItem;
    return true;
}

template<typename T>
bool Stack<T>::pop() {
    if (!isEmpty()) {
        Top--;
        return true;
    }
    return false;
}

template<typename T>
const T &Stack<T>::top() const throw(std::range_error) {
    if (isEmpty()) {
        throw std::range_error("Empty Stack");
    }
    return items[Top];
}

template<typename T>
void Stack<T>::clear() {
    Top = 0;
}