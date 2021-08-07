/*
*
//**********************************************************1048. Longest String Chain.***************************************************

https://leetcode.com/problems/longest-string-chain/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["a","b","ba","bca","bda","bdca"]
["abcd","dbqca"]
["xbc","pcxbcf","xb","cxbc","pcxbc"]
["a","ab","ac","bd","abc","abd","abdd"]
["a","ab"]
["ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"]




// Time Complexity: O(nlong+n*l*l).											// n-#strings, l-avg. length of strings.
// Space Complexity: O(n*l).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlong+n*l*l).											// n-#strings, l-avg. length of strings.
// Space Complexity: O(n*l).	
// This algorithm is Dynamic Programming based. We first sort the array based on string length. We iter. over strings and push them into map, we form 
// all possible predecessor strings for each string and check if they are in the map, which contains strings of length<=curr str. length. If we find the
// predecessor string, we try to maximize the word chain length with curr. string as the longest word, and we maximize the res var at the end of loop. We
// return the var res after iterating all strings.











class Solution {
public:
    
    static bool comp(string& lt, string& rt){
        return lt.length()<rt.length();    
    };
    
    
    int longestStrChain(vector<string>& words) {
        // sort(words.begin(), words.end(),[](string& lt, string& rt){
        //     return lt.length()<=rt.length();    
        // });
        sort(words.begin(), words.end(), comp);								// Sotring strings based on length.
        int res=1;
        // vector<int>dp(words.size(),1);
        unordered_map<string,int>st;										// Stores strings, word chain length ending with them as last string.
        for(int i=0;i<words.size();i++){									// Iter. over all strings.
            int maxm=1;
            for(int j=0;j<words[i].length();j++){							// Forming all predecessor strings.
                string temp=words[i].substr(0,j)+words[i].substr(j+1);
                if(st.count(temp)==1) maxm=max(maxm, 1+st[temp]);			// If predecessor found, we maximize word chain length.
            }
            // for(int j=i-1;j>=0 && words[j].length()+1>=words[i].length();j--){
            //     // cout<<"comparing j: "<<words[j]<<" and i: "<<words[i]<<endl;
            //     if(words[j].length()+1==words[i].length() && compare(words[j], words[i])){
            //         // cout<<words[j]<<" and "<<words[i]<<" are predecessors"<<endl;
            //         dp[i]=max(dp[i], dp[j]+1);
            //     }
            // }
            st[words[i]]=maxm;												// Updating map with curr. string and max word chain length ending with curr. string.
            res=max(res, maxm);												// Updating the overall max word chain length var.
        }
        return res;															// Returning the max word chain length.
    }
};

