//
//  List.cpp
//  study
//
//  Created by 某某 s on 2020/8/27.
//  Copyright © 2020 某某 s. All rights reserved.
//

#include "List.hpp"
#include <iostream>

#define ERROR 1
#define OK 0

using namespace std;

Vertex::Vertex(){
    data = 0;
    next = NULL;
}

Vertex::Vertex(Vertex* newNext, int newData){
    data = newData;
    next = newNext;
}
Vertex::~Vertex()
{
    
}

int Vertex::getData()
{
    return this->data;
}

void Vertex::changeData(int value, Vertex * a)
{
    //this->data =value;
    int *temp = (int*) &a;
    *temp = value;
}

void Vertex::changeData(int value)
{
    this->data = value;
}

List::List(){
    head = NULL;
    tail = NULL;
}

List::~List(){
    Destroy();
}

Status List::Init(){
    head = new Vertex(NULL,0);
    if (head != NULL)
    {
        cout<<"init is done!"<<endl;
        return OK;
    }
    
    return ERROR;
}

Status List::Destroy(){
    if (head != NULL)
    {
        Vertex *temp = head;
        while(head)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        return OK;
    }
    else
    {
        cout<<"list is NULL already"<<endl;
        return ERROR;
    }
}

bool List::isEmpty()
{
    return (head == NULL);
}

int List::Length(){
    if (!head)
    {
        cout<<"this list is NULL"<<endl;
        exit(-1);
    }
    Vertex* temp = head->next;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//插入节点

Status List::Insert(int pos, int value)
{
    if (isEmpty())
    {
        cout<<"this list is NULL plz init a new list first"<<endl;
        exit(-1);
    }
    //create a new node for store which will be inserted
    Vertex* newNode = new Vertex(NULL,value);
    //if insert to the head
    if (pos == 0){
        //newNode->changeData(value);
        newNode->next = head->next;
        head->next = newNode;
    }
    else if (pos > 0 && pos<=Length())
    {
        Vertex* preNode = GetAddress(pos-1);//找到要插入位置前一个节点
        if (preNode != NULL)
        {
            if(preNode->next !=NULL)//not tail
            {
                newNode->next = preNode->next;
            }
            preNode->next = newNode;
            
        }
    }
    else
    {
        cout<<"input param pos is wrong! "<<endl;
        return ERROR;
    }
    return OK;
        
}

//获取地址

Vertex* List::GetAddress(int i)
{
    Vertex* ptr = head; // we have to start from head
    for (int k = 0; k < i; k++) // advance forward i time(s)
      ptr = ptr->next; // the pointers are pointing to the higher index
    return ptr;
}

//获取值

int List::GetValue(int i)
{
    Vertex* ptr = GetAddress(i);
    if (ptr != NULL)
    {
        return ptr->getData();
        //return ptr->data;举例子说明这里是不行的 用内部的函数将这个private的data提取出来
    }
    else
    {
        cout<<"this node is NULL!!"<<endl;
        return ERROR;
    }
}

//删除节点

Status List::Remove(int pos)
{
    Vertex * preNode = NULL;
    Vertex * curNode = NULL;
    Vertex * nextNode = NULL;
    
    if (pos < 0 || pos >= Length())
    {
        cout <<"Remove node has wrong position"<<endl;
        exit(-1);
    }
    else if (pos == 0)
    {
        preNode = head;
    }
    else if (pos < this->Length())
    {
        preNode = GetAddress(pos - 1);
    }
    
    if (!preNode){
        return ERROR;
    }
    curNode = preNode->next;
    if(curNode){
        nextNode = curNode->next;//如果是最后一个节点 curNode->next 就是tail 而tail is NULL
        preNode->next = nextNode;
        delete curNode;
    }
    
    return OK;
        
}

//寻找第一个出现的节点
int List::SearchPosition(int value)
{
    if(!head){
        cout<<"this list is NULL"<<endl;
        exit(-1);
    }
    Vertex* start = head->next;
    int pos = 0;
    while (start != NULL)
    {
        pos++;
        if (start->getData() == value)
        {
            return pos;
        }
        else{
            start = start->next;
        }
    }
    cout<<"can't find this value in this list"<<endl;
    return ERROR;
}

//更新指定位置的数值
Status List::Update(int pos, int value)
{
    Vertex * pointNode = GetAddress(pos);
    if (pointNode != NULL)
    {
        pointNode->changeData(value);
        //pointNode->changeData(value,pointNode);这里这样为啥改不了呢？？
        cout<<"now this node is "<< pointNode->getData()<<endl;
        return OK;
    }
    
    return ERROR;
    
}

//打印链表
Status List::PrintList(){
    if(isEmpty())
    {
        cout<<"this list is NULL, plz create a new list and init it!"<<endl;
        return ERROR;
    }
    
    cout<<"List:[ ";
    if (Length() == 0)
    {
        cout<<"NULL"<<endl;
    }
    else
    {
        Vertex* p = head->next;
        while (p!= NULL)
        {
            cout<<p->getData()<<" ";
            p = p->next;
        }
    }
    cout<<"]"<<endl;
    return OK;
}






