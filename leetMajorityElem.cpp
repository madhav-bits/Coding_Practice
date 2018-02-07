/*
*
//**************************************************************169. Majority Element.******************************************************

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

//These are the examples I had created, tweaked and worked on.
[10,2,9,2,8,2,7,2,6,2,2]
[2,3,2,4,2,5,2,6,7,2,2]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************USING BOYER-MOORE ALGORITHM.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This is Boyer- Moore Algorithm explained in this link: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html , where
// unequal elements cancel out each other the last remaining elem. might be the majority(occure.> n/2). In the second iteration, we check it's 
// no of occurences. If it's >n/2, then we return the value. As, in this qsn. its guaranteed that there will be a majority elem. no need of 
// second loop.



class Solution {
public:
    int majorityElement(vector<int>& v) {
        int count=0, elem=0;
        for(int i=0;i<v.size();i++){
            if(count==0)
                elem=v[i];											// Updating the majority elem. at that point of time(index).
            if(elem==v[i])											// If elem. repeats, then inc. it's count.
                count++;	
            else													// Unequal elem. cancelling out each other's count.										
                count--;
        }
        /*															//This commented not required, as max. elem. is guaranteed in this qsn.
        count=0;
        cout<<"Elem is: "<<elem<<endl;
        for(int i=0;i<v.size();i++){								// Checks whether the extracted elem. occurs >n/2 times or not.
            if(v[i]==elem)
                count++;
        }
        */
        //cout<<"Count is: "<<count<<endl;
        return elem;												//Returning the majority element.
    }
};