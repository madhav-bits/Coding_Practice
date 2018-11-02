/*
*
//******************************************************558. Quad Tree Intersection.***********************************************

A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, bottomLeft and bottomRight. Quad trees 
are often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.

We want to store True/False information in our quad tree. The quad tree is used to represent a N * N boolean grid. For each node, it will be 
subdivided into four children nodes until the values in the region it represents are all the same. Each node has another two boolean 
attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of 
the region it represents.

For example, below are two quad trees A and B:

A:
+-------+-------+   T: true
|       |       |   F: false
|   T   |   T   |
|       |       |
+-------+-------+
|       |       |
|   F   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight: T
bottomLeft: F
bottomRight: F

B:               
+-------+---+---+
|       | F | F |
|   T   +---+---+
|       | T | T |
+-------+---+---+
|       |       |
|   T   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight:
     topLeft: F
     topRight: F
     bottomLeft: T
     bottomRight: T
bottomLeft: T
bottomRight: F
 

Your task is to implement a function that will take two quadtrees and return a quadtree that represents the logical OR (or union) of the 
two trees.

A:                 B:                 C (A or B):
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       | F | F |  |       |       |
|   T   |   T   |  |   T   +---+---+  |   T   |   T   |
|       |       |  |       | T | T |  |       |       |
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       |       |  |       |       |
|   F   |   F   |  |   T   |   F   |  |   T   |   F   |
|       |       |  |       |       |  |       |       |
+-------+-------+  +-------+-------+  +-------+-------+
Note:

Both A and B represent grids of size N * N.
N is guaranteed to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.
The logic OR operation is defined as this: "A or B" is true if A is true, or if B is true, or if both A and B are true.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



// Complex Test cases to write.



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate through all parts of Quad Tree until we reach an Leaf segment in either of the Trees. If both 
// are not leaves, then we calculate recursively (OR) values of 4 sections of both trees.








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
    Node* intersect(Node* tree1, Node* tree2) {
        Node* res=new Node(false, false,NULL, NULL, NULL, NULL);			// Result node. 
        if(tree1->isLeaf)													// If first Tree is Leaf.
            return (tree1->val==true)?tree1:tree2;							// If leaf is True, return true else return other Tree.
        if(tree2->isLeaf)
            return (tree2->val==true)?tree2:tree1;
																			// If both are not Leaves.
        res->topLeft=intersect(tree1->topLeft, tree2->topLeft);				// Calc. (OR) of topLeft parts of both Trees.
        res->topRight=intersect(tree1->topRight, tree2->topRight);
        
        res->bottomLeft=intersect(tree1->bottomLeft, tree2->bottomLeft);
        res->bottomRight=intersect(tree1->bottomRight, tree2->bottomRight);
																			// If all child are leaves and are of same value.
        if(res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf && res->topLeft->val==res->topRight->val && res->topRight->val==res->bottomLeft->val && res->bottomLeft->val==res->bottomRight->val){
            res->isLeaf=true;												// Marking it as leaf, as are of same value.
            res->val=res->topLeft->val;										// Setting the value.
        }
        return res;															// Returning the result node.
    }
};