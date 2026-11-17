//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T* data;
    Node<T>* next;

    Node(T* item) : data(item), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next;
            delete current->data;
            delete current;
            current = next_node;
        }
        head = nullptr;
        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    void insert(T* newItem) {
        Node<T>* newNode = new Node<T>(newItem);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() const {
        if (head == nullptr) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;
        Node<T>* current = head;
        int index = 1;
        while (current != nullptr) {
            std::cout << index++ << ". " << current->data->toString() << std::endl;
            current = current->next;
        }
        std::cout << "------------------------" << std::endl;
    }

    void playCurrent() const {
        if (head != nullptr) {
            head->data->play();
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H