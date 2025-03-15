struct stud_node *createlist()
{
    struct stud_node *L = (struct stud_node*)malloc(sizeof(struct stud_node) * 1);
    struct stud_node *s;
    struct stud_node *tail = L;
    int num;

    scanf("%d", &num);
    
    while (num != 0)
    {
        s = (struct stud_node*)malloc(sizeof(struct stud_node) * 1);
        s->num = num;
        scanf("%s %d", s->name, &s->score);
        tail->next = s;
        tail = s;
        scanf("%d", &num);
    }

    return L->next;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    struct stud_node *dummy = (struct stud_node*)malloc(sizeof(struct stud_node) * 1);
    dummy->next = head;
    struct stud_node *p, *q;

    q = dummy;
    p = dummy->next; // p = head;

    while (p)
    {
        if (p->score < min_score)
            q->next = p->next;
        else
            q = p;

        p = p->next;
    }

    return dummy->next;
}
