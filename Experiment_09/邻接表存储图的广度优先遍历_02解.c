/** 该解法是从层的视角来实现bfs */

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    if (Visited[S]) /** 若已经搜索过了, 就结束搜索 */
        return;

    Vertex q[1001];
    int head = 0;
    int tail = 0;

    q[tail] = S;
    tail++;

    Visit(S);
    Visited[S] = true;

    while (head != tail)
    {
        int n = tail - head;

        for (int i = 0; i < n; i++)
        {
            Vertex t = q[head];
            head++;

            PtrToAdjVNode p = Graph->G[t].FirstEdge;

            while (p)
            {
                Vertex v = p->AdjV;

                if (!Visited[v])
                {
                    q[tail] = v;
                    tail++;

                    Visit(v);
                    Visited[v] = true;
                }

                p = p->Next;
            }
        }
    }
}
