/*
Median of two Sorted Arrays.
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// *******************************************************HARD PROBLEM.**************************************************
//**************************************This code doesn't work for cases with repitition, still need to work on them.************
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& u, vector<int>& v) {
          int size1=u.size();
          int size2=v.size();
          float sum=0;
          float num1, num2;
          if(size1==0 && size2%2==0){
              num1=v[size2/2];
              num2=v[(size2/2)-1];
              return (num1+num2)/2;
          }
          if(size1==0 && size2%2!=0){
              return v[(size2)/2];
          }
        
          if(size2==0 && size1%2==0){
              num1=u[size1/2];
              num2=u[(size1/2)-1];
              cout<<"Num1 is: "<<size1/2<<"Num2 is: "<<num2<<endl;
              return (num1+num2)/2;
          }
          if(size2==0 && size1%2!=0){
              return u[(size1)/2];
          }
        
          if((size1+size2)%2==0){
            float index1=(size1+size2)/2;
            float index2=index1+1;
            cout<<"Index1 is: "<<index1<<" and index2 is: "<<index2<<endl;
            int j=0; int k=0;
            for(int i=0;i<u.size();i++){
              while(j<=u.size() && u[j]<=u[i] && j<i){
                cout<<"u array value is: "<<u[j]<< "u main value is: "<<u[i]<<endl;
                j++;
              }
              while(k<v.size() && v[k]<=u[i]){
                cout<<"v array value is: "<<v[k]<< "u main value is: "<<u[i]<<endl;
                k++;
              }
              if((j+k)==index1-1 || (j+k)==index2-1){
                sum+=u[i];
                cout<<"The u integer is: "<<u[i]<< " j is: "<<j<<" k is: "<< k<<endl;
                cout<<"the new sum is: "<<sum<<endl;
              }
            }
            //************************************************************************************************
            j=0; k=0;
            for(int i=0;i<v.size();i++){
              while(j<v.size() && j<u.size() && u[j]<=v[i]){
                cout<<"u array value is: "<<u[j]<< "v main value is: "<<v[i]<<endl;  
                j++;
              }
              while(k<v.size() && v[k]<=v[i] && k<i){
                cout<<"v array value is: "<<v[k]<< "v main value is: "<<v[i]<<endl;
                k++;
              }
              if((j+k)==index1-1 || (j+k)==index2-1){
                sum+=v[i];
                cout<<"The v integer is: "<<v[i]<< " j is: "<<j<<" k is: "<< k<<endl;
                cout<<"the new sum is: "<<sum<<endl;
              }
            }
            return sum/2;
          }
        //*********************************************************************************************************
        //*********************************************************************************************************
          else{
            float s1=size1; float s2=size2;
            int index1=ceil((s1+s2)/2);
            cout<<"Index1 is: "<<index1<<endl;
            int j=0; int k=0;
            for(int i=0;i<u.size();i++){
                cout<<"inside for loop"<<endl;
              while(j<u.size() && u[j]<=u[i] && j<i ){
                  cout<<"u array value is: "<<u[i]<< " v array value is: "<<v[j]<<endl;                  
                  j++;
              }
              while(k<v.size() && v[k]<=u[i]){
                k++;
              }
              if((j+k)==index1-1){
                sum+=u[i];
                cout<<"The u array integer is: "<<u[i]<< " j is: "<<j<<" k is: "<< k<<endl;
                cout<<"the new sum is: "<<sum<<endl;  
              }
            }
            //**********************************************************************************************************
            j=0; k=0;
            for(int i=0;i<v.size();i++){
                cout<<"inside for loop2"<<endl;
              while(j<v.size() && j<u.size() && u[j]<=v[i] ){
                j++;
                cout<<"u array value is: "<<u[j]<< " v array value is: "<<v[i]<<endl;
              }
                cout<<"xxxxxxxxx"<<endl;
              while(k<v.size() && v[k]<=v[i] && k<i){
                k++;
                cout<<"u arrayyy value is: "<<u[j]<< " v array value is: "<<v[i]<<endl;
              }
              if((j+k)==index1-1){
                sum+=v[i];
                cout<<"The v array integer is: "<<v[i]<< " j is: "<<j<<" k is: "<< k<<endl;
                cout<<"the new sum is: "<<sum<<endl;
              }
            }
            return sum;
          }
        
    }
};