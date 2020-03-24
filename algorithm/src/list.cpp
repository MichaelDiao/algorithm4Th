#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include "list.h"

//产生一个[0, 99]的随机数
#define GET_RAND_NUM (rand() % 100)


List::List(){
    _pdata = nullptr;
    _length = 0;
    _capacity = 0;
}

List::List(const ElemType arr[], int length){
    _length = length;
    _capacity = 2*_length;
    _pdata = new ElemType[_capacity];
    for(int i=0; i<length; ++i){
        _pdata[i] = arr[i];
    }
}

List::List(const List& l){
    if(l.GetCapacity() == 0){
        _pdata = nullptr;
        _length = 0;
        _capacity = 0;
    }else{
        _capacity = l.GetCapacity();
        _length = l.GetLength();
        _pdata = new ElemType[_capacity];
        for(int i=0; i<_length; ++i){
            _pdata[i] = l[i];
        }
    }
}

List::~List(){
    delete[] this->_pdata;
    _pdata = nullptr;
    _length = 0;
    _capacity = 0;
}


/**
* @brief: 使用下标的方式访问数组
* @param: 
* @return: 当前索引的val
* @error: 如果索引非法，则返回0位置的数据*/
ElemType& List::operator[](int index)const{
    if(index > _length || index < 0){
        std::cerr << "index out of range!" << std::endl;
        return _pdata[0];
    }

    return _pdata[index];
}


/**
* @brief: 判断列表是否为空
* @param: 
* @return: bool, true is empty, or not empty
*/
bool List::ListEmpty() const
{
    return this->_length==0 ? true : false;
}

/**
* @brief: brief
* @param: 
* @return: void
*/
void List::ClearList()
{
    _length = 0;
    if(_capacity > MAXSIZE){
        delete[] _pdata;
        _pdata = new ElemType[MAXSIZE];
        _capacity = MAXSIZE;
    }
}


/**
* @brief: brief
* @param: 
* @return: ElemType
*/
ElemType List::GetElem(int index) const
{
    if(index >= _length || index < 0){
        std::cerr << "out of range: " << index << std::endl;
        return -1;
    }
    return _pdata[index];
}


/**
* @brief: brief
* @param: 
* @return: int
*/
int List::FindElem(ElemType elem) const
{
    for(int i=0; i<_length; ++i){
        if(elem == _pdata[i]){
            return i;
        }
    }
    return -1;
}


/**
* @brief: 在元素序号为index的位置插入元素elem, 当容量不够时,进行以2倍速率扩容.
* @param:  
*       index: 想要插入的元素的下标
*       elem: 要插入的元素值
* @return: bool
*/
bool List::ListInsert(int index, ElemType elem)
{
    if(index > _length || index < 0){
        return false;
    }

    // capacity expansion
    if(_capacity == 0 || _length / float(_capacity) >= 0.75){
        _capacity = _capacity==0 ? MAXSIZE : _capacity*2;
        ElemType* tmp = new ElemType[_capacity];
        memcpy(tmp, _pdata, _length*sizeof(ElemType));
        delete[] _pdata;
        _pdata = tmp;
        std::cout << "expand capacity." << std::endl;
    }

    for(int i=_length-1; i>=index; --i){
        _pdata[i+1] = _pdata[i];
    }
    _pdata[index] = elem;

    ++_length;

    return true;
}

/**
* @brief: 按索引删除元素,当使用率小于0.25时且容量大于MAXSIZE时,回收部分内存.
* @param: 
* @return: ElemType
*/
ElemType List::ListDelete(int index)
{
    if(index >= _length || index < 0){
        std::cerr << "index out of range: " << index << std::endl;
        return INT_MIN;
    }

    ElemType val = _pdata[index];
    for(int i=index; i<_length-1; ++i){
        _pdata[i] = _pdata[i+1];
    }

    --_length;
    if(_capacity > MAXSIZE && _length/float(_capacity) < 0.25){
        _capacity /= 2;
        ElemType* tmp = new ElemType[_capacity];
        memcpy(tmp, _pdata, _length*sizeof(ElemType));
        delete[] _pdata;
        _pdata = tmp;
        std::cout << "reduce the capacity." << std::endl;
    }

    return val;
}

