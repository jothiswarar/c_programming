void insertbegin(int i)
{
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->n = head;
        head = n;
    }
    
}
void insertatend(int i)
{
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->n = n;
        tail = n;
    }
    
}
void insert(int i, int s)
{
    struct node *c = head, *a;
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head != NULL)
    {

        for (int i = 1; i < s; i++)
        {
            c = c->n;
        }
        struct node *a = c->n;
        c->n = n;
        n->n = a;
        
    }
    else
    {
        head = n;
        tail = n;
        
    }
}
