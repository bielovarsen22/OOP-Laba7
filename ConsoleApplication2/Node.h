#pragma once
#include <memory>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};