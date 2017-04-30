#include "Task.h"
#include <iostream>

uint16_t Task::getId() const
{
    return id;
}

void Task::setId(const uint16_t &value)
{
    id = value;
}

uint32_t Task::getAst() const
{
    return ast;
}

void Task::setAst(const uint32_t &value)
{
    ast = value;
}

uint32_t Task::getAft() const
{
    return aft;
}

void Task::setAft(const uint32_t &value)
{
    aft = value;
}

double Task::getRanku() const
{
    return ranku;
}

void Task::setRanku(double value)
{
    ranku = value;
}

uint32_t Task::getPId() const
{
    return pId;
}

void Task::setPId(const uint32_t &value)
{
    pId = value;
}

Task::Task(int i)
{
    this->id = i;
}

