/*
*
//**************************************************1580. Put Boxes Into the Warehouse II.**********************************************

https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



// Worked on testcases provided with the question.
[1,2,2,3,4]
[3,4,1,2]
[3,5,5,2]
[2,1,3,4,5]
[1,2,3]
[1,2,3,4]
[4,5,6]
[3,3,3,3,3]





// Time Complexity: O(nlogn+mlogm).  										// n-length of boxes, m-length of warehouse array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogm).											// n-length of boxes, m-length of warehouse array.
// Space Complexity: O(m).	
// This algorithm iterates the array, at each step finds the greater following value, also makes sure that duplicates are avoided. Thus includes
// a greater following value and calls the func. to find further greater following values. Thus ,we get increasing subsequences(include only
// whose length is >= 2).








class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int>maxAllowed(warehouse.size(),0);							// Stores max allowed box size in each index.
        int leftMin=INT_MAX, rightMin=INT_MAX;
        for(int i=0;i<warehouse.size();i++){						// Do a left iterate and right iterate to find max in each index.
            leftMin=min(leftMin, warehouse[i]);
            maxAllowed[i]=leftMin;
        }
        for(int i=warehouse.size()-1;i>=0;i--){
            rightMin=min(rightMin, warehouse[i]);
            maxAllowed[i]=max(maxAllowed[i], rightMin);
        }
        int res=0, rem=0;
        sort(boxes.begin(), boxes.end());									// Sort the boxes and max allowed array.
        sort(maxAllowed.begin(), maxAllowed.end());
        // for(auto num:boxes)
        //     cout<<"box: "<<num<<endl;
        // for(auto num:maxAllowed)
        //     cout<<"maxAllowed: "<<num<<endl;
        int i=boxes.size()-1;
        int j=maxAllowed.size()-1;
        while(i>=0 && j>=0){												// Until both boxes or warehouse index remains.
            if(maxAllowed[j]>=boxes[i]){									// If curr. spot is greater size than box size.
                rem++;
                j--;
            }else{															// If curr. box size is smaller than curr. spot.
                if(rem>0){													// If any spots of greater size are left.
                    res++;
                    rem--;
                }
                i--;
            }
        }
        res+=min(rem, i+1);													// If any boxes and spots in warehouse remains.
        return res;															// Total warehouse spots filled.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).											// n-length of boxes, m-length of warehouse array.
// Space Complexity: O(1).	
// This solution is Sorting/Greedy and Observation based. Here, since filling a huge box requires all the spots along the way to it's final
// spot to be greater than it. We try to fill the huge values first in dec. order. Sort the boxes array. Take two ptrs on both ends
// place the curr. box in one of them if their size is greater and move to next spot, if the box is greater than both ends, then it 
// can't be fit into warehouse, so we move to the next smaller box. In this way greedily we pick the spots and assign the boxes there.

// This requires lot of inituition and took quite some time to understand it.








class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int res=0;
        int i=0, j=warehouse.size()-1, k=boxes.size()-1;
        sort(boxes.begin(), boxes.end());									// Sort the boxes based on sizes.
        while(i<=j && k>=0){												// Until boxes and spots are available.
            if(warehouse[i]>=boxes[k]){										// If curr. spot is greater than curr. box.
                res++;
                i++;
            } 
            else if(warehouse[j]>=boxes[k]){								// If curr. spot is greater than curr. box.
                res++;
                j--;
            } 
            k--;															// Moving to next smaller box.
        }
        return res;															// Returning the warehouse spots filled.
    }
};
