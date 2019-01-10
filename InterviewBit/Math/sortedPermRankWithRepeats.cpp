/*
*
//******************************************************Sorted Permutation Rank with Repeats.***********************************************

https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"abaacd"



"aba"



"caabbaaddeebcdae"




IDoAgpWmipGWOUuCIksS







// Time Complexity: O((k^2)*n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O((k^2)*n).												// Facorials are precomputed linearly and stored(Code submitted in IB).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we count the #perm. needed to get each char in target string. So,as to get each char, we need to 
// skip few lexically small chars, which with else chars forms few perm., which we count towards the final perm.. While counting a skipped 
// char's perm. with else chars, there might be duplicate chars which lead to duplicate strings, we calculate the duplicate perm. and divide 
// total perms. by dupli. perms to get unique perms. which are counted towards final perm. For each skipped char, we count dup. perms by iter.
// over all chars and calc. dupli. perms contributed by each type of char. Thus, at the end of iteration, we get the rank of the target string.







long long int factorial(int num){											// Calc. factorial of a number.
    int res=1;
    int mod=1000003;
    if(num<=1) return res;
    for(int i=2;i<=num;i++) res=(res*i)%mod;
    return res;
}


long long int inverseNumber(int num) {										// Calc. inverse of a number in modulo form.
    // Inverse modulo : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
    // Calculate num ^ MOD-2  % MOD
    long long int ans = 1, base = (long long) num;
    int MOD=1000003;
    int power = MOD - 2;													// If MOD is prime, we just have to raise it to power of MOD-2.
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % MOD;
        }
        if (power % 2 == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            ans = (ans * base) % MOD;
            power--;
        }
    }
    return ans;																// Returning the inverse number value.
}
        
        
        
        
long long int factorialVector(vector<int>&v){								// Calc. #perm. because of dupli. chars.
    int mod=1000003;
    long long res=1;
    for(int i=0;i<58;i++){													// Iter. over all chars.
        if(v[i]!=0){														// If chars exist.
            long long int temp=factorial(v[i]);
            res=(res*temp)%mod;
        } 
    }
    return res;
}

int Solution::findRank(string s) {	
    if(s.length()==0) return 0;												// Base case.
    long long res=0;														// Tracks rank of target string.
    int mod=1000003;														// Mod value.
    int index=0;															// The target string's index which we are currently matching.
    vector<int>v(58,0);														// Stores #occur. of each char.
    for(auto ch:s) v[ch-'A']++;												// Updating #occur. of each char.
    vector<long long>factorials(s.length(),1);								// Stores #perm. with (s.length()-1-i) chars at 'i' index.
    int nums=1;
    for(int i=factorials.size()-2;i>=0;i--){								// Calc. #perms.
        factorials[i]=(factorials[i+1]*nums)%mod;
        nums++;
    }
    
    while(index<s.length()){
        // cout<<"index: "<<index<<endl;
        for(int i=0;i<58;i++){
            if(v[i]==0) continue;
            long long numer=factorials[index];								// #Perm. formed by rem. chars.
            v[i]--;															// Dec. count of curr. char while calc. #perm. without it.
            long long denom=factorialVector(v);
            v[i]++;															// Revert to orig. state.
            // cout<<"numer: "<<numer<<" and denom: "<<denom<<endl;
            long long inver=inverseNumber(denom);							// #Perm. formed by dupli. chars.
            long long int temp=(numer*inver)%mod;							// #Unique Perm. formed by rem. chars. 
																			// We use inverse modulo theorem here while dividing with modulo.
            char ch=i+65;
            if(ch!=s[index]) res=(res+temp)%mod;							// If curr. char isn't required char, add perm. to final count.
            else{															// If curr. char is required char from targe string.
                v[i]--;														// Dec. count of curr. chosen char.
                index++;													// Inc. the index iterator.
                break;														// Break to look for next index in target string.
            }
        }
    }
    return res+1;															// Returning rank of target string.
}
