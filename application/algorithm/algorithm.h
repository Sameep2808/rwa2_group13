//Work in progress...
//Needs Documentation

#ifndef __ALGORITHM__h
#define __ALGORITHM__H

#pragma once

#include <string>
#include <vector>

namespace rwagroup12
{
    class Algorithm{
        private:
        //optimized path is stored sequentially
        std::vector<std::pair<int, int>> m_position_vector;

        //stores the coordinates of goals
        std::pair<int, int> goal;

        public:
        //constructor to 
        Algorithm(): goal{0, 0}{}

        //entry point of the class
        void run();

        //sets the outer walls
        void init_outer_walls();

        //left-wall follower
        void follow_wall_left();

        //right-wall follower
        void follow_wall_right();

        //randomly generates goal adjacent to the outer wall
        void generate_goal();

        //sets right wall w.r.t. robot as red
        void set_right_wall();

        //sets left wall w.r.t. robot as red
        void set_left_wall();

        //sets front wall w.r.t. robot as red
        void set_front_wall();

        //displays the coordinates of the goal
        void get_goal();
    };
}

#endif