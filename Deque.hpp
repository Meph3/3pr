#ifndef Deque_hpp
#define Deque_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class Deque {
public:
    virtual bool Empty() = 0; //проверка на пустоту
    virtual bool Full() = 0; //проверка на полноту
    virtual void InLeft(T x) = 0; //добавление в открытый конец
    virtual T ReadLeft() = 0; //неразрушающее чтение с левого конца
    virtual T ReadRight() = 0; //неразрушающее чтение с правого конца
    virtual T OutLeft() = 0; //удаление с левого конца
    virtual T OutRight() = 0; //удаление с правого конца
};
template <typename T>
class List : public Deque<T> {
    struct element {
        T data;
        element* next, * prev;
    } *left, * right;
public:
    List() {
        left = right = nullptr;
    }
    ~List() {
        element* temp = left;
        while (left) {
            temp = left;
            left = left->next;
            delete temp;
        }
    }
    bool Empty() override {
        return this->left == nullptr;
    }
    bool Full() override {
        element* temp = new (std::nothrow) element;
        if (temp == NULL) return false;
        delete temp;
        return true;
    }
    void InLeft(T x) override { //добавление в открытый конец
        element* temp;
        temp = new (std::nothrow) element;
        temp->data = x;
        temp->next = left;
        temp->prev = nullptr;
        if (left)
            left->prev = temp;
        else
            right = temp;
        left = temp;
    }
    T OutLeft() override { //удаление с открытого конца
        T temp = this->left->data;
        element* tmp = this->left;
        this->left = this->left->next;
        delete tmp;
        return temp;
    }
    T ReadLeft() override { //неразрушающее чтение с открытого конца
        return this->left->data;
    }
    T OutRight() override { //удаление с закрытого конца
        T temp = this->right->data;
        element* tmp = this->right;
        this->right = this->right->prev;
        delete tmp;
        return temp;
    }
    T ReadRight() override { //неразрушающее чтение с закрытого конца
        return this->right->data;
    }
};
template <typename T>
class Array : public Deque<T> {
    int left, right;
    int maxlength;
    T* data;
public:
    Array(int n = 10) : maxlength(n) {
        this->data = new T[maxlength];
        this->left = 0;
        this->right = maxlength - 1;
    }
    ~Array() {
        delete[] this->data;
    }
    bool Empty() override {
        return (this->right + 1) % this->maxlength == left;
    }
    bool Full() override {
        return (this->right + 2) % maxlength == left;
    }
    void InLeft(T x) override { //добавление в открытый конец
        if (this->Full()) return;
        this->left = this->left ? this->left - 1 : maxlength - 1;
        this->data[this->left] = x;
        return;
    }
    T OutLeft() override { //удаление с открытого конца
        int temp = this->left;
        this->left = (this->left + 1) % this->maxlength;
        return this->data[temp];
    }
    T ReadLeft() override { //неразрушающее чтение с открытого конца
        return this->data[left];
    }
    T OutRight() override { //удаление с закрытого конца
        int temp = this->right;
        this->right = this->right ? this->right - 1 : maxlength - 1;
        return this->data[temp];
    }
    T ReadRight() override { //неразрушающее чтение с закрытого конца
        return this->data[right];
    }
};

#endif /* Deque_hpp */