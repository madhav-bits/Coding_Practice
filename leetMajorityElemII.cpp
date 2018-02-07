/*
*
//**************************************************************229. Majority Element II.******************************************************

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear 
time and in O(1) space.

//These are the examples I had created, tweaked and worked on.
[2,3,2,4,2,5,2,6,7,2,2]
[2,3,4,5,3,2,6,4,2,4,5,6,4,2,2,2]
[1,2,2,3,2,1,1,3]
[1,2,3,1,3]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************USING BOYER-MOORE ALGORITHM.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This is Boyer- Moore Algorithm explained in this link: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html . We might have
// elem. with n/3 elem. In order for an elem.not to be a majority elem. there has to two other non equal elem. Of them one is saved as co-majority
// elem., if an elem. not equal to both temp major. elem. is encountered them count of both temp majo. is dec. by one. For each of them the other 
// temp majo. and the curr. scanning non equal index value vote against. The final remaining two elem. might be majority elem. Which can be 
// confirmed in the second iteration.


class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        if(v.size()<2) return v;							// If size<2, the elem. themselves would be answer, they occur once > (2/3)=(0).
        vector<int>u;
       int elem1=0,elem2=0, count1=0, count2=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==elem1)									// If same. elem. is encountered then count inc.
                count1++;
            else if(v[i]==elem2)							// If same. elem. is encountered then count inc.
                count2++;
            else if(count1==0){								// If count1=0, new elem. is attached.
                elem1=v[i];
                count1++;
            }
            else if(count2==0){								// If count2=0, new elem. is attached.
                elem2=v[i];
                count2++;
            }
            else{											//If non equal elem. is encountered then count of both temp majo. is dec.
                count1--; 							// For each of temp majo., the other temp. majo. elem. and this non-equal elem. vote against.
                count2--;
            }
            //cout<<"Index: "<<i<<" Elem1 is: "<<elem1<<" and Elem2 is: "<<elem2<<" count1: "<<count1<<" and count2: "<<count2<<endl;
        }
        //cout<<"Elem1 is: "<<elem1<<" and Elem2 is: "<<elem2<<endl;
        count1=0; count2=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==elem1)								//Counting occurances of two temp. majo. elem.
                count1++;
            else if(v[i]==elem2)
                count2++;
        }
        if(count1>v.size()/3)							// If the count>n/3, then push into result vector.
            u.push_back(elem1);
        if(count2>v.size()/3)
            u.push_back(elem2);
        return u;										//Returning the vector containing the answers.
    }
};