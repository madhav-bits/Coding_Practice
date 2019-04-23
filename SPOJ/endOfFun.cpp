/*

//****************************************************DCEPC12E - End of Fun.********************************************************
https://www.spoj.com/problems/DCEPC12E/




Time Complexity:O(n^3).                                                     // O(n) for each query.                                                                                                                                                                           
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^3).                                                  // O(n) for each query.                                     
// Space Complexity:O(n).                                                   
// This is Observaion based solution. Here, we first calculate the sum of matrix product in the first step. Our solution depends on
// observation that all elem. which belongs to a colmn. interacts with all elem. with row number equalling colmn. number. So, whenever
// we get a change in first matrix, we get it's col number, since that index interacts with it's col valued row number elem. form other
// matrix, we pre-calculate the sum of each row elem. elements from other row.

// Same logic applied to each index of second matrix, each index in second matrix, interacts with all elem. from col. numbered equal
// to index's row number. So, we calculate each col's elements from first matrix.

// For every change in value, we multiply diff with sum of elem. of it's interacting row/col from other matrix and add the product to
// total sum. We also change the cumulative row/col sum accordingly and also update the index accordingly.







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;



long long int multiply(vector<vector<long long int>>u, vector<vector<long long int>>&v){
    long long int res=0;
    for(int i=0;i<u.size();i++){
        for(int k=0;k<u.size();k++){
            long long int sum=0;
            for(int j=0;j<u.size();j++){
                sum+=u[i][j]*v[j][k];
            }
            // cout<<"sum: "<<sum<<endl;
            res+=sum;
        }
    }
    return res;
}







int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int queries, dims;
    cin>>dims;
    vector<vector<long long int>>u(dims, vector<long long int>(dims,0));
    vector<long long int>cols(dims,0);
    vector<vector<long long int>>v(dims, vector<long long int>(dims,0));
    vector<long long int>rows(dims,0);
    for(int i=0;i<dims;i++){
        for(int j=0;j<dims;j++){
            cin>>u[i][j];
            cols[j]+=u[i][j];
        }
    }

    for(int i=0;i<dims;i++){
        for(int j=0;j<dims;j++){
            cin>>v[i][j];
            rows[i]+=v[i][j];
        }
    }
    long long int total=multiply(u,v);
    // cout<<"total"<<total<<endl;
    cin>>queries;
    char ch;
    long long int row, col, val;
    for(int b=1;b<=queries;b++){
        cin>>ch>>row>>col>>val;
        if(ch=='A'){
            long long int diff=val-u[row][col];
            total+=diff*rows[col];
            cols[col]+=diff;
            u[row][col]=val;
        }else{
            long long int diff=val-v[row][col];
            total+=diff*cols[row];
            rows[row]+=diff;
            v[row][col]=val;
        }
        cout<<total<<endl;
    }

    return 0;
}
