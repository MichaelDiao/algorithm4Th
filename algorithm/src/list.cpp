#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "list.h"

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



