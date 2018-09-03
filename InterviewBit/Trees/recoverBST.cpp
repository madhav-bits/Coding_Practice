/*
*
//************************************************************Recover Binary Search Tree.***************************************************


https://www.interviewbit.com/problems/recover-binary-search-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[30,20,40,10,25,35,45,7,15,23,27,null,null,null,null,null,9,12,17]


[30,15,40,10,25,35,45,7,20,23,27,null,null,null,null,null,9,12,17]


[30,20,40,10,17,35,45,7,15,23,27,null,null,null,null,null,9,12,25]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is traversal based. We iterated over entire BST in Inorder fashion. We stored the prev. visited node in the process. As, we have 
// two swapped nodes, both of them would violate inc. order condition. In case of first encountered swapped val.(As this is a val greater than it's 
// supposed to be, then this value would be <next value, we store the greater value), we observe for this scenario. In case of second swapped 
// val(As this a val smaller than it's prev. value, we store curr. value/smaller value). As, first and second conditions overlap second swapped 
// val would also be chosen, but the actual scenario would occur later, so it replaces the prev. init. value.








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
    
    TreeNode* prev=NULL;													// Tracks predecessor to curr. node.
    TreeNode* first=NULL, *second=NULL;										// Stores first and second swapped nodes.
    
    void inorderTrav(TreeNode* node, int& count){
        if(!node) return ;													// If null node, return from call.
        
        inorderTrav(node->left,count);										// Give recur. call to left child.
        if(prev!=NULL && count==0 && node->val<prev->val){					// If curr. val<prev.val, then store prev. node.
            // cout<<"first prev. "<<prev->val<<" and curr: "<<node->val<<endl;
            first=prev;														// Store the prev. node.
            count++;														// Inc. the count, indicating first swapped node is found.
        }
        if(count==1 && node->val<prev->val){								// If first is found, then look for second.	
            // cout<<"second prev. "<<prev->val<<" and curr: "<<node->val<<endl;
            second=node;													// If curr. val<prev. val, then store curr. value.
		}	        
        prev=node;															// Update the prev. visited node.
        inorderTrav(node->right,count);										// Give recur. call to right child.
        
    }
    
    vector<int> Solution::recoverTree(TreeNode* root) {
        int count=0;														// Tracks #swapped vals found.
        
        inorderTrav(root,count);											// Call fn. to do Inorder traversal.
        if(first->val<second->val)											// Returning swapped values in Inc. order.
			return vector<int>({first->val, second->val});
		else 
			return vector<int>({second->val, first->val});
    }
};













//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm is Inorder traversal using Morris Traversal. First we form link b/w predecessor node and curr. node of Inorder traversal.
// For every node, we move to left child if present, then iter. rightwards till we reach NULL, then make curr. node as right child of last node
// in predecessor search. We then move to left child of curr. node. In the second visit of this node, we must have been already visited it's prev. 
// node. so we can compare prev. and curr. node(The comparing and deciding first and second swapped nodes is the same as the above algo.).






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
    
    vector<int> Solution::recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;												// Stores predecessor of curr. node.
        TreeNode* first=NULL, *second=NULL;									// Stores first and second swapped nodes.
        
        TreeNode* curr=root;												// Init. the curr. var.
        while(curr){														// Till all nodes are visited.
            // cout<<"Curr. node: "<<curr->val<<endl;
            if(!curr->left){												// If no left child, visit the node.
                if(!first && prev!=NULL && prev->val>curr->val){			// Look for first swapped node.
                    first=prev;
                }
                if(first && prev->val>curr->val){							// Look for second swapped node.
                    second=curr;
                }
                prev=curr;													// Update the prev. visited node.
                curr=curr->right;											// Move to right child.
            }
            else{															// Make connections for Morris Inorder traversal.
                TreeNode*pred=curr->left;									// Taking a left step.
                // cout<<" pred: "<<pred->val<<endl;	
                while(pred->right!=NULL && pred->right!=curr) pred=pred->right;// Finding the Inorder predecessor of curr. node.
                
                if(pred->right==NULL){										// If pred. node reached.
                    pred->right=curr;										// Make curr. the right child of pred. node.
                    curr=curr->left;										// Iter. to left chlid of curr. node.
                }
                else{														// In second iter. Pred->right=curr. node.
                    if(!first && prev!=NULL && prev->val>curr->val){		// Look for first swapped node.
                    first=prev;
                    }
                    if(first && prev->val>curr->val){						// Look for second swapped node.
                        second=curr;
                    }
                    prev=curr;												// Update the prev. visited node.
                    pred->right=NULL;										// Bring it back to orig. state.
                    curr=curr->right;										// Move to right child of curr. node(As lt child,curr. node are visited).
                }
            }
        }
        
        if(first->val<second->val)											// Returning swapped values in Inc. order.
			return vector<int>({first->val, second->val});
		else 
			return vector<int>({second->val, first->val});			
    }
};