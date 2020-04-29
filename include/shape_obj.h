#ifndef SHAPE_OBJ_H
#define SHAPE_OBJ_H
#include "obsrvr.h"
#include "drawable.h"
#include "alive.h"
#include <memory>


#include <iostream>
class shape_obj:public observer,public drawable,public alive
{
    public:
    explicit shape_obj(sf::Shape* shp = nullptr);
    shape_obj(const shape_obj&) = delete;
    shape_obj& operator=(const shape_obj&) = delete;
    shape_obj(shape_obj&&) = default;
    shape_obj& operator=(shape_obj&&) = default;
    void init(const sf::RenderTarget& rt, const reactor* re) override;
    sf::Shape* shape_pointer();
    void add_tr_func(const std::function<void(const sf::Event& ev, shape_obj& sh)>& f);
    void get_notification(const sf::Event& ev) override;
    void draw_on(sf::RenderTarget& rt) const override;
    void check();
    void time_update(const sf::Time& t) override;
    const sf::Time& get_time();
    virtual ~shape_obj();
    void add_anm_func( const std::pair<std::function<void(shape_obj& sh)>,const sf::Time>& p);
    void animate();
    const sf::Vector2u& get_border();
    void set_id(int32_t i) override;
    int32_t get_id() const override;
    sf::FloatRect get_local_bounds() const;
    sf::FloatRect get_global_bounds() const;
    void collided_with(drawable& d);
    void collidable_opt(bool b) override;
    void hide_opt(bool b) override;

    bool is_cell_alive() { return is_cell_alive_v; }

    void is_cell_alive(bool b)
    {
        is_cell_alive_v = b;
        is_cell_alive_t = b;
        shape_obj_ptr.get()->setFillColor( (is_cell_alive_v)? sf::Color::Black:sf::Color::White);
        if(b == true)
            birth_time = utime;
    }

    void is_cell_alive_pre(bool b)
    {
        is_cell_alive_t = b;
    }

    void trig()
    {
        is_cell_alive(is_cell_alive_t);
    }

    sf::Time get_birth_time()
    {
        return birth_time;
    }


    protected:

    private:
    std::unique_ptr<sf::Shape> shape_obj_ptr;
    std::vector<std::function<void(const sf::Event& ev,shape_obj& sh)>> transform_vec;
    std::vector<std::pair<std::pair<std::function<void(shape_obj& sh)>,const sf::Time>,sf::Time>> animate_vec;
    sf::Time utime;
    sf::Time birth_time;
    sf::Vector2u border_size;
    int32_t id;
    const reactor* reactor_h;
    bool collidable;
    bool hide;
    bool is_cell_alive_v;
    bool is_cell_alive_t;

    static void border_update(const sf::Event& ev, shape_obj& sh);
};

#endif // SHAPE_OBJ_H