/**
* @brief: brief
* @param: 
* @return: int
*/
int List::GetLength() const
{
    return _length;
}

/**
* @brief: brief
* @param: 
* @return: int
*/
int List::GetCapacity() const
{
    return _capacity;
}


/**
* @brief: 两个线性表取交集
* @param: 
* @return: bool
*/
bool List::ListUnion(const List& l)
{
    if(l.ListEmpty())
        return true;

    int len = l.GetLength();
    for(int i=0; i<len; ++i){
        if(this->FindElem(l[i]) == -1){
            if(!ListInsert(_length, l[i])){
                return false;
            }
        }
    }
    return true;
}



//////////////单链表类函数定义SingleLinkList
/*
 * desc: 链表初始化,只创建一个头结点并初始化头指针
 */
SingleLinkList::SingleLinkList(){
    _head = new Node;
    _head->_data = 0;
    _head->_next = nullptr;
}

/*
 * desc: 链表初始化,只创建一个头结点并初始化头指针
 */
SingleLinkList::SingleLinkList(int num){
    _head = new Node;
    _head->_data = 0;
    _head->_next = nullptr;
    createSingleLinkList(num);
}


SingleLinkList::~SingleLinkList(){
    clear();
    //最后释放头结点
    delete _head;
    std::cout << "destruct success!" << std::endl;
}

/*****************************************************************
* @brief: 从头结点开始插入元素
* @param: 
*   index: 在第index个节点之前插入
*   ele: 插入的元素值
* @retrun:  成功返回true,否则为false
* @comment:  如果index是链表长度+1,则表示直接在链表尾部插入一个节点
* 避免链表为空或在链表末尾不能插入节点的问题
*****************************************************************/
bool SingleLinkList::insertHead(int index, ElemType ele){
    int i=0;
    Node* node = _head;
    while(i < index-1 && node != nullptr){
        node = node->_next;
        ++i;
    }
    
    if((node == nullptr && i<index) || (node != nullptr && index==0)){
        return false;
    }

    Node* tmp = new Node;
    tmp->_data = ele;
    tmp->_next = node->_next;
    node->_next = tmp;
    ++_head->_data;//链表长度加1

    return true;
}

/*****************************************************************
* @brief: 从头结点开始插入节点
* @param: 
*   index: 在第index个节点之前插入
*   node: 插入的节点
* @retrun:  成功返回true,否则为false
* @comment:  -
*****************************************************************/
bool SingleLinkList::insertNodeHead(int index, Node* node){
    int i=0;
    Node* tmp_node = _head;
    while(i < index-1 && tmp_node != nullptr){
        tmp_node = tmp_node->_next;
        ++i;
    }
    
    if((tmp_node == nullptr && i<index) || (tmp_node != nullptr && index==0)){
        return false;
    }

    node->_next = tmp_node->_next;
    tmp_node->_next = node;
    ++_head->_data;//链表长度加1

    return true;
}
/*****************************************************************
* @brief: 遍历链表并打印
* @param: 
* @retrun:  retrun
* @comment:  -
*****************************************************************/
void SingleLinkList::show() const{
    Node* tmp = _head->_next;
    std::cout << "SingleLinkList: " << std::endl;
    while(tmp != nullptr){
        std::cout << tmp->_data << "\t";
        tmp = tmp->_next;
    }
    std::cout << std::endl;
}

