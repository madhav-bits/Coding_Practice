#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Rotate a given array. This algo uses shifts to left all the elements by 1 place, number of times as requested in the question.
**This can also be done by copying all the elements to be shifted in an temp array, shift all the else elements of the aray leftwise and copy the temp array elements to the main array.
*/

vector<int> rotateArray(vector<int> v, int target){
  int size= v.size();
  for(int i=0;i<target;i++){
    int temp;
    temp=v[0];
    for(int j=0;j<v.size()-1;j++)
      v[j]=v[j+1];
    v[v.size()-1]=temp;
  }
  return v;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1,4,7,9,11,14,17,21};// These are stock values for a certain days.
    vector<int> v,w;
    int target=2;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    w=rotateArray(v,target);
    for(int i=0;i<v.size();i++)
      cout<<w[i]<<endl;
    return 0;
}