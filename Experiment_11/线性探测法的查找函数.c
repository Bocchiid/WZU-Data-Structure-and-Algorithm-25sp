Position Find( HashTable H, ElementType Key )
{
    Position i, pos;
    int cnt;

    pos = Key % H->TableSize;
    cnt = 0;

    for (i = pos; cnt != H->TableSize; i = (i + 1) % H->TableSize)
    {
        if (H->Cells[i].Data == Key && H->Cells[i].Info == Legitimate)
            return i;
        else if (H->Cells[i].Info == Empty)
            return i;

        cnt++;
    }

    return ERROR;
}
