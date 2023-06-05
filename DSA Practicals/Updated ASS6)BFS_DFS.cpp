#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class Graph
{
public:
	unordered_map<int,list<int>> adj;
	bool direction;
	int n, e;
	Graph(int n, int e, bool direction)
	{
		this->n = n;
		this->e = e;
		this->direction = direction;
	}

	//Adjacency matrix
	void addEdges(int u, int v)
	{
		adj[u].push_back(v);

		if(direction == 0)
		{
			adj[v].push_back(u);
		}
	}

	void printAdj()
	{
		for(auto i : adj)
		{
			cout<<i.first<<" -> ";
			int count = 0;

			for(auto j : i.second)
			{
				cout<<j;
				if(++count < i.second.size())
				{
					cout<<"- ";
				}
			}
			cout<<endl;
		}
	}

	void dfs(int start)
	{

		stack<int> stk;
		vector<bool> visited(n,false);

		stk.push(start);
		visited[start] = true;

		while(!stk.empty())
		{
			int u = stk.top();
			cout<<u<<" ";
			stk.pop();

			for(auto i : adj[u])
			{
				if(!visited[i])
				{
					visited[i] = true;
					stk.push(i);
				}
			}
		}
	}
	

	void BFS(int s)
	{
		vector<bool> visited(n,false);
		queue<int> q;

		q.push(s);
		visited[s] = true;

		while(!q.empty())
		{
			s = q.front();
			cout<<s<<" ";

			q.pop();

			for(auto i : adj[s])
			{
				if(!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}

	}
};

int main()
{
	int n, e;
	int u,v;
	bool direction;
	
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter number of edges : ";
	cin>>e;

	cout<<"Enter 1->Directed Graph and 0->Undirected Graph :";
	cin>>direction;

	Graph g1(n,e,direction);

	cout<<"Enter edges : "<<endl;
	for(int i = 0; i < e; i++)
	{
		cin>>u>>v;
		g1.addEdges(u,v);
	}

	g1.printAdj();

	cout<<"DFS traversal sequence : ";
	g1.dfs(1);

	cout<<"BFS traversal sequence : ";
	g1.BFS(1);

	return 0;
}
