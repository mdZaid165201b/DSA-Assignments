
#include <iostream>

using namespace std;

class Node{
    int data;
    Node *left;
    Node *right;
    public:
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        
    }
    // setters and getters
    void setData(int data) { this->data = data; }
    void setLeft(Node *left) { this->left = left; }
    void setRight(Node *right) { this->right = right; }
    
    int getData() { return this->data; }
    Node * getLeft() { return this->left; }
    Node * getRight() { return this->right; }
};

class BST{
    Node * root;
    public:
    BST(){ root = NULL; }
    
    bool isEmpty(){ return root == NULL; }
    
    void insert(int val){
        if(isEmpty()){
            root = new Node(val);
        }
        else{
            Node *temp = root;
            Node *prev;
            while(temp){
                if(temp->getData() < val){
                    prev = temp;
                    temp = temp->getRight();
                }
                else{
                    prev = temp; 
                    temp = temp->getLeft();
                }
                
                
            }
            if(prev->getData() > val){
              prev->setLeft(new Node(val));
            }
            else{
                prev->setRight(new Node(val));
                
            }
        }
        
    }
    
    void inOrder(Node * root){
        if(root == NULL){ return; }
        inOrder(root->getLeft());
        cout<<root->getData()<<" ";
        inOrder(root->getRight());
    }
    void inOrder(){
        inOrder(this->root);
    }
};




int main()
{
    BST bst;
    bst.insert(8);
    bst.insert(2);
    bst.insert(6);
    bst.inOrder();

    return 0;
}
