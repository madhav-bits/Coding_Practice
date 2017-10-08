#include<iostream>
#include<cstring>

using namespace std;

//Insertion Sort Algorithm.

// Picking an element from the array in a sequence, and comparing it with the elements prior to it 
//and swapping with them till it's proper position.  

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int main(){
    int arr[]={3,2,7,23,11,56,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<size;i++){
        int k=i;
        for(int j=i-1;j>=0;j--){
        if(arr[j]>arr[k]){
            swap(&arr[j],&arr[k]);
            k--;
            }
        }
    }
    cout<<"Hi"<<endl;
    
    for(int a=0;a<size;a++)
        cout<<arr[a]<<endl;
}
