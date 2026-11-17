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
    Node<T>* tail;
    Node<T>* current;

public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~LinkedList() {
        if (head == nullptr) {
            std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
            return;
        }

        tail->next = nullptr;
        Node<T>* temp = head;
        Node<T>* next_node = nullptr;

        while (temp != nullptr) {
            next_node = temp->next;
            delete temp->data;
            delete temp;
            temp = next_node;
        }

        head = nullptr;
        tail = nullptr;
        current = nullptr;
        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    void insert(T* newItem) {
        Node<T>* newNode = new Node<T>(newItem);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            current = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayList() const {
        if (head == nullptr) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;
        Node<T>* temp = head;
        int index = 1;
        do {
            std::cout << index++ << ". " << temp->data->toString() << std::endl;
            temp = temp->next;
        } while (temp != head);
        std::cout << "------------------------" << std::endl;
    }

    void playCurrent() const {
        if (current != nullptr) {
            current->data->play();
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }

    void playNext() {
        if (head == nullptr) {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
            return;
        }

        if (current == nullptr) {
            current = head;
        } else {
            current = current->next;
        }
        current->data->play();
    }
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H