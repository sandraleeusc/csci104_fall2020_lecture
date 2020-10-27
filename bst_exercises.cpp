
#include<iostream>
#include <memory>
#include <algorithm>
using namespace std;


struct Node {    
    int val;    
    shared_ptr<Node> left;    
    shared_ptr<Node> right;      
  };
  
  
shared_ptr<Node> find(shared_ptr<Node> root, int value); 

void findInRange(shared_ptr<Node> root, int k1, int k2);


 // Write a recursive function to print the binary tree in 
 // preorder traversal order
 void print_preorder(shared_ptr<Node> root);


 
 
   
   int main(){   
       shared_ptr<Node> head = make_shared<Node>();
       shared_ptr<Node> l = make_shared<Node>();
       shared_ptr<Node> r = make_shared<Node>();
       shared_ptr<Node> ll = make_shared<Node>();
       shared_ptr<Node> lr = make_shared<Node>();
       head->val = 4;
       l->val = 2;
       r->val = 8;
       ll->val = 1;
       lr->val = 3;
       head->left = l;
       head->right = r;
      // l->val = 3;
       l->left = ll;
       l->right = lr;
        
       print_preorder(head);  
       cout << endl;
       shared_ptr<Node> search = find(head, 23);
       if (search == nullptr) cout << "23 not found" << endl;
       return 0;
   }


void print_preorder(shared_ptr<Node> root){
    if (root == nullptr) return;
    cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}


