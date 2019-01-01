/*
*
//***********************************************************432. All O`one Data Structure.****************************************************

Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this 
function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["AllOne","getMaxKey","getMinKey"]
[[],[],[]]




["AllOne","inc", "inc", "dec","getMaxKey","getMinKey"]
[[],["yo"],["yo"],["yo"],[],[]]



["AllOne","inc", "inc", "dec","getMaxKey","getMinKey"]
[[],["yo"],["bro"],["yo"],[],[]]





["AllOne","inc","dec","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
[[],["hello"],["hello"],[],[],["leet"],[],[]]




["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
[[],["hello"],["hello"],[],[],["leet"],[],[]]




["AllOne","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","dec","getMinKey"]
[[],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["a"],["b"],["b"],["c"],["c"],[]]




["AllOne","inc","inc","inc","inc","inc","dec","dec","getMaxKey","getMinKey"]
[[],["a"],["b"],["b"],["b"],["b"],["b"],["b"],[],[]]




// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, as we need operations of cost O(1), we take HashMap for writing, reading, searching. Here, we maintain
// two maps, one to maintain strings whose #occurances are same, other is to track the #occurances of each string. For every inc/dec. we try to 
// udpate minm, maxm variables. When, putting a str, we try to update the maxm. with #occurances of curr. string, for minm: the curr. string 
// may be minm, or some other may be minm. If curr. str is minm, then #strings with #occurances as minm will be zero now, so we inc. the minm
// by one. If the curr. string inc. may be minm, so try to update it #occur. of curr. str.
// For dec. If curr. str is the only str with #occur. as maxm value, then we dec. the maxm. val. For minm, if the curr. str is the only str with
// min. count and count>1, then. we dec. the minm. by one. If minm. is 1 and curr. str is the only one, then we have to look for the first key 
// in the map(least count among rem. strs). If minm. is >1 and curr. str is the only str, then dec. minm. by 1. 








class AllOne {
public:
    /** Initialize your data structure here. */
    map<int, unordered_set<string>>m;										// Tracks strs with same #occurances.
    unordered_map<string,int>occur;											// Tracks count of each str.
    int minm,maxm;															// Tracks minm, maxm #occurances.
    AllOne() {
        minm=0;																// Init. all global vars.
        maxm=0;
        m=map<int, unordered_set<string>>();
        occur=unordered_map<string,int>();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // cout<<"INc. key with str: "<<key<<endl;
        occur[key]++;														// INc. the #occurances.
        int len=occur[key];													
        m[len].insert(key);													// Inserting curr. str to #occurances key in map.
        if(len>maxm) maxm=len;												// Updating maxm. var.
        if(len>1){															// If str had prev. occured.
            m[len-1].erase(key);											// Remove curr. str from prev. #occurances.
            if(m[len-1].size()==0) m.erase(len-1);							// If now there are no strs with prev. count, remove that count key.
        } 
        if(occur[key]<minm) minm=occur[key];								// If updated count<minm, update minm. var.(A str not a minm count str earlier).
        else if(m.count(minm)==0) minm++;									// If curr. str is the only minm. count str, then inc. minm. value.
        // cout<<"minm: "<<minm<<" and map size: "<<m[minm].size()<<" and maxm: "<<maxm<<endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // cout<<"Dec. key with str: "<<key<<endl;
        // cout<<"Beginning minm: "<<minm<<" and maxm: "<<maxm<<endl;
        if(occur.count(key)==0) return ;									// If str not present, return.
        int len=occur[key];													// Get #earlier occurances.
        // cout<<"len: "<<len<<endl;
        m[len].erase(key);													// Removing str from list of earlier #occurances.
        if(m[len].size()==0) m.erase(len);									// If this is only str with earlier count, remove that count key.
        if(m.count(maxm)==0) maxm--;									 	// If curr. str is the only maxm. count str earlier, dec. maxm. count.
        if(len==1) occur.erase(key);										// If curr. str had occured once, earlier then remove str from map.
        else{																// If curr. str occured>1.
            m[len-1].insert(key);											// Insert the str. in the new #occurances list.
            occur[key]--;													// Dec. the #occurances value.
        }
        if(minm==1 && m.count(minm)==0) minm=m.size()>0? m.begin()->first:0;// If curr. str is the only minm. count str with count 1, then get least count(key).
        else if(minm>1 && m.count(minm)==0) minm--;							// If curr. str is the only str with minm. count>1, then dec. minm. by 1.
        // cout<<"minm: "<<minm<<" and maxm: "<<maxm<<endl;
        // cout<<"minm: "<<minm<<" and map size: "<<m[minm].size()<<" and maxm: "<<maxm<<endl;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        // cout<<"Getting max. key."<<endl;
        if(m.size()==0) return "";											// If map is empty, return empty string.
        auto it=m[maxm].begin();											// Return first str in the maxm. #occurances list.
        return *it;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        // cout<<"Getting minm. key."<<endl;
        if(m.size()==0) return "";											// If map is empty, return empty string.
        auto it=m[minm].begin();											// Return first str in the minm. #occurances list.
        return *it;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */