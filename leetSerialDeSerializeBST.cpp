/*
*
//******************************************************449. Serialize and Deserialize BST.***********************************************

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory 
buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to 
the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,6, null,3]
[4,2,6, null,3,null,7]
[1]
[1,null,3]
[64,56,72,48,60,null,76, null,52,null,null,74,78,50,54]
[]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm does a INorder traversal, and stores the tree in the form of string(Leetcode uses same way to rep. Bin. Tree) and passing it.
// Before passing, remove all ending null chars. And then attach every curr. node to two conse. nodes in Inorder Traversal. Return the root node.



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

    // Encodes a tree to a single string.
    string serialize(TreeNode* temp) {
        string s="";
        queue<TreeNode*> q;
        if(temp==NULL) return s;
        else {q.push(temp);s+=to_string(temp->val);}//+'0'							// Passing the root, before the while loop.
        while(!q.empty()){
            int count=q.size();
            while(count>0){
                TreeNode* temp=q.front();
                q.pop();
                count--;
                if(temp!=NULL ){//&& (temp->left!=NULL || temp->right!=NULL)		// If the curr. node!=NULL, then only pass it's child.
                    if(temp->left==NULL) s+=",null";
                    else s+=","+to_string(temp->left->val);//(temp->left->val)+'0';
                    q.push(temp->left);
                    if(temp->right==NULL) s+=",null";
                    else s+=","+to_string(temp->right->val);
                    q.push(temp->right);
                }
                
            }
        }
        //cout<<"The string is: "<<s<<endl;
        int index=s.length()-1;
        while(s[index]<48 || s[index]>57)									// Removes all terminating null chars.
            index--;
        return s.substr(0,index+1);											// Passes substring excluding terminating null chars.
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        //cout<<"Retrieved string is: "<<data<<endl;
        TreeNode* root=NULL;
        if(data.length()==0) return root;
        vector<TreeNode*>v;
        int curr=0;
        while(curr<data.length()){									// Parsing the string and extracing all the useful(int, null) terms int vector.
            int init=curr;
            //cout<<"Initial is; "<<init<<endl;
            while(curr != data.length() && data[curr]!=',')			// Comma is delimiter.
                curr++;
            if(data.compare(init,curr-init,"null" )==0) v.push_back(0);		// If it's null, then push null into vector. 
            else v.push_back(new TreeNode(stoi(data.substr(init, curr-init+1))));//Else, push int. into vector.
            
            curr++;
        }
        //cout<<"The vector size is: "<<v.size()<<" and first value is: "<<v[0]->val<<endl;
        root=v[0];
        for(int i=0,j=1;j<v.size();i++){							// First iterator(i), passes over the parent node.
            while(v[i]==NULL){ i+=1;}								// Making sure,that parent node is not NULL, as child have to be assigned to it.
            v[i]->left=v[j];
            j++;													// Second iterator(i), passes over two children node.
            if(j>=v.size()) break;									// Making sure, that vector's index limits are not exceeded.
            v[i]->right=v[j];
            j++;
        }
        return root;												// Returning the parent node of the reconstructed BST.
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));