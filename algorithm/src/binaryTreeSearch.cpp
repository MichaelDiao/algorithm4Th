/*************************************************************************
  > File Name   : binaryTreeSearch.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月13日 星期三 17时55分47秒
 ************************************************************************/
#include "binaryTreeSearch.h"
#include <queue>
#include <stack>

BinaryTreeSearch::BinaryTreeSearch(){
    this->root = nullptr;
}


BinaryTreeSearch::~BinaryTreeSearch(){
    std::queue<BiTree> my_que;
    my_que.push(root);
    while(!my_que.empty()){
        BiTree tmp = my_que.front();
        if(nullptr != tmp->lchild)
            my_que.push(tmp->lchild);
        if(nullptr != tmp->rchild)
            my_que.push(tmp->rchild);
        delete tmp;
        my_que.pop();
    }
    root = nullptr;
}

bool BinaryTreeSearch::CreateBiTree(const std::vector<int> &arr){

    return true;
}

/*****************************************************************
* @brief: 插入节点到二叉搜索树中
* @param: 
*	BiTree *T: 当前的二叉搜索树的某个节点
*	int key: 想要插入的节点的值
* @retrun: 插入成功返回true，否则返回false
* @comment:  -
*****************************************************************/
bool BinaryTreeSearch::InsertNode(int key){
    BiTree p, s;
    if(!SearchBST(root, key, nullptr, &p)){//not find it
        s = new BiTNode;
        s->data = key;
        s->lchild = s->rchild = nullptr;
        if(nullptr == p){
            root = s; //插入的s为新的根节点
        }else if(key < p->data){
            p->lchild = s; //插入的节点为左孩子
        }else{
            p->rchild = s; // right child
        }
        return true;
    }

    return false;
}

/*****************************************************************
* @brief: 删除某个节点
* 二叉搜索树中，节点存在以下四种状态：
*       节点无左右孩子；
*       节点有左孩子，无有孩子；
*       节点有右孩子，无左孩子；
*       节点左右孩子都有；
* @param: 
*	int key: 欲删值
* @retrun:  删除成功返回true，否则false
* @comment:  -
*****************************************************************/
bool BinaryTreeSearch::DelNode(const int key){
    if(nullptr == root)
        return false;
    //查找欲删节点
    BiTree *del_node = &root;
    while((*del_node)->data != key){
        if((*del_node)->data < key){
            del_node = &((*del_node)->rchild);
        }else if((*del_node)->data > key){
            del_node = &((*del_node)->lchild);
        }
    }

    BiTree p;
    BiTree s;
    //根据欲删节点左右孩子情况，分四种情况讨论
    //无左孩子, 直接把有孩子替换到当前节点
    if(nullptr == (*del_node)->lchild && nullptr == (*del_node)->rchild){//左右孩子都为空，则直接删除当前节点
        delete del_node;
        del_node = nullptr;
    }else if(nullptr == (*del_node)->lchild){
        //保存当前节点位置
        p = *del_node;
        //将右孩子替换到当前节点处
        (*del_node) = (*del_node)->rchild;
        //将堆中想要删除的节点空间释放
        delete p;
        p = nullptr;
    }else if(nullptr == (*del_node)->rchild){//无右孩子，直接将左孩子替换到当前节点处
        //保存当前节点位置
        p = *del_node;
        //将左孩子替换到当前节点处
        (*del_node) = (*del_node)->lchild;
        //将堆中想要删除的节点空间释放
        delete p;
        p = nullptr;
    }else {//左右孩子都有，需要找到以当前节点的左右孩子为根的树中最小值或者最大值，用其替换欲删除节点
        // 1. 选左子树中最大值替代欲删除节点
        // 2. 选右子树中最小值替代欲删除节点
        //二叉搜索树中，根节点一定大于左子树任意节点，一定小于等于右子树任意节点
        //这里采用第一种方法，选左子树最大值替换
        p = *del_node;//保存欲删除节点的地址
        //找左子树最大值, 根据二叉搜索树性质，找到左子树的中序遍历的最后一个节点既是最大值
        s = (*del_node)->lchild;
        
        while(nullptr != s->rchild){
            //需要把左子树最大值节点的父节点记录下来，因为将最大值节点移走后，需要将最大值节点的左子树顶上来
            p = s;
            s = s->rchild;
        }

        (*del_node)->data = s->data;//将最大值覆盖到欲删除节点上
        //找到的最大值节点一定没有右孩子，所以只需要重新拼接最大值的左孩子即可
        if(p == *del_node){//如果最大值节点的父节点就是欲删除节点的左孩子，则需要将最大值节点的左孩子替换到欲删节点的左孩子上
            p->lchild = s->lchild;
        }else{//否则，需要将最大值节点的父节点的右孩子设置为最大值的左孩子
            p->rchild = s->lchild;
        }
        delete s;
        s = nullptr;
        p = nullptr;
        
    }


    return true;
}

