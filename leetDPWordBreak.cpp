/*
*
//**********************************************************139. Word Break.******************************************************

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a 
space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get 
the latest changes.

//These are the examples on which I had created and worked on.
"leetcodeleet"
["leet","code"]
"abcdefghi"
["bcd", "def", "ghi","abc"]


//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//This problem is similar to (0/1)-Kanpsack, 2 Partition Subset Sum Problem(Near Similar to Problem No. 416). 


class Solution {
public:
    bool wordBreak(string s, vector<string>& v) {
        unordered_map<string, int> m;
        for(auto str:v)
            m[str]=1;
        int len=s.length();
        int dp[len+1]={0};						//Says whether the string till that index can be completely formed by elem. of vector's strings.
        for(int i=0;i<len;i++){					//Checking whether the string till "i" index can be formed by elem. of vector or not.
            for(int j=-1;j<i;j++){				//If the string till "i" index can be combination of two strings till then with a cut at "j" index.
                //cout<<"The substring 1: "<<s.substr(0, j+1)<<endl;
                //cout<<"The substring 2: "<<s.substr(j+1, i-j)<<endl<<endl;
                if( (j>=0 && dp[j]==1 && m[s.substr(j+1, i-j)]==1) || (j==-1 && m[s.substr(j+1, i-j)]==1 )){
                    dp[i]=1;					//If the string till "i" index can be formed by one/two/more strings.
                    break;
                }
            }
        }
        
        //for(auto num:dp)
        //    cout<<"The values are: "<<num<<endl;
        
        //cout<<"The result is: "<<dp[len-1]<<endl;
        return dp[len-1];						//Returning whether string till index "len-1" can be formed by strings in vector or not.
    }
};



//************************************************************Solution 2:************************************************************
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//This problem is similar to (0/1)-Kanpsack, 2 Partition Subset Sum Problem(Near Similar to Problem No. 416). 
//This algorithm is same as the previous one, except that there were small changes in the if condition, keeping optmization in mind.


class Solution {
public:
    bool wordBreak(string s, vector<string>& v) {
        unordered_map<string, int> m;
        for(auto str:v)
            m[str]=1;
        int len=s.length();
        int dp[len+1]={0};
        //dp[0]=1;
        //cout<<"The length of string is: "<<len<<endl;
        for(int i=0;i<len;i++){
            for(int j=-1;j<i;j++){
                //cout<<"The substring 1: "<<s.substr(0, j+1)<<endl;
                //cout<<"The substring 2: "<<s.substr(j+1, i-j)<<endl<<endl;
                if(m[s.substr(j+1, i-j)]==1){
                    if( (j>=0 && dp[j]==1 )|| (j==-1) ){
                        dp[i]=1;
                        break;
                    }
                }
                   
            }
        }
        
        //for(auto num:dp)
        //    cout<<"The values are: "<<num<<endl;
        
        //cout<<"The result is: "<<dp[len-1]<<endl;
        return dp[len-1];
    }
};