#include<iostream>
#include <ctime>
#include "list.h"
#include "show.h"

using namespace std;

void list_test(){
    int arr[10] = {5, 18, 78, 72, 781, 274, 63, 82, 298, 671};
    int arr2[7] = {72, 81, 274, 77, 82, 61, 1927};
    show_arr(arr, 10);
    show_arr(arr2, 7);
    cout << "*************" << endl;
    List l1(arr, 10);
    List l2(arr2, 7);
    List l4;
    List l3(l4);


    cout << "L1 insert 0, 18?: " << l1.ListInsert(0, 18) << ", insert 10,100?:" << l1.ListInsert(10, 110) << endl;
    cout << "L1 insert 0, 18?: " << l1.ListInsert(0, 28) << ", insert 10,100?:" << l1.ListInsert(10, 140) << endl;
    cout << "L1 insert 0, 18?: " << l1.ListInsert(0, 88) << ", insert 10,100?:" << l1.ListInsert(10, 120) << endl;

    cout << "L1 delete 1?: " << l1.ListDelete(1) << ", delete 10?:" << l1.ListDelete(1) 
        << ", delete 5?: " << l1.ListDelete(5) << ", delete 671?:" << l1.ListDelete(6) 
        << ", delete 5?: " << l1.ListDelete(5) << ", delete 671?:" << l1.ListDelete(6) 
        << ", delete 5?: " << l1.ListDelete(5) << ", delete 671?:" << l1.ListDelete(6) << endl;

/*     cout << "L1 empty? " << l1.ListEmpty() << endl; */
/*     cout << "L2 empty? " << l2.ListEmpty() << endl; */
/*     cout << "L3 empty? " << l3.ListEmpty() << endl; */

/*     cout << endl; */
/*     cout << "L1 operator[2]: " << l1[2] << ", l1[11]: " << l1[11] << ", l1[-1]: " << l1[-1] << endl; */

/*     cout << "L2 operator[2]: " << l2[2] << ", l2[11]: " << l2[11] << ", l2[-1]: " << l2[-1] << endl; */
/*     cout << "L3 operator[2]: " << l3[2] << ", l3[11]: " << l3[11] << ", l3[-1]: " << l3[-1] << endl; */


/*     cout << endl; */
/*     cout << "GetElem" << endl; */
/*     cout << "L1 [1]: " << l1.GetElem(1) << ", [10]: " << l1.GetElem(10) << ", [5]:" << l1.GetElem(5) << endl; */
/*     cout << "L2 [1]: " << l2.GetElem(1) << ", [10]: " << l2.GetElem(7) << ", [5]:" << l2.GetElem(5) << endl; */
/*     cout << "L3 [1]: " << l3.GetElem(1) << ", [10]: " << l3.GetElem(10) << ", [5]:" << l3.GetElem(5) << endl; */


/*     cout << endl; */
/*     cout << "FindElem" << endl; */
/*     cout << "L1 find 18?: " << l1.FindElem(18) << ", find 100?:" << l1.FindElem(100) */ 
/*         << ", find 5?: " << l1.FindElem(5) << ", find 671?:" << l1.FindElem(671) << endl; */
/*     cout << "L2 find 77?: " << l2.FindElem(77) << ", find 100?:" << l2.FindElem(100) */ 
/*         << ", find 72?: " << l2.FindElem(72) << ", find 1927?:" << l2.FindElem(1927) << endl; */
/*     cout << "L3 find 18?: " << l3.FindElem(18) << ", find 100?:" << l3.FindElem(100) */ 
/*         << ", find 5?: " << l3.FindElem(5) << ", find 671?:" << l3.FindElem(671) << endl; */



    /* cout << endl; */
    /* cout << "ListInsert" << endl; */
    /* cout << "L1 insert 0, 18?: " << l1.ListInsert(0, 18) << ", insert 10,100?:" << l1.ListInsert(10, 100) */ 
    /*     << ", insert 7,5?: " << l1.ListInsert(7, 5) << ", insert 20, 671?:" << l1.ListInsert(20, 671) << endl; */
    /* cout << "L2 insert 0, 77?: " << l2.ListInsert(0, 77) << ", insert 7, 100?:" << l2.ListInsert(7,100) */ 
    /*     << ", insert 4, 72?: " << l2.ListInsert(4, 72) << ", insert 22, 1927?:" << l2.ListInsert(22, 1927) << endl; */
    /* cout << "L3 insert 0, 18?: " << l3.ListInsert(0, 18) << ", insert 2,100?:" << l3.ListInsert(2,100) */ 
    /*     << ", insert 1, 5?: " << l3.ListInsert(1, 5) << ", insert 4, 671?:" << l3.ListInsert(4, 671) << endl; */

    /* cout << "L1 raw: " << endl; */
    /* for(int i=0; i<l1.GetLength(); ++i){ */
    /*     cout << l1[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L2 raw: " << endl; */
    /* for(int i=0; i<l2.GetLength(); ++i){ */
    /*     cout << l2[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L3 raw: " << endl; */
    /* for(int i=0; i<l3.GetLength(); ++i){ */
    /*     cout << l3[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << endl; */
    /* cout << "ListDelete" << endl; */
    /* cout << "L1 delete 1?: " << l1.ListDelete(1) << ", delete 10?:" << l1.ListDelete(10) */ 
    /*     << ", delete 5?: " << l1.ListDelete(5) << ", delete 671?:" << l1.ListDelete(671) << endl; */
    /* cout << "L2 delete 7?: " << l2.ListDelete(7) << ", delete 0?:" << l2.ListDelete(0) */ 
    /*     << ", delete 10?: " << l2.ListDelete(10) << ", delete 19?:" << l2.ListDelete(19) << endl; */
    /* cout << "L3 delete 18?: " << l3.ListDelete(18) << ", delete 100?:" << l3.ListDelete(100) */ 
    /*     << ", delete 5?: " << l3.ListDelete(5) << ", delete 671?:" << l3.ListDelete(671) << endl; */

    /* cout << "L1 raw: " << endl; */
    /* for(int i=0; i<l1.GetLength(); ++i){ */
    /*     cout << l1[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L2 raw: " << endl; */
    /* for(int i=0; i<l2.GetLength(); ++i){ */
    /*     cout << l2[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L3 raw: " << endl; */
    /* for(int i=0; i<l3.GetLength(); ++i){ */
    /*     cout << l3[i] << "\t"; */
    /* } */
    /* cout << endl; */

    cout << endl;
    cout << "GetLength" << endl;
    cout << "L1 len: " << l1.GetLength() << ", L2 len: " << l2.GetLength() << ", l3 len: " << l3.GetLength() << endl;

    cout << endl;
    cout << "GetCapacity" << endl;
    cout << "L1 len: " << l1.GetCapacity() << ", L2 len: " << l2.GetCapacity() << ", l3 len: " << l3.GetCapacity() << endl;


    /* cout << endl; */
    /* cout << "ListUnion" << endl; */
    cout << "L1 raw: " << endl;
    for(int i=0; i<l1.GetLength(); ++i){
        cout << l1[i] << "\t";
    }
    cout << endl;

    /* cout << "L2 raw: " << endl; */
    /* for(int i=0; i<l2.GetLength(); ++i){ */
    /*     cout << l2[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L3 raw: " << endl; */
    /* for(int i=0; i<l3.GetLength(); ++i){ */
    /*     cout << l3[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "--------------starting union" << endl; */
    /* l1.ListUnion(l2); */
    /* cout << "--------------end union" << endl; */
    /* cout << "L1 raw: " << endl; */
    /* for(int i=0; i<l1.GetLength(); ++i){ */
    /*     cout << l1[i] << "\t"; */
    /* } */
    /* cout << endl; */

    /* cout << "L2 raw: " << endl; */
    /* for(int i=0; i<l2.GetLength(); ++i){ */
    /*     cout << l2[i] << "\t"; */
    /* } */
    /* cout << endl; */

    cout << "L3 raw: " << endl;
    for(int i=0; i<l3.GetLength(); ++i){
        cout << l3[i] << "\t";
    }
    cout << endl;

    cout << "all done" << endl;

}

