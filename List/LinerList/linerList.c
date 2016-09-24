/*****************************************************
* 作者：何志强
* 时间：2016年9月23号
* 功能：线性表的基本操作 源文件 linerList.c
*****************************************************/
#include"linerList.h"

Status InitList_Sq(SqList *L) { 
	//构造一个空的线性表L
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(! L->elem)                      //空间分配失败  
		return OVERFLOW;          
	L->length = 0;                     //当前长度为0 
	L->listsize = LIST_INIT_SIZE;      //分配存储空间大小为 LIST_INIT_SIZE
	return OK;
}

Status ListInsert(SqList *L,int i,ElemType e) {
	//在线性表第i个位置插入e
	//i的合法值1<<i<<L.length+1
	if(i < 1 || i> L->length + 1)    //位置不合法
		return ERROR;
	if(L->length >= L->listsize){     //分配的空间满了，新增空间 函数realloc(.....)
		ElemType *newBase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if(!newBase)                  //新空间分配失败
			return OVERFLOW;
		L->elem = newBase;            //改变基址  
		L->listsize += LISTINCREMENT; //线性表空间增加
	}
	ElemType *q = &(L->elem[i-1]);
	ElemType *p;
	for(p = &(L->elem[L->length-1]);p >= q; --p)  //数据后移
		*(p + 1) = *p;
	*q = e;
	++L->length;
	return OK;
}

Status ListDelect(SqList *L,int i,ElemType *e) {
	//删除线性表第i个元素，并把删除的元素存储在变量e中
	//i值得范围是：1<=i<=L->length
	if(i < 1 || i > L->length) {                //i值不合法
		printf("Illegal i!\n");                 
		return ERROR;
	}
	ElemType *p = &(L->elem[i-1]);              //取出第i个元素
	*e = *p;
	ElemType *q = L->elem + L->length - 1;      //获取最后一个元素的地址
	for(++p; p <= q; p++) {
		*(p-1) = *p;                            //数据前移
	}
	--L->length;                                //长度-1
	return OK;
}
/*
Status compare(ElemType a,ElemType b) {
	if(a == b)
		return OK;
	else
		return ERROR;
}

int LocalElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)) {
	//在顺序表中查找第一个与e满足compare()的元素位序
	//若找到返回其在L中的位序，否则返回0
	int i = 1;
	ElemType *p = L.elem;                     //p指向L的第一个元素
	while(i <= L.length && !(*compare)(*p++,e))
		++i;
	if(i <= L.length)
		return i;
	else
		return 0;
}*/
