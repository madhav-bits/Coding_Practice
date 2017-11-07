/*
//*******************************************************153. Find Minimum in Rotated Sorted Array.*******************************
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

//**********************************************************THIS IS LEET ACCEPTED CODE.******************************************
*/
class Solution {
public:
    int findMin(vector<int>& v) {
        int begin=0, end=v.size()-1, mid;
        
        while(begin<end){
            mid=(begin+end)/2;
            //cout<<"begin is: "<<v[begin]<<" and end is: "<<v[end]<<endl;
            if(v[begin]<=v[mid] && v[end]<v[begin])// Covers all the cases when min is in the second half.
                begin=mid+1;
            else
                end=mid;
        }
        //cout<<"The min. elem is: "<<v[begin]<<endl;
        return v[begin];
    }
};



//****************************Solution 2: Focusing on pushing the problem into left-half sub problem.*****************************

class Solution {
public:
    int findMin(vector<int>& v) {
        int begin=0, end=v.size()-1, mid;
        
        while(begin<end){
            mid=(begin+end)/2;
            cout<<"begin is: "<<v[begin]<<" and end is: "<<v[end]<<endl;
            if(v[begin]<=v[mid] && v[end]>v[begin] || v[begin]>v[mid] && v[end]<v[begin] || v[mid]<= v[begin] && v[mid]< v[end])
                end=mid;//Covers all the cases, when the min is present in the first half.
            else
                begin=mid+1;
        }
        //cout<<"The min. elem is: "<<v[begin]<<endl;
        return v[begin];
    }
}; 