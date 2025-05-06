/** 该解法采用了先污染后治理的思想 */

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    if (Visited[V]) /** 后治理(判断) */
        return;

    Visit(V);
    Visited[V] = true;

    for (int i = 0; i < Graph->Nv; i++)
        if (Graph->G[V][i] != INFINITY) /** 若可达, 就搜索 */
            DFS(Graph, i, Visit); /** 先污染(搜索) */
}
