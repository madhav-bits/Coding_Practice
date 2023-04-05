/*
*
//******************************************************1952. Three Divisors.******************************************************

https://leetcode.com/problems/three-divisors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
49
50
4
9
25
36
9409
2342
9999
1



// Time Complexity: O(n).																				// n-number provided.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-number provided.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since the range of nums is small, we iter. from 1 to n, divide to see each iter. is a divisor and inc. the res count, if it's >3, we return false. If we reach end of iter. we return if
// res is equal to 3.






class Solution {
public:
    
    bool isThree(int target) {
        int cnt=0;
        for(int i=1;i<=target;i++) {																	// Iter. from 1 to n.
            if(target%i==0) cnt++;																		// We inc. the res by 1, if curr. iter. is divisor of n.
            if(cnt>3) return false;																		// If res>3, we return false.
        }
        return (cnt==3);																				// We return if #divisors is equal to 3.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn+pow(n,1/4)).																				// n-number provided.
// Space Complexity: O(1).
// This algorithm is Binary Search based. For a num to have three divisors it has to be a square of a prime number. So, we do a binary search to find the square root of the number, later we check whether it's a prime.
// Calc. square takes O(logn) for binary search, to check if square root of n->'sqrt(n)' is prime, it takes sqrt(sqrt(n)) time.

// For this question, particularly for the range of nums provided as inputs, this approach is a overkill, but this works fine it we are working on a list of query nums or if we are working on greater range, which would have made
// iter. from 1 to n, a time taking process.







class Solution {
public:
    
    bool isPrime(int num) {																				// To check if the square root value is a prime.
        // cout<<"num: "<<num<<endl;
        if(num==2) return true;
        if(num==1 || num%2==0) return false;
        
        for(int i=3;i*i<=num;i+=2) {
            if(num%i==0) return false;
        }
        return true;
    }
    
    bool isThree(int target) {
        // The number has to be square of a prime number.
        int low=1, high=100;																			// Setting lower, upper limits for the square root value based on nums range.
        while(low<high) {																				// Binary Search to calc. the square root of the num.
            int mid=(low+high)/2;
            if(mid*mid<target) low=mid+1;
            else high=mid;
        }
        if(low*low!=target) return false;																// If there is no square root for this num, we return false.
        return isPrime(low);																			// Returning if the square root of the num is a prime.
    }
};

