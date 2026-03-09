#ifndef _DATAPOOL_H_
#define _DATAPOOL_H_


#include <vector>
#include <any>
#include <memory>

#include "define.h"
#include "some_structures.h"


using namespace std;


struct DataPool
{
    ERROR_INFO first(vector<any> &vec);
    void insert(vector<any> const &vec);
    size_t length();

private:
    shared_ptr<vector<vector<any>>> MyVec = make_unique<vector<vector<any>>>();
};


#endif