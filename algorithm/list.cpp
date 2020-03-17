#include <iostream>
#include <stdexcept>
#include "list.h"

List::List(){
    _pdata = new ElemType[MAXSIZE];
    _length = MAXSIZE;
    _capacity = MAXSIZE;
}

List::List(int length){
    _pdata = new ElemType[length];
    _length = length;
    _capacity = 2*_length;
}

virtual ~List(){
    delete[] this->_pdata;
    _pdata = nullptr;
    _length = 0;
    _capacity = 0;
}


/**
* @brief: 判断列表是否为空
*
* @param: 
*
* @return: bool, true is empty, or not empty
*/
bool ListEmpty() const
{
    return this->_length==0 ? true : false;
}

/**
* @brief: brief
*
* @param: 
*
* @return: void
*/
void ClearList()
{
    for_each(_pdata, _pdata+_length, [](int& ele){ele=0;});
}


/**
* @brief: brief
*
* @param: 
*
* @return: ElemType
*/
ElemType GetElem(int index) const
{
    if(index > _length || index < 0){
        std::cerr << "out of range: " << index << std::endl;
        return -1;
    }
    return _pdata[index];
}


/**
* @brief: brief
*
* @param: 
*
* @return: int
*/
int FindElem(ElemType elem) const
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
bool ListInsert(int index, ElemType elem)
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
