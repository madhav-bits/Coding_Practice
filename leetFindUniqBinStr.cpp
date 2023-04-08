/*
*
//******************************************************1980. Find Unique Binary String.******************************************************

https://leetcode.com/problems/find-unique-binary-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["01","10"]
["00","01"]
["111","011","001"]
["1110","0110","0010","0001"]



// Time Complexity: O(n).  																				// n-length of the string.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-length of the string.
// Space Complexity: O(1).	
// This algorithm is observation based. We have to make use of the fact that length of the array<=length of the expected result string. We create a empty result str, we iter. over given array, for each of the string, we set 
// ith bit of result string converse to the ith bit of ith string in iter. as a result the result str has atleast 1 bit that doesn't match for each of the strings in the array.


// This approach has clear explanation in the below discussion posts.
// https://leetcode.com/problems/find-unique-binary-string/discuss/1418743/Sweep-OMG-and-Randomization
// https://leetcode.com/problems/find-unique-binary-string/discuss/1418687/Detailed-Explanation-O(N)-Java-C%2B%2B-Python-short-concise-code-Cantor's-Diagonalization





class Solution {
public:
    string findDifferentBinaryString(vector<string>& arr) {
        string res="";
        for(int i=0;i<arr.size();i++) {
            res+=(arr[i][i]=='1')?'0':'1';
        }
        return res;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-length of the string.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, since the length of the string is low, we store all the number(base 10) rep of these binary values in set, we iter. from 0 and we are bound to get our anser in 'n+1' steps at max.









class Solution {
public:
    string findDifferentBinaryString(vector<string>& arr) {
        
        unordered_set<int>st;
        for(string&num:arr) {
            st.insert(stoll(num, nullptr, 2));															// This converts base 2 strings to base 10 numbers and store in set.
        }
        
        for(int i=0;;i++) {																				// We start iter. from 0 and find the first number not present in set and return it's binary rep.
            if(st.count(i)==0) return bitset<32>(i).to_string().substr(32-arr[0].length());
        }
        return "";
    }
};

