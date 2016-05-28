#ifndef MODULEDEPLACEMENT_H
#define MODULEDEPLACEMENT_H

#include <stdlib.h>
#include <vector>

using namespace std;

// 3D implementation but can of course be used in 2D

class Mobile
{
    public:
        Mobile();
        virtual ~Mobile();

        // get
        unsigned get_position_x();
        unsigned get_position_y();
        unsigned get_position_z();
        vector<unsigned> get_orientation();
        vector<vector<unsigned> > see(vector<vector<vector<bool> > > environment);

        // move
        void basic_movement(vector<unsigned> direction);


    protected:

    private:
        unsigned pos_x;
        unsigned pos_y;
        unsigned pos_z;
        vector<unsigned> m_orientation;
};

#endif // MODULEDEPLACEMENT_H
