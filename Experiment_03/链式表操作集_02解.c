Position Find( List L, ElementType X )
{
    Position p;

    p = L;

    while (p)
    {
        if (p->Data == X)
            return p;

        p = p->Next;
    }

    return ERROR;
}
List Insert( List L, ElementType X, Position P )
{    // 不带dummy(虚拟头节点)的做法, 需进行特判
    Position s;

    if (P == L) // 在第一个结点前插入新的结点
    {
        s = (Position)malloc(sizeof(struct LNode) * 1);
        s->Data = X;
        s->Next = L;

        return s;
    }

    Position p, q;

    q = L;
    p = L->Next;

    while (p)
    {
        if (p == P)
            break;

        q = p;
        p = p->Next;
    }

    if (p == P)
    {
        s = (Position)malloc(sizeof(struct LNode) * 1);
        s->Data = X;
        s->Next = q->Next;
        q->Next = s;

        return L;
    }
    else
    {
        printf("Wrong Position for Insertion\n");

        return ERROR;
    }
}
List Delete( List L, Position P )
{    // 不带dummy(虚拟头节点)的做法, 需进行特判
    if (L == NULL) // 空链表应该删除失败, 但题目没有考虑
    {
        printf("Wrong Positon for Deletion");

        return ERROR;
    } // 上面这一块代码不写也可以过OJ
    else if (P == L) // 删除的结点为第一个结点, 且链表不为空
        return L->Next;

    Position p, q;

    q = L;
    p = L->Next;

    while (p)
    {
        if (p == P)
            break;

        q = p;
        p = p->Next;
    }

    if (p)
    {
        q->Next = p->Next;
        free(p); // 这句话可以不要

        return L;
    }
    else
    {
        printf("Wrong Position for Deletion\n");

        return ERROR;
    }
}
