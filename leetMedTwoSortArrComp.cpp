/*
*
//*********************************************************4. Median of Two Sorted Arrays.**************************************************

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


//These are the examples I had created, tweaked and worked on.
[1,2]
[3,4]

[1]
[]

[1,2]
[0,0,1]

[1,1,2]
[1,2]


// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//************************************************************NEED TO FOLLOW UP.************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algorithm check whether diagonal elements are same or not. Appraoches the comparision row wise. Whenever diagonal elem. are not equal
// return false. If it passes the entire loop without any issues, then it returns true.


class Solution {
public:
    double findMedianSortedArrays(vector<int>& u, vector<int>& v) {
        int len=u.size()+v.size();
        //cout<<"The length is: "<<len<<endl;
        int idx1=0, idx2=0;
        int num1, num2;
        for(int i=0;i<len;i++){												//Iterates through the all the elements of the arrays.
            int temp;
            if( idx1<u.size() && idx2<v.size() && u[idx1]<v[idx2]){			//If both indices are within range and elem1<elem2 then index1 is
                temp=u[idx1];												// increased.
                idx1++;
            }
            else if(idx1<u.size() && idx2<v.size() && v[idx2]<=u[idx1]){	//If both indices are within range and elem1<elem2 then index1 is
                temp=v[idx2];												// increased.
                count++;
            }
            else if(idx1==u.size()){										//If index1 is out of range, then we keep on increasing index2 &count.
                temp=v[idx2];
                idx2++;
            }
            else {															//The rem. case is that index2 is out of range, so we keep on inc.													
                temp=u[idx1];												// index1 value and the count of overall numbers iterated.
                idx1++;
            }
            
            if(len%2!=0 && i== len/2)
                return temp;
            if(len%2==0 && i== len/2){//Value at index- half of len.
                num2=temp;
                return (double(num1)+double(num2))/2;
            }
            if(len%2==0 && (i+1) == len/2)//Value at index- (half of len)-1.
                num1=temp;
            
        }
    }
};