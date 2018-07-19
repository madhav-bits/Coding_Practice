/*
*
//******************************************************487. Max Consecutive Ones II.***********************************************

Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as 
it's too large to hold in memory. Could you solve it efficiently?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[1,0,1,1,0,1]


[1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,1]



[]


[1,1,1,1]



[0,1,0,0]


[0,0,0,0]



[0,1,0,1,0]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We track the length of conse. ones curr. and prev. seq and store them in two vars. Whenever zero is encoun.
// we assign the currOnes to prevOnes. Whenever we encounter ones, we add currOnes,prevOnes,1 if zeros is 1. We add currOnes+1, if zeros>1, as
// we can change last zero adj. to 1, and the conse. ones len. inc by one. There might be scenario with all ones(zeros=0), in that case, we have
// to take into account length of curr. seq. 



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int prevOnes=0, currOnes=0, zeros=0, maxOnes=0;						// Tracks curr, prev 1's seq, zeros seq. len, max consec. ones len.
        if(v.size()==0) return 0;											// If len=0, return 0.
        for(int i=0;i<v.size();i++){
            // cout<<"Curr. index: "<<i<<endl;
            if(v[i]==0){
                if(i-1>=0 && v[i-1]==1) zeros=0;							// First time zero is encountered, set count=0.
                zeros++;													// Inc. the count of conse. zeros.
                if(currOnes!=0)												// Assigning currOnes to prevOnes.
                    prevOnes=currOnes;
                currOnes=0;													// Setting currOnes to 0.
            }
            else{
                currOnes++;													// Tracking curr conse. ones count.
                if(zeros==1)												// If we have one zero, add curr., prev. 1 seqs+1.
                    maxOnes=max(maxOnes,prevOnes+currOnes+1);
                else if(zeros>1)											// If zeros>1, then add curr 1's seq+1(change prev. zero bit to 1).
                    maxOnes=max(maxOnes,currOnes+1);
                else 
					maxOnes=max(maxOnes,currOnes);							// If zeros=0, take curr 1's seq len. into consideation.
            }
            // cout<<"maxOnes: "<<maxOnes<<endl;
        }
        if(v.back()==0) return max(maxOnes,prevOnes+1);						// If we have zeros seq ending vector, we can convert one of zeroes.
        return maxOnes;														// Return the max cosec. ones in the transformed vector.
    }
};