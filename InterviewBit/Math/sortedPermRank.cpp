/*
*
//**************************************************************Sorted Permutation Rank.*******************************************************

https://www.interviewbit.com/problems/sorted-permutation-rank/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcd"



"debac"



"ZCSFLVHXRYJQKWABGT"




"view"


"abzdZAY"





// Time Complexity: O(n^2).  
// Space Complexity: O(k).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(k).	
// This algorithm is Permutation based. Here, we iterate over possible chars and choose the req. char at each step. In the process, we skip
// some chars which would be taken by later indices in reaching char. that suits curr. index. Since, we skipped some chars they account to few
// permutations, which we calculate already and those permutations to final count of perm. with each skip. This way, we form all indices's 
// chars of target string. At the end of iteration, we return total #perm. needed to form target string.








long long int factorial(long int num){										// Calc. factorial of a number.
    long int res=1;
    int mod=1000003;
    if(num<=1) return 1;
    for(int i=2;i<=num;i++) res=(res*i)%mod;
    return res;
}

int Solution::findRank(string s) {
    int mod=1000003;														// Mod value.
    vector<int>v(58,0);														// Stores chars in this string.
    for(auto ch: s) v[ch-65]=1;												// Mark as present/need to put in string to be formed.
    int res=0;																// Tracks perm. of the string.
    int index=0;															// Tracks the index we are currently trying to set.
    while(index<s.length()){												// Until all chars are set.
        long long int denom=factorial(s.length()-index-1);					// #Perm. for each skip of char at curr. index.
        // cout<<"temp: "<<temp<<" and denom: "<<denom<<endl;
        for(int i=0;i<58;i++){												// Iter. over all chars.
            char ch=i+65;													// Form curr. char.
            // cout<<"Char: "<<ch<<endl;
            if(v[i]==0) continue;											// Char already used.
            if(s[index]!=ch){												// Is this char needs to be skipped.
                res=(res+denom)%mod;										// Add the perm. to final count.
            }else{															// If char mathces to curr. index of target string.
                v[i]=0;														// Marking char as placed.
                index++;													// INc. the index iterator.
                // cout<<"Added ch: "<<ch<<endl;
                break;														// Restart setting next index.
            }
        }
    }
    return res+1;															// Returning total #perm. needed to form target string.
}
