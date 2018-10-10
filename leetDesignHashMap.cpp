/*
*
//**********************************************************706. Design HashMap.***************************************************


Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyHashMap","put","put","get","get","put","get", "remove", "get"]
[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]






// Time Complexity: O(1).  													// Setting the vector/arr takes O(Max. query size) though.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Setting the vector/arr takes O(Max. query size) though.
// Space Complexity: O(n).	
// This algorithm is Vector based. Here, we create a vector of size max. query size. We place the values in the index valued keys, if we 
// remove that key, we set the value in that index to -1.In case of update, we update the value in that index.








class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int>v;															// Vector to maintain key, value pairs.
    MyHashMap() {
        v=vector<int>(1000001, -1);											// Setting default value to all indices.
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        v[key]=value;														// Updating/ Setting the value to that key value.
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return v[key];														// Returning the value, if pres. gives that value, else gives def.(-1).
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        v[key]=-1;
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Setting the vector/arr takes O(Max. query size) though.
// Space Complexity: O(n).	
// This algorithm is same as previous one, except that here arrays are used instead of vectors as in prev. case.


 
 
 
 
 
 class MyHashMap {
public:
    /** Initialize your data structure here. */
    int arr[1000001];
    MyHashMap() {
        memset(arr,-1,1000001);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        arr[key]=value;
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return arr[key];
        // return v[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        arr[key]=-1;
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */