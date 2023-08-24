/*
*
//******************************************************2261. K Divisible Elements Subarrays.******************************************************

https://leetcode.com/problems/k-divisible-elements-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,3,2,2]
2
2
[1,2,3,4]
4
1
[4,6,64,3,33,8,86,54,4,8,9,86,94,72,22,137,119,84,6,87,138,4,88,97,101,4,3,3,34,67,67,78,9,9,7,5,34,3,5,67,6,45]
10
6



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^3).	
// This algorithm is Sliding Window based. Here, we extend the window as much as possible until we #divisible nums in the window doesn't exceed 'k', if exceeds
// we pop elems from the front until #divisible nums becomes<=k. For every window whose divisible nums count<='k', we form substr starting every index in window
// until last index, thus we cover all windows with divisible nums count<=k for the given array. Here, we have to count unique substr simply counting the 
// substrs won't work, we have to form the substr and try to insert it into an set to keep unique substr and return the set size at the end of process.







class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        int res=0, start=0;
        unordered_set<string>st;
        for(int i=0;i<v.size();i++) {
            if(v[i]%p==0) k--;
            while(k<0) {													// If #divisible nums in window>k, we pop elems from the front.
                if(v[start++]%p==0) k++;
            }
            string temp="";
            for(int j=i;j>=start;j--) {										// We form substrs ending with 'i' and try to insert it into set.
                temp+=to_string(v[j])+"#";
                st.insert(temp);											// Inserting substr into set.
            }
        }
        return st.size();													//Returning #unique subsets with divisible nums in them<='k'.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(^2).	
// This algorithm is Trie based. If we are only counting #subsets we could have used Sliding Window for better runtime, here as we are tracking unique 
// substrs, we eventually have to form the substrs and check for uniqueness, we have to iter and form substr, thus making it O(n^2). We could have also 
// used Tries as it would also take same time compl. We form substrs starting every index as long as #divisible nums<='k'. We make every entry into substr a 
// child node in Trie, thus a unique substr wont' exist in Trie earlier, so we add this node and inc. res by 1.








class Solution {
public:
    
    struct Trie{
        unordered_map<int, Trie*>child;
        Trie() {
            child=unordered_map<int,Trie*>();
        }
    };
    
    int countDistinct(vector<int>& v, int k, int p) {
        int res=0;
        Trie*root=new Trie();
        for(int i=0;i<v.size();i++) {
            Trie* node=root;
            int cnt=0;
            for(int j=i;j<v.size();j++) {									// Forming substrs as long as #div nums<='k'.
                if(v[j]%p==0) cnt++;
                if(cnt>k) break;
                if(node->child.count(v[j])==0) {							// If substr doesn't exist earlier.
                    res++;													// We inc. res by 1.
                    node->child[v[j]]=new Trie();							// We create a new node for it.
                }
                node=node->child[v[j]];										// We move to the child node.
            }
        }
        return res;															//Returning #unique subsets with divisible nums in them<='k'.
    }
};








//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// This solution doesn't work as there were collisions in the set while inserting calculated hash of the subsets.
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Hashing based. Here, we form hash rep for each of the substrings and store it in set, #entries in set represents #uniq. subsets.
// Since the scope of nums is high it lead to collisions








class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        int res=0, mod=1000000007;
        unordered_set<int>st;
        for(int i=0;i<v.size();i++) {
            int cnt=0, rep=0;
            for(int j=i;j<v.size();j++) {									// Forming substrs as long as #div nums<='k'.
                if(v[j]%p==0) cnt++;
                if(cnt>k) break;
                rep=(1ll*rep*200+v[j])%mod;									// Calc. hash of subset after adding curr. num.
                st.insert(rep);												// Adding curr. rep to set.
            }
        }
        return st.size();													//Returning #unique subsets with divisible nums in them<='k'.
    }
};



//************************************************************Solution 4:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// As there were collisions in Solution 3, if we store subsets of all lengths in one set, so we maintain a set for each subset size, thus decreasing prob. 
// of collision.





class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        int res=0, mod=1000000007;
        vector<unordered_set<int>>st(v.size());
        for(int i=0;i<v.size();i++) {
            int cnt=0, rep=0, rep2=0;
            for(int j=i;j<v.size();j++) {
                if(v[j]%p==0) cnt++;
                if(cnt>k) break;
                rep=((long long)rep*200+v[j])%mod;
                int len=j-i;												// Calc. length of curr. subset.
                res+=st[len].insert(rep).second;							// Inserting curr. substr's rep in it's corresponding length set.
            }
        }
        return res;															//Returning #unique subsets with divisible nums in them<='k'.
    }	
};

