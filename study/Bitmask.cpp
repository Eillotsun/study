//
//  Bitmask.cpp
//  study
//
//  Created by 某某 s on 2020/8/25.
//  Copyright © 2020 某某 s. All rights reserved.
//



//位运算 & 按位或 0&0=0 1&0=0 0&1=0 1&1=1
//      | 按位于 0|0=0 1|0=1 0|1=1 1|1=1
//      ~ 取反   ~1=0 ~0=1
//      ^ 异或   0^0=0 0^1=1 1^0=1 1^1=0
//      ?: 三元运算符  int result = 1 > 2 ? 1 + 1 : 2 + 2; result = 4
#include <iostream>
#include "Bitmask.h"


using namespace std;



void Permisson::set_permisson (int permisson)
{
    flag = permisson;
}
//增加一项或者多项权限
void Permisson::enable_permisson(int permisson)
{
    flag = flag | permisson;
}
//删除一项或者多项权限
void Permisson::disable_permisson(int permission)
{
    flag = flag & ~permission;
}
//是否有这项权限
int Permisson::is_allow(int permission)
{
    return ((flag & permission) == permission);
}
//是否没有这样的权限
int Permisson::is_not_allow (int permission)
{
    return ((flag & permission) == permission);
}
//是否只有这个权限
int Permisson::is_only_allow (int permission)
{
    return (flag == permission);
}
int Permisson::get_flag ()
{
    return flag;
}



