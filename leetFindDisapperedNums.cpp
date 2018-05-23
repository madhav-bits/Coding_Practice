/*
*
//**************************************************448. Find All Numbers Disappeared in an Array.*******************************************

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[8,2,6,8,4,2,2,1]
[]
[1]
[1,2,3,4,5]
[4,3,3,4,5]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm at each step makes sure that index gets proper value(index+1)/it gets one of the repeated values. So, only indices which doesn't
// have proper values indicate the missing values.




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        vector<int>res;
        if(v.size()==0) return res;
        for(int i=0;i<v.size();i++){
            while(v[i]!=i+1 && v[i]!=v[v[i]-1] ){							// Making sure the curr. index gets proper value/one of repeated vals.
                swap(v[i], v[v[i]-1]);
            }
        }
        //for(auto num:v) cout<<num<<" ";
        for(int i=0;i<v.size();i++){
            if(v[i]!=i+1) res.push_back(i+1);								// If proper value not present, then that (index+1) is missing value.
        }
        return res;															// Returning the vector of missing values.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Masking based. At each step, we store the occurane of a number by masking  negating value in (value-1) index and making sure
// it's stays negative. In case of multiple occurance of values same index will be negated multiple times(Which we will avoid checking for neg. 
// values. If found we let the value as it is. In the second iteration, those indices where we encounter positive values are the one indicate
// the missing values(As those (indices+1) valued num haven't occured they stayed positive.





class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        vector<int>res;
        if(v.size()==0) return res;
        for(int i=0;i<v.size();i++){
            // while(v[i]!=i+1 && v[i]!=v[v[i]-1] ){
            //     swap(v[i], v[v[i]-1]);
            // }
            int ind=abs(v[i])-1;
            v[ind]=v[ind]>0?-v[ind]:v[ind];											// Negating the value, to indicate occurance of (ind+1) value.
        }
        //for(auto num:v) cout<<num<<" ";
        for(int i=0;i<v.size();i++){
            //if(v[i]!=i+1) res.push_back(i+1);
            if(v[i]>0) res.push_back(i+1);											// Pos. values indicate absence of (i+1) valued num.
        }
        return res;																	// Returning the vector of missing values.
    }
};