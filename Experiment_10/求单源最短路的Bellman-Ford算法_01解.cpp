/** 该解法的图存储为邻接表实现 */
/** 该解法的邻接表为数组实现 */ 

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

int n, m;

vc<vc<pair<int, int>>> a;
vc<int> dist;

bool bellmanford(int s)
{
	int i, j;
	int u;
	/** init dist */
	dist.assign(n, INF);
	/** dist of source = 0 */
	dist[s] = 0;
	/** loop of (n -1)times */
	for (i = 1; i < n; i++)
	{ /** search for all edges */
		for (u = 0; u < n; u++)
		{ /** starting point u */
			for (auto ed : a[u])
			{ /** ending point v */
				int v = ed.first;
				int w = ed.second; /** weight w(cost from u to v) */
				dist[v] = min(dist[v], dist[u] + w);
				/** try to update dist of point v */
			}
		}
	}
    /** having done (n - 1)times, dist shouble be fixed */
	/** do one more time */
	for (u = 0; u < n; u++)
	{ /** starting point u */
		for (auto ed : a[u])
		{ /** ending point v */
			int v = ed.first;
			int w = ed.second; /** weight w(cost from u to v) */
			/** if there is a shorter dist, return false */
			if (dist[u] + w < dist[v])
				return false;
		}
	}
	/** else return true */
	return true;
}

int main()
{
	int i, j;
	/** input */ 
	cin >> n >> m;
	/** input edge */
	a.resize(n);
	
	for (i = 0; i < m; i++)
	{
		int u, v, w;
		
		cin >> u >> v >> w;
		a[u].pb({v, w});
	}
	/** bellmanford with source of 0 */
	bool flag = bellmanford(0);
	/** output */
	cout << "BF returns " << flag << endl;
	/** output dist */
	for (i = 0; i < n; i++)
		cout << "dist[" << i << "] = " << dist[i] << endl;
	
	return 0;
}
