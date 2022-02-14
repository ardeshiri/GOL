#include "World.h"
#include <SFML/Graphics.hpp>
#include <utility>
#include <random>
#include <iostream>
#include <cmath>


World::World(int p ,int xw, int xh):h{xh},w{xw},shv{},utime{},auxtime{},bit{sf::milliseconds(p)},rd{},rg{rd()},uid1{(w*h)/10, (w*h)/7},uid2{0, w*h-1}
                                    ,mouse_x{},mouse_y{},mouse_valid{false},reactor_h{nullptr},pause{false}
{
    for(int i = 0 ; i < (h*w); ++i)
        shv.push_back(std::move(shape_obj (new sf::RectangleShape (sf::Vector2f(EL, EL)))));
}

World::~World()
{
    //dtor
}

void World::init(const sf::RenderTarget& , const reactor* rp)
    {
        reactor_h = rp;
        int i = 0;
        for(auto& o : shv)
            {
                o.shape_pointer()->setPosition((1+EL)*(i%w) , (1+EL)*floor(i/w));
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
        // for(auto& o : shv)
        //   o.time_update(t);
        update_cells();
    }


void World::update_cells()
{
    if(!pause)
    {
        int cn = 0;
        if(utime - auxtime > bit )
        {
            auxtime = utime;
            cn = 0;
            for(auto& o : shv)
            {
                int neighbours = count_neighbours(cn);
                if(o.is_cell_alive())
                {
                    if(neighbours < 2 ||  neighbours > 3)
                    {
                        o.is_cell_alive_pre(false);
                    }
                }
                if(!(o.is_cell_alive()))
                {
                    if(neighbours == 3)
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


void World::get_notification(const sf::Event& ev)
{
    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::L)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x+w].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::T)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x+w].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);

            shv[x-w+1].is_cell_alive(true);
            shv[x+1].is_cell_alive(true);
            shv[x-w-w+1].is_cell_alive(true);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::U)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x+w].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);
            shv[x+1].is_cell_alive(true);
            shv[x-1].is_cell_alive(true);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::B)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x+1].is_cell_alive(true);
            shv[x+w].is_cell_alive(true);
            shv[x+w+1].is_cell_alive(true);

            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::O)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x+w].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);
            shv[x-w-1].is_cell_alive(true);
            shv[x+1].is_cell_alive(true);
            shv[x-1].is_cell_alive(true);

            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::D)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            mouse_valid = false;
        }
    }
    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::G)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x-1].is_cell_alive(true);
            shv[x-2].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);
            shv[x-w-w-1].is_cell_alive(true);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::S)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x-1].is_cell_alive(true);
            shv[x-2].is_cell_alive(true);
            shv[x-3].is_cell_alive(true);
            shv[x-w].is_cell_alive(true);
            shv[x-w-w].is_cell_alive(true);
            shv[x-w-w-w-1].is_cell_alive(true);
            shv[x-w-4].is_cell_alive(true);
            shv[x-w-w-w-4].is_cell_alive(true);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::E)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(false);
            shv[x-1].is_cell_alive(false);
            shv[x+1].is_cell_alive(false);
            shv[x-w].is_cell_alive(false);
            shv[x-w-1].is_cell_alive(false);
            shv[x-w+1].is_cell_alive(false);
            shv[x+w].is_cell_alive(false);
            shv[x+w-1].is_cell_alive(false);
            shv[x+w+1].is_cell_alive(false);
            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::H)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x+3].is_cell_alive(true);
            shv[x+w+1].is_cell_alive(true);
            shv[x+w+2].is_cell_alive(true);
            shv[x-w+1].is_cell_alive(true);
            shv[x-w+2].is_cell_alive(true);

            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::I)
    {
        reactor_h->mouse_pos(*this);
        if( mouse_valid == true )
        {
            int x = get_cell_index(mouse_x, mouse_y);
            shv[x].is_cell_alive(true);
            shv[x+1].is_cell_alive(true);
            shv[x+3].is_cell_alive(true);
            shv[x+w+1].is_cell_alive(true);
            shv[x+w+2].is_cell_alive(true);
            shv[x-w+1].is_cell_alive(true);
            shv[x-w+2].is_cell_alive(true);

            mouse_valid = false;
        }
    }

    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::C)
    {
        for( auto& o :shv )
        {
            o.is_cell_alive(false);
        }
    }


    if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::P)
    {
        pause = !pause;
    }

}

int World::get_cell_index(int x, int y)
{
    return (floor(y/(EL+1)))*w + floor(x/(EL+1));
}


void World::mouse_update(int x, int y)
{
    if(x < 0 || y < 0)
        return;
    mouse_x = x;
    mouse_y = y;
    mouse_valid = true;
}


sf::FloatRect World::get_local_bounds() const
{
    return sf::FloatRect(0,0,w ,h);
}

sf::FloatRect World::get_global_bounds() const
{
    return sf::FloatRect(0,0,w ,h);
}

int32_t World::get_id() const
{
    return int32_t{};
}

std::tuple<bool,int,int> World::get_mouse()
{
    mouse_valid = false;
    return std::make_tuple(true,mouse_x,mouse_y);
}
