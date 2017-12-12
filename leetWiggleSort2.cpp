/*

//**********************************************************324. Wiggle Sort II.*****************************************************

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.


//Time Complexity: O(nlogn).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/



// Solution 1: 
// The idea is to reverse the set of elements before the mid index also the set of elements after the mid index and insert them b/w 
//- the reversed elements of the first half, such that the v[i]<v[i+1]>v[i+2] condition will be satisfied.

class Solution {
public:
    void wiggleSort(vector<int>& v){
        if(v.size()==1)
            return; 
        vector<int> u(v);
        sort(u.begin(), u.end());
        int mid;
        if(v.size()%2==0)
            mid=v.size()/2-1;
        else
            mid=v.size()/2;
        int last=v.size()-1;
        for(int i=0;i+1<v.size();i+=2){
            v[i]=u[mid];
            v[i+1]=u[last];
            mid--; last--;
        }
        if(v.size()%2!=0)
            v[v.size()-1]=u[0];
        return ;
    }
};



//Solution 2:
// This logic works for all the cases, except in the case of few elements(1-4), where index on both side of mid still remain adjacent, so-
//- if there are repeating elem. then the v[i]<v[i+1]>v[i+2] condition won't be satisfied.
 
 
class Solution {
public:
    void wiggleSort(vector<int>& v) {
        sort(v.begin(), v.end());
        int last=v.size()-1;
		int mid=ceil(float(v.size()/2));
        for(int i=1;i<v.size();i+=2){
            //cout<<"mid elem. is: "<<v[mid]<<endl;
            int num=v[mid];											//Pushing the values close to mid index one after another to in -
            v.erase(v.begin()+mid);									//- between the begin elements. 
            v.insert(v.begin()+i,num);								// Pushing the last elem. to the beginning also yield the same result.
            //cout<<"size at the end of iteration is: "<<v.size()<<endl;
			mid++;
        }
        return ;
    }
};