#pragma once
#ifndef booking_h
#define booking_h

#include <iostream>

using namespace std;

class Node {
public:
    
    string passport;
    string room;
    string goesin;
    string goesout;
   
    Node* next;
    Node* prev;

    Node(string p, string r, string in, string out) {
        passport = p;
        room = r;
        goesin = in;
        goesout = out;
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

    void add(string p, string r, string in, string out) {
        Node* node = new Node(p, r, in, out);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    Node* remove_by_room(string room) {
        Node* current = head;
        if (current->room == room)
        {
            remove(current);
            return 0;
        }
        current = current->next;
        while (current != head) {
            if (current->room == room)
            {
                remove(current);
                return 0;
            }
        }
        return 0;
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
           
            cout << node->room << " "<<node -> passport<<" "<< node->goesin<<" "<<node->goesout<<"\n";
            node = node->next;
        }
        cout << endl;
    }
};

#endif