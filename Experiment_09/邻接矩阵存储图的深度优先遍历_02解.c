/** 该解法采用了先治理的思想 */

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Visit(V);
    Visited[V] = true;

    for (int i = 0; i < Graph->Nv; i++)
        if (Graph->G[V][i] != INFINITY) /** 若可达, 就搜索 */
            if (!Visited[i]) /** 先治理(判断) */
                DFS(Graph, i, Visit);
}
