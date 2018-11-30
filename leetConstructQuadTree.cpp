/*
*
//************************************************************427. Construct Quad Tree.*****************************************************

We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole 
grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a 
leaf node contains the value of the region it represents.

Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:

Given the 8 x 8 grid below, we want to construct the corresponding quad tree:



It can be divided according to the definition above:



 

The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.

For the non-leaf nodes, val can be arbitrary, so it is represented as *.



Note:

N is less than 1000 and guaranteened to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[1]]


[[1,0,0,0],[0,0,0,0],[1,1,1,1],[1,0,1,1]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Recursion based. Here, we recursively keep on working on smaller rectangles, until the size of the rectangle is 1. If that
// pixel is true/false values are assigned accordingly. If from the recursion we have curr. node's 4 children as leaves and all of them having 
// same value, then we make curr. node a leaf node with the children's value as it's value. If any of children is not leaf, or leaves values
// doesn't match then the curr. node won't be a leaf. This way, we bulid nodes upto the root node. Since, we iterate and touch every index only
// once. The time complexity is O(n).








/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    
    Node* formTree(vector<vector<int>>& v, int rowStart, int rowEnd, int colStart, int colEnd){
        // cout<<"rowStart: "<<rowStart<<" rowEnd: "<<rowEnd<<" colStart: "<<colStart<<" colEnd: "<<colEnd<<endl;
        Node* curr=new Node(false, false, NULL, NULL, NULL, NULL);
        if(rowStart==rowEnd && colStart==colEnd){							// If representation space is reduced to single index.
            curr->isLeaf=true;
            // cout<<"rowStart: "<<rowStart<<" and colStart: "<<colStart<<endl;
            if(v[rowStart][colStart]==1) curr->val=true;					// Assign values to node based on index's value.
            else curr->val=false;
        }else{																// If representation space is more than single block.
            int midRow=(rowStart+rowEnd)/2;
            int midCol=(colStart+colEnd)/2;
            curr->topLeft=formTree(v,rowStart,midRow, colStart, midCol);	// Recursive call to Represent  Top Left.
            curr->topRight=formTree(v,rowStart, midRow, midCol+1, colEnd);	// Recursive call to Represent  Top Right.
            
            curr->bottomLeft=formTree(v, midRow+1, rowEnd, colStart, midCol);	// Recursive call to Represent  Bottom Left.
            curr->bottomRight=formTree(v, midRow+1, rowEnd, midCol+1, colEnd);	// Recursive call to Represent  Bottom Right.
            if(curr->topLeft->isLeaf && curr->topRight->isLeaf && curr->bottomLeft->isLeaf && curr->bottomRight->isLeaf){// If all child are leaves.
                if(curr->topLeft->val==curr->topRight->val && curr->topRight->val==curr->bottomLeft->val && curr->bottomLeft->val==curr->bottomRight->val){
                    curr->val=curr->topLeft->val;							// If all of them have same values.
                    curr->isLeaf=true;										// Labelling curr. node has leaf.
                    curr->topLeft=NULL;										// Reassigning all child node values.
                    curr->topRight=NULL;
                    curr->bottomLeft=NULL;
                    curr->bottomRight=NULL;
                }
            }
        }
        return curr;														// Returning curr. node.
    }
    
    Node* construct(vector<vector<int>>& v) {
        if(v.size()<1) return NULL;											// If no elements are present.
        return formTree(v,0, v.size()-1, 0, v[0].size()-1);					// Calling fn. to form QuadTree.
    }
    
};