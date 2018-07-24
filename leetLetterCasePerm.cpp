/*
*
//**********************************************************784. Letter Case Permutation.***************************************************

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all 
possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"a1b2"

"a"

""






// Time Complexity: O(2^n).  
// Space Complexity: O((2^n)n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O((2^n)*n).	
// This algorithm is Bit Manipulation based. First I find the numbers of chars to work on (#Alphabets). Then, I iterate from 0 to
// 2^#Alpha-1. At each iteration(i), I find the #bits set to 1 in "i", and change those corresponding bits in string and push the modified str
// into result vector.







class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int>v;														// Stores the indices of alphabets in string.
        for(int i=0;i<s.length();i++)
            if(s[i]>57) v.push_back(i);    									// Storing the indices of alphabets.
        
        int last=v.size()-1;												// Storing the alpha index vector size.
        vector<string>res;													// Storing the result vector.
        int limit=(1<<v.size());											// Storing the maxm. iteration number.
        for(int i=0;i<limit;i++){											// Iterating through all combinations.
            // cout<<"value: "<<i<<" and str: "<<s<<endl;
            int temp=0,num;
            num=1<<temp;													// Bit extractor in curr. iteration number.
            string t=s;														// Storing the str's orig. state.
            while(num<limit){
                // cout<<"inner num: "<<num<<endl;
                // cout<<"matched: "<<(i&num)<<"with temmp: "<<temp<<" and char: "<<s[v[last-temp]]<<endl;
                if((i&(num))>0 && s[v[last-temp]]>=97 && s[v[last-temp]]<=122) s[v[last-temp]]-=32;// If it's a block alpha, changing to small one.
                else if((i&(num))>0 && s[v[last-temp]]>=65 && s[v[last-temp]]<=90) s[v[last-temp]]+=32;// If small one, change to capital one.
                temp++;
                num=1<<temp;
            }
            res.push_back(s);												// Pushing the modified str into result vector.
            s=t;															// Brining str to orig. state.
        }
        return res;															// Returning the result vector of strs.
    }
};














//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O((2^n)*n).	
// This algorithm is DFS/Backtracking based. We start iterating from the first index. We iterate through until we reach alpha., on reaching we 
// give a recur. call to extract further alphas after that index. We also iterate further in curr. recur. call to extract all further alphas 
// till end. Thus, we get all combi's of changed alphas. At each call, we also push the curr. str into result vector, to get the unmodified str
// wrto curr. alpha psn.





class Solution {
public:
    void findCombi(string &s,int index, vector<string>&res){
        res.push_back(s);													// Push curr. str into result vector.
        for(int i=index;i<s.length();i++){									// ITerate through all indices.
            if(s[i]>57){													// On encount. alpha.
                if(s[i]>=97 && s[i]<=122){									// If it's a small alpha.
                    s[i]-=32;												// Change it to capital, and give recur. call.
                    findCombi(s,i+1,res);
                    s[i]+=32;												// Restore orig. str.
                }
                else if(s[i]>=65 && s[i]<=90){								// If it's a capital, change into small alphas and restore.
                    s[i]+=32;
                    findCombi(s,i+1,res);
                    s[i]-=32;
                }
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;													// STores the result str vector.
        findCombi(s,0,res);													// GIve fn. call to extract all combi. str.
        return res;															// Returning the vector of strs.
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O((2^n)*n).	
// This algorithm is DFS/Backtracking based. Here, we iterate through all the indices, on encount. alphas, we give a call without changing it, 
// another call after changing alpha. On, encount. alpha, we would break the loop. Thus, we get all combi. of strs. For the case of alpha
// occurance at last index, we check for index equals str length, if it is, push str into result vector of strs. If we reach end of iteration,
// then it's that there are no more alphas to be change, so, we can push curr. str into final result vector.






class Solution {
public:
    void findCombi(string &s,int index, vector<string>&res){
        if(index>=s.length()) res.push_back(s);								// If index= str length, push into result vector.
        for(int i=index;i<s.length();i++){									// Iterating through all indices.
            if(s[i]>57){													// If alpha found.
                findCombi(s,i+1,res);										// A recur. call without changing alpha.
                if(s[i]>=97 && s[i]<=122){									// Change alpha and give another recur. call.
                    s[i]-=32;
                    findCombi(s,i+1,res);
                    s[i]+=32;
                }
                else if(s[i]>=65 && s[i]<=90){
                    s[i]+=32;
                    findCombi(s,i+1,res);
                    s[i]-=32;
                }
                break;														// Break from loop, on encount. alpha.
            }
            if(i==((int)s.length()-1)) res.push_back(s);					// If no alpha found until end, then push str into result vector.
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;													// Stores all combi. of strs.
        findCombi(s,0,res);													// Call fn. to extract all combi. of strs.
        return res;															// Returning the final result vector of strs.
    }
};