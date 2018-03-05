/*
*
//******************************************************743. Network Delay Time.***********************************************

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is 
the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]


"aaraxrafafaodifjafibbbbiiraxbxbjit"
"rabbit"


"abcd"
"abcbadefged"

[[2,1,1],[2,3,1],[3,4,2],[1,4,1]]
4
2




// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n*n).	
// This algorithm is Bellman Ford Algorithm. Can also be done using Dijkstra's Algorithm to find shortest paths to all nodes in graph, return 
// the max. dist of them. If a node is not reachable, then return "-1" else return max. dist.


// I tried to implement using Dijkstra's Algo. but missed on implemeting the priority queue part. Will read concepts once again, and do this 
// problem once again using Dijkstra's Algo.







class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1, INT_MAX);
        dist[K]=0;
        for(int i=1;i<=N;i++){
            for(vector<int> node:times){
                int curr=node[0], adj=node[1], edge=node[2];
                if(dist[curr]!=INT_MAX && dist[adj]>dist[curr]+edge) dist[adj]=dist[curr]+edge; 
            }
        }
        int max_dist=0;
        for(int i=1;i<=N;i++)
            max_dist=max(max_dist, dist[i]);
        return (max_dist==INT_MAX)?-1:max_dist;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n*n).	
// This is Dijkstra's algo. need to implement properly.
// This algorithm is Dijkstra's Algo.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int>> v(N+1), dist(N+1);
        vector<int> dist2(N+1, INT_MAX);
        map<int, int>m,n;
        int time=INT_MIN;
        queue<int>q;
        sort(times.begin(), times.end(),[=](const vector<int> a, const vector<int> b){
            return a[2]<b[2];
        });
        
        dist2[K]=0;
        for(int i=1;i<=N;i++) m[i]=1;
        for(int i=0;i<times.size();i++){
            v[times[i][0]].push_back(times[i][1]);
            dist[times[i][0]].push_back(times[i][2]);
        }
        
        int curr=K;
        int a=1;
        for(int i=0;i<v[curr].size();i++){
            //cout<<"Inside the first for loop with iter. is: "<<i<<endl;
            m.erase(curr);
            if(m.count(v[curr][i])==1){
                dist2[v[curr][i]]=min(dist2[v[curr][i]],dist[curr][i]);
                q.push(v[curr][i]);
                //dist2[v[curr][i]]=dist[curr][i];
                //m.erase(v[curr][i]);
            }
        }
        
        while(!q.empty()){
            //cout<<"Inside the second for loop with iter. is: "<<q.front()<<endl;
            curr=q.front();
            //cout<<"Adjacent size of curr: "<<curr<<" is: "<<v[curr].size()<<endl;
            m.erase(curr);
            for(int i=0;i<v[curr].size();i++){
                if(m.count(v[curr][i])==1){
                    dist2[v[curr][i]]=min(dist2[v[curr][i]],(dist2[curr]+dist[curr][i]));
                    cout<<"New dist of index: "<<v[curr][i]<<" is: "<<dist2[v[curr][i]]<<endl;
                    q.push(v[curr][i]);
                    //dist2[v[curr][i]]=dist[curr][i];
                    //m.erase(v[curr][i]);
                }
            }
            q.pop();
        }
        for(int i=1;i<dist2.size();i++){
            //cout<<"Dist of node i:"<<i<<" is: "<<dist2[i]<<endl;
            time=max(time,dist2[i]);
        }
        if(time== INT_MAX) return -1;
        else
            return time;
            //cout<<"Max time is: "<<time<<endl;
        
    }
};