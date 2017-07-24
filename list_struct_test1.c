#include <stdio.h>
#include <stdlib.h>

typedef int elem_type; //定义元素类型

//线性表

typedef struct list
{
    elem_type *data;
    int size;
    int max_size;
}list;

//1
int create_list(list* l,int max_size)
{
    if (max_size <= 0 || NULL == l) {
        return -1;
    }

    l->data = (elem_type* )malloc(max_size * sizeof(elem_type));
    if (NULL == l->data) {
        return 1;
    }

    l->max_size = max_size;
    l->size = 0;

    return 0;
}

//2
void delete_list(list *l)
{
    if (NULL != l->data) {
        free(l->data);
        l->data = NULL;
        l->max_size = 0;
        l->size = 0;
    }
}

//3
int size_list(list* l)
{
    if (NULL == l || NULL == l->data) {
        return -1;
    }
    return l->size;
}

//4
int empty_list(list* l)
{
    if (0 == l->size) {
        return 1;
    } else {
        return 0;
    }
}

//5
int get_pos_elem_list(list *l, int pos, elem_type *elem)
{
    if (NULL ==  elem) {
        printf("elem is NULL.\n");
        return -1;
    }

    if (pos < 0 || pos >= l->size) {
        printf(" pos = %d is out of size...\n", pos);
        return -1;
    }
    return l->data[pos];
}

