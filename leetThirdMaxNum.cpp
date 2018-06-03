/*
*
//**********************************************************414. Third Maximum Number.***************************************************

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time 
complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,3,4,4,5,5,1]

[1,1,2]

[1]

[2,1]


[1,2,-2147483648]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Min Heap based. As, here we need Third Largest unique elem., we maintain Min heap of size 3, we replace already existing vals
// iff it's greater than min. of them. We use set to make sure that only unique elem. stay in Min Heap. In fact, we can solve the problem using
// set,but for readability I had solved using Min Heaps. At the end of iteration, if Min Heap of size=3, isn't filled, then we return the max. 
// value of max heap.






class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];												// If size<3, return max. value.
        if(nums.size()==2) return max(nums[0], nums[1]);								// If size<3, return max. value.
        priority_queue<int, vector<int> , greater<int>> pq;     						// Implem. Min Heap.
        set<int> s;																		// Makes sure uniq. elem. go into Min Heap.
        for(int i=0;i<nums.size();i++){	
            //cout<<"curr. index: "<<i<<endl;
            if(pq.size()<3 && s.count(nums[i])==0){										// If Heap not filled, push uniq. elem.
                // cout<<"Curr. pushing value: "<<nums[i]<<endl;
                pq.push(nums[i]);
                s.insert(nums[i]);
            } 
            else if(pq.size()==3 && s.count(nums[i])==0 && nums[i]>pq.top()){			// If uniq. elem. is> least val. in Heap, then push it.
                // cout<<"Curr. deleting value: "<<pq.top()<<endl;
                s.erase(pq.top());														// Remove the curr. least and insert new elem.
                pq.pop();
                // cout<<"Curr. pushing value: "<<nums[i]<<endl;
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }
        //cout<<"The answer is: "<<pq.top()<<endl;
        if(pq.size()==3) return pq.top();												// If Min Heap is of size=3, return min. value.
        int ans;
        while(!pq.empty()){																// If size<3, then return maxm. val stored in Min. Heap.
            ans=pq.top();
            pq.pop();
        }
        return ans;																		// Returning the maxm. val in Min. Heap.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is variable based, we maintain three vars to keep track of top three values in array. If after the iteration, we don't have top 3
// values, then we return maxm. value of the three values.If size=3, we return the min. of the three values.








class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];												// If size<3, we return maxm. value.
        if(nums.size()==2) return max(nums[0], nums[1]);	
        priority_queue<int, vector<int> , greater<int>> pq;     						// Implem. Min Heap.
        long max1=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;								// Tracks top 3 values.
        for(int i=0;i<nums.size();i++){													// Iteratest the entire array.
            // cout<<"Curr. index: "<<i<<" and val: "<<nums[i]<<endl;
            if(nums[i]<max3) continue;													// If curr. value<all 3 values, continue.
            if(nums[i]>max1){															// If curr. value>max1, update all vars.
                // cout<<"Curr. pushing val into max1: "<<nums[i]<<endl;
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2 && nums[i]<max1){										// If curr. val>max2 and <max1, update max2, max3.
                // cout<<"Curr. pushing val into max2: "<<nums[i]<<endl;
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i]>max3 && nums[i]<max2){										// If curr. val>max3 and <max2, update max3 var.
                // cout<<"Curr. pushing val into max3: "<<nums[i]<<endl;
                max3=nums[i];
            }
        }
        // cout<<"max3: "<<max3<<" max2: "<<max2<<" and max1: "<<max1<<endl;
        if(max3==LONG_MIN) return max1;													// If all vars, not updated, then return maxm. value.
        return max3;																	// Else return the minm. of three values.
    }
};