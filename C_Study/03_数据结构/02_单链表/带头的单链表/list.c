#include "list.h"

// 创建单链表
list *list_create()
{
	list *me;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->next = NULL;
	return me;
}

// 按位插入
int list_insert_at(list *me,int i,datatype *data)
{
	int j = 0;
	list *node = me,*newnode;
	if(i < 0)
		return -1;
	
	while(j<i && node != NULL)
	{
		node = node->next;
		j++;
	}
	
	if(node)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return -2;
		newnode->data = *data;
	
		newnode->next = node->next;
		node->next = newnode;
	
		return 0;
	}
	else
		return -3;
}

// 按值插入
int list_order_insert(list *me,datatype *data)
{
	/*
		p：来做移动
		q：记录位置	
	*/
	list *p = me,*q;
	// 如果p的下一个结点的data的值小于新的data
	while(p->next && p->next->data < *data)
	{
		p = p->next; // 则向后移动
	}
	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;
	
	q->data = *data;
	q->next = p->next;
	p->next = q;
	
	return 0;
}

// 按位删除
int list_delete_at(list *me,int i,datatype *data)
{
	int j = 0;
	list *p = me,*q;

	*data = -1;
	
	if(i < 0)
		return -1;

	while(j < i)
	{
		p = p->next;
		j++;
	}
	if(p)
	{
		q = p->next;
		p->next = q->next;
		*data = q->data;
		free(q);
		q = NULL;
		
		return 0;
	}
	else
		return -2;
}

// 按值删除
int list_delete(list *me,datatype *data)
{
	list *p = me,*q;
	while(p->next && p->next->data != *data)
		p = p->next;
	if(p->next == NULL)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
	}
}

// 判断是否为空
int list_isempty(list *me)
{
	if(me->next == NULL)
		return 0;
	return 1;
}

// 显示链表
void list_display(list *me)
{
	list *node = me->next;
	if(list_isempty(me) == 0)
		return ;
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
	
	return ;
}

// 销毁链表
void list_destory(list *me)
{
	list *node,*next;
	for(node = me->next;next != NULL;node = next)
	{
		next = node->next;
		free(node);
	}
	free(me);
	
	return ;
}

