/*
*
//**********************************************************625. Minimum Factorization.***************************************************

Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 
Output:
68
Example 2
Input:

15
Output:
35




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3000000


12


24


48


5040


// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Observation based. So as to get the min. value for factorization. We have to get least possible factors(2-9) as possible.
// So, as to get least possible factors, we need to check for factorials from back till 2. We push the extracted factorials into a vector. We
// iter. over this vector from the back, to get the least valued factor number.







class Solution {
public:
    int smallestFactorization(int target) {
        if(target<=9) return target;										// Base cases.
        int res=0, prod=target;												// Tracks result, temp. stores given num at various stages of fact. extr.
        vector<int>v;														// Stores target num's factorial nums.
        int prev;															// Stores value of target num, at the beginning of iter.
        while(prod>1){														// Until prod is >1(can still be dissolved).
            prev=prod;														// Temp. storing value of num. at beginning of iter.
            for(int i=9;i>=2;i--){											// Extracting factorials starting from bigger ones.
                if(prod%i==0){												// If we find a factorial, break from loop.
                    prod/=i;												// Dec. the value of num.
                    v.push_back(i);											// Push factorial into vector.
                    break;
                }
            }
            if(prev==prod)													// If there is no factorial in 2-9, then return 0.
                return 0;													// Return 0, as per question.
            
        }
        
        for(int i=v.size()-1;i>=0 ;i--){									// We iter. from back to get smaller values first.
            int num=v[i];													// Temp. storing factorial value.
			if((INT_MAX-num)/10<res) return 0;								// If the resulting val. is >INT_MAX, then return 0.
			res*=10;														// Else, update the res var.
			res+=num;
        }
        
        return res;															// Return the calculated result num.
    }
};