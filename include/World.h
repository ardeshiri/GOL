#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "shape_obj.h"
#include "drawable.h"
#include "alive.h"
#include "obsrvr.h"
#include <cmath>
#include <random>
#include <tuple>

class World: public drawable,public alive,public observer
{
    public:
        World(int refreash_rate = 1, int xw= 200, int xh= 150);
        ~World();
        World(const World&) = delete;
        World& operator= (const World&) = delete;
        World(World&&) = delete;
        World& operator=(World&&) = delete;

        void init(const sf::RenderTarget& , const reactor* ) override;
        void draw_on(sf::RenderTarget& rt) const override;
        sf::FloatRect get_local_bounds() const override;
        sf::FloatRect get_global_bounds() const override;
        void check() override {}
        void collided_with(drawable& ) override {}
        void hide_opt(bool ) override {}
        void collidable_opt(bool )  {}
        void set_id(int32_t) override {}
        int32_t get_id() const override;
        void time_update(const sf::Time& t) override;
        int count_neighbours(int i);
        int get_cell_index(int x, int y);
        void mouse_update(int x, int y);
        std::tuple<bool,int,int> get_mouse();

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
    const float EL{4};
    int mouse_x;
    int mouse_y;
    bool mouse_valid;
    const reactor* reactor_h;
    bool pause;


    void update_cells();
    void get_notification(const sf::Event& ev) override;

};

#endif // WORLD_H
