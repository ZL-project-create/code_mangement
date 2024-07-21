#include "nohead.h"


int main()
{
	int ret;
	struct node_st * list = NULL;
	struct score_st temp;
	struct score_st *ptr;
	
	for(int i=0;i < 7;i++)
	{
		temp.id = i;
		snprintf(temp.name,NAMESIZE,"stu%d",i);
		temp.math = rand()%100;
		temp.chinese = rand()%100;

		ret = list_insert(&list,&temp);
		if(ret != 0)
			exit(1);
	}
	list_show(list);

	printf("\n\n");
	int id = 3;
	list_find(list,id);

	printf("\n\n");
	int id_1 = 1;
	ptr = list_find(list,id_1);
	if(ptr == NULL)
		printf("Can not find!\n");
	else
		printf("%d %s %d %d\n",ptr->id,ptr->name,ptr->math,ptr->chinese);

	printf("\n\n");

	list_delete(&list);
	
	list_show(list);

	list_destory(list);
	exit(1);
}
