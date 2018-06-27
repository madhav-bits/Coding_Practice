/*
*
//******************************************************536. Construct Binary Tree from String.***********************************************

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents 
the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"4(2(3)(1))(6(5)(7))"

"4(2(3)(1))(6(5))"

"4"

""


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We take a default temp node and push it to stack, we extract node values from str, we check whether the 
// top node has left child, if not we set the curr. node as it's left child and push the curr. node into stack. If it has left child, we make
// curr. node as it's right child and push the curr. node into stack. At the end of all iterations, we return the temp node's left child, as that's
// the root of the given tree.

// As, we form nodes based on the parens, we might have only root, in that case that won't be pushed onto stack, so, we make that as the left/right
// child of the node at the top of the stack accordingly.








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*>st;													// Stores the nodes of the tree.
        int temp=0;															// Stores the value of the node value.
        int sign=1;															// Stores the sign of the node value.
        TreeNode* root= new TreeNode(-1);
        st.push(root);														// Push the temp. node onto stack.
        for(int i=0;i<s.length();i++){										// Iterates the entire array.
            if(s[i]>=48 && s[i]<=57)										// Extracting value of the node.
                temp=temp*10+s[i]-48;
            else if(s[i]=='-') sign=-1;										// Setting the sign to the value of the curr. node.
            
			
            if((s[i]=='(' || s[i]==')') ){									// We push/remove nodes whenever parens are encountered.
                // cout<<"Inside the if with parens: "<<i<<endl;
                if(st.top()->left==NULL && s[i-1]>=48 && s[i-1]<=57){		// Make curr. node, left child of the node at the top of the stack.
                    TreeNode* tempNode= new TreeNode(temp*sign);
                    // cout<<"Setting leftNode to: "<<st.top()->val<<" is: "<<temp*sign<<endl;
                    st.top()->left= tempNode;								
                    // cout<<"Pushing node: "<<tempNode->val<<endl;
                    st.push(tempNode);										// Push curr. node onto stack. Hoping to extract it's children.
                }
                else if(st.top()->left!=NULL && s[i-1]>=48 && s[i-1]<=57){	// If left child already present to node at the top of stack.
                    TreeNode* tempNode= new TreeNode(temp*sign);			// Creating curr. node.
                    // cout<<"Setting rightNode to: "<<st.top()->val<<" is: "<<temp*sign<<endl;
                    st.top()->right= tempNode;								// Make curr. node, the right child of the node at top of stack.
                    // st.pop();
                    // cout<<"Pushing node: "<<tempNode->val<<endl;
                    st.push(tempNode);										// Push curr. node onto stack. Hoping to extract it's children.
                }
                sign=1;														// Setting default sign value to next possible node.
                if(s[i]==')'){												// When closing paren encoutnered, we remove node at top of stack.
                    // cout<<"Popping node: "<<st.top()->val<<endl;
                    st.pop();    
                } 
                temp=0;														// Setting the base value to the next node's value.
            }
        }
        
        if(s[s.length()-1]>=48 && s[s.length()-1]<=57){						// If only single node is passed, then we make it left/right child.
            if(st.top()->left==NULL) st.top()->left= new TreeNode(sign*temp);
            else st.top()->right= new TreeNode(sign*temp);
        }
        return root->left;													// Returning the root of the given tree.
    }
};