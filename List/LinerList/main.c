/********************************************************
* 作者：何志强
* 时间：2016年9月23号
* 功能：测试线性表基本函数 源文件 main.c
********************************************************/
#include"linerList.h"

int main() {

	SqList L;
	ElemType e;
	int i;
	if(InitList_Sq(&L)) {
		printf("InitList OK!\n");
		printf("L->length = %d\n",L.length);
		printf("L->listsize = %d\n",L.listsize);
	}
	
	ElemType data[10] = {12,31,24,52,11,62,18,63,75,10};

	for(i = 1;i <= 10;i++) {
		ListInsert(&L,i,data[i-1]);
	}
	printf("List data is :\n");
	for(i = 0;i < L.length;i++) {
		printf("%d\t",L.elem[i]);
	}
	printf("\n");


	if(ListInsert(&L,1,15)) {
		printf("Insert OK!\n");
		printf("List data is :\n");
		for(i = 0; i < L.length; i++) {
			printf("%d\t",L.elem[i]);
		}
		printf("\n");
	}
	printf("Begin Delete!\n");
	if(ListDelect(&L,1,&e)) {
		printf("Delect OK!\n");
		printf("List data is :\n");
		for(i = 0; i < L.length;i++) {
			printf("%d\t",L.elem[i]);
		}
		printf("\n");
		printf("Delect data is %d\n",e);
	}

	ElemType data_temp;
	int location;
	Status (*compare_temp)(ElemType,ElemType);
	compare_temp = compare;
	printf("Which data you want find :  ");
	scanf("%d",&data_temp);
	location = LocalElem_Sq(L,data_temp,*compare_temp);
	if(0 == location) {
		printf("Nothing!\n");
	}
	else {
		printf("%d 's location is %d!\n",data_temp,location);
	}
	return 0;
}
