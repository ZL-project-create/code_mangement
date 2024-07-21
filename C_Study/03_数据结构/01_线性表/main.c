#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>

int main()
{
	sqlist *list;
	sqlist *list1;
	datatype arr[] = {12,23,34,45,56};
	datatype arr1[] = {89,90,78,67,56,45};
	int i,err;
	//list = sqlist_create();// 利用函数的返回值把一个指针（起始位置）带回来
	sqlist_create1(&list);// 利用二级指针传参来把一级目表来进行完成
	if(list == NULL)
	{
		fprintf(stderr,"sqlist_create() failed!\n");
		exit(1);
	}
	
	list1 = sqlist_create();
	if(list1 == NULL)
	{
		fprintf(stderr,"sqlist_create() dailed!\n");
		exit(1);
	}
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
		if((err = sqlist_insert(list,0,&arr[i])) != 0)
		{
			if(err == -1)
				fprintf(stderr,"The arr is full.\n");
			else if(err == -2)
				fprintf(stderr,"The pos you want to insert is wrong.\n");	
				else
					fprintf(stderr,"Error!\n");
			exit(1);
		}

	sqlist_display(list);// 显示list的线性表

	for(i = 0;i < sizeof(arr1)/sizeof(*arr1);i++)
		sqlist_insert(list1,0,&arr1[i]);

	sqlist_display(list1);// 显示list1的线性表

	sqlist_union(list,list1); 

	sqlist_display(list);// 显示联合之后的线性表
#if 0
	sqlist_delete(list,1);
	sqlist_display(list);
#endif
	sqlist_destory(list);
	exit(0);
}