/*****************************************************************
* @brief: 删除第index位置的元素,同时将该元素返回到ele中
* @param: 
*   index 第index位置, ele为被删除位置的元素值
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::remove(int index, ElemType& ele){
    if(index <= 0 || index > _head->_data){
        return false;
    }
    int i = 0;
    Node* node = _head; // 1st node
    //找到被删除位置的前置节点
    while( i < index - 1 && node != nullptr){
        node = node->_next;
        ++i;
    }

    Node* tmp = node->_next; //要被删除的节点
    node->_next = tmp->_next; //将被删除节点的下一个节点链接到其前置节点上
    
    ele = tmp->_data;
    delete tmp;
    tmp = nullptr;
    --_head->_data;//链表长度减1

    return true;
}

/*****************************************************************
* @brief: 删除第index位置的元素,不返回被删除节点的值
* @param: 
*   index 第index位置
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::remove(int index){
    if(index <= 0 || index > _head->_data){
        return false;
    }
    int i = 0;
    Node* node = _head; // 1st node
    //找到被删除位置的前置节点
    while( i < index-1 && node != nullptr){
        node = node->_next;
        ++i;
    }

    Node* tmp = node->_next; //要被删除的节点
    node->_next = tmp->_next; //将被删除节点的下一个节点链接到其前置节点上
    
    delete tmp;
    tmp = nullptr;
    --_head->_data;//链表长度减1

    return true;
}

/*****************************************************************
* @brief: 获取第index位置节点的值
* @param: 
*   index 要访问的节点的序列号, ele为该节点的值
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::get(int index, ElemType& ele) const{
    if(index <= 0 || index > _head->_data){
        return false;
    }
    int i = 1;
    Node* node = _head->_next;
    //找到index位置的节点
    while( i < index && node != nullptr){
        node = node->_next;
        ++i;
    }

    ele = node->_data;
    return true;

}

/*****************************************************************
* @brief: 删除链表所有元素并释放所有空间,只保留头结点
* @param: 
*	parametes
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::clear(){
    Node* tmp = _head->_next;
    while(tmp != nullptr){
        //从第一个节点开始释放
        _head->_next = tmp->_next;
        delete tmp;
        --_head->_data;
        tmp = _head->_next;
    }
    return true;
}


/*****************************************************************
* @brief: 创建一个随机链表
* @param: 
*   num: 链表长度
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::createSingleLinkList(int num){
    if(num < 0 || _head->_data > 0){
        return false;
    }
    int i=1;
    Node* tmp = nullptr;

    srand((unsigned int)time(NULL));
    while(i++ <= num){
        tmp = new Node;
        tmp->_data = GET_RAND_NUM;
        tmp->_next = _head->_next;
        if(!insertNodeHead(1, tmp)){
            delete tmp;
            tmp = nullptr;
            clear();
            return false;
        }
    }
    return true;
}

/*****************************************************************
* @brief: i查找值为ele的节点
* @param: 
*   ele: 待查找的元素
* @retrun:  true: success, false: failed
* @comment:  -
*****************************************************************/
bool SingleLinkList::find(ElemType ele) const{
    Node* tmp = _head;
    while(tmp->_next != nullptr && tmp != nullptr){
        tmp = tmp->_next;
        if(ele == tmp->_data){
            return true;
        }
    }
    return false;
}


/*****************************************************************
* @brief: i查找值为ele的节点,并将该节点返回到node,若不存在node=nullptr
* @param: 
*   ele: 待查找的元素
*   node: 若找到ele,则返回第一个ele的节点,否则该节点为nullptr;
* @retrun:  true: success, false: failed
* @comment:  -
*****************************************************************/
bool SingleLinkList::find(ElemType ele, Node* &node) const{
    Node* tmp = _head;
    while(tmp->_next != nullptr && tmp != nullptr){
        tmp = tmp->_next;
        if(ele == tmp->_data){
            node = tmp;
            return true;
        }
    }
    node = nullptr;
    return false;
}


/*****************************************************************
* @brief: 更新index位置的值为ele
* @param: 
*   index: [1,n]
*   ele: 新的值
* @retrun:  retrun
* @comment:  -
*****************************************************************/
bool SingleLinkList::update(int index, ElemType ele){
    if(index <= 0 || index > _head->_data){
        return false;
    }
    int i = 0;
    Node* tmp = _head;
    while(tmp->_next != nullptr && tmp != nullptr){
        tmp = tmp->_next;
        if(++i == index){
            tmp->_data = ele;
            return true;
        }
    }
    return false;
}

int SingleLinkList::get_length() const{
    return _head->_data;
}

void SingleLinkList::get_head(Node* &head) const{
    head = _head;
}


