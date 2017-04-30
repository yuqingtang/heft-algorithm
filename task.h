#ifndef TASK_H
#define TASK_H
#include <cstdlib>
#include <iostream>
#include <iomanip>

class Task
{
private:
    uint16_t id;
    uint32_t ast =0;
    uint32_t aft =0;
    double ranku;
    uint32_t pId = 0;
public:
    Task(int i);
    bool operator <(const Task& t)
    {
         return this->getRanku() > t.getRanku();
    }
    friend  std::ostream &operator <<(std::ostream &out, const Task &t)
    {
        out << "|task " << std::setw(2) << t.getId()+1 << "|AST " << std::setw(2) << t.getAst()
            << "|AFT " << std::setw(2)  << t.getAft() <<"|ranku " << std::setw(7)  << t.getRanku()
            << "|processor " << std::setw(1)  << t.getPId()+1 <<"|" <<std::endl;
        return out;
    }

    uint16_t getId() const;
    void setId(const uint16_t &value);
    uint32_t getAst() const;
    void setAst(const uint32_t &value);
    uint32_t getAft() const;
    void setAft(const uint32_t &value);
    double getRanku() const;
    void setRanku(double value);
    uint32_t getPId() const;
    void setPId(const uint32_t &value);
};


#endif // task_H
