/*
*
//******************************************************Longest Arithmetic Progression.***********************************************



https://www.interviewbit.com/problems/longest-arithmetic-progression/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4 2 5 7 10
4 1 1 1 1



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB PARTIALLY ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is HashMap/Dynamic Programming based. Here, we track the #seq. with diff-'i', starting from index -'j' and try to update 
// seq. starting from index -'k' with diff -'i'. At the end, we get the max. length AP seq.

// This algo. has got Time Limit Exceeding errors. Don't know why, the Solution 2, also has the same logic, but the key's seq. in the map is
// changed. But, both these combinations of keys would create same number of elem.








int Solution::solve(const vector<int> &v) {
    if(v.size()<=1) return v.size();
    int res=0;
    unordered_map<int,unordered_map<int,int>>m;       						// Tracks # seq. with diff -'i' and starting from index -'j'.                         
    for(int i=v.size()-1;i>=0;i--){
        // cout<<""
        for(int j=i+1;j<v.size();j++){
            int diff=v[j]-v[i];
            if(m.count(diff)==0 || m[diff].count(j)==0) m[diff][i]=max(m[diff][i],2);// If no seq. with that diff found, make len=2.
            else 
                m[diff][i]=max(m[diff][i], m[diff][j]+1);					// If found, try to update seq. starting from curr. index.
            res=max(res, m[diff][i]);										// Try to update the final result.
        }
    }
    return res;																// Return the max. len AP seq.
}







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is HashMap/DP based. Here, we iter. from the back, buliding the AP seq. from the back. In the DP array, we track #elem. in array 
// with diff-'i', starting at index-'j'. This, way entire array to get Arithmetic sequences. We, extract the max. len of those sequences.






int Solution::solve(const vector<int> &v) {
    if(v.size()<=2) return v.size();										// Base cases.
    int res=0;
    unordered_map<int,unordered_map<int,int>>m;								// #elem. in AP seq. with diff-'i' starting at index-'j'.
    for(int i=v.size()-1;i>=0;i--){											// ITer. over all possible starts.
        // cout<<"row: "<<i<<endl;
        for(int j=i+1;j<v.size();j++){										// Iter. over all possible prev. starts.
            int diff=v[j]-v[i];
            if(m[j].count(diff)==0) m[i][diff]=max(m[i][diff],2);			// If no start with that diff exists, we create one at curr. index.
            else m[i][diff]=max(m[i][diff],m[j][diff]+1);					// If exists, we extract the count, maximize the len from curr. index.
            // m[i][diff]=max(m[i][diff],m[j][diff]+1);
            res=max(res, m[i][diff]);										// Try to update the max. AP seq.length encountered.
        }
    }
    return res;																// Return the max AP seq. length.
}