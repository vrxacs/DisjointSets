#include <iostream>
#include "DisjointSet.h"

using std::cout;
using std::endl;

void print(vector<int> v);

int main(){

	DisjointSet<int> i = DisjointSet<int>(1);

	for(int k = 0; k < 9; ++k){
		DisjointSet<int> j = DisjointSet<int>(k+2);
		i.unionSets(j);

	}

	cout << i.getMarker() << endl;

	DisjointSet<int> f = DisjointSet<int>(13);
	f.unionSets(i);

	cout << f.getMarker() << endl;


	return 0;
}

