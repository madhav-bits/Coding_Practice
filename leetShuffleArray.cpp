/*
*
//******************************************************384. Shuffle an Array.***********************************************

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is to get a random number from the given range of values i to len at any pt. of time. Since, C++ doesn't allow to specify range.
// I had modified to get values in the range. Don't know why it doesn't work(Might be they are not equally likely).



class Solution {
public:
    vector<int> init;
    Solution(vector<int> nums) {
        init=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {																	// Return the orig. vector.
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len= init.size();																// Useful in getting rand. from range of values.
        srand (time(NULL));
        vector<int> ans;																	// Stores final result.
        ans=init;
        for(int i=0;i<len;i++){																// Gen. a random index to swap with curr. index-"i".
            int num= rand() % (len-i);
            swap(ans[i], ans[num+i]);
        }
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
 
 
 
 
 
 // Another implementation of random, filled the array with indices and shuffled those indices in it, later obtained values from orig. vector
 // according those shuffled indices, even this is wrong. Don't know how to solve.
 
 
int len= init.size();
	srand (time(NULL));
	vector<int> ans, temp(len,0);
	//ans=init;
	for(int i=0;i<len;i++) temp[i]=i;														// Storing all indices in array and shuffle it.
	random_shuffle(temp.begin(), temp.end());
	for(int i=0;i<len;i++){
		//cout<<"Curr. index i: "<<i<<endl;
		//int num= rand() % (len-i);
		//swap(ans[i], ans[num+i]);
		temp[i]=init[temp[i]];																// Assign values based on shuffled indices.
	}
	return temp;																			// Returning the shuffled array.
	
}