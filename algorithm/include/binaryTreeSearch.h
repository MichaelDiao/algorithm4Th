/*************************************************************************
  > File Name   : binaryTreeSearch.h
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月13日 星期三 17时56分13秒
 ************************************************************************/
#ifndef BINARYTREESEARCH_H
#define BINARYTREESEARCH_H

#include <iostream>
#include <vector>
typedef struct BiTNode{
    int data;
    BiTNode *lchild, * rchild;
}*BiTree, BiTNode;



class BinaryTreeSearch
{
public:
    BinaryTreeSearch ();
    virtual ~BinaryTreeSearch ();
    bool CreateBiTree(const std::vector<int> &arr); //根据一个数组创建一个二叉搜索树
    bool InsertNode(int key); //向树中插入节点
    bool DelNode(const int key); //删除节点
    bool SearchBST(BiTree T, int key, BiTree f, BiTree *p) const; //查找key


    //层序遍历
    void BSTLevelOrder() const;

    //后序遍历
    void BSTPostOrder(bool recursion = true) const;

    //前序遍历
    void BSTPreOrder(bool recursion = true) const;

    //中序遍历
    void BSTInOrder(bool recursion = true) const; //中序遍历 递归实现

private:
    /* data */
    BiTree root;

    void BSTPreOrder(const BiTNode *node) const;//前序遍历 非递归实现
    void BSTPreOrderRecursion(const BiTNode *node) const;//前序遍历 递归实现

    void BSTPostOrderRecursion(const BiTNode *node) const; //后续遍历 递归实现
    void BSTPostOrder(const BiTNode *node) const; //后续遍历 非递归实现

    void BSTInOrder(const BiTNode *node) const; //中序遍历 非递归实现
    void BSTInOrderRecursion(const BiTNode *node) const; //中序遍历 递归实现

    void BSTLevelOrder(const BiTNode *node) const; //层序遍历
};

#endif /* BINARYTREESEARCH_H */
