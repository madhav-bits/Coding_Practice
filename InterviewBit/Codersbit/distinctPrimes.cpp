/*
*
//****************************************************************Distinct Primes.*********************************************************

https://www.interviewbit.com/problems/distinct-primes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



4 1 2 3 4



7 2 4 3 24 26 35 36




6 7 0 1 2 3 6




// Time Complexity: O(n*sqrt(n)).  
// Space Complexity: O(m).													// Depends on the prime factors of nums in array.	

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(n)).
// Space Complexity: O(m).													// Depends on the prime factors of nums in array.	
// This algorithm is iteration based. Here, we for each num. in array we get all it's prime factors by iter. over odd nums. and extract prime 
// factors and push them into a set. This way, we extract prime factors of all nums in array. At the end of iter., we return the size of the set
// containing prime factors.




// This point had lead to TIME LIMIT EXCEEDING ERRORS.
// If any prime factor>sqrt(n) exists, there would be only one. Two prime factors>sqrt(n) doesn't exist because as they are factors there prod.
// would be >target value, which means they aren't factors of target value.




void extractFactors(int val, unordered_set<int>&s){							// Extracts prime factors of each num. and push them into set.
    if(val<=1) return ;														// Base case.
    int target=val;
    if(val%2==0) s.insert(2);												// If 2 is a factor, push it into set.
    while(val%2==0) val/=2;													// Removes all 2 factors.
    for(int divi=3;divi*divi<=sqrt(target);divi+=2){						// Iter. over odd nums. 
        if(val%divi==0){													// If divi(prime num. ) divides rem. value.
            s.insert(divi);													// Push prime value into set.
            while(val%divi==0) val/=divi;									// Remove prime factors(curr. prime factor) out of rem. value.
        }
    }
    if(val>1) s.insert(val);												// If any Prime factor >sqrt(target) exists.
}

int Solution::solve(vector<int> &v) {
    // cout<<"size: "<<v.size()<<endl;
    unordered_set<int>s;													// Saves prime factors of nums. in array.
    for(int i=0;i<v.size();i++){											// Iter. over array.
        // if(v[i]<=1) continue;
        extractFactors(v[i], s);											// Extract prime factors of each num. 
    }
    return (int)s.size();													// Return #prime factors of nums. in array.
}
