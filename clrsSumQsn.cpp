#include<iostream>
#include<cstdlib>
#include<map>


using namespace std;


//To find whether there exists numbers whose sum is equal to the given number. CLRS Question.
//In this it takes extra memory, going through array once again, and searching for(6-integer) key in the map,
// which takes logn time, as a whole it is O(logn).

// Another method is to sort the array, then iterate through array once again,
// binary searching for the (6-integer) in the array, thus making it (nlogn+nlogn) calc. and O(logn)complexity.

int main(){
    cout<<"Hi"<<endl;
    int num_expected;
    cout<<"What's the desired sum looking for."<<endl;
    cin>>num_expected;
    map<int, int> m;
    int array[]={3,2,9,4,1,12,57,64,65};
    int size= sizeof(array)/ sizeof(array[0]);
    for(int i=0;i<size;i++)
        m[array[i]]=(i+1);
    map<int, int>::iterator it;
    it=m.find(112);
    cout<<it->first<<endl;
    for(int i=0;i<size;i++){
        it=m.find(num_expected-array[i]);
        if(it->second!=0){
            cout<<"Combination found"<<endl;
            cout<<"First element index is: "<<i<<endl;
            cout<<"Second element index is: "<<it->second-1<<endl;
            break;
        }
        if(i== (size-1))
            cout<<"No Combinatin found summing upto the number found in this array."<<endl;
    }
    return 0;
}
