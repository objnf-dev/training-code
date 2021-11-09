#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int ElementType;

/* 普通结点结构 */
typedef struct NodeStruct
{
    ElementType data;
    struct NodeStruct *next;
}
// Node, *LinkList; /* 共用数据结构示例 */
Node;

/* 头结点结构 */
typedef struct LinkStruct
{
    int length;
    Node *next;
}
LinkList;

/* 标准方法 */
LinkList* construct_list();
void destroy_list(LinkList **L);
void insert_from_head(LinkList *L, ElementType data);

/* 非标准方法 */
int get_list_length_direct(LinkList *L);

#endif // LINKLIST_H_INCLUDED
