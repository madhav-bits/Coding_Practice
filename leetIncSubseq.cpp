/*
*
//******************************************************491. Increasing Subsequences.***********************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).	
// Space Complexity: O(n*n!).	
// This algorithm iterates the array, at each step finds the greater following value, also makes sure that duplicates are avoided. Thus includes
// a greater following value and calls the func. to find further greater following values. Thus ,we get increasing subsequences(include only
// whose length is >= 2).



class Solution {
public:
    vector<vector<int>> w;													// The result vector containing the increasing subsequences.
    void findSub(vector<int>v,vector<int>u,int index){
        if(u.size()>=2) w.push_back(u);										// If subseq. length >=2 then push to final vector.
        //cout<<endl<<endl<<"The index is: "<<index<<endl;
        map<int, int>m;
        for(int i=index;i<v.size();i++){
            if((u.size()==0 || v[i]>=u[u.size()-1]) && m[v[i]]==0){			// Not pushing duplicates into subsequence.
                //cout<<"Calling func. from if with start index is: "<<index<<" and passed index is: "<<i+1<<endl;
                u.push_back(v[i]);											// This code is optimzed by combining if and else if conditions.
                findSub(v,u,i+1);
                u.pop_back();
                m[v[i]]=1;
            }
            /*
            else if(v[i]>=u[u.size()-1] && m[v[i]]==0){
                //cout<<"Calling func. from if with start index is: "<<index<<" and passed index is: "<<i+1<<endl;
                u.push_back(v[i]);
                findSub(v,u,i+1);
                u.pop_back();
            }
            */
            
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& v) {
        vector<int> u;															// Temp. stores the inc. subseq.
        findSub(v,u,0);
        return w;																// Result containing the inc. subsequences.
    }
};