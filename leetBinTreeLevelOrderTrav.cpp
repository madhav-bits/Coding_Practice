/*
*
//*****************************************************102. Binary Tree Level Order Traversal.**********************************************

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).
// This is standard way, calc. the height of the tree. Iterate from the start to reach height of the tree and printing all the level elem. into
// vector at a go. This algorithm is costly time complexity wise(ex: root is iterated height no. of times, 1 per level's iteration).



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
    vector<vector<int>>u;
    int calcHeight(TreeNode* temp){
        if(temp==NULL)
            return 0;
        //cout<<"Inside calcHeight func. with elem. value: "<<temp->val<<endl;
        int lHeight=calcHeight(temp->left);
        int rHeight=calcHeight(temp->right);
        if(lHeight>rHeight)
            return lHeight+1;
        else
            return rHeight+1;
    }
    
    void printLevel(TreeNode* temp, int height, int target){
        //cout<<"Inside printLevel func. with elem. value: "<<temp->val<<" and height is: "<<height<<endl;
        if(temp!=NULL){
            if(height==target){
                //if(temp!=NULL)
                    u[target-1].push_back(temp->val);
            }
            else{
                //cout<<"Inside else."<<endl;
                printLevel(temp->left,height+1,target);
                printLevel(temp->right,height+1,target);
            }
        }
        
    }
    void printLevelOrder(TreeNode* temp){
        int height=calcHeight(temp);
        //cout<<"The height is: "<<height<<endl;
        for(int i=1;i<=height;i++){
            u.push_back({});
            printLevel(temp,1,i);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* temp=root;
        printLevelOrder(temp);
        /*
        for(auto nums:u){
            for(auto num:nums){
                cout<<"The elem. are: "<<num<<endl;
            }
        }
        */
        
        return u;
    }
};





//************************************************************Solution 2:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This is pretty clever approach to the problem, doing a pre order traversal of the tree and putting the elem. in the vector as enocuntered 
// wrt their heights.





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
    vector<vector<int>>u;
    void preOrder(TreeNode* temp, int height){
        if(temp!=NULL){
            //cout<<"Curr. val. is: "<<temp->val<<endl;
            if(u.size()==height)
                u.push_back({});
            u[height].push_back(temp->val);
        
            preOrder(temp->left,height+1);
            preOrder(temp->right, height+1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        //TreeNode* temp=root;
        preOrder(root,0);
        /*
        for(auto nums:u){
            for(auto num:nums){
                cout<<"The elem. are: "<<num<<endl;
            }
        }
        */
        
        return u;
    }
};