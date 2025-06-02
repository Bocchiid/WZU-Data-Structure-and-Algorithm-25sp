bool Push( ElementType X, Deque D )
{ /** If queue is full, then return false */
    if ((D->Rear + 1) % D->MaxSize == D->Front)
        return false;
    /** If not, then add ele to queue */
    /** Move Front pointer */
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    /** Add ele to queue */
    D->Data[D->Front] = X;
    /** Return true */
    return true;
}
ElementType Pop( Deque D )
{ /** If queue is empty, then return ERROR */
    if (D->Front == D->Rear)
        return ERROR;
    /** If not, then return deleted ele */
    /** Get deleted ele */
    ElementType x = D->Data[D->Front];
    /** Move Front pointer */
    D->Front = (D->Front + 1) % D->MaxSize;
    /** Return deleted ele */
    return x;
}
bool Inject( ElementType X, Deque D )
{ /** If queue is full, then return false */
    if ((D->Rear + 1) % D->MaxSize == D->Front)
        return false;
    /** If not, then add ele to queue */
    /** Add ele to queue */
    D->Data[D->Rear] = X;
    /** Move Rear pointer */
    D->Rear = (D->Rear + 1) % D->MaxSize;
    /** Return true */
    return true;
}
ElementType Eject( Deque D )
{ /** If queue is empty, then return ERROR */
    if (D->Front == D->Rear)
        return ERROR;
    /** If not, then return deleted ele */
    /** Move Rear pointer */
    D->Rear = (D->Rear - 1 + D->MaxSize) % D->MaxSize;
    /** Get deleted ele */
    ElementType x = D->Data[D->Rear];
    /** Return deleted ele */
    return x;
}