//6
void print_list(list *l)
{
    if (NULL == l) {
        printf("list is NULL.\n");
        return;
    }
    int i = 0;
    for (; i < l->size; ++i) {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

//7
int find_elem_list(list *l, elem_type elem)
{
    if (NULL == l) {
        return -1;
    } 
    int i = 0;
    for (; i < l->size; ++i) {
        if (elem == l->data[i]) {
            return i;
        }
    }
    return -1;
}

//8
int update_pos_list(list *l, int pos, elem_type x)
{
    if (pos < 0 || pos >= l->size) {
        return -1;   
    }
    
    l->data[pos] = x;
    return 1;
}

//9
int realloc_elem_space(list *l)
{
    if (NULL == l) {
        return -1;
    }

    elem_type* p = (elem_type *)realloc(l->data, 2 * l->max_size * sizeof(elem_type));
    if (NULL == p) {
        printf("realloc fail.\n");
        return -1;
    }

    l->data = p;
    l->max_size = 2 * l->max_size;
    return 0;
}

//10
int insert_first_list(list *l, elem_type x)
{
    int ret, i;
    if (l->size == l->max_size) {
        ret = realloc_elem_space(l);
        if (0 != ret) {
            return -1;    
        }
    }

    for (i = l->size-1; i >= 0; --i) {
        l->data[i+1] = l->data[i];
    }

    l->data[0] = x;
    l->size++;
    return 0;
}

//11
int insert_last_list(list *l, elem_type x)
{
    int ret;
    if (l->size == l->max_size) {
        ret = realloc_elem_space(l);
        if (0 != ret) {
            return -1;
        }
    }
    l->data[l->size] = x; 
    l->size++;
    return 0;
}

//12
int insert_pos_list(list *l, int pos, elem_type x)
{
    int ret, i = 0;
    if (pos < 0 || pos > l->size) {
        return -1;
    }

    if (l->size == l->max_size) {
        ret = realloc_elem_space(l);
        if (0 != ret) {
            return -1;
        } 
    }
    //print_list(l);
    for (i = l->size-1; i >= pos; --i) {
        l->data[i + 1] = l->data[i];
    }

    l->data[pos] = x;
    l->size++;
    return 0;
}

//13
int insert_inorder_list(list *l, elem_type x)
{
    int ret, i, j;

    if (l->size == l->max_size) {
        ret = realloc_elem_space(l);
        if (0 != ret) {
            return -1;
        }
    }

    for (i  = 0; i < l->size; ++i) {
        if (l->data[i] > x) {
            break;
        }
    }

    for ( j = l->size - 1; j >=i; --j) {
        l->data[j + 1] = l->data[j];
    }

    l->data[j] = x;
    l->size++;
    return 0;
}

//14
int delete_first_list(list *l)
{
    int i;

    if (l->size <= 0) {
        return -1;    
    }

    for (i = 0; i < l->size - 1; i++) {
        l->data[i] = l->data[i + 1];        
    }
    
    l->size--;
    return 0;
}

//15
int delete_last_list(list *l)
{
    if (l->size <= 0) {
        return -1;
    }

    l->size--;
    return 0;
}

//16
int delete_pos_list(list *l, int pos)
{
    int i;

    if (pos < 0 || pos > l->size - 1) {
        return -1;
    }

    for (i = pos; i < l->size - 1; i++) {
        l->data[i] = l->data[i+1];
    }

    l->size--;
    return 0;
}

//17
int delete_value_list(list *l, elem_type x)
{
    int i, j;
    if (l->size <= 0) {
        return -1;
    }

    for (i = 0; i < l->size; i++) {
        if (l->data[i] == x) {
            break;
        }
    }

    if (i != l->size) {
        for (j = i; j < l->size - 1; j++) {
            l->data[j] = l->data[j + 1];
        }
        l->size--;
        return 0;
    } else {
        return -1;
    }
}

//单链表
typedef struct s_node
{
    elem_type data;
    struct s_node *next;
}s_node;


s_node* new_s_node(void)
{
    s_node * p = (s_node *)malloc(sizeof(s_node));
    return p;
}


//1
void init_s_list(s_node** head)
{
    *head = NULL;
}

//2
void delete_s_list(s_node** head)
{
    s_node *current, *next;
    current = *head;

    while (NULL != current) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

//3
int size_s_list(s_node** head)
{
    int count = 0;
    s_node *p = *head;
    while (NULL != p ) {
        count++;
        p = p->next;
    }
    return count;
}
//4
int empty_s_list(s_node** head)
{
    if (NULL != *head) {
        return 0;
    } else {
        return 1;
    }

}
//5
int get_elem_s_list(s_node** head, int pos, elem_type *x)
{
    if (1 == empty_s_list(head)) {
        return -1;
    }

    int cnt = 0;
    s_node *p;

    p = *head;

    while (NULL != p) {
        cnt++;
        if (pos == cnt) {
             *x = p->data;
             return 0;
        }
        p = p->next;
    }
    return -1;
}
//6
void traverse_s_list(s_node** head)
{
    if (1 == empty_s_list(head)) {
        return;
    }
    s_node *p = *head;

    while (NULL != p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//7
s_node* find_s_list(s_node** head, elem_type x)
{
    if (1 == empty_s_list(head)) {
        return NULL;
    } 
    s_node *p = *head;

    while (NULL != p) {
        if (x == p->data) {
            break;
        }
        p = p->next;
    }
    return p;
}
//8
int update_pos_s_list(s_node** head, int pos, elem_type x)
{
    if (1 == empty_s_list(head)) {
        return -1;
    }

    s_node *p = *head;
    int cnt = 0;

    while (NULL != p) {
        cnt++;
        if (cnt == pos) {
            break;
        }
        p = p->next;
    }

    if (NULL != p) {
        p->data = x;
        return 0;
    } else {
        return -1;   
    } 
}
//9
int insert_first_s_list(s_node** head, elem_type x)
{
    s_node *p, *p2;
    if (1 == empty_s_list(head)) {
        p2 = (s_node *)malloc(sizeof(s_node));
        if (NULL == p2) {
            return -1;
        } else {
            p2->data = x;
            p2->next = NULL;
            *head = p2;
            return 0;
        }
    }
    p = *head;
    p2 = (s_node *)malloc(sizeof(s_node));
    if (NULL == p2) {
        return -1;
    } else {
        p2->data = x;
        p2->next = NULL;
    }

    p2->next = p;
    *head = p2;
    return 0;
}
//10
int insert_last_s_list(s_node** head, elem_type x)
{
    s_node *p, *p2, *tmp;
    if (1 == empty_s_list(head)) {
        p2 = (s_node *)malloc(sizeof(s_node));
        if (NULL == p2) {
            return -1;
        } else {
            p2->data = x;
            p2->next = NULL;
            *head = p2;
            return 0;
        }
    }
    p2 = (s_node *)malloc(sizeof(s_node));
    if (NULL == p2) {
        return -1;
    } else {
        p2->data = x;
        p2->next = NULL;
    }
    p = *head;
    tmp = p;
    while (NULL != p) {
        tmp = p;
        p = p->next;
    }
    tmp->next = p2;
    return 0;
}
//11
int insert_pos_s_list(s_node** head, int pos, elem_type x)
{
    s_node *p, *p2, *tmp;
    int cnt;

    if (pos < 1) {
        return -1;
    }

    if (1 == empty_s_list(head) && 1 == pos) {
        p2 = (s_node *)malloc(sizeof(s_node));
        if (NULL == p2) {
            return -1;
        } else {
            p2->data = x;
            p2->next = NULL;
            *head = p2;
            return 0;
        }
    }


    p2 = (s_node *)malloc(sizeof(s_node));
    if (NULL == p2) {
        return -1;
    } else {
        p2->data = x;
        p2->next = NULL;
    }

    p = *head;
    tmp = NULL;//赋值
    cnt = 0;
    while (NULL != p) {
        cnt++;
        if (cnt == pos) {
            break;
        }
        tmp = p;
        p = p->next;
    }

    if (NULL == tmp) {//表头插入
        p2->next = p;
        *head = p2;
    } else {//在tmp和p之间插入
        p2->next = p;
        tmp->next = p2;
    }
    return 0;

}
//12 像有序单链表插入元素，使得插入之后依然有序
int insert_inorder_s_list(s_node** head, elem_type x)
{
    s_node *p = *head, *tmp = NULL, *p2;

    p2 = (s_node *)malloc(sizeof(s_node));
    if (NULL == p2) {
        return -1;
    } else {
        p2->data = x;
        p2->next = NULL;
    }

    if (1 == empty_s_list(head) || p->data > x) {
        p2->next = p;
        *head = p2;
        return 0;
    }

    while (NULL != p) {
        if (p->data > x) {
            break;
        }
        tmp = p;
        p = p->next;
    }
    tmp->next = p2;
    p2->next = p;
    return 0;
}
//13
int delete_first_s_list(s_node** head)
{
    s_node *p = *head, *tmp = NULL;
    if (1 == empty_s_list(head)) {
        return -1;
    }

    tmp = p;
    p = p->next;
    free(tmp);
    tmp = NULL;
    *head = p;
    return 0;
}
//14
int delete_last_s_list(s_node** head)
{
    s_node *p = *head, *prev = NULL;
    if (1 == empty_s_list(head)) {
        return -1;
    }

    while (NULL != p->next) {
        prev = p;
        p = p->next;
    }

    if (NULL == prev) {//链表只有一个元素，即删除表头元素
        *head = NULL;
        free(p);
    } else {
        prev->next = NULL;
        free(p);
    }
    return 0;
}
//15
int delete_pos_s_list(s_node** head, int pos)
{
    s_node *p = *head, *prev = NULL;
    int cnt = 0;
    if (pos < 1 || 1 == empty_s_list(head)) {
        return -1;
    }

    while (NULL != p) {
        cnt++;
        if (cnt == pos) {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (NULL == p) {//链表中没有第pos元素
        return -1;
    }

    if (1 == pos) {//删除表头第一个元素
        *head = p->next;
    }else {//删除第dos个元素
        prev->next = p->next;
    }
    free(p);
    return 0;
}
//16
int delete_value_s_list(s_node** head, elem_type x)
{
    s_node *p = *head, *prev = NULL;

    if (1 == empty_s_list(head)) {
        return -1;
    }
    
    while (NULL != p) {
        if (p->data == x) {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (NULL == p) {//
        return -1;
    }

    if (NULL == prev) {
        *head = p->next;
    } else {
        prev->next = p->next;
    }
    free(p);
    return 0;
}
//17
void reverse_s_list(s_node** head)
{
    if (1 == empty_s_list(head)) {
        return;
    }
    s_node *q, *p, *r;

    p = *head;
    q = (*head)->next;
    (*head)->next = NULL;

    while (NULL != q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    *head = p;
}

//双链表
typedef struct d_node
{
    elem_type data;
    struct d_node *prev;
    struct d_node *next;
}d_node;



int main() 
{
    //线性表
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int i;
    int ret;
    list l;
    
    //单链表
    int array[20];
    s_node *p, *h, *s;

    //
    create_list(&l, 5);//初始化分配线性空间为5
    for (i = 0; i < 10; i++) {
        insert_last_list(&l, a[i]);//将数组中的元素依次插入线性表
    }
    print_list(&l);

    ret = insert_pos_list(&l, 10, 48);
    if (0 != ret) {
        printf("1 ret = %d\n", ret);
    }
    print_list(&l);

    ret = insert_pos_list(&l, 0, 64);
    if (0 != ret) {
        printf("2 ret = %d\n", ret);
    }
    print_list(&l);

    delete_first_list(&l);
    delete_last_list(&l);
    delete_pos_list(&l, 4);
    print_list(&l);

    printf("the size of list is %d, and max_size is %d\n", size_list(&l), (&l)->max_size);
    delete_list(&l);

    //
    init_s_list(&p);
    init_s_list(&h);
    s = p;
    for (i = 0; i < 20; i++) {
        array[i] = rand() % 129;
        printf("%d ", array[i]);
    }
    printf("\n");

    for (i = 0; i < 20; i++) {
        insert_first_s_list(&p, array[i]);
        insert_last_s_list(&h, array[i]);
    }
    printf("p\n");
    traverse_s_list(&p);
    printf("h\n");
    traverse_s_list(&h);

    reverse_s_list(&p);
    reverse_s_list(&h);
    printf("p\n");
    traverse_s_list(&p);
    printf("h\n");
    traverse_s_list(&h);

    delete_s_list(&p);
    delete_s_list(&h);

    return 0;
}

