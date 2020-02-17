/*
*
//**************************************1297. Maximum Number of Occurrences of a Substring.*************************************

Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0
 

Constraints:

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s only contains lowercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"aababcaab"
2
3
4

"aaaa"
1
3
3


"abcde"
2
3
3


"aabcabcab"
2
2
3



"aabcabcabacdefghijklmnopqrstuvwxyzadsfadfaf"
26
26
26



// Time Complexity: O(n).  													// n- length of the string.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).	
// This algorithm is Greedy and Sliding Window based solution. Here, since we are looking for substirngs of length between minLen and 
// maxLen, we can just keep track of subsrings of length minLen, as #times a substring of length>minLen occurs, the minLen substring
// would have occured as part of it. So, it just tracking minLen would work. For each of these substring, we use a array to keep track
// of #occurances of each char. and uniq. chars. When these conditions are satisfied, we maintaing their count and we update the 
// max. #occurances of such substrings.







class Solution {
public:
    int maxFreq(string s, int maxLetters, int minLen, int maxLen) {
        unordered_map<string,int>m;											// Track #occuraces of MinLen substrings.
        int uniqChars=0, res=0;												// Tracks max. #occurances and uniqChars in the window.
        vector<int>occur(26,0);												// Tracks #occurances of each char. in window.
        for(int i=0;i<s.length();i++){
            occur[s[i]-'a']++;												// Updating #Occur. of each char.
            if(occur[s[i]-'a']==1) uniqChars++;
            
            if(i-minLen>=0){												// Removing the char. at the start of the window.
                occur[s[i-minLen]-'a']--;
                if(occur[s[i-minLen]-'a']==0) uniqChars--;					// If this removal makes zero occur., dec. uniqChars by 1.
            }
            int start=i-minLen+1;
            if(start>=0 && uniqChars<=maxLetters){							// If window's uniqChars<maxLetters.
                res=max(res, ++m[s.substr(start, minLen)]);					// Track max. #occurances of such substrings.
                // cout<<"i: "<<i<<" and temp: "<<temp<<" and uniqChars: "<<uniqChars<<endl;
            }
        }
        return res;															// Returns max. #occurances of such substrings.
        
        
    }
};
















//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).
// This algorithm is Greedy and Rolling Hash based algorithm. This algo. is same as the above one, except that this uses rolling hash
// to keep track substrings and used map to keep track of occurrences.


// In the rolling hash, since we have 26 possible chars, I calculated rolling hash based on base 26 number system. 

// Here, the minLen value would be at max. 26, which makes it on the verge of out of bounds for unsigned long long int., it have't 
// thrown any out of bound errors, despite that we can void such out of bounds by using mod of a very large power of prime. Here, 
// we use 29^20. If we use these modulus, we might face some clash of hash values, in such cases, we have to check linearly whether
// this string is what is we are looking for? Here, considering the input constraints, we have very marginal chances of facing 
// clashes.


// This link has very detailed explanation and discussion of the rolling hash solution.
// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/discuss/457577/C%2B%2B-Greedy-approach-%2B-Sliding-window-O(n)./452863




class Solution {
public:
    int maxFreq(string s, int maxLetters, int minLen, int maxLen) {
        int uniqChars=0, res=0;
        vector<int>occur(26,0);
        unordered_map<unsigned long long int, int>n;
        unsigned long long int hash=0, maxStep=pow(26, minLen-1);
        
        for(int i=0;i<s.length();i++){
            occur[s[i]-'a']++;
            if(occur[s[i]-'a']==1) uniqChars++;
            if(i-minLen>=0){
                occur[s[i-minLen]-'a']--;
                if(occur[s[i-minLen]-'a']==0) uniqChars--;
                hash-=(s[i-minLen]-'a')*maxStep;
            }
            hash=hash*26+(s[i]-'a');
            int start=i-minLen+1;
            if(start>=0 && uniqChars<=maxLetters){
                res=max(res, ++n[hash]);
                // cout<<"i: "<<i<<" and temp: "<<temp<<" and uniqChars: "<<uniqChars<<endl;
            }
        }
        return res;
        
        
    }
};












//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).
// This solution is posted by a user in the dicussion forum. It discusses rolling hash method of tracking substring and it's 
// occurrences.
// Link to the solution. 
// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/discuss/457577/C%2B%2B-Greedy-approach-%2B-Sliding-window-O(n)./452863








static const unsigned long long MOD=(unsigned long long) pow(2,63)-1;               //Large mod least collisions.
class Solution {
public:
    unsigned long long int powMod(unsigned long long x,int y) {           //Modular power
        unsigned long long res=1;
        while (y>0) 
        { 
            if(y&1) 
                res=(res*x)%MOD; 
            y=y>>1;
            x=(x*x)%MOD;   
        } 
        return res; 
    } 
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        unsigned long long hash=0,Pow=powMod(51,minSize-1);
        int start=0,result=0;
        unordered_map<int,int> count;           	//Stores count of letters in the window.
        unordered_map<long long,int> occurence;        //Stores count of occurence of that string.
        for(int i=0;i<s.length();i++)			//Sliding window
        {
            count[s[i]]++;						//Increase the count of letter at i.
            if(i-start+1>minSize)                  //Reduce the size of the window if increased to size.
            {
                hash-=(s[start]-'a')*Pow;
                if(--count[s[start]]==0)			//Remove the letter from map if count 0 to track unique letters.
                    count.erase(s[start]);
                start++;
            }
            hash=(hash*51+s[i]-'a')%MOD;
            if(i-start+1==minSize&&count.size()<=maxLetters)	//When the substring in the window matches the constraints.
                result=max(result,++occurence[hash]);     //Increase the occurence count of the string and get max.
        }
        return result;
    }
};