/*
*
//**************************************************************Kth Permutation Sequence.*******************************************************

https://www.interviewbit.com/problems/kth-permutation-sequence/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



17
223423


4
5


3
1


3
4


3
6




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Backtracking based. Here, we keep finding suitable digit in each psn and forward the remaining permutations needed from 
// following digits. At each step, we find the #perm. possible from remaining digits per each digit in curr. psn by using factorial. We subtract 
// #perm. curr. digit covers from req. perm. value and forward req. perm. to the recursive call and by the end, we will cover all req perm. by 
// k digits and return the string formed in the process.




long double calcFactorial(int num){											// Calculates factorial of num.
    long double res=1;
    for(int i=1;i<=num;i++){
        res=res*i;
    }
    return res;
}

void findStr(int psn, unordered_set<int>&occur, int num, int perm, string &res, long int combi){	// Forms the perm. sequence.
    if(psn==num) return ;
    long double folPerm=calcFactorial(num-psn-1);							// Calc. num. of combinations in rem. psns.
    // cout<<"psn: "<<psn<<"combi: "<<combi<<" and folPerm: "<<(long double)folPerm<<endl;
    long double el=0;														// Calc. #combi. consumed by this psn's digit.
    long double last=0;														// Becomes valid for last digit.
    for(int i=1;i<=num;i++){												// Iter. over all possible digits.
        if(occur.count(i)==1) continue;										// If curr. digit had been already used,skip it.
        if(psn==num-1) last=1;												// Is valid only in case of last psn.
        el+=folPerm;														// Adding #comb. consumed in this psn.
        if(el+combi+last>=perm){											// If curr. digit is part of final result(Is part of Kth perm).
            res+=to_string(i);												// Adding to final result str and map.
            occur.insert(i);
            // cout<<"Appending i: "<<i<<endl;
            findStr(psn+1, occur,num,perm, res, combi+el-folPerm);			// Giving recursive call to get remaining psns digits and break.
            break;
        }
    }
    return ;																// Returning from the recursive call.
}

string Solution::getPermutation(int num, int perm) {
    string res="";															// Accumulates the final result str.
    // cout<<"num: "<<num<<endl;
    unordered_set<int>occur;												// Keeps tracks of used digits in the sequence.
    findStr(0,occur, num, perm, res, 0);									// Call to get Kth perm. sequence.
    return res;																// Returning the final result str(Kth Perm.).
}
