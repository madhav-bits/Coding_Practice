#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

//This Code calculates the Median of a dynamically increasing sequence of numbers(vector) using minHeap and maxHeap, where in maxHeap we-
//- maintain the lower half of the numbers and in the minHeap we maintain the upper half of numbers. 

int main(){
	vector<int> v;
	v.push_back(7);
	v.push_back(5);
	v.push_back(-1);
	v.push_back(3);
	v.push_back(17);
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	if(v.size()>=1)									//Pushing the First element into maxHeap.
		maxHeap.push(v[0]);
	cout<<"Median is: "<<maxHeap.top()<<endl;
	
	int temp, median_temp=INT_MAX;
	for(int i=1;i<v.size();i++){
		cout<<endl<<endl<<endl;
		//cout<<"Inside for loop with index: "<<i<<" with vector val is: "<<v[i]<<endl;
		if(maxHeap.top()>=v[i]){					//The new value is bound to be in maxHeap.
			maxHeap.push(v[i]);
		else										// The new value is bound to be in minHeap.
			minHeap.push(v[i]);
		
		//cout<<"After inserting: "<<v[i]<<" minHeap top is: "<<minHeap.top()<<" and maxHeap  top is: "<<maxHeap.top()<<endl;
		cout<<"The size of minHeap is: "<<minHeap.size()<<" and the size of maxHeap is: "<<maxHeap .size()<<endl;
		cout<<endl;
		
		if(minHeap.size() > maxHeap.size()){		//If the minHeap size is more, then shifting a val. from minHeap to maxHeap, making sure-
			cout<<"minHeap size is more than maxHeap size."<<endl;// that diff. in size of elem. would be zero to 1.
			median_temp =minHeap.top();
			minHeap.pop();
			maxHeap.push(median_temp);
		}
		else if(minHeap.size() < maxHeap.size()){	// If the maxHeap size is more, then shifting a val. from maxHeap to minHeap, making sure-
			cout<<"maxHeap size is more than minHeap size."<<endl;// that diff. in size of elem. would be zero to 1.
			median_temp =maxHeap.top();
			maxHeap.pop();
			minHeap.push(median_temp);
		}
		if(minHeap.size()== maxHeap.size())			// If the size of both the heaps are equal, then median is avg of both top values.
			median_temp=(minHeap.top()+maxHeap.top())/2;// If not the shifted val. is the median value.	
		
		//cout<<"After swap inserting: "<<v[i]<<" minHeap top is: "<<minHeap.top()<<" and maxHeap  top is: "<<maxHeap.top()<<endl;
		cout<<"The size of minHeap is: "<<minHeap.size()<<" and the size of maxHeap is: "<<maxHeap .size()<<endl;
		cout<<"After inserting: "<<v[i]<<" median is: "<<median_temp<<endl;// Printing the Median value after every insertion.
		cout<<endl;
	}
	return 0;
}