#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct node_st
{
	datatype data;
	struct node_st *next;
}list;

// 创建链表
list *list_create();

// 按位插入
int list_insert_at(list *,int i,datatype *);

// 按顺序插入
int list_order_insert(list *,datatype *);

// 按位删除
int list_delete_at(list *,int i,datatype *);

// 按值删除
int list_delete(list *,datatype *);

// 判断是否为空
int list_isempty(list *);

// 显示链表
void list_display(list *);

// 销毁链表
void list_destory(list *);


#endif
