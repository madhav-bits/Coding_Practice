/*
*
//******************************************************744. Find Smallest Letter Greater Than Target.***********************************************

Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element 
in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



    
["a","c","f","j","z"]
"l"

["a","b","z"]
"a"



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// THIS ALGORITHM ASSUMES THAT ARRAY IS NOT SORRTED.
// This algorithm is iteration based. We go through all iteraions and calc. distance b/w curr. index and target, and saves the minm. of the dist.
// At the end of iteration, return the char. with minm. dist. from target.







class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        int res=target-65;														// Conv. chars to values starting from 0.
		int index;																// Stores the result.
        int minm=INT_MAX;														// Tracks min. dist.
        for(int i=0;i<v.size();i++){											// Iterates the entire array.
            int curr=v[i]-65;													// Conv. the curr. char to values starting from 0.
            if(curr==res) continue;												// As, we need to get values>target.
            else if(curr>res){													// If curr. char is>target.
                if(curr-res<minm){												// Tries to update the minm value.
                    minm=curr-res;
                    index=i;													// Updates the index value.
                }
            }
            else{																// If the curr. char is<target.
                if(26-res+1+curr<minm){											// We need to calc. the round distance.
                    minm=26-res+1+curr;
                    index=i;
                }
            }
        }
        
        // cout<<"The result is: "<<v[index]<<endl;
        return v[index];														// Returning the result char.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We go through all indices, the instant we found a char>target, that's the answer, as the array is sorted.
// If we didn't find any such char. It's that all chars are <target, then the first char is the closest char to target.So, we return it.





class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        for(int i=0;i<v.size();i++){										// Iterates through the array.
            if(v[i]>target)													// Finding a char>target.
                return v[i];
        }
        return v[0];														// If there is no char>target.
    }
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. We iterate until start<end, we check middle index, if it's >target, then first char. >target might be in
// first half. If the mid char<=target, then first char>target might be in second half. If the last narrowed index has char==target, return first
// char in array, as that's closest to given char if rounding is considered, else return that narrowed down char.





class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        int start=0, close=v.size()-1;									// Setting the iterator values.
        int mid;														// Declaring the mid value var.
        while(start<close){
            // cout<<"Inside the while with start: "<<start<<" and close: "<<close<<endl;
            mid=start+(close-start)/2;									// Calc. the mid value.
            if(v[mid]>target)											// If mid char>target, then first char>target might in first half.
                close=mid;	
            else														// If mid char<=target, then first char. >target might be in second half.
                start=mid+1;
        }
        // cout<<"Outside the while with start: "<<start<<" and close: "<<close<<endl;
        if(v[start]>target)												// If the narrowed index's char>target, return it.
            return v[start];
        else return v[0];												// If narrowed index's char==target, return first char in array.
    }
};