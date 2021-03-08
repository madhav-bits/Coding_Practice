/*
*
//**************************************************1628. Design an Expression Tree With Evaluate Function.*******************************************

https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/

Given a postfix expression in an array, we have to return a tree where the non-leaf nodes store the operator and the leaves would be the operands(numbers).
An Interface class is defined, we can make changes to it or create new classes to meet the requirements and return the root of the tree.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


["3","4","+","2","*","7","/"]
["3","4","+","2","*","7","/","5","/","23","+","5","*"]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Object Oriented Progamming based. We are requested to design classes to suit the requirement. So, we create two classes,
// NumNode- in which we store the integers in the laves, EvalNode- which are non-leaf nodes in the tree, which performs operations on the values obtained
// from both the children. We make use of Inheritance and polymorphism and we define the evaluate function based on the operator provided or return num
// if no operator is provided(leaf node). We also create properties for EvalNodes like sign which provided information about operator and val in NumNode
// to store the value that this node stores.









/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
    
};


class NumNode: public Node{													// Stores the integer val that this node represents.

    private:
        int val;
    
    public: 
        NumNode(int val){
            this->val=val;
        }
        virtual int evaluate() const{
            return val;
        } 
    
       
};


class EvalNode:public Node{													// Stores operator and performs evaluation based on operators.
    
    private:
        Node* left;
        Node* right;
        int sign;
    
    public: 
        EvalNode(int sign){
            left=NULL;
            right=NULL;
            sign=sign;
        }
    
        EvalNode(int sign, Node* lt, Node* rt){
            left=lt;
            right=rt;
            this->sign=sign;
        }
    
        int evaluate() const{
            if(sign==0){
                return this->left->evaluate()+this->right->evaluate();
            }else if(sign==1){
                return this->left->evaluate()-this->right->evaluate();
            }else if(sign==2){
                return this->left->evaluate()*this->right->evaluate();
            }else if(sign==3){
                return this->left->evaluate()/this->right->evaluate();
            }
            return -1;
        }    
    
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& v) {
        stack<Node*>st;
        for(int i=0;i<v.size();i++){
            Node* node=NULL, *left=NULL,*right=NULL;
            if(v[i]=="+"){													// Extracting prev. two nodes and making them the children of curr. EvalNode.
                right=st.top(); st.pop();
                left=st.top(); st.pop();
                node=new EvalNode(0, left, right);
            }else if(v[i]=="-"){
                right=st.top(); st.pop();
                left=st.top(); st.pop();
                node=new EvalNode(1, left, right);
            }
            else if(v[i]=="*"){
                right=st.top(); st.pop();
                left=st.top(); st.pop();
                node=new EvalNode(2, left, right);
            } 
            else if(v[i]=="/"){
                right=st.top(); st.pop();
                left=st.top(); st.pop();
                node=new EvalNode(3, left, right);
            }else node=new NumNode(stoi(v[i]));								// Inserting the NumNode into stack.
            // cout<<"eval: "<<node->evaluate()<<endl;
            st.push(node);
        }
        return st.top();													// Returning the root node of the tree.
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */