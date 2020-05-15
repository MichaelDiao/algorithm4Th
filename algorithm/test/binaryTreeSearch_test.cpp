/*************************************************************************
  > File Name   : binaryTreeSearch_test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月13日 星期三 17时57分51秒
 ************************************************************************/
#include<iostream>
#include "binaryTreeSearch.h"

using namespace std;


int main(int argc, char *argv[])
{
    /* int a[]={34, 18, 76, 13,12,11, 52, 82, 16, 67, 58, 73, 72 }; */
    int a[]={62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
    BinaryTreeSearch bst;
    for(auto ele : a){
        if(bst.InsertNode(ele) == false)
            cout << "false" << "\t";
    }

    cout << endl << "--------------------\nPreOrder:" << endl;
    bst.BSTPreOrder();
    bst.BSTPreOrder(false);

    cout << endl << "--------------------\nInOrder:" << endl;
    bst.BSTInOrder();
    bst.BSTInOrder(false);

    /* cout << endl << "--------------------\nPostOrder:" << endl; */
    /* bst.BSTPostOrder(); */
    /* bst.BSTPostOrder(false); */

    /* cout << endl << "--------------------\nLevelOrder:" << endl; */
    /* bst.BSTLevelOrder(); */

    bst.DelNode(62);

    cout << endl << "After del\n--------------------\nPreOrder:" << endl;
    bst.BSTPreOrder();
    bst.BSTPreOrder(false);

    cout << endl << "--------------------\nInOrder:" << endl;
    bst.BSTInOrder();
    bst.BSTInOrder(false);




    return 0;
}
