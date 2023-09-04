void deleteatbegin()
{
    struct node *c = head;
    head = head->n;
    free(c);
    
}
void deleteatend()
{
    struct node *c = head;
    while (c->n != tail)
    {
        c = c->n;
    }
    tail = c;

    struct node *a = c->n;
    free(a);
    c->n = NULL;
    
}
void delete(int a)
{
    struct node *c = head;
    if (head != NULL)
    {
        if (c->n != NULL)
        {
            while (c->n->d != a)
            {
                c = c->n;
            }
            struct node *b = c->n;
            c->n = b->n;
            free(b);
            
        }
        else
        {
            head = head->n;
            free(c);
            
        }
    }
    else
    {
        printf("List is already empty\n");
    }
}
