#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "shape_obj.h"
#include "drawable.h"
#include "alive.h"
#include <cmath>
#include <random>

class World: public drawable,public alive
{
    public:
        World(int b = 1000, int xw= 200, int xh= 100);
        ~World();

        void init(const sf::RenderTarget& , const reactor* ) override;
        void draw_on(sf::RenderTarget& rt) const override;
        sf::FloatRect get_local_bounds() const override
        {
            return sf::FloatRect(0,0,w ,h);
        }
        sf::FloatRect get_global_bounds() const override
        {
            return sf::FloatRect(0,0,w ,h);
        }
        void check() override {}
        void collided_with(drawable& ) override {}
        void hide_opt(bool ) override {}
        void collidable_opt(bool )  {}
        void set_id(int32_t) override {}
        int32_t get_id() const override
        {
            return int32_t{};
        }
        void time_update(const sf::Time& t) override;
        int count_neighbours(int i);
    protected:

    private:
    int h;
    int w;
    std::vector<shape_obj> shv;
    sf::Time utime;
    sf::Time auxtime;
    const sf::Time bit;
    std::random_device rd;
    std::mt19937 rg;
    std::uniform_int_distribution<int> uid1;
    std::uniform_int_distribution<int> uid2;
    int starter = 0;

    void update_cells();

};

#endif // WORLD_H
