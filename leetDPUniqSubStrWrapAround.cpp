/*
*
//***************************************************467. Unique Substrings in Wraparound String.***********************************************

Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look 
ike this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In 
particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.

//This is the example on which I had worked on.
"zsdgsdfzabcd"

// Time Complexity: O(n).
// Space Complexity: O(1	).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// Silghtly tricky one.

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int len=s.length();
        if(len==0)
            return 0;
        long long int count=0;
        vector<int>v(26,0);
        int prev=s[0]-'a';
        v[prev]=1;
        int max_len=1;
        for(int i=1;i<len;i++){
            int curr=s[i]-'a';
            if(curr==prev+1 ||(curr==0 && prev==25)){
                //cout<<"Inside if with index i: "<<i<<endl;
                max_len++;
            }
            else
                max_len=1;
            v[curr]=max(max_len,v[curr]);			//The longest conse. substring ending with "alphabet" has all combinations of shorter substr.
            prev=curr;								// ending with "alphabet".
        }
        for(int i=0;i<26;i++)						//Counting the no. of substrings ending with all possible alphabets.
            count+=v[i];
        //cout<<"The result is: "<<count<<endl;
        return count;								//Returning the count.
        
    }
};






//************************************************************Solution 2:************************************************************
//********************************************************THIS IS NOT A LEET ACCEPTED CODE.***************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// I had come up with algorithm.
// This algorithm works perfectly fine for all the cases, but since it's time complexity is slightly higher, So, time out error isssue arises.


class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int len=s.length();
        if(len==0)
            return 0;
        int count;
        vector<int>v(len,0), seq(len,0);		//This can be changed to vectors of length, change indexes acco. in for loop 2 and still works.
        unordered_set<string> uniq;
        v[0]=s[0]-'a';
        uniq.insert(to_string(s[0]));
        seq[0]=1;
        count=1;
        for(int i=1;i<len;i++){
            //int diff=s[i]-'a';
            uniq.insert(to_string(s[i]));
            v[i]=s[i]-'a';
            if(v[i]>=0 && v[i]<=25)
                count++;
            if(v[i]==v[i-1]+1 ||(v[i]==0 && v[i-1]==25)){
                //cout<<"Inside if with index i: "<<i<<endl;
                seq[i]=seq[i-1]+1;
                count+=seq[i]-1;
                for(int j=1;j<seq[i];j++)		//Storing the small substring formed in the conse. substring in the set to avoid duplicates.
                    uniq.insert(s.substr(i-j, j+1));
            }
            else if(v[i]>=0 && v[i]<=25)
                seq[i]=1;
            
        }
        //cout<<"The result is: "<<count<<endl;
        //cout<<"No. of elements is: "<<uniq.size()<<endl;
        return uniq.size();						//Returns the no. of uniq. substr formed from the given string.
        
    }
};