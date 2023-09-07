/*
*
//******************************************************2094. Finding 3-Digit Even Numbers.******************************************************

https://leetcode.com/problems/finding-3-digit-even-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3,0]
[2,2,3]
[2,2,8,8,2]
[4,1,4,3,1,4,7,7,4,3,6,8,8,4,3,8,6,9,8,7,5,4,3,2]



// Solution 2 has better Time and Space Complexity.
// Time Complexity: O(1).													// We iterate 450=(999-100)/2 times.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+n^3).
// Space Complexity: O(1).	
// This algorithm is DFS based. We sort the given digits and form 3 digit nums using DFS and use conditions to prevent reusing used digits and avoid duplicates.
// and add nums to res if it's even.







class Solution {
public:
    
    void form3DigitNums(vector<int>&digits, int val, vector<int>&res) {		
        for(int i=0;i<digits.size();i++) {									// Iter. over all digits.
            if(val==0 && digits[i]==0) continue;							// Prevents leading zeroes.
            if(digits[i]==-1 || (i>0 && digits[i]==digits[i-1])) continue;	// Prevents duplicates and avoid reusing used digits.
            val=val*10+digits[i];											// Add curr. digit to num.
            digits[i]=-1;
            if(val*10>=1000) {												// If we form a 3 digit num.
                if(val%2==0) res.push_back(val);							// If it's even, add to res.
            } else form3DigitNums(digits, val, res);						// Else DFS call to form greater length num.
            digits[i]=val%10;												// Resetting vals for next iter.
            val/=10;
        }
        return ;
    }
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        vector<int>res;
        form3DigitNums(digits, 0, res);										// DFS call to form 3 digit even nums.
        return res;															// Returning sorted 3 digit even nums.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// We iterate 450=(999-100)/2 times.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over all 3 digit even nums and check whether if we have req. digits available from the array. If yes, we add it 
// to res.






class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int occur[10];
        memset(occur, 0, sizeof(occur));
        for(int&digit:digits) occur[digit]++;								// Tracking #occur of each num.
        vector<int>res;
        for(int num=100;num<1000;num+=2) {									// Iter. over all 3 digit even nums.
            int hund=num/100, tens=(num%100)/10, ones=num%10;				// Extract digits in curr. num.
            occur[hund]--; occur[tens]--;occur[ones]--;						// Removing used digits.
            if(occur[hund]>=0 && occur[tens]>=0 && occur[ones]>=0) res.push_back(num);// If req. digits available, we add curr. num to res.
            occur[hund]++; occur[tens]++;occur[ones]++;						// Resetting digits count.
        }
        return res;															// Returning sorted 3 digit even nums.
    }
};

