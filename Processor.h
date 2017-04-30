#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <vector>
#include <cstdint>
using namespace std;

typedef vector<vector<int16_t> > v2d;
class processor
{
private:
    uint32_t id;
    vector<std::pair<uint16_t,uint32_t> > freeTimeSlot;
public:
    processor(int id);
    vector<std::pair<uint16_t, uint32_t> > & getFreeTimeSlot() ;
    void setFreeTimeSlot(const vector<std::pair<uint16_t, uint32_t> > &value);
};

#endif // PROCESSOR_H
