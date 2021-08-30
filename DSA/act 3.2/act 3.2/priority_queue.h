//  priority_queue.h
//  act 3.2
//
//  Created by Valeria Conde on 17/10/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef priority_queue_h
#define priority_queue_h

class priority_queue {
private:
    vector<int> datos;
public:
    // Complejidad: O(1)
    priority_queue() {
        datos.push_back(-7);
    }
    
    // Complejidad: O(log n)
    void push(int data) {
        datos.push_back(data);
        int i = datos.size() - 1;
        while(i > 1 && datos[i / 2] < datos[i]){
            swap(datos[i / 2], datos[i]);
            i /= 2;
        }
    }
    
    // Complejidad: O(log n)
    void pop() {
        swap(datos[1], datos[datos.size()-1]);
        datos.pop_back();
        int i = 1;
        int hijos = 2 * i;
        while(hijos <= size()) {
            int hijoMay = -1;
            if(hijos <= size() && datos[hijos] > datos[i]) {
                hijoMay = hijos;
            }
            if(hijos + 1 <= size() && datos[hijos + 1] > datos[i]) {
                if(datos[hijos + 1] > datos[hijos])
                    hijoMay = hijos + 1;
            }
            
            if(hijoMay == -1) break;
            swap(datos[i], datos[hijoMay]);
            i = hijoMay;
            hijos = 2 * i;
        }
    }
    
    // Complejidad: O(1)
    int top() {
        if(size() > 0) return datos[1];
        cout << "Error, la fila de prioridad esta vacía" << endl;
        return -1;
    }
    
    // Complejidad: O(1)
    bool empty() {
        return datos.size() == 1;
    }
    
    // Complejidad: O(1)
    int size() {
        return datos.size() - 1;
    }
};

#endif /* priority_queue_h */
