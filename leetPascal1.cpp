#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Given numRows, generate the first numRows of Pascal's triangle.
*/

void pascalDsgn(int rows){
    int arr[rows][(2*rows)];
    for(int i=0;i<rows;i++){
      for(int j=0;j<(2*rows);j++)
        arr[i][j]=0;  
    }
    arr[0][rows-1]=1;
    for(int i=0;i<rows;i++)// Setting indent for the first row.
      cout<<"\t";
    cout<<arr[0][rows-1]<<endl;
    int a;// Acts as indent measure for each row.
    
    for(int i=1;i<rows;i++){
      for(int j=rows-1-i;j<=rows-1+i;j+=2){
        a=rows-1-i;
        for(int b=0;b<=a;b++)// Setting indent for each row.
          cout<<"\t";
        arr[i][j]=arr[i-1][j-1]+ arr[i-1][j+1];
        cout<<arr[i][j]<<"\t";
      }
      cout<<endl;
    }
    return ;
}


int main(){
    cout<<"Give the number of rows of Pascal Triangle."<<endl;
    int rows;
    cin>>rows;
    pascalDsgn(rows);
    return 0;
}