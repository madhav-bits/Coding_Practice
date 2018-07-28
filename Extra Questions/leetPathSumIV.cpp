/*
*
//****************************************************************666. Path Sum IV.*********************************************************

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full 
binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths 
from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[111,217,221,315,415]

[112]


[111,211,232]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is vector based. Here, I extract the tree and store the values in a 2D vector(We could have used a Tree direclty, since we have 
// depth avaialbe from the vector, psn from the left in a level in the tree. These two indicates it's more easy to represent Tree here in 
// vector). We form a tree in vector. 
// Then iterate the tree, nodes in each level starting from level 1, extract values from their parents and add 
// the curr. node's val and pass it to it's child.On reaching the leaf(both child with value -1). We sum the extracted value+curr. node's val
// to the var res. Thus, we get sum of all paths from root to leaves.








class Solution {
public:
    int pathSum(vector<int>& v) {
        if(v.size()==0) return 0;											// If empty tree is given, return 0.
        vector<vector<int>>tree;											// Used to store the tree.
        for(int i=0;i<v.size();i++){										// Iterating the given array.
            int val=v[i]%10;												// Extracting the val.
            v[i]/=10;
            int psn=v[i]%10-1;												// Extracting the psn in curr. row.
            v[i]/=10;	
            int depth=v[i]%10-1;											// Extracting the depth value.
            if(tree.size()==depth) tree.push_back(vector<int>(pow(2,depth),-1));// Pushing a new row into 2D vector.
            tree[depth][psn]=val;											// Pushing val in curr. row's given psn in tree vector.
        }
        // for(auto nums:tree){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        if(tree.size()==1) return tree[0][0];								// If single row given, return root value.
        int res=0;															// Stores the sum of diff. path's values.
        for(int i=1;i<tree.size();i++){										// Iterating through the tree.
            for(int j=0;j<(1<<i);j++){										// ITerating through the curr. level in tree.
                if(tree[i][j]==-1) continue;								// If not init. skip it.
                int par=(j)/2;												// Getting parent of curr. node.
                tree[i][j]+=tree[i-1][par];									// Getting sum of path from parent.
                if(i+1==tree.size() || (tree[i+1][2*j]==-1 && tree[i+1][(2*j)+1]==-1)){// If curr. node is leaf, add val to final result: res.
                    // cout<<"Adding val at row: "<<i<<" and clmn: "<<j<<endl;
                    res+=tree[i][j];
                }
            }
            
        }
        return res;															// Returning the sum of all paths from root to leaves.
    }
};