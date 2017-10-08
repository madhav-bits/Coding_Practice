#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

// To remove the duplicates in a array.

int main(){
    vector<int> v;
    int array[]={3,5,1,6,3,6,2,5};
    int size= sizeof(array)/sizeof(array[0]);
    for(int i=0;i<size;i++)
        v.push_back(array[i]);
    //cout<<v[3]<<endl;
    vector<int>::iterator it, it1;
    for(it=v.begin(); it!=v.end();++it){
        int c=*it;
        //cout<<*it<<endl;
        //cout<<"xx: "<<*(it+3)<<endl;
        for(it1=it+1;it1!=v.end();++it1){
            if(c==*it1){
                cout<<"xxxxxx: "<<*(it)<<endl;
                cout<<"yy: "<<*(it1)<<endl;
                v.erase(it1);
            }
        }
    }
    cout<<"New Length is: "<<v.size()<<endl;
    return 0;
}