#ifndef _DATAPOOL_H_
#define _DATAPOOL_H_


#include <vector>
#include <any>

#include "define.h"
#include "some_structures.h"


using namespace std;


struct DataPool
{
    ERROR_INFO first(vector<any> &vec);
    void insert(vector<any> const &vec);
    size_t length();

private:
    vector<vector<any>> MyVec;
};


#endif