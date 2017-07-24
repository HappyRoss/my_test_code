#include <stdio.h>
#include <stdlib.h>

typedef int elem_type;
//线性表堆栈
typedef struct stack
{
    elem_type *data;
    int top;
    int max_size;
}stack;
//1
int realloc_elem_space(stack* s)
{
    elem_type* p = (elem_type *)realloc(s->data, 2 * s->max_size * sizeof(elem_type));
    if (NULL == p) {
        return -1;
    }

    s->data = p;
    s->max_size = 2*s->max_size;
    return 0;
}
//2
int empty_stack(stack *s)
{
    if (-1 == s->top) {
        return 1; 
    } else {
        return 0;
    }
}
//3
int create_stack(stack *s, int mx)
{
    s->data = (elem_type *)malloc(mx * sizeof(elem_type));
    if (NULL == s->data) {
        return -1;
    }
    s->max_size = mx;
    s->top = -1;//为空栈
    return 0;
}
//4
int push_stack(stack *s, elem_type x)
{
    int ret;
    if (s->top == s->max_size -1) {
        ret = realloc_elem_space(s);     
        if (0 != ret) {
            return -1;
        }
    }
    s->data[++s->top] = x;
    printf("push %d \n", s->data[s->top]);
    return 0;
}
//5
elem_type pop_stack(stack *s)
{
    if (1 == empty_stack(s)) {
        exit(-1);
    }
    return s->data[s->top--];
}
//6
elem_type peek_stack(stack *s)
{
    if (1 == empty_stack(s)) {
        exit(-1);
    }
    return s->data[s->top];
}
//7
int delete_stack(stack *s)
{
    if (1 == empty_stack(s)) {
        return 0;
    }

    free(s->data);
    s->top = -1;
    s->max_size = 0;
    return 0;
}


//链表堆栈
typedef struct s_node
{
    elem_type data;
    struct s_node *next;
}s_node;
//1
void init_list_stack(s_node** ls)
{
    *ls = NULL;
}
//2
int push_list_stack(s_node** ls, elem_type x)
{
    s_node *p;
    p = (s_node *)malloc(sizeof(s_node));
    if (NULL == p) {
        return -1;
    }

    p->data = x;
    if (NULL == *ls) {
        p->next = NULL;
    } else {
        p->next = (*ls);
    }
    (*ls) = p;
    return 0;
}
//3
elem_type pop_list_stack(s_node** ls)
{
    s_node *p;
    elem_type tmp;
    if (NULL == *ls) {
        exit(-1);
    }
   
    p = *ls;
    (*ls) = (*ls)->next;
    tmp = p->data;
    free(p);
    return tmp;
}
//4
elem_type peek_list_stack(s_node** ls)
{
    if (NULL == *ls) {
        exit(-1);
    }
   
    return (*ls)->data;
}
//5
int empty_list_stack(s_node** ls)
{
    if (NULL == *ls) {
        return 1;
    } else {
        return 0;
    }
}
//6
int delete_list_stack(s_node** ls)
{
    s_node *p, *np;
    if (NULL == *ls) {
        return 0;
    }
    p = (*ls);
    while (NULL != p) {
        np = p->next;
        free(p);
        p = np;
    }
    (*ls) = NULL;
    return 0;
}
//

int main()
{
    //线性表堆栈
    stack s;
    int a[8] = {3, 8, 5, 17, 9, 30, 15, 22};
    int i;
    
    //链表堆栈
    struct s_node *ls;
    int x = 0;
    int m[8] = {3, 8, 5, 17, 9, 30, 15, 22};

    
    //线性表堆栈
    create_stack(&s, 5);

    for (i = 0; i < 8; i++) {
        push_stack(&s, a[i]);
    }

    for (i = 0; i < 8; i++) {
        printf("%d\n", pop_stack(&s));
    }
    push_stack(&s, 90);
    printf("%d \n", peek_stack(&s));
    while (1 == empty_stack(&s)) {
        printf("stack is empty.\n");
    }
    delete_stack(&s);


    //链表堆栈
    for (i = 0; i < 8; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");

    init_list_stack(&ls);
    while (8 != x) {
        push_list_stack(&ls, m[x]);
        x++;
    }
    printf("pop_list_stack.\n");
    while (1 != empty_list_stack(&ls)) {
        printf("%d ", pop_list_stack(&ls)); 
    }
    printf("\n");

    if (1 == empty_list_stack(&ls)) {
        printf("list_stack is empty.\n");
    }
    delete_list_stack(&ls);
    
    return 0;
}


