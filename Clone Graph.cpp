#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		map<int, UndirectedGraphNode*> vis;
		UndirectedGraphNode *ans=_cloneGraph(node, vis);
		return ans;
	}
	UndirectedGraphNode *_cloneGraph(UndirectedGraphNode* node, map<int, UndirectedGraphNode*> &vis)
	{
		UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label);
		vis[node->label] = tmp;
		for (int i = 0; i < node->neighbors.size(); ++i)
		{
			if (!vis[node->neighbors[i]->label])
				tmp->neighbors.push_back(_cloneGraph(node->neighbors[i], vis));
			else
				tmp->neighbors.push_back(vis[node->neighbors[i]->label]);
		}
		return tmp;
	}
};

int main()
{
	return 0;
}
