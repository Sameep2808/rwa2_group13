#include "algorithm.h"
#include "../simulator/simulator.h"

#include <iostream>
#include <utility>
#include <ctime>    //for random number seed

#include <unistd.h>
//---------------------------------------------------------------------
namespace rwagroup12
{
    //-----------------------------------------------------------------
    void Algorithm::generate_goal(){
        //Randomly assigning the goal position/coordinates
        srand(time(0));
        int x{(rand() % 16)};
        int y{0};
        if (x == 0){
            y = 1 + (rand() % 15);
        }
        else if (x == 15){
            y = rand() % 16;
        }
        else{
            int y_vals[2] = {0, 15};
            y = y_vals[rand() % 2];    //randomly picks 0 or 15
        }
        goal.first = x;
        goal.second = y;

        //Marking the goal as "G" and background color as red
        Simulator::setColor(x, y, 'r');
        Simulator::setText(x, y, "G");
    }
    //-----------------------------------------------------------------

    //-----------------------------------------------------------------
    void Algorithm::init_outer_walls(){
        for(int row{0}; row <= 15; ++row){
            for(int col{0}; col <= 15; ++col){
                //checking the left and right column
                if (col == 0){
                    Simulator::setWall(row, col, 's');
                }
                if (col == 15){
                    Simulator::setWall(row, col, 'n');
                }
                //checking the bottom and top row
                if (row == 0){
                    Simulator::setWall(row, col, 'w');
                }
                if (row == 15){
                    Simulator::setWall(row, col, 'e');
                }
            }
        }
    }
    //-----------------------------------------------------------------

    //-----------------------------------------------------------------
    void Algorithm::get_goal(){
        std::cerr << "The goal is: " << std::endl;
        std::cerr << "(" << goal.first << ", " << goal.second << ")";
        std::cerr << std::endl;
        sleep(2);
    }
    //-----------------------------------------------------------------

    //-----------------------------------------------------------------
    void Algorithm::run(){
        Algorithm::generate_goal();
        Algorithm::init_outer_walls();
    }
    //-----------------------------------------------------------------
}