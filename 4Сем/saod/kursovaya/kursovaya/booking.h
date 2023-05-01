#ifndef booking_h
#define booking_h

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void remove(Node* node) {
        if (node == head) {
            head = node->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }
        else if (node == tail) {
            tail = node->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }

    void print() {
        Node* node = head;
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

#endif