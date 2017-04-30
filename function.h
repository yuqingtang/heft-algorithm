#ifndef FUNCTION_H
#define FUNCTION_H
#include "Task.h"
#include <vector>
using namespace std;

typedef vector<vector<int16_t> > v2d;

class function
{
private:
    uint16_t id;
    v2d comm;
    v2d comp;
    vector<Task> tasks;
public:
    function(int i);
    uint16_t getId() const;
    v2d getComm() const;
    void setComm(const v2d &value);
    v2d getComp() const;
    void setComp(const v2d &value);
    vector<Task>& getTasks();
    void setTasks(const vector<Task> &value);
    void init();
    double calRank(int i,vector<double> &v);
    Task getTaskById(int id);
};

#endif // FUNCTION_H
