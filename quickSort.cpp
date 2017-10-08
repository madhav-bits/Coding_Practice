#include <iostream>
#include<cstdlib>

using namespace std;

// Quick Sort Algorithm.
// Picking a pivot and separating the array into two parts- one with elements less then pivot and other one with elements more that pivot. Recursively
//calling the function over the two created sub blocks.

int swap(int* a , int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}

int quick(int arr[], int start, int end, int pivot){
    int marker=start;
    //cout<<"Start is: "<<start<<endl;
    //cout<<"End is: "<<end<<endl;
    //cout<<"Pivot element is: "<<arr[pivot]<<endl;
    for(int i=start;i<end;i++){
        if(arr[i]<arr[pivot]){
            swap(&arr[marker], &arr[i]);
            marker++;
        }
    }
    swap(&arr[marker], &arr[pivot]);
    return marker;
}


int quickSort(int arr[], int start, int end, int pivot){
    if (start>=end)
        return 0;
    pivot=quick(arr, start, end, pivot);
    quickSort(arr, start, pivot, pivot-1);
    quickSort(arr, pivot+1, end,end);
    return 0;
}

int main(){
    int arr[]={2,12,4,64,1,8,9,5};
    int size= sizeof(arr)/sizeof(arr[0]);
    int start;
    //cout<<"Size of the array is: "<<size<<endl;
    start=0;
    quickSort(arr, start, size-1, size-1);

    //Printing out the sorted array.
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    return 0;
}