//
//  List.hpp
//  study
//
//  Created by 某某 s on 2020/8/27.
//  Copyright © 2020 某某 s. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
typedef int Status;

class Vertex
{
    int data; //data is stored here
   
    
public:
    Vertex* next;// this pointer tells the next Vertex
    Vertex();
    Vertex(Vertex*, int);
    ~Vertex();
    int getData();
    void changeData(int value, Vertex* a);
    void changeData(int value);
    
    //Vertex* Get(int i)

};

class List
{
private:
    Vertex *head;//Vertex* shows that head is a pointer to list
    Vertex *tail;//tails is same as head but points to NULL
public:
    List();
    virtual ~List();// destructor of base class should be set to a virtual function
    
    Status Init();
    Status Destroy();
    bool isEmpty();
    int Length();
    
    Status Insert(int pos, int value);
    Status Remove(int pos);
    Status Update(int pos, int value);
    Status PrintList();
    
    Vertex* GetAddress(int i);// get address of NO.i
    int GetValue(int i);
    int SearchPosition(int value);
    
};
#endif
/* List_hpp */

