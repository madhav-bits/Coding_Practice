/*
*
//******************************************************2166. Design Bitset.******************************************************

https://leetcode.com/problems/design-bitset/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Bitset","fix","fix","flip","all","unfix","flip","one","unfix","count","toString"]
[[5],[3],[1],[],[],[0],[],[],[0],[],[]] 
["Bitset","all","fix","flip","fix","flip","unfix","one","all","toString","flip","fix","all","flip","fix","flip","unfix","fix","all","flip","all"]
[[1],[],[0],[],[0],[],[0],[],[],[],[],[0],[],[],[0],[],[0],[0],[],[],[]]



// Time Complexity: O(1)- for all operations except toString().				// O(n) for toString().
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1)- for all operations except toString().				// O(n) for toString().
// Space Complexity: O(n).	
// This algorithm  is Observation based. Here, whenever we get a call to flip entire array, rather than flipping entire array, we store #flips were called on 
// the entire array. When we get calls to fix/unfix, we use another array flipCount[i] to include flips made as part of fix/unfix calls per specific index.
// If index 'i' is already set, which is represented by combined flips of isFlip and flipCount[i]=(isFlip ^ flipCount[idx]) by time fix is called, we ignore 
// the fn. call else we make change in flipCount[i] so that isFlip ^ flipCount[idx] would represent the latest state of index 'i'. Sames goes for unfix too.
// We use setBitsCount to keep track #set indices which is useful in all(), one(), count() functions. When toString() is called, we iter. over flipCount array,
// use (isFlip ^ flipCount[idx]) at every index to the final flip state for that index and use proper char accordingly and append it to res and retur it at the
// end of iter.


// We use bolean isFlip, vector<bool>flipCount rather than int and int array to keep track #flips, since we are dealing with two chars, using bool vars
// would be sufficient to reflect the final state after running total #flips on orig. array.








class Bitset {
public:
    
    vector<bool>flipCount;													// Tracks #flip calls for 'i' were made and readjusts so that (isFlip ^ flipCount[idx]) rep. total flips for 'i'
    int len, setBitsCount;													// Tracks #set indices in the array.
    bool isFlip;															// Tracks #calls for entire array flip are made.
    Bitset(int size) {
        flipCount=vector<bool>(size, false);
        len=size;
        setBitsCount=0;
        isFlip=false;
    }
    
    void fix(int idx) {
        if(isFlip ^ flipCount[idx]) return ;								// If the resulting state indicates curr. index is already set, return fn.
        flipCount[idx]=(flipCount[idx]^ true);								// Make change in flipCount[i], so that (isFlip ^ flipCount[idx]) rep. latest state.
        setBitsCount++;														// Inc. #setBitsCount by 1 as curr. index is fixed now.
        return ;
    }
    
    void unfix(int idx) {
        if((isFlip^flipCount[idx])==false) return ;
        flipCount[idx]=(flipCount[idx]^ true);
        setBitsCount--;
        return ;
    }
    
    void flip() {
        isFlip=(isFlip^ true);												// Updating the total array flips tracker.
        setBitsCount=len-setBitsCount;										// Updating the setBitsCount after flipping entire array.
        return ;
    }
    
    bool all() {
        return (setBitsCount==len);
    }
    
    bool one() {
        return (setBitsCount>0);
    }
    
    int count() {
        return setBitsCount;
    }
    
    string toString() {
        string temp="";
        for(int i=0;i<len;i++) temp+=((isFlip ^ flipCount[i])?'1':'0');		// If the resulting final state is set, we use '1' else '0'.
        return temp;														// Returning the latest state of the binary array.
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();

 */
 
 
 
 
 
 
 
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1)- for all operations.
// Space Complexity: O(n).	
// This solution is observation based. Here, we use two strings to represent it's actual state and inverse state, for fix, unfix calls, we make converse 
// changes in both of them. In case  of flip call, we swap both strs, as they swap references to string, copying wont' be time consuming. For onString(), we 
// just print the orig. str.

// The swap part is crucial here, as it isn't time consuming, we maintian two strs, orig. and it's inverted version and swap them when needed.









class Bitset {
public:
    
    string str, inverseStr;
    int bitSetCount;
    int len;
    Bitset(int size) {
        len=size;
        bitSetCount=0;
        str=string(len, '0');
        inverseStr=string(len, '1');
    }
    
    void fix(int idx) {
        if(str[idx]=='1') return ;
        str[idx]='1';														// Making changes in both orig. and inverted str.
        inverseStr[idx]='0';
        bitSetCount++;
        return ;
    }
    
    void unfix(int idx) {
        if(str[idx]=='0') return ;
        str[idx]='0';
        inverseStr[idx]='1';
        bitSetCount--;
        return ;
    }
    
    void flip() {
        str.swap(inverseStr);												// Swapping orig. and it's inverted version str.
        bitSetCount=len-bitSetCount;
        return ;
    }
    
    bool all() {
        return (bitSetCount==len);
    }
    
    bool one() {
        return (bitSetCount>0);
    }
    
    int count() {
        return bitSetCount;
    }
    
    string toString() {
        return str;															// Returning the final state of orig. str.
    }
};

