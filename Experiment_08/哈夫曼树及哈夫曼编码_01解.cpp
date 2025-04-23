void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)
{
    int first = 1;
    int second = 1;

    for (int i = 1; i < upbound; i++)
    {
        if (HT[i].parent == 0)
        {
            if (first)
            {
                s1 = i;
                first = 0;
            }
            else
            {
                if (second)
                {
                    s2 = i;
                    second = 0;
                }

                if (HT[i].weight < HT[s1].weight)
                {
                    s2 = s1;
                    s1 = i;
                }
                else if (HT[i].weight < HT[s2].weight)
                {
                    s2 = i;
                }
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

    for (i = n + 1; i <= 2 * n - 1; i++)
    {
        int s1, s2;
        
        SelectTwoMin(i, HT, s1, s2);
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[s1].parent = i;
        HT[s2].parent = i;
    }

    int p, q;

    HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));

    for (i = 1; i <= n; i++)
    {
        char s[1001];
        int length = 0;

        p = i;

        while (HT[p].parent != 0)
        {
            q = p;
            p = HT[p].parent;

            if (HT[p].lchild == q)
            {
                s[length] = '0';
                length++;
            }
            else if (HT[p].rchild == q)
            {
                s[length] = '1';
                length++;
            }
        }

        for (j = 0; j < length / 2; j++)
            swap(s[j], s[length - 1 - j]);

        s[length] = '\0';
        HC[i] = (char*)malloc(sizeof(char) * (length + 1));
        strcpy(HC[i], s);
    }
}
