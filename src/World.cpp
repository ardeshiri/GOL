#include "World.h"
#include <SFML/Graphics.hpp>
#include <utility>
#include <random>
#include <iostream>
#include <cmath>


World::World(int b ,int xw, int xh):h{xh},w{xw},shv{},utime{},auxtime{},bit{sf::milliseconds(b)},rd{},rg{rd()},uid1{(w*h)/10, (w*h)/7},uid2{0, w*h-1}
{
    for(int i = 0 ; i < (h*w); ++i)
        shv.push_back(std::move(shape_obj (new sf::RectangleShape (sf::Vector2f(4.f, 4.f)))));
}

World::~World()
{
    //dtor
}

void World::init(const sf::RenderTarget& , const reactor* )
    {
        int i = 0;
        for(auto& o : shv)
            {
                o.shape_pointer()->setPosition(5*(i%w) , 5*floor(i/w));
                ++i;
            }
    }

void World::draw_on(sf::RenderTarget& rt) const
    {
        for(const auto& o : shv)
            o.draw_on(rt);
    }

void World::time_update(const sf::Time& t)
    {
        utime = t;
        for(auto& o : shv)
            o.time_update(t);
        update_cells();
    }


void World::update_cells()
{
    int cn = 0;
    if(starter < 7)
    {
        cn = int(uid1(rg) / (starter+1));
        std::vector<int> rv(cn);
        for(int i = 0; i < cn; i++)
        {
            rv[i] = uid2(rg);
        }
        for(auto o : rv)
        {
            shv[o].is_cell_alive(true);
        }
        std::cout<<"generating "<<starter<<std::endl;
        starter++;
    }


/*
    if(starter < 1)
    {
        cn = 0;
        for(auto& o : shv)
        {
            if (++cn%3 == 0)
            o.is_cell_alive_pre(true);

        }
        std::cout<<"generating "<<starter<<std::endl;
        starter++;
    }
*/

    /// rules :
    if(utime - auxtime > bit )
    {
        auxtime = utime;
        cn = 0;
        for(auto& o : shv)
        {
            if(o.is_cell_alive())
            {
                if(count_neighbours(cn) < 2 ||  count_neighbours(cn) > 3)
                {
                    o.is_cell_alive_pre(false);
                }
            }
            if(!(o.is_cell_alive()))
            {
                if(count_neighbours(cn) == 3)
                {
                    o.is_cell_alive_pre(true);
                }
            }
            ++cn;
        }
        for(auto& o : shv)
        {
            o.trig();
        }
    }
}


int World::count_neighbours(int i)
{
    int c = 0;
    if((i-w-1 > 0) && (i-w-1 < shv.size()))
    {
        if( shv[i-w-1].is_cell_alive() == true )
            ++c;
    }
    if((i-w > 0) && (i-w < shv.size()))
    {
        if( shv[i-w].is_cell_alive() == true )
            ++c;
    }
    if((i-w+1 > 0) && (i-w+1 < shv.size()))
    {
        if( shv[i-w+1].is_cell_alive() == true )
            ++c;
    }
    if((i-1 > 0) && (i-1 < shv.size()))
    {
        if( shv[i-1].is_cell_alive() == true )
            ++c;
    }
    if((i+1 > 0) && (i+1 < shv.size()) )
    {
        if( shv[i+1].is_cell_alive() == true )
            ++c;
    }
    if((i+w-1 > 0) && (i+w-1 < shv.size()))
    {
        if( shv[i+w-1].is_cell_alive() == true )
            ++c;
    }
    if((i+w > 0) && (i+w < shv.size()) )
    {
        if( shv[i+w].is_cell_alive() == true )
            ++c;
    }
    if((i+w+1 > 0) && (i+w+1 < shv.size()) )
    {
        if( shv[i+w+1].is_cell_alive() == true )
            ++c;
    }
    return c;
}

