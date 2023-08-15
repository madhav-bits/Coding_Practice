/*
*
//**********************************2817. Minimum Absolute Difference Between Elements With Constraint.*********************************

https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,3,2,4]
2
[5,3,2,10,15]
1
[1,2,3,4]
3
[4,6,4,3,6,6,3,7,8,21,4,5,423,4,6,87,9,9,98,5,3,3,5,8,8]
4
[20,1,2,21,50,60,70,80,90]
3
[10,20,30,40,50,60,70,80,61]
3
[10,89,2,2,30,2,40,5,40,61,20,7,23,85,6]
5




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Map/Sorting based. Here, we use map to check if any values closer to curr. val exist at a dist>gap. We maintain a window of size 'gap-1'
// we check if values closers to left side values are present in map with rightside values. We first populate map with all indices>=gap. We now iter. and
// check if closer values present for v[i-1] as this would new entry into leftside and we also remove v[i+gap-1] from map, and check lower_bound for v[i-1] 
// in map and try to update res with the diff. All the indices before 'i' are already searched for in the map with rightside values then, so we don't have to 
// freshly compare all values from [0,i-1] with rightside values and #righside values had only decreased from the earlier comparisons, so we haven't missed any
// comparisons effectively. We return res at the end of iter.






class Solution {
public:
    int minAbsoluteDifference(vector<int>& v, int gap) {
        if(gap==0) return 0;
        gap--;
        int res=INT_MAX;
        map<int,int>right;
        for(int i=gap;i<v.size();i++) right[v[i]]++;						// Pushing all rightside values into map.
        for(int i=1;i<v.size()-gap;i++) {
            // cout<<"currently searching for: "<<v[i-1]<<endl;
            if(--right[v[i+gap-1]]==0) right.erase(v[i+gap-1]);				// Removing entry from map, which is going to enter into window.
            auto it=right.lower_bound(v[i-1]);								// Check for new exit from window in rightSide values map.
            if(it!=right.end() && it->first-v[i-1]<res) res=it->first-v[i-1];// Check for the lowest value>=v[i-1] and try to update res with their diff.
            if(res==0) return 0;											// If we observed lowest possible val, return 0 directly.
            if(it!=right.begin() && v[i-1]-(--it)->first<res) res=v[i-1]-it->first;// Check for greatest val<v[i-1] and try to update res with their diff.
        }
        return res;															// Returning min abs diff b/w nums separated by gap indices atleast.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Set/Solution based. This algo is almost same as the above one, except that we don't put in all entries into map in the beginning and we 
// add vals in map and search for vals in map which are going to enter into window as we iter., using the explanation provided in above sln, we don't 
// effectively miss out any comparisons. We rturn res at the end of iter.







class Solution {
public:
    int minAbsoluteDifference(vector<int>& v, int gap) {
        if(gap==0) return 0;
        int res=INT_MAX;
        set<int>left;
        for(int i=0;i+gap<v.size();i++) {
            // cout<<"currently searching for: "<<v[i-1]<<endl;
            left.insert(v[i]);												// Val just outside from window.
            auto it=left.lower_bound(v[i+gap]);								// Val which is going into window at the end of curr. iter.
            if(it!=left.end() && *it-v[i+gap]<res) res=*it-v[i+gap];
            if(res==0) return 0;
            if(it!=left.begin() && v[i+gap]-*(--it)<res) res=v[i+gap]-*it;
        }
        return res;
    }
};

