/*
*
//******************************************************2614. Prime In Diagonal.******************************************************

https://leetcode.com/problems/prime-in-diagonal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[5,6,7],[9,10,11]]
[[1,2,3],[5,17,7],[9,11,10]]
[[1,2,3],[5,17,7],[9,11,883]]



// Time Complexity: O(n*sqrt(m)).																		// n-size of the array, m-max. allowed number.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(m)).																		// n-size of the array, m-max. allowed number.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iter. over the diagonal indices and check if they are prime and return the max prime value.






class Solution {
public:
    
    bool isPrime(int num) {																				// Checking if a num is prime.
        if(num<=1) return false;
        if(num==2) return true;
        if(num%2==0) return false;
        for(int i=3;i*i<=num;i+=2) {
            if(num%i==0) return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& arr) {
        int res=0;
        for(int i=0;i<arr.size();i++) {																	// Iter. over diagonal indices.
            if(arr[i][i]>res && isPrime(arr[i][i])) res=arr[i][i];										// Check if num is prime and updating the max diagonal prime number var.
            if(arr[i][arr.size()-1-i]>res && isPrime(arr[i][arr.size()-1-i])) res=arr[i][arr.size()-1-i];
        }
        return res;																						// Returing the max diagonal prime number.
    }
};

