/*
*
//******************************************************2349. Design a Number Container System.******************************************************

https://leetcode.com/problems/design-a-number-container-system/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["NumberContainers","find","change","change","change","change","find","change","find"]
[[],[10],[2,10],[1,10],[3,10],[5,10],[10],[1,20],[10]] 
["NumberContainers","change","find","change","find","find","find"]
[[],[1,10],[10],[1,20],[10],[20],[30]]



// Time Complexity: O(logm) for Change function.							// O(1) for find function. 
// Space Complexity: O(n+m*n).												// n-#nums, m-avg. #indices each num is stored in.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm) for Change function.							// O(1) for find function. 
// Space Complexity: O(n+m*n).												// n-#nums, m-avg. #indices each num is stored in.
// This algorithm is Map/Set based. One map is to link indices to the number stored in it. Other is to list all indices related to a number. When we change
// number in an index, we remove that index from indices map's number related set and we add this index to indices map's new number related set, we also 
// update the map: 'm' to reflect that this index stores new number.
// When asked for minIndex, we check if the number is present or the set related to that number in indices map is empty, then we return -1 else we return 
// first elem. in set.







class NumberContainers {
public:
	unordered_map<int,set<int>>indices;										// Key-Value Relation: {number->set of indices with this number}
    unordered_map<int,int>m;												// Key-Value Relation: {index->number}
    NumberContainers() {
        m=unordered_map<int,int>();
        indices=unordered_map<int,set<int>>();
    }
    
    void change(int index, int number) {
        if(m.count(index)==1) {
            indices[m[index]].erase(index);									// Removing curr. index from old num's indices set.
        }
        m[index]=number;													// Updating curr. index to store curr. number.
        indices[number].insert(index);										// Adding curr. index in curr. num's indices set.
        return ;
    }
    
    int find(int number) {
        if(indices.count(number)==0 || indices[number].empty()) return -1;	// Returning -1 in case PQ is empty or the number is not present in indices map.
        return *indices[number].begin();									// Returning the minIndex for this number.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm) for Change function.							// O(logm) for find function. 
// Space Complexity: O(n+m*n).												// n-#nums, m-avg. #indices each num is stored in.
// This algorithm is Map+Priority Queue based. This is same as the above solution except that it uses PQ instead of a set to give us the minIndex of a number.
// When we change the value in an index, we insert new index into the PQ related to number in indices map. 
// When we find the minIndex for the value, we pop all the top values which currently doesn't store the target number and we return the first index from the
// PQ top which curr. stores the target number. If the indices map doesn't have this number key or if the corresponding PQ is empty, we return -1.







class NumberContainers {
public:
    unordered_map<int,int>m;												// Key-Value Relation: {index->number}
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>indices;// Key-Value Relation: {number->PQ of indices with this number}
    NumberContainers() {
        m=unordered_map<int,int>();
        indices=unordered_map<int, priority_queue<int, vector<int>, greater<int>>>();
    }
    
    void change(int index, int number) {
        m[index]=number;													// Updating curr. index with this number.
        indices[number].push(index);										// Inserting curr. index  into the indices map's curr. number's PQ.
        return ;
    }
    
    int find(int number) {
        while(!indices[number].empty() && m[indices[number].top()]!=number) {// Pop all the indices from PQ which curr. doesn't store curr. number.
            indices[number].pop();
        }
        if(!indices[number].empty()) return indices[number].top();			// If PQ is non-empty, return the first index which stores curr. number.
        return -1;															// Returning -1 in case PQ is empty or the number is not present in indices map.
    }
};

