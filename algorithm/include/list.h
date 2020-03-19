#ifndef LIST_H
#define LIST_H
//线性表头文件
/******************************************************************************
* File:             list.h
*
* Author:           MichaelDiao  
* Created:          03/17/20 
* Description:     线性表的相关操作 
*****************************************************************************/
#include <limits.h>
#include <cstring>
#define MAXSIZE 20 //存储空间初始分配量

typedef int ElemType; //元素类型


class List
{
private:
    ElemType* _pdata;
    int _length; // 线性表当前长度
    int _capacity;
    

public:
    List();
    List(const ElemType arr[], int length);
    virtual ~List();
    ElemType& operator[](int vindex)const;
    bool ListEmpty() const;
    void ClearList();
    ElemType GetElem(int index) const;
    int FindElem(ElemType elem) const;
    bool ListInsert(int index, ElemType elem);
    ElemType ListDelete(int index);
    int GetLength() const;
    int GetCapacity() const;
    bool ListUnion(const List& l);
};

#endif /* LIST_H */


