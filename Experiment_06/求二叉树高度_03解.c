/* 该解法的思想为遍历 + 维护一个全局变量 */

int h;

void getHeight(BinTree root, int deep)
{
    if (!root) // if (root == NULL)
    {
        if (deep > h)
            h = deep;

        return;
    }

    deep++;
    getHeight(root->Left, deep);
    getHeight(root->Right, deep);
}

int GetHeight( BinTree BT )
{
    h = 0;
    getHeight(BT, 0);

    return h;
}
