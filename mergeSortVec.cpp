#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

// This code Merges two vectors. Same logic as in Merge Sort.
int main(){
	vector<int> c,d;
	c.push_back(2);
	c.push_back(77);
	c.push_back(3);
	c.push_back(4);
	
	d.push_back(12);
	d.push_back(177);
	d.push_back(23);
	d.push_back(44);
	
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	vector<int> e; int g=0, h=0;
	while(g<c.size() || h<d.size()){
		if(g<c.size() && h<d.size() && c[g]<=d[h]){// When two values are within the range indices.
			e.push_back(c[g]);
			g++;
		}
		else if(g<c.size() && h<d.size() && c[g]>d[h]){// When two values are within the range indices.
			e.push_back(d[h]);
			h++;
		}
		else if(g>=c.size()){// When one of val. is out of index range.
			e.push_back(d[h]);
			h++;
		}
		else if(h>=d.size()){// When one of val. is out of index range.
			e.push_back(c[g]);
			g++;
		}      
	}

	for(const auto& num:e)// Prints contents of the vector.
		cout<<num<<endl;
	
	return 0;
}