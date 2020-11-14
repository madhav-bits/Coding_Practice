/*
*
//******************************************1634. Add Two Polynomials Represented as Linked Lists.***************************************

https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[[1,1]]
[[1,0]]
[[2,2],[4,1],[3,0]]
[[3,2],[-4,1],[-1,0]]
[[1,2]]
[[-1,2]]
[[-3,8],[-4,3],[4,2]]
[[3,8],[7,6],[4,3],[-5,2]]



// Time Complexity: O(n+m).  
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).
// Space Complexity: O(1).	
// This algorithm is iteration based. At every step, we check powers of both nodes, if they are same, we add their coefficients and
// create a new node and assign it the total, if one power is greater than other, we assign greater power as next node to curr. node
// we move to smaller powers in every step, thus we reach end of both LL in n+m steps.








/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if(poly2==NULL) return poly1;
        if(poly1==NULL) return poly2;
        PolyNode* res=new PolyNode();
        PolyNode* temp=res;
        int total=0;
        while(poly1 && poly2){												// Iter. until both nodes exist.
            if(poly1->power==poly2->power){									// If both powers are equal.
                temp->next=NULL;
                total=poly1->coefficient+poly2->coefficient;
                if(total!=0)												// If added coeff. is zero, we don't create new node.
                    temp->next=new PolyNode(total, poly1->power);

                poly1=poly1->next;
                poly2=poly2->next;
            }else if(poly1->power>poly2->power){							// If one power is >other power.
                temp->next=poly1;
                poly1=poly1->next;
            }else{
                temp->next=poly2;
                poly2=poly2->next;
            }
            
            if(temp->next)
                temp=temp->next;
        }
        if(poly1) temp->next=poly1;											// If only one of them exists.
        if(poly2) temp->next=poly2;
        return res->next;													// Return the root node of addition step result.
    }
};
