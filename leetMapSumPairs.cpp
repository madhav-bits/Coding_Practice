/*
*
//**************************************************************677. Map Sum Pairs.*****************************************************

Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the 
key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts 
with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple",3], ["ap"], ["app",2], ["ap"]]


["MapSum", "insert", "sum", "insert", "sum","insert","sum"]
[[], ["apple",3], ["ap"], ["app",2], ["ap"], ["apples",4],["ap]]




// Time Complexity: O(logn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).	
// Space Complexity: O(n).	
// This algorithm is basically slight modification of the map. For insert, just insert the key. For the sum, I had iterated through the entire map,
// extracted the iterator's corresponding first's -key's length chars and checked whether they are equal to the key or not. If equal, I had added 
// that iter's second value to the total count and returned it.



class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {              													// This is constructor.
        
    }
    
    
    void insert(string key, int val) {											//Adding a key to the map.
        m[key]=val;
    }
    
    int sum(string key) {														// Function to give the sums.
        int count=0;
            int len=key.length();
            for(auto it=m.begin();it!=m.end();it++){
                if(it->first.length()>=len && it->first.substr(0,len)==key){	// Checks, whether the curr. iter has first with required prefix.
                    count+=it->second;											// If true, then incre. the count by curr. iter's second value.
                }
            }
            return count;
    }
    unordered_map<string,int> m;												// Declaring the variable to be used by both the functions.
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */