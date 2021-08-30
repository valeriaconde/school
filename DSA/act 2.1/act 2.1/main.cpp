//  main.cpp
//
//  Created by Valeria Conde on 03/09/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class Node {
private:
    T data;
    Node<T> *next;
public:
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
    
    Node(T data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }
    
    T getData() {
        return data;
    }
    
    Node<T>* getNext() {
        return next;
    }
    
    void setData(T data) {
        this->data = data;
    }
    
    void setNext(Node<T> *next) {
        this->next = next;
    }
    
};

template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    // Constructor
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    
    // Destructor
    ~LinkedList() {
        deleteAll();
    }
    
    // METODOS COOLS
    // O(1)
    void addFirst(T data) {
        head = new Node<T>(data, head);
        size++;
    }

    // O(n)
    void addLast(T data) {
        if(size == 0) {
            addFirst(data);
            return;
        }
        Node<T> *curr = head;
        while(curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
    
    // O(1)
    int getSize() {
        return size;
    }
    
    // O(1)
    bool isEmpty() {
        return head == nullptr;
    }
    
    bool add(T data, int pos) {
        if (pos > size) return 0;
        if(pos == 0) addFirst(data);
        if(pos == size) addLast(data);
        Node<T>* curr = head;
        for(int i = 1; i < pos; i++) {
            curr = curr -> getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
        return 1;
    }
    
    void deleteFirst() {
        if(head != nullptr) {
            Node<T> *curr = head;
            head = head->getNext();
            delete curr;
            size--;
        }
    }
    
    void deleteLast() {
        if (size <= 1) deleteFirst();
        Node<T> *curr = head;
        while(curr->getNext()->getNext() != nullptr) {
            curr = curr->getNext();
        }
        delete curr->getNext();
        size--;
        curr->setNext(nullptr);
    }
    
    int deleteAll() {
        Node<T> *curr = head;
        while(head != nullptr) {
            head = head->getNext();
            delete curr;
            curr = head;
        }
        int sizeAux = size;
        size = 0;
        return sizeAux;
    }
    
    void print() {
        Node<T> *curr = head;
        cout << "Contenido de la lista" << endl;
        while(curr != nullptr) {
            cout << curr->getData() << endl;
            curr = curr->getNext();
        }
    }
    
    T get(int pos) {
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++) {
            curr= curr->getNext();
        }
        return curr->getData();
    }
    
    T set(T data, int pos) {
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++) {
            curr = curr->getNext();
        }
        T dataAux = curr->getData();
        curr->setData(data);
        return dataAux;
    }
    
    // O(n)
    bool change(int pos1, int pos2) {
        if(pos1 < 0 || pos1 >= size || pos2 < 0 || pos2 <= size) return 0;
        if(pos1 == pos2) return 1;
        int posMen = (pos1 < pos2 ? pos1 : pos2);
        int posMay = (pos1 > pos2 ? pos1 : pos2);
        Node<T> *curr1 = head;
        for(int i = 1; i < posMen; i++) {
            curr1 = curr1->getNext();
        }
        Node<T> *curr2 = curr1;
        for(int i = 1; i <= (posMay - posMen); i++) {
            curr2 = curr2->getNext();
        }
        T dataAux = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(dataAux);
        return true;
    }


    
    //  FUNCIONES ACT 2.1 //
    // O(n)
    void create(T data, int pos) {
        if (pos <= 0) addFirst(data);
        else if (pos >= size) addLast(data);
        else add(data, pos);
    }
        
    // O(n)
    int read(T key) {
        Node<T> *curr = head;
        int currPos = 1;
        while(curr != nullptr) {
            if (curr->getData() == key) return currPos;
            else {
                curr = curr -> getNext();
                currPos++;
            }
        }
        return -1;
    }
    
    // O(n)
    bool update(T data, T newData) {
        int idx = read(data);
        if(idx == -1) return false;
        set(newData, idx);
        return 1;
    }
    
    // O(n)
    bool del(T data) {
        int pos = read(data);
        if(pos == -1) return 0;
        
        else{
            Node<T> *curr = head;
            for(int i = 1; i < pos - 1; i++) {
                curr = curr->getNext();
            }
            Node<T> *aux = curr->getNext();
            curr->setNext(aux->getNext());
            delete aux;
            size--;
            return 1;
        }
    }
};



int main(){
    // CREA LA LISTA
    LinkedList<string> lista;
    lista.addLast("LA");
    lista.addLast("COMPUTACION");
    lista.addLast("ES");
    lista.addLast("SUPER");
    lista.addLast("FICIAL");
    lista.print();
    cout << "--------"<<endl;

    // READ (false)
    cout << lista.read("VALERIA") << endl;
    
    // READ (true)
    cout << lista.read("SUPER") << endl;
    
    // UPDATE
    lista.update("FICIAL", "CALIFRAGILISTICA");
    lista.print();
    
    // DELETE
    lista.del("CALIFRAGILISTICA");
    lista.print();
    
    return 0;
}
