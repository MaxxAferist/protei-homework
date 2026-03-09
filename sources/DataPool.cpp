#include "DataPool.h"
#include <iostream>

ERROR_INFO DataPool::first(vector<any> &vec)
{
    if (MyVec->size() == 0)
    {
        return ERROR_INFO(ERROR_CODE, "data pool is empty");
    }
    vec = MyVec->back();
    MyVec->pop_back();
    return ERROR_INFO(S_OK, "success");
}


void DataPool::insert(vector<any> const &vec)
{
    MyVec->insert(MyVec->begin(), vec);
}


size_t DataPool::length()
{
    return MyVec->size();
}