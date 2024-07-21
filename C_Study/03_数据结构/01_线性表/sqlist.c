#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


sqlist *sqlist_create()
{
	sqlist *me;
	me = malloc(sizeof(*me)); // 动态分配内存空间
	if(me == NULL)
		return NULL;
	me->last = -1;	// 目前没有任何有效内容
	
	return me;
}

// 利用二级指针回填的形式创建线性表
void sqlist_create1(sqlist **ptr)
{
	*ptr = malloc(sizeof(**ptr));
	if(*ptr == NULL)
		return ;
	(*ptr)->last = -1;
	return ;
}
// 插入
int sqlist_insert(sqlist *me,int i,datatype *data)
{
	int j;
	if(me->last == DATASIZE-1)
		return -1;// 当前空间已经消耗完了
	if(i < 0 || i > me->last+1)
		return -2;// i值不对
	for(j = me->last;i<=j;j--)
		me->data[j+1] = me->data[j];

	me->data[i] = *data;
	me->last++;

	return 0;
}
// 删除
int sqlist_delete(sqlist *me,int i)
{
	// 按位置删除
	int j;
	if(i < 0 || i > me->last)
		return -1;
	for(j = i+1;j <= me->last;j++)
		me->data[j-1] = me->data[j];
	me->last--;
	return 0;
}
// 查找
int sqlist_find(sqlist *me,datatype *data)
{
	int i;
	if(sqlist_isempty(me) == 0)
		return -1;
	for(i=0;i<me->last;i++)
		if(me->data[i] == *data)
			return i;
	return -2;
}
// 判断是否为空
int sqlist_isempty(sqlist *me)
{
	// 空为0
	if(me->last == -1)
		return 0;
	return -1;
}
// 强制设置为空
int sqlist_setempty(sqlist *me)
{
	me->last = -1;
	return 0;
}
// 表长
int sqlist_getnum(sqlist *me)
{
	return (me->last+1);
}
// 遍历
void sqlist_display(sqlist *me)
{
	int i;
	if(me->last == -1)
		return ;
	for(i = 0;i <= me->last;i++)
		printf("%d ",me->data[i]);
	printf("\n");
	return ;

}
// 销毁
int sqlist_destory(sqlist *me)
{
	free(me);
	return 0;
}
// 合并线性表
int sqlist_union(sqlist *list1,sqlist *list2)
{
	// list1 -> 12 34 34 45 56
	// list2 -> 78 89 56 23 10
	int i = 0;
	for(i=0;i<=list2->last;i++)
	{
		if(sqlist_find(list1,&list2->data[i]) < 0)
		{
			sqlist_insert(list1,0,&list2->data[i]);
		
		}
	}
}
