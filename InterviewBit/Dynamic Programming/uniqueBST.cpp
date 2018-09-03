/*
*
//************************************************************Unique Binary Search Trees.*****************************************************

https://www.interviewbit.com/problems/unique-binary-search-trees/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4

3

2

6

9



// Time Complexity: O(Catalan(n)).  
// Space Complexity: O(sigmanck(Catalan(k)).								// Not sure abt. space complexity though.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Catalan(n)).
// Space Complexity: O(sigmanck(Catalan(k)).								// Not sure abt. space complexity though.	
// https://www.geeksforgeeks.org/program-nth-catalan-number/   				// Explains what are catalan numbers.
// This algorithm is Dynamic Programming and DFS based. We go through all possible combination of roots and children, if we are in need of pre
// formed nodes, we reuse them using maps.








/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode*> findCombi(int num,unordered_map<string,vector<TreeNode*>>&m, int start,int end){
    vector<TreeNode*>res;													// Stores Nodes with this start, end combination.
    if(end<start) return vector<TreeNode*>(1,NULL);							// If no such combi. possible return NULL.
    string s=to_string(start)+to_string(end);								
    if(m.count(s)==1) return m[s];											// If this combi. is already created, return the calc. nodes.
    
    for(int i=start;i<=end;i++){											// Trying out all possible roots.
        vector<TreeNode*>lt=findCombi(num,m,start,i-1);						// Extracting all possible left child combinations.
        vector<TreeNode*>rt=findCombi(num,m,i+1,end);						// Extracting all possible right child combinations.
        for(int j=0;j<lt.size();j++){										// Forming diff. combinations of lt and rt child.
            for(int k=0;k<rt.size();k++){
                TreeNode* node=new TreeNode(i);								// Creating new node for the root.
                node->left=lt[j];											// Assigning left and right child.
                node->right=rt[k];
                res.push_back(node);										// Storing the root in the result vector.
            }
        }
    }
    m[s]=res;																// Storing the calc. roots.
    return res;																// Returning the calc. roots.
} 

vector<TreeNode*> Solution::generateTrees(int num) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<string,vector<TreeNode*>>m;								// Stores calc. roots for various start, end combinations.
    return findCombi(num,m,1,num);											// Returns the roots of this start, end combination.
    
}
