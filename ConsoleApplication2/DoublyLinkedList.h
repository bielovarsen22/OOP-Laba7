#pragma once
#include "Node.h"
#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head)
            throw std::runtime_error("List is empty");

        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        size--;
    }

    void pop_back() {
        if (!tail)
            throw std::runtime_error("List is empty");

        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        size--;
    }

    T get(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index error");

        auto temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }

    void insert(int index, T value) {
        if (index < 0 || index > size)
            throw std::out_of_range("Index error");

        if (index == 0) {
            push_front(value);
            return;
        }

        if (index == size) {
            push_back(value);
            return;
        }

        auto newNode = std::make_shared<Node<T>>(value);
        auto temp = head;

        for (int i = 0; i < index; i++)
            temp = temp->next;

        newNode->prev = temp->prev;
        newNode->next = temp;

        temp->prev->next = newNode;
        temp->prev = newNode;

        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index error");

        if (index == 0) {
            pop_front();
            return;
        }

        if (index == size - 1) {
            pop_back();
            return;
        }

        auto temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        size--;
    }

    int find(T value) {
        auto temp = head;
        int index = 0;

        while (temp) {
            if (temp->data == value)
                return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        auto temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};