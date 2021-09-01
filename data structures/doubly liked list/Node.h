//
//  Node.h
//  Act2.3
//
//  Created by Valeria Conde on 10/10/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Node_h
#define Node_h

class Node {
private:
    Datos data;
    Node *next;
    Node *prev;
public:
    Node(Datos data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    
    Node(Datos data, Node *next, Node *prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
    Datos getData() {
        return data;
    }
    
    Node* getNext() {
        return next;
    }
    
    Node* getPrev() {
        return prev;
    }
    
    void setData(Datos data) {
        this->data = data;
    }
    
    void setNext(Node *next) {
        this->next = next;
    }
    
    void setPrev(Node *prev) {
        this->prev = prev;
    }
    
    void print() {
        this->data.print();
    }
};

#endif /* Node_h */
