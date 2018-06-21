/*
*
//************************************************340. Longest Substring with At Most K Distinct Characters.*****************************************

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abaccddeghilaj"
4


""
2

"a"
0

""
0


"nfhiexxjrtvpfhkrxcutexxcodfioburrtjefrgwrnqtyzelvtpvwdvvpsbudwtiryqzzy"
25




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm  is Sliding Window based. We iterate the array, at each step we check whether curr. char is in the already encountered 
// distinct chars list. If it is we just take it in the substring, if the #distinct chars in curr. substr<k, then also we just take curr. char
// into curr. substring. If not we remove things from the back, until we get rid of one type of char from the substring. Then we add current 
// char to the substring, update the last index of substring.








class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length()==0 || k==0) return 0;
        map<char,int>m;													// Keeps track of #distinct chars in curr. substring.
        int maxm=0;														// Maxm. len of substr.
        int st=0,lt=0;													// Start and end of Sliding Window.
        for(int i=0;i<s.length();i++){									// Iterates through the array.
            if(m.count(s[i])==1 || m.size()<k){							// If curr. char is already in map/#dist. chars is<k.
                m[s[i]]++;lt=i;											// We add the curr. char to substring.
            }
            else{
                maxm=max(maxm,lt-st+1);									// Get the length of substring, try to update the max len.
                // cout<<"Out. at st: "<<st<<" and lt: "<<lt<<endl;
                while(m.size()==k){										// We remove chars from back, until one dist. char is removed from substr.
                    m[s[st]]--;											// Removing last char. from substring.
                    if(m[s[st]]==0) m.erase(s[st]);						// Once one type of char is removed from substr, dec. the keys in map.
                    st++;												// Moving the start of sliding window ahead.
                }
                m[s[i]]++;												// Include the curr. char in Sliding Window.
            }
            
        }
        maxm=max(maxm,lt-st+1);											// Considers last substr ending at s.length()-1.
        return maxm;													// Returning the max. len Sliding Window.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm  is Sliding Window based. We iterate the array, at each step we check whether curr. char is in the already encountered 
// distinct chars list. If it is we just take it in the substring, if the #distinct chars in curr. substr<k, then also we just take curr. char
// into curr. substring. If not we remove things from the back, until we get rid of one type of char from the substring. Then we add current 
// char to the substring, update the last index of substring.

// This algo. is almost same as the previous algo., except that it uses the vector of size(128) to accomodate all ascii chars. We maintain
// one more var-num, which tracks #dist. chars in curr. substring.



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length()==0 || k==0) return 0;
        vector<int>v(128,0);												// Keeps tracks of count of chars in Sliding Window.
        int maxm=0, num=0;													// Tracks max. len of Sli. Window till now, #dist. elem. in Sli. Window.
        int st=0,lt=0;														// Start and last index of Sliding Window.
        for(int i=0;i<s.length();i++){
            if(v[s[i]-NULL]>0 || num<k){
                if(v[s[i]-NULL]==0) num++;									// Adding curr. char to Sliding Window.
                v[s[i]-NULL]++;												// Inc. the curr. chars count.
                lt=i;														// Updating the last index of Sliding Window.
            }
            else{
                maxm=max(maxm,lt-st+1);										// Get the length of substring, try to update the max len.
                // cout<<"Out. at st: "<<st<<" and lt: "<<lt<<endl;
                while(num==k){
                    v[s[st]-NULL]--;										// Removing last char. from substring.
                    if(v[s[st]-NULL]==0) num--;								// If remov. char count=0, then dec. the #dist. chars in Sli. Window.
                    st++;													// Inc. the start index of Sli. Window.
                }
                lt=i;														// Updating the curr. last index of substring.
                v[s[i]-NULL]++;												// Adding the curr. char to Sliding Window.
                num++;														// Inc. the count of #dist. chars in Sliding Window.
            }
            
        }
        maxm=max(maxm,lt-st+1);												// Considers last substr ending at s.length()-1.
        return maxm;														// Returns the max. len of Sliding Window.
    }
};



