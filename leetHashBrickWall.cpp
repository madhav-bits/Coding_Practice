/*
There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height
 but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row
 from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line
 to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

**************************************** THIS IS LEET ACCEPTED CODE.************************************************
*/


class Solution {
public:
    int leastBricks(vector<vector<int>>& v) {
        int rows=v.size();
        map<long long int, long long int> m;
        map<long long int, long long int>::iterator it;
        vector<vector<int>> u;
        u=v;
        cout<<v[0].size()<<endl;
        int max=0;
        int d;
        for(int i=0;i<v[0].size();i++)
            max+=v[0][i];
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(j>=1)
                    v[i][j]=v[i][j]+v[i][j-1];
                if(m.find(v[i][j])!=m.end())
                    m[v[i][j]]+=1;
                else
                    m[v[i][j]]=1;
            }
            int count=0;
            
            for(it=m.begin();it!=m.end();it++){
                if(it->second>count && it->first != max)
                    count=it->second;
            }
            //cout<<"Length of wall is: "<<max<<endl;
            //cout<<"COunt is: "<<count<<endl;
            d=v.size()-count;
        }
        return d;
    }
};