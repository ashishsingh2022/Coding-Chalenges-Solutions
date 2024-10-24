#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
	private:
		vector<int>parent;
		vector<int>rank;

	public:
		DisjointSet(int n) {
			parent.resize(n);
			rank.resize(n);
			int i;
			for(i = 0; i < n; i++)
			{
			    parent[i] = i;
			    rank[i] = 1;
			}
		}
		int findParent(int i)
		{
			if(parent[i] == i) return i;
			parent[i] = findParent(parent[i]);
			return parent[i];
		}
		bool doUnion(int i, int j) {
			int pi = findParent(i);
			int pj = findParent(j);
			if(pi == pj) return false;
			if(rank[pi] >= rank[pj])
			{
				parent[pi] = pj;
				rank[pi] += rank[pj];
			} else {
				parent[pj] = pi;
				rank[pj] += rank[pi];
			}
			return true;
		}
};