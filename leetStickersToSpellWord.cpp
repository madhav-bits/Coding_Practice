/*
*
//**********************************************************691. Stickers to Spell Word.***************************************************

We are given N different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

Example 1:

Input:

["with", "example", "science"], "thehat"
Output:

3
Explanation:

We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
Example 2:

Input:

["notice", "possible"], "basicbasic"
Output:

-1
Explanation:

We can't form the target "basicbasic" from cutting letters from the given stickers.
Note:

stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation 
of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["with", "example", "science"]
"xamceswimap"


["with", "example", "science"]
"thehat"



// Time Complexity: O(2^n*26*m).  
// Space Complexity: O(2^n*26*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n*26*m).											// N,#words in target, m is #words in stickers.
// Space Complexity: O(2^n*26*m).	
// This algorithm is Depth First Search based Algo. At each step, we chose only stickers, which contains the first char of the target, thus 
// reducing the numbers of nodes to cover in backtracing. We start from the target string, we keep on reducing the required chars for obtaining
// all chars in target by chosing stickers, we pass the new updated str, representing no. of chars of each type required. At the end, when all
// chars are obtained, the target becomes a empty str, which has been already saved in map with value=0, so returns 0.


// THE OPTIMIZATION PART OF CHOSING STICKERS, WHICH CONTAIN ATLEAST ONE CHAR/FIRST CHAR IN TARGET, STILL HAVEN'T YET CONVINCED ME IN REDUCING
// THE TIME COMPLEXITY DRASTICALLY.





class Solution {
public:
    
    int minCount(vector<vector<int>> &words, unordered_map<string, int> &dp, string target){
        if(dp.count(target)==1) return dp[target];							// If Target str, already visited, return #steps to obtain it.
        vector<int>tar(26,0);
        int ans=INT_MAX;
        for(auto ch:target) tar[ch-'a']++;
        
        for(int i=0;i<words.size();i++){
            if(words[i][target[0]-'a']==0) continue;						// The next sticker has to contain, atleast one char in target.
            
            string s;														// Stores the new char. requirement.
            for(int j=0;j<26;j++){
                if(tar[j]-words[i][j]>0){									// Updates the char. requirements.
                    s+=string(tar[j]-words[i][j], 'a'+j);					// Forms the new updated char. requirement str.
                } 
            }
            // cout<<"The new target is; "<<s<<endl;
            int tempRes=minCount(words,dp,s);								// Making a DFS call to minStickers for new char. requirement str.
            if(tempRes!=-1) ans=min(tempRes+1,ans);							// Updating the minStickers.
        }
        dp[target]=(ans==INT_MAX)?-1:ans;									// If it's not possible to obtain target str, return -1.
        return dp[target];													// Returning the minStickers required.
    }
	
	
    int minStickers(vector<string>& w, string target) {
        vector<vector<int>> words(w.size(),vector<int>(26,0));				// Stores the char. count of all stickers.
        unordered_map<string, int> dp;										// Tracks the char. requirements.
        for(int i=0;i<w.size();i++){										// Couning the #chars in stickers.
            for(auto ch:w[i])
                words[i][ch-'a']++;
        }
        dp[""]=0;															// Base case.
        return minCount(words,dp,target);									// Calling fn. to get minCount of stickers.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n*26*m).											// N,#words in target, m is #words in stickers.
// Space Complexity: O(2^n*26m).	
// This algorithm is Breadth First Search based Algo.  We start from the target string, we keep on reducing the required chars for obtaining
// all chars in target by chosing stickers, we pass the new updated str, representing no. of chars of each type required iff the target str isn't 
// pushed into queue once. Thus, on reaching the target str, we return no. of moves till then. If target can't be obtained, the queue gets 
// empty at a stage. Then, we return -1.


// THIS ALGO. WORKS PERFECTLY FINE, AN ALGO. IN JAVA, WHICH IS ALMOST SAME AS THIS ONE, EXCEPT FOR USAGE OF DATA STRUCTURES, GOT ACCEPTED. THIS ONE
// PASSES 99/100 CASES.MISSING OUT THE LAST ONE ON TIME COMPLEXITY ERROR.






class Solution {
public:
    
    string toString(vector<int>&v){											// Converts the vector with char. requirements to str.
        string res="";
        for(int i=0;i<26;i++){
            res+=string(v[i],i+'a');
        }
        return res;
    }
	
    int minStickers(vector<string>& words, string target) {
        // unordered_map<char,int>tar;
        vector<int>tar(26,0), fin(26,0);									// Stores target chars. count and empty string(obtained at the end).
        for(int i=0;i<target.length();i++) tar[target[i]-'a']++;
        vector<vector<int>>mem;
        for(int i=0;i<words.size();i++){									// Conv. vector of strings of stickers into vector of chars count.
            vector<int>temp(26,0);
            for(int j=0;j<words[i].length();j++){
                temp[words[i][j]-'a']++;
            }
            mem.push_back(temp);
        }
        unordered_map<string,int> dp;										// Tracks target strs visited.
        string strTarget=toString(tar);										// We go in reverse drn. target to "".
        string strFinal=toString(fin);										// We aim to get empty target str at the end.
        queue<pair<vector<int>, int>>q;										// Stores the target strs to be visited.
        q.push(make_pair(tar,0));											// Pushing the target into queue.
		dp[strTarget]=0;													// Marking the target as visited.
        while(!q.empty()){
            //cout<<"Inside the queeu."<<endl;
            pair<vector<int>, int>curr=q.front();							// Extract target str. from queue.
            string strCurr=toString(curr.first);
            q.pop();
            vector<int>temp;
            for(int i=0;i<mem.size();i++){									// Iter. over all stickers.
                temp=curr.first;
                // if(mem[i][curr.first[0]-'a']==0) continue;				// ********Need to make this optimizer work for my algo.**********
                for(int j=0;j<mem[i].size();j++){
                    if(temp[j]>=0){											// Work only on requi. target chars.
                        temp[j]-=mem[i][j];
                        if(temp[j]<=0) temp[j]=0;
                    }                                                 
                }
                string strTemp=toString(temp);
                if(strTemp==strFinal) return curr.second+1;					// On reaching the target, return the count directly.
                if(dp.count(strTemp)==0){									// If the updated target isn't reached prev. then push into queue.
                    // cout<<"Pushed into queue with str: "<<words[i]<<endl;
					dp[strTemp]=curr.second+1;								// Update the Map, that this updated str has been updated.
                    q.push(make_pair(temp,curr.second+1));
                } 
            }
            
        }
        
        // cout<<" curr. outside the loop."<<endl;
        return -1;															// If the target str. can't be obtained, then return -1.
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n*26*m).											// N,#words in target, m is #words in stickers.
// Space Complexity: O(2^n*26*m).	
// This algo. is same as the above one. The above is slightly improvised one. Which also, utilizes some other Data Structures.

class Solution {
public:
    
    string toString(vector<int>&v){
        string res="";
        for(int i=0;i<26;i++){
            res+=v[i]+'0'+',';
        }
        return res;
    }
    int minStickers(vector<string>& words, string target) {
        // unordered_map<char,int>tar;
        vector<int>tar(26,0), fin(26,0);
        for(int i=0;i<target.length();i++) tar[target[i]-'a']++;
        vector<vector<int>>mem;
        for(int i=0;i<words.size();i++){
            // unordered_map<char, int> temp;
            vector<int>temp(26,0);
            for(int j=0;j<words[i].length();j++){
                temp[words[i][j]-'a']++;
            }
            mem.push_back(temp);
        }
        map<vector<int>,int> dp;
        
        queue<pair<vector<int>, int>>q;
        q.push(make_pair(tar,0));
        while(!q.empty()){
            //cout<<"Inside the queeu."<<endl;
            pair<vector<int>, int>curr=q.front();
            dp[curr.first]=curr.second;
            q.pop();
            // cout<<"Inside the while with count: "<<curr.second<<" and map contents: "<<endl;
            // for(auto it=curr.first.begin();it!=curr.first.end();it++){
            //     cout<<"key: "<<it->first<<" and value: "<<it->second<<endl;
            // }
            vector<int>temp;
            // for(int i=0;i<words.size();i++){
            //     temp=curr.first;
            //     for(int j=0;j<words[i].length();j++){
            //         if(temp.count(words[i][j])==1){
            //             temp[words[i][j]]--;
            //             if(temp[words[i][j]]==0) temp.erase(words[i][j]);
            //         }
            //     }
            //     if(temp.empty()) return curr.second+1;
            //     if(temp!=curr.first){
            //         // cout<<"Pushed into queue with str: "<<words[i]<<endl;
            //         q.push(make_pair(temp,curr.second+1));
            //     } 
            // }
            
            
            
            for(int i=0;i<mem.size();i++){
                temp=curr.first;
                if(mem[i][curr.first[0]-'a']==0) continue;
                for(int j=0;j<mem[i].size();j++){
                    if(temp[j]>=0){
                        temp[j]-=mem[i][j];
                        if(temp[j]<=0) temp[j]=0;
                    }                                                 
                }
                if(temp==fin) return curr.second+1;
                if(dp.count(temp)==0){
                    // cout<<"Pushed into queue with str: "<<words[i]<<endl;
					dp[temp]=curr.second+1;
                    q.push(make_pair(temp,curr.second+1));
                } 
            }
            
        }
        
        // cout<<" curr. outside the loop."<<endl;
        return -1;
    }
};

