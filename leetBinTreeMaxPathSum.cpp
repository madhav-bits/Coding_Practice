/*
*
//*****************************************************124. Binary Tree Maximum Path Sum.********************************************

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child 
connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[10,5,19,1,9,15,29,null, null, null, null,12]
[10,5,19,1,8,15,29,null, null, null, null,11]
[]
[2,5,5,4,6,2,4,-2,-5,-3]

[2,5,5,-4,-6,2,4,-2,-5,-3, 4,11,3,5,6,null,null,null,null,30]

[-1,null,9,-6,3,null,null,null,-2]

// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
//  This algorithm does Inorder Traversal, then temp. stores the temp. max from that node and child and return it. We check whether the child and
// the current node form a Max. Path Sum or not.

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
    int maxm=INT_MIN;
    int findMaxSum(TreeNode* temp){
        
        if(temp==NULL) return -32000;									// In case of NULL, returning the INT_MIN.
        //cout<<"Passed root value is: "<<temp->val<<" "<<nodeValue<<endl;
        int sum1=findMaxSum(temp->left);								//Passing to the left child.
        int sum2=findMaxSum(temp->right);
        //**************************************************This calculates which combination of node and children give the max. sum.
		//Instead of this lengthy if, else condition, this four lines would suffice, as cases of choosing only child are handled in their own calls.
		/*
		int sum=root->val; 
        if(l>0) sum+=l ;
        if(r>0) sum+=r; 
        max_sum=max(max_sum, sum); 
		*/
        if( temp->val>=0){												
            //cout<<"Inside temp value>0 with sum1: "<<sum1<<" and sum2: "<<sum2<<endl;
            if(sum1>=0 && sum2>=0 )
                maxm=max(maxm,sum1+sum2+temp->val);                     // Path taking turn at this node, so need to handle carefully.
            else if(sum1<0 && sum2<0)
                maxm=max(maxm,temp->val);
            else{
                int maxChild=max(sum1,sum2);
                //cout<<"Extracting max. child."<<endl;
                maxm=max(maxm,temp->val+maxChild);
            }
            //cout<<"Maxm. value is: "<<maxm<<endl;
        }
        
        else if(temp->val<0){
            //cout<<"Inside else "<<endl;
            if(sum1>=0 && sum2>=0){                                   //Both of the childs are positive.
                int sumMax=max(sum1,sum2);
                sumMax=max(sumMax,sum1+sum2+temp->val);
                //cout<<" Maxm. value in else case's  two +ves is: "<<sumMax<<endl;
                maxm=max(maxm,sumMax);
            }
            else{
                int value=max(sum1,sum2);
                value=max(value,temp->val);
                //cout<<" Maxm. value in else case is: "<<value<<endl;
                maxm=max(maxm,value);
            }
            
        }
        
        
        return max(temp->val, temp->val+max(sum1,sum2));						//This gives the max. sum one gets from this root and it's child.
       
    }
    
    int maxPathSum(TreeNode* root) {
        findMaxSum(root);
        return maxm;												// Returning the max. path sum.
    }
};