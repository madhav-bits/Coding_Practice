/*

//**************************************************423. Reconstruct Original Digits from English.****************************************

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" 
are not permitted.
Input length is less than 50,000.


Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"





//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

//****************************************************THIS QUESTION WAS ASKED IN GOOGLE CODE JAM.**************************************

class Solution {
public:
    string originalDigits(string s) {
        vector<string> num_words={"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums={0,2,4,6,8,1,3,5,7,9};
        vector<int> dist_char={'z','w','u','x','g','o','r','f','v','i'};// In the sense, after removing char. associated with index "i",
        vector<int>occurs(26,0);//- elem. at index j>i becomes distinct in the rem. sequence of numbers.
        string res;
        for(const auto& ch:s){occurs[ch-'a']++;}//Counts occurences of all chars in the input string.
                                  
        for(int i=0;i<10;i++){
            int count=occurs[dist_char[i]-'a'];//Retrieves the no. of occurences of unique char.
            for(int j=0;j<num_words[i].size();j++)
                occurs[num_words[i][j]-'a']-=count;//Dec. the count of all char. associated with teh uniq. char in the given string.
            while(count--)
                res+=to_string(nums[i]);//Appends the num_words asso. with an integer, it's no. of occurence times.
            
            
        }
        sort(res.begin(), res.end());//Sorting the final result, as sorted result is what is asked.
        return res;
    }
};