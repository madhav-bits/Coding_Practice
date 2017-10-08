#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

vector<int> maxSubArray(vector<int> v){
    int i, j,max, MAX_so_far;
    i=0;j=0;max=0;MAX_so_far=0;
    for(int k=0;k<v.size();k++){
        
        if(v[k]>=max+v[k]){
            i=k;
            j=k;
            max=v[k];
            MAX_so_far=max;
            //cout<<"Currnet element is: "<<v[k]<<" Newwwwwwwwwwwwww max is: "<<max<< " j is: "<<i<<endl;
        }
        else{
            max+=v[k];
            if(MAX_so_far<max){
                j=k;
                MAX_so_far=max;
            }
            //cout<<"Currnet element is: "<<v[k]<<" max is: "<<max<<" J is: "<<j<<endl;
        }
    }
    int arr[3]={0};
    vector<int> p;
    //cout<<"The final value if i is: "<<j<<endl;
    p.push_back(i);// If planning of returning a vector.
    p.push_back(j);
    p.push_back(MAX_so_far);
    arr[0]=i;// If planning of returning array.
    arr[1]=j;
    arr[2]=MAX_so_far;
    //cout<<"The second element is: "<<MAX_so_far<<endl;
    return p;// Here vector is returned.
}


int main(){
    vector<int> v;
    int array[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int size= sizeof(array)/sizeof(array[0]);
    for(int i=0;i<size;i++)
        v.push_back(array[i]);
    int* b;// If array is returned from the function.
    vector<int> q;
    q=maxSubArray(v);
    cout<<"The starting index of max sum is: "<<q[0]<<endl;
    cout<<"The end index of max sum is: "<<q[1]<<endl;
    cout<<"The MAX sum is: "<<q[2]<<endl;
    //cout<<"The starting index of max sum is: "<<*b<<endl;
    //cout<<"The end index of max sum is: "<<*(b+1)<<endl;
    //cout<<"The MAX sum is: "<<*(b+2)<<endl;
    //cout<<*(b+2)<<endl;
    return 0;
}