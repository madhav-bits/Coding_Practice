/*
*
//************************************************************705. Design HashSet.*****************************************************

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
[[],[1],[21],[1],[3],[1000000],[2],[2],[2]]


["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
[[],[0],[1],[1],[0],[1000000],[2],[2],[1000000]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap/Vector based. Here, we create a vector of size: max. input query size+1, we track the elements of HashMap by 
//  those indices to true, if removed we revert back to false. 
// This can also be implemented by bitset library by setting max. query size+1 bits and setting them to 1/0 accordingly.







class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool>dict;														// Tracks elements of HashMap.
    MyHashSet() {
        dict=vector<bool>(1000001);											// Declaring size of vector.
    }
    
    void add(int key) {
        dict[key]=true;														// Setting that index to be true.
    }
    
    void remove(int key) {
        dict[key]=false;													// Setting that index to be false.
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return dict[key];													// Returning the value in that index, if pres. value is true else false.
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */