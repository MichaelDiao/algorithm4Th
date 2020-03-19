#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "list.h"

List::List(){
    _pdata = new ElemType[MAXSIZE];
    _length = 0;
    _capacity = MAXSIZE;
}

List::List(const ElemType arr[], int length){
    _pdata = new ElemType[length];
    _length = length;
    _capacity = 2*_length;
    for(int i=0; i<length; ++i){
        _pdata[i] = arr[i];
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
    std::for_each(_pdata, _pdata+_length, [](int& ele){ele=0;});
}


/**
* @brief: brief
* @param: 
* @return: ElemType
*/
ElemType List::GetElem(int index) const
{
    if(index > _length || index < 0){
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
* @brief: 在元素序号为index的位置插入元素elem
* @param:  
*       index: 想要插入的元素的下标
*       elem: 要插入的元素值
* @return: bool
*/
bool List::ListInsert(int index, ElemType elem)
{
    if(index > _capacity || index < 0){
        return false;
    }

    // capacity expansion
    if(_length / float(_capacity) >= 0.75){
        _capacity *= 2;
        ElemType* tmp = new ElemType[_capacity];
        memcpy(tmp, _pdata, _length);
        delete[] _pdata;
        _pdata = tmp;
    }

    for(int i=_length-1; i>=index; --i){
        _pdata[i+1] = _pdata[i];
    }
    _pdata[index] = elem;

    return true;
}

/**
* @brief: brief
* @param: 
* @return: ElemType
*/
ElemType List::ListDelete(int index)
{
    if(index > _length || index < 0){
        return INT_MIN;
    }

    ElemType val = _pdata[index];
    for(int i=index; i<_length-i; --i){
        _pdata[i] = _pdata[i+1];
    }

    --_length;

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
            if(!ListInsert(_length-1, l[i])){
                return false;
            }
        }
    }
    return true;
}



