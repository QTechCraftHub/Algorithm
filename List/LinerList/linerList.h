/***********************************************
* 作者：何志强
* 时间：2016年9月23日
* 功能：线性表的基本函数头文件 linerList.h
***********************************************/
#ifndef _H_LINERLIST
#define _H_LINERLIST
#include"stdio.h"
#include"malloc.h"

//-----------线性表的动态分配顺序存储结构-------
#define LIST_INIT_SIZE 100       //线性表存储空间的初始分配量
#define LISTINCREMENT  10        //线性表存储空间的增量

#define OVERFLOW       0
#define OK             1
#define ERROR          0
typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *elem;              //存储空间基地址
	int      length;             //当前长度
	int      listsize;           //当前分配的存储容量
}SqList;

Status InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L,int i,ElemType e);
Status ListDelect_Sq(SqList *L,int i,ElemType *e);
//Status compare(ElemType a,ElemType b);
//int LocalElem_Sq(SqList L,ElemType e, Status(*compare)(ElemType,ElemType));
#endif
