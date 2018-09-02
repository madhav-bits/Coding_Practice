/*
*
//**********************************************************605. Can Place Flowers.***************************************************

Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent 
plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new 
flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,0,0,0,1,0,0,0,1,0,0,0]
4


[1,1,1,1]
0


[0]
0


[0]
1


[0,0,0,0]
2




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. There are quite a few corner cases to work on. First case is to handle zeroes in the beginning of the 
// array. We get their count, add their contribution to the final count of new flowers placable. If we reach end of flowerbed without seeing any
// flowers, then odd #vacancies contribute count/2+1, even contribute count/2 in both the cases, whethere we reach end or not? We start iterating 
// from the first flower in the for loop. Here, the seq. count contributes count/2, in case of odd vacancies, count/2-1, in case of even vacancies.
// If there is a seq. of empty slots after the last flower, they contribute count/2 to the total count. At the end of iteration, we check 
// whether the new flowers placable are greater than target flowers or not?









class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int target) {
        int place=0,count=0;												// Tracks #placable flowers, len of seq. of empty slots.
        int i=0;															// Init. the iterator.
        while(i<v.size() && v[i]==0){										// Until first flower is reached.
            count++;														// Inc. the count of empty slots.
            i++;
        }
        if(i==v.size() && count%2==1) return (((count/2)+1)>=target);		// If we reach end of flowerbed, then odd contribute count/2+1.
        place+=(count/2);													// Cases with even count, odd count without reaching end of flowerbed.
        count=0;															// Resetting count=0.
        for(;i<v.size();i++){
            if(v[i]==0) count++;											// Inc. the count of len of seq. of empty slots.
            else{															// If flower encountered.
                // cout<<"The count is: "<<count<<endl;
                if(count==0) continue;										// If count=0, skip adding to final count.
                else if(count%2==0) place+=(count/2)-1;						// If even count obtained, then inc. by count/2-1.
                else if(count%2==1) place+=(count/2);						// If odd count obtained, then inc. by count/2.
                count=0;													// Resetting the count to zero.
            }	
        }
        place+=(count/2);													// Add contribution of seq. of empty slots after final flower.
        // cout<<"The final count is: "<<count<<endl;
        // cout<<"place: "<<place<<endl;
        return (place>=target);												// Check if new placable flowers are >= target or not?
    }
};