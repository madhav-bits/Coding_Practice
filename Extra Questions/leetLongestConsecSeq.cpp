/*
*
//******************************************************128. Longest Consecutive Sequence.***********************************************

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,0,1,-1]

[0,1,5,7,6,8,3,4,2]


[0,1,5,6,8,3,4,2]


[4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Union-Find based which iterates the array, at each step, we check for seq. to left/right of curr. value, if we find one,
//  we get their len stored
// in maps, all the nodes belonging to one seq. would have one core parent(whose parent is itself). Add the new elem. to the old seq. and make
// it's parent the parent of the earlier seq. If it has seq. on both the sides, then we make the parent of right seq. the parent of left, curr.
// value. We have a map which tracks the core node values to the len of seq. that has this node as core parent.


// This is of O(n^2), can be improved by going to other end of seq. and changing it's parent(As, we can get other end by sub. len from curr.
// value), done in algorithm 2.Surprisingly not much difference in execution time b/w both these algos.





class Solution {
public:
    
    int findParent(int node, unordered_map<int,int>&parent){				// Finds the core parent of curr. value.	
        int res;
        while(parent[node]!=node){											// Till core parent is reached, where parent is itself.
            node=parent[node];
        }
        return node;														// Returning the core parent.
    }
    
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        unordered_map<int,int>parent,val;
        int res=1;
        for(int i=0;i<v.size();i++){
            // cout<<"Curr.value: "<<v[i]<<endl;
            if(parent.count(v[i])==1) continue;
            if(parent.count(v[i]-1)==0 && parent.count(v[i]+1)==0){
                parent[v[i]]=v[i];
                val[v[i]]=1;
            }
            else{
                int parR,parL;
                if(parent.count(v[i]-1)==1 && parent.count(v[i]+1)==1){ 	// When two side numbers exist.
                    parL=findParent(v[i]-1, parent);						// Extracting core parent of left, right seqs.
                    parR=findParent(v[i]+1, parent);
                    // cout<<"Left len: "<<len1<<"right len: "<<len2<<endl;
                    parent[parL]=parR;										// Making right's parent as parent of left seq.
                    val[parR]=1+val[parL]+val[parR];						// Updating len of right's parent.
                    res=max(res,val[parR]);
                    parent[v[i]]=parR;										// Setting right's parent as parent of curr. value.
                }
                else if(parent.count(v[i]-1)==1){                          	// Numbers exists on left side.
                    // cout<<"Inside left seq."<<endl;
                    parL=findParent(v[i]-1,parent);							// Extracting core parent of left seq.
                    parent[v[i]]=parL;										// Setting left's parent as parent of curr. value.
                    val[parL]=1+val[parL];									// Updating left's parent's len.
                    res=max(res,val[parL]);
                }
                else if(parent.count(v[i]+1)==1){                          // Numbers exists on right side.
                    parR=findParent(v[i]+1,parent);
                    parent[v[i]]=parR;
                    val[parR]=1+val[parR];
                    res=max(res,val[parR]);
                }
                
            }
            // cout<<"The result is: "<<res<<endl;
        }
        return res;															// Returning the overall longest seq. len.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Union-Find based which iterates the array, at each step, we check for seq. to left/right of curr. value, if we find one, 
// we get their len stored
// in maps, all the nodes belonging to one seq. would have one core parent(whose parent is itself). Add the new elem. to the old seq. and make
// it's parent the parent of the earlier seq. If it has seq. on both the sides, then we change the parent of v[i]-1 and the last elem. in this
// seq's parent to parent of v[i]+1, thus all of them would be having same parent. We need not search for core parent in a while loop.
// We have a map which tracks the core node values to the len of seq. that has this node as core parent.




class Solution {
public:
    
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        unordered_map<int,int>parent,val;									// Tracks num and parent, other map tracks parent's seq. len.
        int res=1;															// Default ans. 1.
        for(int i=0;i<v.size();i++){
            // cout<<"Curr.value: "<<v[i]<<endl;
            if(parent.count(v[i])==1) continue;
            if(parent.count(v[i]-1)==0 && parent.count(v[i]+1)==0){			// If no adj. seq's exist, create a new seq.
                parent[v[i]]=v[i];											// Make itself as core parent.
                val[v[i]]=1;												// Set to length of one.
            }
            else{
                int parR,parL;
                if(parent.count(v[i]-1)==1 && parent.count(v[i]+1)==1){ // When two side numbers exist.
					parR=parent[v[i]+1]; parL=parent[v[i]-1];
                    // cout<<"Left len: "<<len1<<"right len: "<<len2<<endl;
                    val[parR]=1+val[parL]+val[parR];
                    res=max(res,val[parR]);									// We change the parent of left, curr. to right seq's parent.
                    parent[v[i]-val[parent[v[i]-1]]]=parR;					// Changing parent of left's other end(farther from curr. value).
                    parent[v[i]-1]=parR;									// Changing parent of left's one end(adj. to curr. value).
                    parent[v[i]]=parR;
                }
                else if(parent.count(v[i]-1)==1){                          	// Numbers exists on left side.
                    // cout<<"Inside left seq."<<endl;						
					parL=parent[v[i]-1];									// Extracing parent of left seq.
                    parent[v[i]]=parL;										// Setting left's seq. parent as curr. value's parent.
                    val[parL]=1+val[parL];									// Updating the len. linked to parent.
                    res=max(res,val[parL]);
                }
                else if(parent.count(v[i]+1)==1){                          	// Numbers exists on right side.
					parR=parent[v[i]+1];
                    parent[v[i]]=parR;										// Setting right's seq. parent as curr. value's parent.
                    val[parR]=1+val[parR];
                    res=max(res,val[parR]);
                }
                
            }
            // cout<<"The result is: "<<res<<endl;
        }
        return res;
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algo. is HashMap based. Here, we do the same as above, but instead of maintaining child parent relationships. We just have a map, where
// value indicates the len. of seq. that this curr.key is in. If, we change at one end(Add elem), we prpopogate inc. len to other end as we get
// it's index by sub. v[i]-1 and len of seq. it is in.
// (I failed to notice this simple point that we can get other end by adding len. of seq. to one end'd value, and ended up doing the 
// elaborate Union-Find method).


class Solution {
public:
    
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        unordered_map<int,int>parent,val;									// Tracks a val. and len of seq. it is in.
        int res=1;
        for(int i=0;i<v.size();i++){
            if(val[v[i]]>0) continue;										// If already visited node, return 
            val[v[i]]=1;													// Marking as viisted.
            int leftLen=val[v[i]-1], rightLen=val[v[i]+1];					// Extracting len. of two adj. seq. if exist.
            if(leftLen>0 && rightLen>0){									// If left, right seq. exist.
                val[v[i]-1-leftLen+1]=leftLen+rightLen+1;					// Changing len of left's seq. end(farther to curr. value).
                val[v[i]+1+rightLen-1]=leftLen+rightLen+1;					// Changing len of right's other end(farther from curr. value).
            }
            else if(leftLen>0){												// If only left seq. exist.
                val[v[i]-1-leftLen+1]=leftLen+1;							// Changing len of left's seq. end(farther to curr. value).
                val[v[i]]=leftLen+1;										// Changing len of curr. value.
            }
            else if(rightLen>0){											// If only right seq. exist.
                val[v[i]+1+rightLen-1]=rightLen+1;							// Changing len of right's seq. end(farther to curr. value).
                val[v[i]]=rightLen+1;										// Changing len of curr. value.
            } 
            res=max(res,leftLen+rightLen+1);								// Trying to update the overall result.
            // cout<<"leftLen: "<<leftLen<<" and rightLen: "<<rightLen<<endl;
            // cout<<"Max. length: "<<res<<endl;

        }
        return res;															// Returning the longest seq.
    }
};