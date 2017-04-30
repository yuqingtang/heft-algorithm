#include "Function.h"
#include <algorithm>

function::function(int i):id(i){}

uint16_t function::getId() const
{
    return id;
}

v2d function::getComm() const
{
    return comm;
}

void function::setComm(const v2d &value)
{
    comm = value;
}

v2d function::getComp() const
{
    return comp;
}

void function::setComp(const v2d &value)
{
    comp = value;
}

vector<Task> &function::getTasks()
{
    return tasks;
}

void function::setTasks(const vector<Task> &value)
{
    tasks = value;
}

void function::init()
{
    for(uint16_t t =0;t < comm.size();t++)
    {
        Task task(t);
        tasks.push_back(task);
    }
    vector<double> v(comm.size(),0.0);
    for(int16_t j =comm.size()-1;j > -1;--j)
    {
        double x = calRank(j,v);
        tasks[j].setRanku(x);
    }

    sort(tasks.begin(),tasks.end());
}

double function::calRank(int i, vector<double> &v)
{
    double avg = 0.0,r=0.0 ,max=0.0;

    for(uint8_t j =0;j<comp[0].size();j++)
        avg+=comp[i][j];
    avg /= comp[0].size();

    for(uint8_t k =i+1;k < comm.size();k++)
    {
        if(comm[i][k] != -1){
            if(v.at(k) != 0.0)
                r = comm[i][k]+v.at(k);
            r = comm[i][k] + calRank(k,v);
        }

        if(max < r)
            max = r;
    }
    return avg + max;
}

Task function::getTaskById(int id)
{
     std::vector<Task> v = getTasks();
    for(uint16_t i = 0; i < v.size();i++){
        if(id == v.at(i).getId()){
            return v.at(i);
        }
    }
}


