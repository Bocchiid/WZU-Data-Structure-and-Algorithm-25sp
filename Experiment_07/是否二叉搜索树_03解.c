/* 该解法的思路为利用BST的中序遍历为递增序列的特点 */
/* 该解法为中序遍历的递归实现 */
/* 访问内容为维护全局变量 */

int last;
bool flag;

void inorder(BinTree root)
{
    if (root)
    {
        inorder(root->Left);

        if (root->Data <= last)
        {
            flag = false;

            return; /* 最优性剪枝 */
        }
        else
            last = root->Data;
            
        inorder(root->Right);
    }
}

bool IsBST ( BinTree T )
{ /* 默认flag为true, 因为空树也是BST */
    flag = true;
    last = -1;
    inorder(T);

    return flag;
}
