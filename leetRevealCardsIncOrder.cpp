/*
*
//*******************************************950. Reveal Cards In Increasing Order.*******************************************

Ghttps://leetcode.com/problems/reveal-cards-in-increasing-order/description/



In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.

 

Example 1:

Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
 

Note:

1 <= A.length <= 1000
1 <= A[i] <= 10^6
A[i] != A[j] for all i != j





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[17,13,11,2,3,5,7,12,15,19,21,18]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS A VERY GOOD QUESTION.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Reverse Simulation based. Here, we build a final result queue filled with it's index values.We simulate the skipping
// alternate index process, we maintain another index over sorted given array. Whenever we take value in the queue, we assign that 
// index in result array with curr. sorted array's value and inc. the pointer by 1. We skip next index in queue and push it to tail and
// repeat the process until queue is empty.







class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        if(v.size()==1) return v;
        vector<int>res(v.size(),0);											// Created final result array.
        sort(v.begin(), v.end());											// Sort the given array.
        queue<int>q;														// To store the result's init. stage with it's indices.
        for(int i=0;i<v.size();i++)											// Pushing indices into queue to reflect init. stage.
            q.push(i);
        int index=0;														// Pointer over sorted array.
        while(!q.empty()){													// Until all indices are assigned values.
            int ind=q.front();												// Index whose value taken to form sorted array.
            q.pop();
            res[ind]=v[index++];											// res's index is assigned curr. value of sorted array.
            if(!q.empty()){													// Skip the next index and push it to tail.
                q.push(q.front());
                q.pop();
            }
        }
        return res;															// Return the result array.
    }
};