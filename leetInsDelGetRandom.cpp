/*
*
//******************************************************380. Insert Delete GetRandom O(1).***********************************************

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
[[],[1],[2],[2],[],[1],[2],[]]



["RandomizedSet","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[0],[0],[-1],[0],[],[],[],[],[],[],[]]



["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
[[],[0],[0],[0],[],[0],[0]]





// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm implements a Data structure using other data structures. Insert takes O(1) has checking it's presence is O(1), if not present
// insert new key, which also takes O(1). We insert given ints into map as key and their indices in vector as values. Where as vector has those 
// map's keys as values in the indices indicated by map. These values and indices are useful in Deletion. Delete also takes O(1) time, as
// Deleting from map is O(1), where deleting from when get the index in vector through key's value from map. In order to maintain the vector 
// intact after removing some inbetween element, we copy from the last index of the vector and remove the last index. Thus, vector sequence
// is maintained, which is very useful in getting the random value from vector with equal prob.





class RandomizedSet {
public:
    
    unordered_map<int, int>m;															// With Given values as keys and index in vec. as values
    int num=0;																			// Indi. the index in vector for to push latest given value
    vector<int> v;																		// Given values as contents in indices shown by map.
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)==1) return false;												// If key already present return fals else push.
        m[val]=num;																		// Given val. as key and vec's index is value.
        v.push_back(val);																// Push given val. into vec at shown index.
        num++;																			// Updating index. for next given value.
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.count(val)==0) return false;												// If such key doesn't exist, then return false.
        int index=m[val];																// Get index in vec. for given value 
        v[index]= v[v.size()-1];														// Updating the given index with new value.
        m[v[index]]=index;																// Cores. updating index/value in map for the key.
        m.erase(val);																	// Removing asked key.
        v.pop_back();																	// Removing last value.
        num--;																			// Updating index for next given value.
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];													// Getting a value from random index from vector.
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */