/*
*
//****************************************************************493. Reverse Pairs.*********************************************************

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2147483647,2147483647,2147483647,2147483647,2147483647,2147483647]

[1,4,2,7,3,4,4]

[1]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Merge Based Algo. This algo. works at the Merging phase of results obtained from the recursive calls. It maintains two 
// ptrs tracking max. value in left and right intervals. If the curr. max. value in first half, is <2* max. value in second half, we dec. the 
// ptr in second half. If the 2* max(2half)<max(1h), then all the nums from (mid+1) to curr. index in second half, would satisfy the conditon in 
// second question. Now, we dec. the ptr in first half, hoping that curr. index in second half's twice would also be < curr. index in first half.
// This way, we go till all elem. in first half are scanned. After, this step, we do regular Merge Sort Merging, to sort the curr. interval.








class Solution {
public:
    int count=0;															// Tracks #important reverse pairs.
    
    void mergeSort(vector<int>&v,vector<int>&rep, int low, int high){
        // cout<<"Inside the mergeSort with low: "<<low<<" and high: "<<high<<endl;
        if(low>=high) return ;
        int mid=low+(high-low)/2;
        mergeSort(v,rep,low,mid);											// Rec. calls. to sort left and right halfs.
        mergeSort(v,rep,mid+1,high);
        vector<int>temp(high-low+1,0);										// Temp. var. to store the sorted values.
        int i=mid, j=high, k=0, ind=low;
        
        while(i>=low && j>mid){												// Count the important reverse pairs.
            if((long)v[rep[i]]>2*(long)v[rep[j]]){							//Now, all elemm. behind curr. index in sec. half satisfy qsn's cdn.
                // cout<<"Found imp. number with ind: "<<ind<<" and j: "<<j<<endl;
                count+=j-mid;												// Includes all elem. in second half till curr. index in result.
                i--;														// Dec. ptr in 1st half, as it might also satisfy qns's cdn.
            }
            else j--;														// Else, dec. the ptr in second half.
        }
        
        i=low; j=mid+1; k=0; ind=low;										// Init. vars for Regular merging in Merge Sort.
        
        while(i<=mid || j<=high){											// This is Regular Merging in Merge Sort.
            if((i<=mid && j<=high && v[rep[i]]<=v[rep[j]]) || j==high+1  ){
                // cout<<"I inc. with i value: "<<v[rep[i]]<<" and j with value: "<<v[rep[j]]<<endl;
                temp[k]=rep[i];
                i++;
            }
            else{
                temp[k]=rep[j];
                j++;
            }
            k++;
        }
        
        
        for(int i=0;i<high-low+1;i++)										// Copying back elem. from temp. array to orig. array.
            rep[low+i]=temp[i];
        
    }
    
    
    int reversePairs(vector<int>& v) {
        vector<int>temp(v.size(),0);
        for(int i=0;i<v.size();i++) temp[i]=i;								// A temp. array which stores indices of all nums in given array.
        mergeSort(v,temp,0,v.size()-1);										// Calling fn. to mergeSort the given array.
        // for(auto num:temp) cout<<num<<" ";
        // cout<<endl;
        return count;														// Return the count of important reverse pairs.
    }
};