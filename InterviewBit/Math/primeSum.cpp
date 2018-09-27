/*
*
//****************************************************************Prime Sum.*********************************************************



https://www.interviewbit.com/problems/prime-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3


1242


23422


99999



// Time Complexity: O(n^1.5).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^1.5).
// Space Complexity: O(1).	
// This algorithm is iteration based. We check whether curr. num is prime or not? If the num is prime, we check for it's pair being prime or not?
// If both are prime, we return true, in the first instance, as we are looking for lexically smallest pair of nums.








bool isPrime(int num){														// Says whether given num is prime or not?
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int num) {
    for(int i=2;2*i<=num;i++){												// Iter. through all possible nums.
        bool res1=isPrime(i);												// Finding first num is prime or not?
		if(res1==false) continue;											// If not don't check second num is a prime or not.
        bool res2=isPrime(num-i);											// Calc. second num is prime or not?
        if(res1 && res2) return vector<int>({i,num-i});						// If both are prime, return the pair.
    }
}
