/*
*
//******************************************2165. Smallest Value of the Rearranged Number.******************************************

https://leetcode.com/problems/smallest-value-of-the-rearranged-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


310
-7605
-329385894858
-2146483647
2500
2502302
48393039483
-2500
-284829568480048



// Time Complexity: O(logn).  												// n-given number.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// n-given number.
// Space Complexity: O(1).	
// This algorithm is Map+bservation based. Here, we store the #occur. of each digit and we use them in dec. order for neg. nums and inc. order for pos. nums.
// For pos. num we first use an non-zero least digit to avoid leading zeroes and start filling rest digits in inc. order and return the number.







class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>=-9 && num<=9) return num;									// Corner conditions.
        long long int res=0;
        vector<int>occur(10, 0);
        bool neg=(num<0);
        if(num<0) num=-num;
        int leastDigit=9;
        while(num) {
            int digit=num%10;
            occur[digit]++;
            if(digit!=0 && digit<leastDigit) leastDigit=digit;
            num/=10;
        }
        
        if(neg) {
            for(int i=9;i>=0;i--) {											// Forming neg. num by using digits in dec. order.
                while(occur[i]-->0) res=res*10+i;
            }
			res=-res;														// Applying '-' sign as it's a neg. num.
        }else {
            res=leastDigit;													// First using a non-zero leastDigit to avoid leading zeroes.
            occur[leastDigit]--;
            for(int i=0;i<=9;i++) {											// Forming pos. num by using digits in inc. order.
                while(occur[i]-->0) res=res*10+i;
            }
        }
        return res;															// Returing Smallest rearranged number.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogm).												// m=logn, n-given number.
// Space Complexity: O(m).	
// This algorithm is Strings+Observation based. We convert given num to string, for neg. nums, we sort string in desc. order and multiply with -1 before 
// returning. For pos. nums, we sort in inc. order of chars, we swap first non-zero from the start with zero index to avoid leading zeroes and we return the
// string after converting it to number.












class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>=-9 && num<=9) return num;
        bool neg=(num<0);
        if(num<0) num=-num;
        string s=to_string(num);
        if(neg) {
            sort(s.rbegin(), s.rend());										// Sorting in dec. order for neg. nums.
            num=stoll(s);
            return -num;													// Returing smallest rearranged number.
        }else {
            sort(s.begin(), s.end());										// Sorting in inc. order for pos. nums.
            int ind=0;
            while(ind<s.length() && s[ind]=='0') ind++;						// Finding index of first non-zero char.
            swap(s[ind], s[0]);												// Swapping zero, first non-zero char's index's values.
            num=stoll(s);
            return num;														// Returing Smallest rearranged number.
        }
        return -1;
    }
};

