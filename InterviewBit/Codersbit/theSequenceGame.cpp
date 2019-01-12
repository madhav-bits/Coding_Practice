/*
*
//**************************************************************The Sequence game.*******************************************************

https://www.interviewbit.com/problems/the-sequence-game/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


45
68



10
100



99
20




// Time Complexity: O(logn).  												// n is the power mentioned in question.
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// n is the power mentioned in question.
// Space Complexity: O(1).	
// This algorithm is Binary based. Here, the value of a index depends on two values out of which the greater value would be the smaller value in 
// it's next index with opposite sign and they would cancel out each other. So, at the end we have greater value in last index and smaller value
// in first index(value is 0). So, we return the greater value in last index directly, which is pow(A,B).









long long int calcPower(int base1, int power){								// Calc. pow(base, expo).
    int mod=1000000007;														// Mod value.
    long long int base=base1, ans=1;										// Init. base and final ans value.
    while(power>0){															// Until base is raised to the power given.
        // cout<<"power: "<<power<<endl;
        if(power==1) return (ans*base)%mod;									// Last iter., mult. base value and return the ans directly.
        else if(power%2==0){												// If even power, squaring base value with halfed power value.
            base=(base*base)%mod;
            power/=2;
        }else{
            ans=(ans*base)%mod;												// If odd power, mult. base value to ans and reduce power by 1.
            power--;
        }
    }
}

int Solution::solve(int A, int B) {
    return calcPower(A,B);													// Returning the sum of first A terms.
}
