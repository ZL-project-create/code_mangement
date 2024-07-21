#include "list.h"

int main()
{
	list *l;
	int i;
	
	datatype arr[] = {12,9,23,2,34,6,45};
	l = list_create();
	if(l == NULL)
		exit(1);

	printf("按位插入之后的链表：");
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{	
		if(list_insert_at(l,0,&arr[i]))
			exit(1);
	}

	list_display(l);

	printf("\n");
    printf("按位删除元素之后的链表：");
    datatype value1;
    int err;
    err = list_delete_at(l,2,&value1);
    if(err)
        exit(-1);
    list_display(l);

	list_destory(l);

	l = list_create(); // 释放内存后得重新申请一片内存空间
	printf("\n");	

	printf("按值插入之后的链表：");
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{
		if(list_order_insert(l,&arr[i]))
			exit(1);
	}
	
	list_display(l);
	
	int value = 12;	
	printf("\n");	
	printf("按值删除元素之后的链表：");
	
	list_delete(l,&value);
		
	list_display(l);

	list_destory(l);
	
	exit(0);
}
