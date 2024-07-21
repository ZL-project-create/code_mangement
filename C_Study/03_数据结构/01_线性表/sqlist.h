#ifndef SQLIST_H__
#define SQLIST_H__

#define DATASIZE 1024

typedef int datatype;

typedef struct node_st{
	datatype data[DATASIZE];
	int last;
}sqlist;

// 创建线性表
sqlist *sqlist_create();
void sqlist_create1(sqlist **);

// 插入
int sqlist_insert(sqlist *,int i,datatype *);

// 删除
int sqlist_delete(sqlist *,int i);

// 查找
int sqlist_find(sqlist *,datatype *);

// 判断是否为空
int sqlist_isempty(sqlist *);

// 强制设置为空
int sqlist_setempty(sqlist *);

// 表长
int sqlist_getnum(sqlist *);

// 遍历
void sqlist_display(sqlist *);

// 销毁
int sqlist_destory(sqlist *);

// 合并线性表
int sqlist_union(sqlist *,sqlist *);

#endif
