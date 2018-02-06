/*
*
//**************************************************************31. Next Permutation.******************************************************

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

//These are the examples I had created, tweaked and worked on.
[]
[3,2,1,0,1,2,3]
[1,4,2,6,9,8,5,4,1]
[1,4,2,9,9,8,5,4,1]
[4,3,2,1]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm first finds the first digit at index-"i" > previous index digit. Then sort all elements from that index till end. Later 
//in the sorted part find the first digit> elem. at index-"i-1" and swap both the next permutation. In case the given is the last permu. possible
// Then swap all elements to get the first permutation of digits.



class Solution {
public:
    void nextPermutation(vector<int>& v) {
        if(v.size()==0) return ;
        int i;
        for(i=v.size()-1; i>0;i--){								// Finding the first occurance of digit which is > previous index's digit.
            if(v[i]>v[i-1])
                break;
        }
        if(i==0){
            for(int j=0,k=v.size()-1;j<k;j++,k--)				// If the given is the last permu. then swap elem. to get first permu.
                swap(v[j],v[k]);
            return ;
        }
            
        else{
            //for(int j=i, k=v.size()-1;j<k;j++, k--){				//Sort elements from index-"i" to v.size().
            //    swap(v[j],v[k]);
            //}
            sort(v.begin()+i,v.end());								//Sort elements from index-"i" to v.size().
            int a;
            for(a=i;a<v.size();a++){								//Finding the first digit > elem. at index at "i-1". Then swap them.
                if(v[a]>v[i-1])
                    break;
            }
            swap(v[a], v[i-1]);
        }
    }
};