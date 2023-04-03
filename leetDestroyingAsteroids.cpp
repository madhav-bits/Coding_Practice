/*
*
//******************************************************2126. Destroying Asteroids.******************************************************

https://leetcode.com/problems/destroying-asteroids/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10
[3,9,19,5,21]
5
[4,9,23,4]
10
[4,3,2,19]



// Time Complexity: O(n+m).																				// n-#asteroids, m-#maxm. value of asteroid size.
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).																				// n-#asteroids, m-#maxm. value of asteroid size.
// Space Complexity: O(m).	
// This algorithm is Greedy + Counting Sort based. Here, as the planet gets destroyed if it encounters greater mass asteroid, we greedily encounter all smaller mass asteroids in inc. order to gain as much mass as possible before 
// moving to greater masses, thus we are ensuring that the plantet wont get destroyed in a best possible way.







class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        int maxm=*max_element(arr.begin(), arr.end());
        vector<int>occur(maxm+1,0);																		// Creating an array for max. asteroid size to track #asteroids of each size and also sort them along the way.							
        for(int&num:arr) occur[num]++;
        long long int curr=mass;
        for(int i=0;i<occur.size();i++) {																// Iter. over all asteroids sizes.
            for(int j=0;j<occur[i];j++) {																// Iter. over all asteroids of curr. size.
                if(curr<i) return false;																// If curr. planet size is less than asteroid size, it gets destroyed.
                curr+=i;																				// As planet has the greater size, asteroids mass gets added to it.
            }
        }
        return true;																					// Returning that planet survives.
    }
};

