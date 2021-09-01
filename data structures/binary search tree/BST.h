#include "NodeT.h"
class BST{
	public:
		BST();
		~BST();
		void add(Info data);
        void topNodes();
	private:
		NodeT *root;
        int top = 5;
		void destruye(NodeT *r);
        void topNodesHelper(NodeT* n);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}

//Complejidad: O(n)
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

// Complejidad: O(altura del árbol)
void BST::add(Info data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		father = curr;
        if (curr->getData().accesos == data.accesos){
            curr = (curr->getData().ipLong > data.ipLong) ? curr->getLeft() : curr->getRight();
        } else {
            curr = (curr->getData().accesos < data.accesos) ? curr->getLeft() : curr->getRight();
        }
	}
	if (father == nullptr){
		root = new NodeT(data);
	}
	else{
        if (father->getData().accesos == data.accesos) {
            (father->getData().ipLong > data.ipLong) ? father->setLeft(new NodeT(data)) :
            father->setRight(new NodeT(data));
        } else {
            (father->getData().accesos < data.accesos) ? father->setLeft(new NodeT(data)) :
            father->setRight(new NodeT(data));
        }
	}

}

void BST::topNodesHelper(NodeT *n) {
    if(n != nullptr) {
        topNodesHelper(n->getLeft());
        if(top > 0) {
            cout << n->getData().accesos << " " << n->getData().ip << endl;
            top--;
        }
        topNodesHelper(n->getRight());
    }
}

void BST::topNodes() {
    topNodesHelper(root);
}




