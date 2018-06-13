/*
*
//**********************************************************390. Elimination Game.***************************************************

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until 
you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


37
20
18
10
16
9
7
1
0																	// Not accepted input value.



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is observation based. We, keep track of head of list after every elim. If we move from L->R or R->L with #elem. begin odd, then
// head moves to right, but #steps it moves to right after each round of elim. inc. with each round of elim(Inc. by 2 times). After all rounds
// of elim., we get the remaining node or head of rem. list of 1 elem.








class Solution {
public:
    int lastRemaining(int n) {
        int rem=1;														// Tracks head of the list.
        int moves=1;													// No. of steps head moves to right.
        bool left=true;													// Elim. form left to right.
        for(int i=n;i>1;i/=2){
            // cout<<"Rem: "<<i<<" and left: "<<left<<endl;
            if(left==true || i%2==1){									// If we elim. from L->R or R->L with #elem. begin odd, head moves to right.
                rem+=moves;
                
            }
            moves*=2;													// #Moves multiplies as we keep on dec. #elem. in list.
            left=!left;													// Reversing the drn of elim.
            
        }
        // cout<<"The result  is: "<<rem<<endl;
        return rem;														// Returning the rem. elem. after all deletions.
    }
};



