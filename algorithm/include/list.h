#ifndef LIST_H
#define LIST_H
//线性表头文件
/******************************************************************************
* File:             list.h
*
* Author:           MichaelDiao  
* Created:          03/17/20 
* Description:     线性表的相关操作List: 线性存储空间; LinkList: 链表存储空间
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
    List(const List& l);
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


//单链表的节点
class Node{
public:
    ElemType _data;
    Node* _next;
    Node(ElemType data=0, Node* next=nullptr){
        _data = data;
        _next = next;
    }
};

//单链表类
class SingleLinkList
{
public:
    SingleLinkList ();
    SingleLinkList (int num);//创建一个长度为num的随机链表
    virtual ~SingleLinkList ();
    virtual bool insertHead(int index, ElemType ele);//头插
    virtual bool insertNodeHead(int index, Node* node);//头插
    virtual void show() const;//遍历链表并打印
    virtual bool remove(int index);//删除index位置的元素 不返回被删除元素值
    virtual bool remove(int index, ElemType& ele);//删除index位置的元素, 返回被删除元素值
    virtual bool get(int index, ElemType& ele) const;//获取index位置的元素
    virtual bool createSingleLinkList(int num);//创建一个长度为num的随机链表
    virtual bool find(ElemType ele) const;//查找值为ele的元素,返回该节点node
    virtual bool find(ElemType ele, Node* &node) const;//查找值为ele的元素,返回该节点node
    virtual bool update(int index, ElemType ele);//更新index位置节点的值
    virtual bool clear();//释放除了头结点之外的所有节点
    virtual int get_length() const;//查询当前链表长度,不包括头结点
    virtual void get_head(Node* &head) const;//获取头结点

private:
    Node* _head;//头指针,数据域存放链表长度
    /* data */
};

#endif /* LIST_H */


