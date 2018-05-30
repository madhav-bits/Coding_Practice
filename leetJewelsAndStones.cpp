/*
*
//**********************************************************771. Jewels and Stones.***************************************************

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a 
type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a 
different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"azAZ"
"aAAbbbbzZabx"

""
"a"

""
""



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. But, instead I use a array as I know the range of keys. As, we use alphabets 64,122 are the start and end
// ascii values of alphabets. In the first iteration, we store the occurance of jewels in vector. In the second iteraiton, we check whether
// the stones are jewels or not by chekcing the corresponding indices in vector. Thus, at the end of iteration, we get the total number 
// of jewels.








class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;															// Number of jewels in the stones..
        vector<int> v(58,0);
        for(int i=0;i<J.length();i++)										// Storing the jewels in the vector.
            v[J[i]-'A']=1;
        for(int i=0;i<S.length();i++){
            //cout<<"CUrr. index: "<<S[i]<<v[S[i]-'A']<<endl;
            if(v[S[i]-'A']==1){												// Checking whether the stone is jewel or not.
                //cout<<"CHars. matched."<<endl;
                res++;														// As, the stone is jewel, we inc. the count of jewels.
            }
        }
        
        return res;															// Returning the total number of jewels.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This is HashMap implementation and the entire logic is same as the above algorithm.




class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;															// Number of jewels in the stones.
        
        map<char, int> m;													// Stores the jewels.
        for(auto ch: J) m[ch]=1;	
        for(auto ch: S){										
            if(m.count(ch)==1) res++;										// If the curr. stone is jewel, we inc. the count of jewels.
        }
        
        return res;															// Returning the total number of jewels.
    }
};