/** 该解法是从层的视角来实现bfs */

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    if (Visited[S]) /** 若已经搜索过了, 就结束搜索 */
        return;

    Vertex q[1001];
    int head = 0;
    int tail = 0;

    Vertex inq[1001] = {0};

    q[tail] = S;
    tail++;
    inq[S] = 1;

    while (head != tail)
    {
        int n = tail - head;

        for (int i = 0; i < n; i++)
        {
            Vertex t = q[head];
            head++;
            inq[t] = 0;

            Visit(t);
            Visited[t] = true;

            PtrToAdjVNode p = Graph->G[t].FirstEdge;

            while (p)
            {
                Vertex v = p->AdjV;

                if (!Visited[v] && !inq[v])
                {
                    q[tail] = v;
                    tail++;
                    inq[v] = 1;
                }

                p = p->Next;
            }
        }
    }
}
