#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType,Status;
#define OK  1//定义 OK
#define OVERFLOW  -1//定义 OK
typedef struct{
	ElemType  *elem;
  	int length;
   	int listsize;
}SqList;
  
Status InitList_Sq(SqList *L)
{
	L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType)) ;
	if(!L->elem) exit(OVERFLOW);//OVERFLOW 未定义
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;//OK 未定义
}
				
void main()
{
	SqList L; 
	if(InitList_Sq(&L))
		printf("InitList OK!\n");
}
