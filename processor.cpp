#include "Processor.h"



vector<std::pair<uint16_t, uint32_t> > & processor::getFreeTimeSlot()
{
    return freeTimeSlot;
}

void processor::setFreeTimeSlot(const vector<std::pair<uint16_t, uint32_t> > &value)
{
    freeTimeSlot = value;
}

processor::processor(int id)
{
    this->id = id;
}
