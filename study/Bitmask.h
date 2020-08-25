//
//  Bitmask.h
//  study
//
//  Created by 某某 s on 2020/8/25.
//  Copyright © 2020 某某 s. All rights reserved.
//

#ifndef Bitmask_h
#define Bitmask_h

#include <iostream>


using namespace std;

//这边可以通过const 来替换宏定义#define 因为const可以做类型的检查 若要共享如下的这些常量可以加上 extern 关键词
const int ALLOW_SELECT = 1<<0;//不过如果这里加上extern关键词会出现duplicate symbols 报错 这里主要是这个.h文件被多个.cpp包含就会出现重复定义的错误
const int ALLOW_INSERT = 1<<1;
const int ALLOW_UPDATE = 1<<2;
const int ALLOW_DELETE = 1<<3;

class Permisson
{
    public:
    //设置新的权限
    void set_permisson (int permisson);
    
    //增加一项或者多项权限
    void enable_permisson (int permisson);
  
    //删除一项或者多项权限
    void disable_permisson (int permission);

    //是否有这项权限
    int is_allow (int permission);

    //是否没有这样的权限
    int is_not_allow (int permission);

    //是否只有这个权限
    int is_only_allow (int permission);

    int get_flag ();

    private:
    
    int flag = 0;//https://www.runoob.com/w3cnote/cpp-static-usage.html 关于static 详解

};


#endif /* Bitmask_h */
