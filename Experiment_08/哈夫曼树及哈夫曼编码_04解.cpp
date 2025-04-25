void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)
{
    bool first = true;
    bool second = true;

    for (int i = 1; i < upbound; i++)
    {
        if (HT[i].parent == 0)
        {
            if (first)
            {
                s1 = i;
                first = false;
            }
            else
            {
                if (second)
                {
                    s2 = i;
                    second = false;
                }

                if (HT[i].weight < HT[s1].weight)
                {
                    s2 = s1;
                    s1 = i;
                }
                else if (HT[i].weight < HT[s2].weight)
                    s2 = i;
            }
        }
    }
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int i, j;
    HT = (HuffmanTree)malloc(sizeof(HTNode) * (2 * n));

    for (i = 1; i <= n; i++)
    {
        HT[i].weight = w[i - 1];
        HT[i].parent = 0;
        HT[i].lchild = HT[i].rchild = 0;
    }

    for (i = n + 1; i <= 2 * n - 1; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = HT[i].rchild = 0;
    }

    int s1, s2;

    for (i = n + 1; i <= 2 * n - 1; i++)
    {
        SelectTwoMin(i, HT, s1, s2);

        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;

        HT[s1].parent = i;
        HT[s2].parent = i;
    }

    int p, q;
    HC = (HuffmanCode)malloc(sizeof(char *) * (n + 1));

    for (i = 1; i <= n; i++)
    {
        char *s = (char *)malloc(sizeof(char) * n);
        int start = n - 1;
        s[start] = '\0';
        
        p = i;

        while (HT[p].parent != 0)
        {
            q = p;
            p = HT[p].parent;
            /* 逆序建立字符串s */
            if (HT[p].lchild == q)
            {
                start--;
                s[start] = '0';
            }
            else if (HT[p].rchild == q)
            {
                start--;
                s[start] = '1';
            }
        }

        HC[i] = (char *)malloc(sizeof(char) * (n - start));
        strcpy(HC[i], &s[start]);
    }
}
