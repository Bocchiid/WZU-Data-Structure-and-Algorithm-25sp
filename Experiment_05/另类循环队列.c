bool AddQ( Queue Q, ElementType X )
{ /** If queue is full, then return false */
    if (Q->Count == Q->MaxSize)
    {
        printf("Queue Full\n");

        return false;
    }
    /** If not, then add ele to queue */
    Q->Data[Q->Front] = X;
    /** Move Front pointer */
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    /** Count++ */
    Q->Count++;
    /** Return true */
    return true;
}
ElementType DeleteQ( Queue Q )
{ /** If queue if empty, then return ERROR */
    if (Q->Count == 0)
    {
        printf("Queue Empty\n");

        return ERROR;
    }
    /** Get deleted ele */
    Position pos = (Q->MaxSize + Q->Front - Q->Count) % Q->MaxSize;
    ElementType x = Q->Data[pos];
    /** Count-- */
    Q->Count--;
    /** Return deleted ele */
    return x;
}
