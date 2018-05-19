/*
*
//******************************************************297. Serialize and Deserialize Binary Tree.***********************************************

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory 
buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm 
should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original 
tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: Just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be 
creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,null,null,4,5, 6,null,7]

[1,2,3,3,null,4,5, 6,null,7]

[1,null,2,null,3,null,4,null,5]

[1,2,null,3,null,4,null,5]

[1]

[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates through the given tree and appends a "null" to the string whenever NULL is encoutnered, if non-NULL is encoutnered,then
// the value is pushed into string. On Deserialization, we maintain a var index which says curr. char in string to be scanned, if we obtain "null"
// we return NULL, if not we get int val from string and form a node with that value and call left and right child fn. calls.







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void extractStr(TreeNode* root, string &res){
        if(root==NULL){															// If, NULL encountered, append "null" and stop travel to child.
            res+="null,";
            return ;
        }
        res+=to_string(root->val)+",";											// If non-NULL, append value and call left and right child.
        extractStr(root->left, res);
        extractStr(root->right, res);
        return ;																	
    }
    
    
    
    TreeNode* formTree( string &data, int* index){          
        //cout<<"Index is: "<<*index<<endl;
        //if(*index>data.length()) return NULL;
        string temp="";
        while( *index<data.length() && data[*index]!=','){						// Extracting the curr. value.
            temp+=data[*index];
            (*index)++;
        }
        if(temp=="null"){														// If "null" extracted, then return NULL.
            (*index)++;
            return NULL;
        }
        
        int num=stoi(temp);														// if non-null Extracted, then form node with that val.
        (*index)++;
        TreeNode* node= new TreeNode(num);
        node->left=formTree(data,index);										// Call left and right child fn. calls..
        node->right=formTree(data,index);
        
        return node;
    }
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        extractStr(root, res);													// Calling fn. to serialize the given tree.
        //cout<<"Extracted string is: "<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //for(auto str:v) cout<<str<<" ";
        //cout<<endl;
        int index=0;															// Says curr. string index under scanning.
        return formTree(data,&index);											// Returning the tree formed.
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));