#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;

typedef vector<vector<int16_t> > v2d;
#include "Task.h"
#include "Function.h"
#include "Processor.h"


uint8_t no_p = 3;




void make_schedule(function &f){
    std::vector<processor> pVector = {processor(0),processor(1),processor(2)};
    v2d comm = f.getComm();
    v2d comp = f.getComp();
    for(size_t i = 0;i < comm.size();i++){
        Task &t = f.getTasks()[i];
        int index = t.getId();
        int min_end = INT32_MAX;
        int a_st;
        int a_p_id;

        // ¼ÆËã EST EFT
        for(int j = 0;j < no_p;j++){
            size_t end = 0;
            processor & p = pVector[j];
            size_t max_start(0);
            vector<std::pair<uint16_t, uint32_t> > & timeslot = p.getFreeTimeSlot();

            for(uint16_t k = 0;k < comm.size();k++){
                size_t start = 0;
                if(comm[k][index] != -1){
                    Task preTask = f.getTaskById(k);
                    start = preTask.getAft() + comm[k][index];
                    if(preTask.getPId() == j){
                        start -= comm[k][index];
                    }

                }

                if(max_start < start)
                    max_start = start;
            }


            if(timeslot.size() == 0){
                end = max_start + comp[index][j];
            }
            else {
                for(uint16_t m = 0 ; m < timeslot.size();m++){
                    uint16_t time1 = timeslot[m].first;
                    uint32_t time2 = timeslot[m].second;
                    int16_t  c  = comp[index][j];



                    if(m == 0){
                        if(max_start < time1){
                            uint32_t t3 = max_start + c;
                            if(t3 <= time1){
                                end = t3;
                                break;
                            }else{
                                if(m == timeslot.size()-1){
                                    max_start = time2;
                                    end = max_start + c;
                                    break;
                                }
                            }

                        }
                    }
                    //else {
                    if(max_start < time2){
                        uint32_t fTime = time2 + c;
                        if(m == timeslot.size() - 1){
                            max_start = time2;
                            end = fTime;
                            break;
                        }else{
                            if(fTime <= timeslot[m+1].first){
                                max_start = time2;
                                end = fTime;
                                break;
                            }
                        }

                    }else {
                        uint32_t fTime = max_start + c;
                        if(m == timeslot.size() - 1){
                            end = fTime;
                            break;
                        }else{
                            if(fTime <= timeslot[m+1].first){
                                end = fTime;
                                break;
                            }
                        }

                    }

                    //}





                }
            }

            if(min_end > end){
                a_p_id = j;
                a_st = max_start;
                min_end = end;
            }
        }

        processor & p = pVector[a_p_id];
        vector<std::pair<uint16_t, uint32_t> > & timeslot = p.getFreeTimeSlot();

        std::pair<uint16_t, uint32_t> pair0 = std::make_pair(a_st,min_end);
        timeslot.push_back(pair0);
        std::sort(timeslot.begin(),timeslot.end());

        t.setAst(a_st);
        t.setAft(min_end);
        t.setPId(a_p_id);
    }

}




int main(int argc, char *argv[])
{
    string file ="C:\\Users\\Administrator\\Documents\\untitled\\Input.txt";
    if(argc == 2)
        string file = argv[1];

    //  cout <<"[DEBUG] "<< file << endl;

    ifstream input(file.c_str());
    string line;
    function func(0);
    v2d vec;
    if(input.is_open())
    {
        for(uint8_t i =0; i < 20;++i)
        {
            int t;
            vector<int16_t> v;
            getline(input,line);
            istringstream iss(line);
            while(iss >> t)
                v.push_back(t);
            vec.push_back(v);
            if(i == 9)
            {
                func.setComp(vec);
                vec.clear();
            }
        }
        func.setComm(vec);
    }

    func.init();
    std::cout << "----------------[before schedule]---------------" << std::endl;
    for(uint8_t i = 0; i < 10 ; i++){
        cout << func.getTasks().at(i);
    }

    make_schedule(func);
    std::cout << "----------------[after schedule]----------------" << std::endl;
    for(uint8_t i = 0; i < 10 ; i++){
        cout << func.getTasks().at(i);
    }

    vec.clear();
    input.close();
    return 0;
}





