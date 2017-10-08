#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

//Calculates the Longest Increasing Subsequence using Dynamic Programming. This is my code, but wont work in case of
// mltiple increasing sub sequences.

int longIncSubSeq(int arr[], int size){
	int increase[size];
    //int increase[size]={0};// Initializes an entire array with zeroes(only).
    fill(increase, increase+size,1); // A function in algorithm library, which initializes an entire array with a particular number.
    for(int i=1;i<size;i++)
        cout<<increase[i]<<endl;
        
    for(int i=1;i<size;i++){
        if(arr[i]>arr[i-1])
            increase[i]=increase[i-1]+1;
        else
            increase[i]=increase[i-1];
    }
    int large=increase[0];
    for(int i=1;i<size;i++){
        if(increase[i]>large)
            large=increase[i];
    }
    return large;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={10, 22, 9, 33, 21, 50, 41, 60};
    int size=sizeof(arr)/sizeof(arr[0]);
    int length=longIncSubSeq(arr, size);
    cout<<"Longest Increasing Sub sequence is: "<< length<<endl;
    return 0;
}



//##############################################################################################################
//##############################################################################################################
//##############################################################################################################















#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;


// This is the complete code which works without any issues( Covers all the cases).
//Calculates the Longest Increasing Subsequence using Dynamic Programming. Still yet to finalize the code.

int longIncSubSeq(int arr[], int size){
    int increase[size];
    //int increase[size]={0};// Initializes an entire array with zeroes(only).
    fill(increase, increase+size,1); // A function in algorithm library, which initializes an entire array with a particular number.
    for(int i=1;i<size;i++)
        cout<<increase[i]<<endl;
        
    for(int i=1;i<size;i++){// Calculates the numbers increase array.
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && increase[i] <= increase[j])
                increase[i]=increase[j]+1;
        }
    }
    
    int largest=increase[0];
    for(int i=1;i<size;i++){
        if(increase[i]>largest)
            largest=increase[i];
    }
    return largest;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={10, 22, 9, 20, 21, 50, 41, 60};
    int size=sizeof(arr)/sizeof(arr[0]);
    int length=longIncSubSeq(arr, size);
    cout<<"Longest Increasing Sub sequence is: "<< length<<endl;
    return 0;
}