/*
*
//******************************************************590. N-ary Tree Postorder Traversal.***********************************************

Given an n-ary tree, return the postorder traversal of its nodes' values.

 
For example, given a 3-ary tree:



 
Return its postorder traversal as: [5,6,3,2,4,1].

 
Note: Recursive solution is trivial, could you do it iteratively?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iterative implementation of Post Order Traversal. Since,we have >1 child, we keep track of #child nodes printed till now by
// using HashMap, with parent node as key, #child printed till now/pushed into stack for iter. as value pair. If we have a parent node at top of 
// stack with all chlidren printed(pushed into final result vector), then we push this parent node into final result vector. This way, we iter.
// till all nodes are printed(Stack is empty).








/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>res;														// Final result vector storing PostOrder Iter.
        if(!root) return res;												// If empty tree, return empty vector.
        stack<Node*>st;														// Stores nodes to be visited.
        unordered_map<Node*,int>m;											// Keeps tracks of #children of a node printed.
        Node* curr=root;													// Stores curr. node under consideration.
        st.push(root);														// Starting with root node.
        while(!st.empty()){													// Till stack is empty/all nodes are visited.
            // cout<<"Curr. node: "<<curr->val<<endl;	
            while(curr){													// Till left childs recur. till leaf are pushed into stack.
                curr=st.top();												// Storing curr. node.
                // cout<<"Curr. node inside inner while: "<<curr->val<<endl;
                if(curr->children.size()>0){								// If children exist.
                    m[curr]=1;												// Storing that one children had been pushed into stack.
                    st.push(curr->children[0]);								// Pushing children into stack.
                    curr=curr->children[0];									// Moving curr. node children node.
                }
                else curr=NULL;                    							// If no children then make it NULL.
                
            }
            curr=st.top();													// Curr. top of stack node.
            // cout<<"Curr. node outside while: "<<curr->val<<endl;
            if(m[curr]==curr->children.size()){								// If all children are pushed into stack.
                // cout<<"PUshing into res"<<endl;
                res.push_back(curr->val);									// Push curr. val into final result vector.
                st.pop();													// Pop curr. node from the stack.
                curr=NULL;													// Assigning curr to NULL to work on it's parent directly in next iter.
            }
            else{															// If still child needs to be pushed into stack.
                // cout<<"Next node: "<<endl;
                st.push(curr->children[m[curr]]);							// Pushing untouched child into stack.
                m[curr]++;													// Inc. the count of #child pushed into stack.
                curr=st.top();												// Making the child as curr val(to recur. left iter. this node).
            }
        }
        return res;															// Returning the postOrder Traversal of Tree.
    }
};