/*****************************************************************
* @brief: 递归查找二叉排序树T中是否存在key
* @param: 
*	BiTree T: 二叉树的顶点
*	int key: 欲查找的值
*	BiTree f: 指针f指向T的双亲，若T为根节点，则赋值为nullptr
*	BiTree *p:若查找成功：指针p指向该数据元素节点，并返回true
*	        若查找失败： 指针指向查找路径上访问的最后一个节点，并返回false
* @retrun: 查找成功返回true，否则为false
* @comment:  -
*****************************************************************/
bool BinaryTreeSearch::SearchBST(BiTree T, int key, BiTree f, BiTree *p) const{
    if(nullptr == T){
        *p = f;
        return false;
    }else if(key == T->data){
        *p = T;
        return true;
    }else if(key < T->data){
        return SearchBST(T->lchild, key, T, p);// finding it in left tree
    }else{
        return SearchBST(T->rchild, key, T, p);// finding it in right tree
    }

    return false;
}

//中序遍历
void BinaryTreeSearch::BSTInOrder(bool recursion) const{
    if(recursion)
        BSTInOrderRecursion(root);
    else
        BSTInOrder(root);
    std::cout << std::endl;
}

void BinaryTreeSearch::BSTInOrder(const BiTNode *node) const{
    if(nullptr == node)
        return;
    std::stack<const BiTNode*> my_stack;
    const BiTNode *tmp = node->lchild;
    my_stack.push(node);

    while(nullptr != tmp || !my_stack.empty()){
        if(nullptr != tmp){
            my_stack.push(tmp);
            tmp = tmp->lchild;
        }else{
            tmp = my_stack.top();
            std::cout << tmp->data << " ";
            my_stack.pop();
            tmp = tmp->rchild;
        }
    }
}

void BinaryTreeSearch::BSTInOrderRecursion(const BiTNode *node) const{
    if(nullptr == node){
        return;
    }
    BSTInOrderRecursion(node->lchild);
    std::cout << node->data << " ";
    BSTInOrderRecursion(node->rchild);
}


//层序遍历
void BinaryTreeSearch::BSTLevelOrder() const{
    BSTLevelOrder(root);
    std::cout << std::endl;
}

void BinaryTreeSearch::BSTLevelOrder(const BiTNode *node) const{
    if(nullptr == node)
        return;
    std::queue<const BiTNode*> que;
    que.push(node);
    while(!que.empty()){
        const BiTNode *tmp = que.front();
        std::cout << tmp->data << " ";
        if(nullptr != tmp->lchild)
            que.push(tmp->lchild);
        if(nullptr != tmp->rchild)
            que.push(tmp->rchild);
        que.pop();
    }
}

//后序遍历
void BinaryTreeSearch::BSTPostOrder(bool recursion) const{
    if(recursion)
        BSTPostOrderRecursion(root);
    else
        BSTPostOrder(root);
    std::cout << std::endl;
}

void BinaryTreeSearch::BSTPostOrder(const BiTNode *node) const{
    if(nullptr == node)
        return;
    std::stack<const BiTNode *> childs, parents;
    childs.push(node);

    while(!childs.empty()){
        const BiTNode *tmp = childs.top();
        childs.pop();
        parents.push(tmp);//当前节点升级为父节点，然后把该父节点的孩子节点放入孩子栈中

        if(nullptr != tmp->lchild){
            childs.push(tmp->lchild);
        }   
        if(nullptr != tmp->rchild){
            childs.push(tmp->rchild);
        }   
    }

    while(!parents.empty()){
        std::cout << parents.top()->data << " ";
        parents.pop();
    }

}

void BinaryTreeSearch::BSTPostOrderRecursion(const BiTNode *node) const{
    if(nullptr == node){
        return;
    }

    BSTPostOrderRecursion(node->lchild);
    BSTPostOrderRecursion(node->rchild);
    std::cout << node->data << " ";

}

//前序遍历
void BinaryTreeSearch::BSTPreOrder(bool recursion) const{
    if(recursion)
        BSTPreOrderRecursion(root);
    else
        BSTPreOrder(root);
    std::cout << std::endl;
}

void BinaryTreeSearch::BSTPreOrder(const BiTNode *node) const{
    if(nullptr == node)
        return;
    std::stack<const BiTNode *> my_stack;
    my_stack.push(node);

    while(!my_stack.empty()){
        const BiTNode *tmp = my_stack.top();
        std::cout << tmp->data << " ";
        my_stack.pop();
        if(nullptr != tmp->rchild){
            my_stack.push(tmp->rchild);
        }   
        if(nullptr != tmp->lchild){
            my_stack.push(tmp->lchild);
        }   
    }
}

void BinaryTreeSearch::BSTPreOrderRecursion(const BiTNode *node) const {
    if(nullptr == node){
        return;
    }

    std::cout << node->data << " ";
    BSTPreOrderRecursion(node->lchild);
    BSTPreOrderRecursion(node->rchild);
}
