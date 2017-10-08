#include<iostream>
#include<cstdlib>

using namespace std;

// Merge Sort Algorithm.

void merge(int array[], int start, int mid, int last){
    int l1, l2;
    l1=mid-start+1;//Calc. length of the sub arrays to be merged.
    l2=last-mid;
    int array1[l1], array2[l2];
    for(int i=0;i<l1;i++)
        array1[i]=array[start+i];// Creating duplicates for the sub arrays for comparision.
    for(int j=0;j<l2;j++)
        array2[j]=array[mid+1+j];
    
    int index=start;
    int i=0; int j=0;
    while(index<=last){// Compares two sub arrays and merges it's elements into the main array.
        if(array1[i]<=array2[j] && i<l1 && j<l2){
            array[index]=array1[i];
            i++; index++;
        }
        else if(array1[i]>array2[j] && j<l2 && i<l1){
            array[index]=array2[j];
            j++; index++;
        }
        else if(i==l1){// Merges all it's elements into main array if the other sub array is already merged into main array.
            array[index]=array2[j];
            j++; index++;
        }
        else if(j==l2){
            array[index]=array1[i];
            i++; index++;
        }
            
    }    
}

void mergeSort(int array[], int start, int last){
    int mid;
    if(start<last){
        mid=(start+last)/2;
        //cout<<"Middd: "<<mid<<endl;
        
        mergeSort(array, start,mid);// Recursively calling the function to exponentially break down the main array.
        mergeSort(array, mid+1, last);
        merge(array, start, mid, last);// Calculating the merge function to compare the ele. of sub arrays and copy them into main array in asc. order.
    }

}


int main(){
    cout<<"Hello world"<<endl;
    int array[]={3,5,1,7,33,11};
    int size= sizeof(array)/ sizeof(array[0]);
    cout<<"xx: "<<size<<endl;
    //cout<<"mid: "<<(size-1)/2<<endl;
    int start=0;
    mergeSort(array, start, size-1);
    for(int i=0;i<size;i++)
        cout<<"ss: "<<array[i]<<endl;
    return 0;
}