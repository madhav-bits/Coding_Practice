/*
*
//*************************************************************60. Permutation Sequence.****************************************************

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

9
300000

4
9

9
37

2
3

// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This is dfs, the logic is that we calc. the index to be swapped by using the factorial values of rem. to be swapped elem. Once found, we swap
// that value and make a recursive call for the next swap. Thus we swap all values in the vector, and add one, as that combination is not
// counted towards total #swaps. We convert vector to string and return it.

// The answer combi. sequence can be obtained if we maintain the state(inc. order of to be swapped values) after every swap.So, we do only
// single swap(not reverse the 1st swap for other possible swaps in same psn).


class Solution {
public:
    string s;
    void findCombi(vector<int> v, int N, int index, int &count, int target){
        //cout<<"The count is: "<<count<<endl;
        if(index==N){											// If all the satisfy the conditions, then inc. the count by one  and return.
            count++;											// This one is for the curr.(answer) combination.
            if(count==target){
                for(int i=0;i<N;i++){							// Could use a string directly, instead of vector, just gone with the flow.
                    //cout<<"Vector elem. are: "<<v[i]<<endl;
                    s+=to_string(v[i]);							// Converting the vector to string.
                }
            }
            
            return ;
        }
        
        int total=count;
        int &&fact=1;
        for(int i=N-1-index;i>0;i--)
            fact*=i;
        int i;
        for(i=index;i<N;i++){									//Finding the correct index to swap.
            total+=fact;
            swap(v[i], v[index]);
            if(total>=target)
                break;
            
        }
        //cout<<"Count to get is: "<<target-count<<endl;
        if(total>=target && count<target){			                        
            //cout<<"i+1 is: "<< i+1<<" and v[i] is: "<<v[i]<<endl;
            total-=fact;
            count=total;										//Dec. fact as target<curr. total.
            //cout<<"Swapped Value for passing: "<<v[index]<<" and i: "<<i<<endl;
            findCombi(v,N,index+1,count, target);
        }													
            
    }
    
    
    string getPermutation(int n, int k) {
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++)									// Intitializing the array.
            v.push_back(i+1);
        findCombi(v,n,0,count,k);								// Calling the fucntion.
        return s;												// Returning the final result.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
//*************************************************THROWS TIME LIMIT EXCEEEDED ERROR.*************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This is dfs, the logic is that we make all possible swaps and add all those combinations towards final count and return once we reach the 
// target numbered combination.







class Solution {
public:
    string s;
    void findCombi(vector<int> v, int N, int index, int &count, int target){
        if(index==N){											// If all the satisfy the conditions, then inc. the count by one  and return.
            count++;
            if(count==target){
                for(int i=0;i<N;i++){
                    //cout<<"Vector elem. are: "<<v[i]<<endl;
                    s+=to_string(v[i]);
                }
            }
            return ;
        }
        
        for(int i=index;i<N;i++){
            if(count<target){			                        // Check whether to be swapped satisfies the condition or not.
                swap(v[i], v[index]);							// If satisfies then only go ahead with the swap and do a recuriseve call.
                //cout<<"i+1 is: "<< i+1<<" and v[i] is: "<<v[i]<<endl;
                findCombi(v,N,index+1,count, target);
                //swap(v[i], v[index]);							// Re-Swap lets us have a clear flow of swaps. Where as single swap maitains the 
            }													// Order of values- Much useful in case of duplicates values in vector.
        }    
    }
    
    
    string getPermutation(int n, int k) {
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++)									// Intitializing the array.
            v.push_back(i+1);
        findCombi(v,n,0,count,k);
        return s;
    }
};