void singleLinkListTest(){
    SingleLinkList sll1;
    sll1.insertHead(1, 10);
    Node* node = new Node(5);
    sll1.insertNodeHead(2, node);
    cout << "len: " << sll1.get_length() << endl;
    if(sll1.insertHead(3, 12)){
        cout << "insert success" << endl;
    }else{
        cout << "insert failed" << endl;
    }
    node = new Node(8);
    sll1.insertNodeHead(5, node);

    sll1.show();
    ElemType ele = 0;
    if(sll1.remove(3, ele)){
        cout << "remove success, ele=" << ele << endl;
    }else{
        cout << "remove failed" << endl;
    }
    sll1.show();
    
    if(sll1.get(0, ele)){
        cout << "get success, ele=" << ele << endl;
    }else{
        cout << "get failed" << endl;
    }

    if(sll1.find(10)){
        cout << "find 12 success " << endl;
    }else{
        cout << "find 12 failed" << endl;
    }
    node = nullptr;
    if(sll1.find(11, node)){
        cout << "find 12 success, next: " << node->_next << ", data:" << node->_data << endl;
    }else{
        cout << "find 12 failed" << endl;
    }
    cout << "------------" << endl;
    SingleLinkList sll2(10);
    sll2.show();
    sll2.update(0, 1000);
    sll2.update(10, 2000);
    sll2.update(1, 3000);
    sll2.update(4, 5000);
    cout << "len: " << sll2.get_length() << endl;
    node = nullptr;
    sll2.get_head(node);
    if(node){
        cout << "1st data: " << node->_next->_data << endl;
    }else{
        cout << "get head failed." << endl;
    }
    sll2.show();
    sll2.clear();
    sll2.show();

}

int main(int argc, char *argv[])
{
    cout << "starting test: " << endl;
    singleLinkListTest();

    cout << "end test! " << endl;

    return 0;
}
