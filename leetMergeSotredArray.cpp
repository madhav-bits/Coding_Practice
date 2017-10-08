#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Question: 
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 The number of elements initialized in nums1 and nums2 are m and n respectively.

 // This problems calculates the bigger sorted array which is combination of two sorted arrays.
// It uses an extra space of m+n but has only m+n compares. Same as merged sort.
*/


vector<int> mixArray(vector<int> u, vector<int> v){
    int psn1, psn2, size1, size2;
    size1= u.size();
    size2= v.size();
    vector<int> w;
    int j=0;int k=0;
    for(int i=0;i<size1+size2;i++){
      if(u[j]< v[k] && j<size1 && k< size2){
        w.push_back(u[j]);
        j++;
      }
      else if(u[j]> v[k] && j<size1 && k< size2){
        w.push_back(v[k]);
        k++;
      }
      else if(j<size1 && k>=size2){
        w.push_back(u[j]);
        j++;
      }
      else{
        w.push_back(v[k]);
        k++;
      }
    }
    return w;
}


int main(){
    vector<int> u,v, w;
    int array1[]={1,4,7,9,11,14,17,21};
    int array2[]={12,16,22,27,29,30,33,34};
    int size1= sizeof(array1)/sizeof(array1[0]);
    int size2= sizeof(array2)/sizeof(array2[0]);
    for(int i=0;i<size1;i++)
        u.push_back(array1[i]);
    for(int i=0;i<size2;i++)
        v.push_back(array2[i]);
    w=mixArray(u,v);
    for(int i=0;i<w.size();i++)
        cout<<w[i]<<endl;
    //cout<<"Median of the mixed array is: "<<med<<endl;
    return 0;
}