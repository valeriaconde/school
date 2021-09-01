//
//  DoubleLinkedList.h
//  Act2.3
//
//  Created by Valeria Conde on 08/10/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

class LinkedList {
private:
    Node *head;
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
    void addFirst(Datos data) {
        head = new Node(data, head, nullptr);
        size++;
    }

    // O(n)
    void addLast(Datos data) {
        if(size == 0) {
            addFirst(data);
            return;
        }
        Node *curr = head;
        while(curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(new Node(data, nullptr, curr));
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
    
    int deleteAll() {
        Node *curr = head;
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
        Node *curr = head;
        cout << "Contenido de la lista" << endl;
        while(curr != nullptr) {
            curr->print();
            curr = curr->getNext();
        }
    }
    
    Datos get(int pos) {
        Node *curr = head;
        for(int i = 1; i < pos; i++) {
            curr= curr->getNext();
        }
        return curr->getData();
    }
    
    Datos set(Datos data, int pos) {
        Node *curr = head;
        for(int i = 1; i < pos; i++) {
            curr = curr->getNext();
        }
        Datos dataAux = curr->getData();
        curr->setData(data);
        return dataAux;
    }
    
    // O(n)
    bool change(int pos1, int pos2) {
        if(pos1 < 0 || pos1 >= size || pos2 < 0 || pos2 <= size) return 0;
        if(pos1 == pos2) return 1;
        int posMen = (pos1 < pos2 ? pos1 : pos2);
        int posMay = (pos1 > pos2 ? pos1 : pos2);
        Node *curr1 = head;
        for(int i = 1; i < posMen; i++) {
            curr1 = curr1->getNext();
        }
        Node *curr2 = curr1;
        for(int i = 1; i <= (posMay - posMen); i++) {
            curr2 = curr2->getNext();
        }
        Datos dataAux = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(dataAux);
        return true;
    }
    
    //  O(n^2)
    void sort() {
        Node* l = head;
        for (int i = 0; i < size - 1; i++){
            Node* r = head;
            for(int j = 0; j < size - i - 1; j++) {
                if(r->getData().longIP > r->getNext()->getData().longIP) {
                    Datos tmp = r->getData();
                    r->setData(r->getNext()->getData());
                    r->getNext()->setData(tmp);
                }
                r = r->getNext();
            }
            l = l->getNext();
        }
    }
    
    void printRango(string ini, string fin) {
        int l = 0, r = size;
        long start = head->getData().ipToLong(ini);
        long end = head->getData().ipToLong(fin);
        while(l < r) {
            int m = (l + r) / 2;
            if(start <= get(m).longIP) r = m;
            else l = m + 1;
        }
        
        while(get(l).longIP <= end) {
            get(l).print();
            l++;
        }
    }
};


#endif /* DoubleLinkedList_h */
