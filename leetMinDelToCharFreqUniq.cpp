/*
*
//***********************************1647. Minimum Deletions to Make Character Frequencies Unique.*************************************

1647. Minimum Deletions to Make Character Frequencies Unique




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



"aab"
"aaabbbcc"
"ceabaacb"


// Time Complexity: O(k). 													// As it involves freq. of a-z(26 chars), it is constant. 
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k).													// As it involves freq. of a-z(26 chars), it is constant. 
// Space Complexity: O(k).	
// This algorithm is HashMap based. We gather #occur. of each char. We fill the map wher keys are #occur. of a char, values are #chars
// with the key #occur. Now, we iter. over from last to start, at every key, we collect all those chars whose freq. is already occupied
// by some other chars into extra var, we fill these chars in the gap b/w prev. and curr. freq. value and move the rest to curr. freq.
// In this way we fill the all the freqs into diff. values. We also calc. the deletions at every step and add it to res and return it.








class Solution {
public:
    int minDeletions(string s) {
        int res=0, extra=0;
        vector<int>occur(26,0);
        for(auto ch:s) occur[ch-'a']++;
        map<int,int>m;
        for(int i=0;i<26;i++){
            if(occur[i]==0) continue;
            m[occur[i]]++;
        }
        m[0]=0;
        int prev=-1;
        for(auto it=m.rbegin();it!=m.rend();it++){
            // cout<<"occur: "<<it->first<<" and dup: "<<it->second<<" and res: "<<res<<endl;
            if(prev!=-1){
                int gap=prev-it->first-1;									// Gap b/w prev. and curr. freq.
                int del=min(gap, extra);									// Calc. fillable extra freqs.
                extra-=del;
                // cout<<"gap: "<<gap<<" and extra: "<<extra<<endl;
                res+=(del*(del+1))/2;										// Filling the gap with extra freq. chars.
                res+=(gap+1)*extra;											// Moving the rest of freq chars to curr. freq.
            }
            extra+=it->second-1;											// Adding the extra freq. chars to extra var.
            prev=it->first;													// Storing the curr. freq. value.
        }
        
        return res;															// Returning the total #deletions for uniq. freq.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k).													// As it involves freq. of a-z(26 chars), it is constant. 
// Space Complexity: O(k).	
// This is Hash Set based. Here, we gather #occur. of each char. We iter. over all chars, at each one, we keep on decreasing chars
// until we met a freq. which isn't occupied. We mark that freq. as occupied in hash map. In this way all chars given uniq. freqs or 
// they are completely deleted. We gather #deletions in the process and return it at the end.







class Solution {
public:
    int minDeletions(string s) {
        int res=0, extra=0;
        vector<int>occur(26,0);
        for(auto ch:s) occur[ch-'a']++;
        unordered_set<int>st;
        for(int i=0;i<26;i++){
            while(occur[i]>0 && st.count(occur[i])==1){						// Iter. through freqs. which are taken.
                occur[i]--;
                res++;
            }
            st.insert(occur[i]);											// Marking this freq. as taken.
        }
        return res;															// Returning the total #deletions.
    }
};
