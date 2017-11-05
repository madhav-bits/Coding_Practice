/*
658. Find K Closest Elements.

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in 
ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 

// *******************************************THIS IS NOT LEET ACCEPTED CODE. BUT CAN'T UNDERSTAND THE REASON FOR DENIAL.*****************
*/
class Solution {
public:
    int findIndex(vector<int> v, int begin, int end, int x){
        int mid=(begin+end)/2, index;
        
        if(v[mid]==x)
            return mid;
        if(begin+1==end){
            //int res=abs(v[begin-1]-x)<abs(v[begin]-x)?(begin-1):begin;
            //res=abs(v[begin+1]-x)<abs(v[res]-x)?(begin+1):res;
            return begin;
        }
        if(v[mid]<x)
            index=findIndex(v,mid+1, end,x);
        else
            index=findIndex(v,begin, mid-1,x);
        return index;
    }
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int begin,end=v.size()-1;
        
        int mid=findIndex(v,begin, end,x);
        //cout<<"Index is: "<<mid<< " and the value is: "<< v[mid]<<endl;
        int count=0;
        int start=mid,close=mid+1;
        while(count<k){
            if(abs(v[start]-x)<=abs(v[close]-x) && start>=begin && close<=(end-1)){
                //cout<<"new count is: "<<count+1<<" with new induct: "<< v[start]<<endl;
                start--;
            }
            else if(abs(v[start]-x)>abs(v[close]-x) && close<=(end-1) && start>=begin){
                //cout<<"new count is: "<<count+1<<" with new induct: "<< v[close]<<endl;
                close++;
            }
            
            else if(close>=end)
                start--;
            else if(start<begin)
                close++;
            count++;
        }
        
        cout<<"start is: "<<v[start]<<" end is: "<<v[close]<<endl;
        //vector<int> u;
        for(int i=start+1;i<close;i++){
            cout<<v[i]<<endl;//u.push_back(v[i]);//int d=v[i];
        }
            
        
        return vector<int>(v.begin() + start + 1, v.begin() + close);
    }
};