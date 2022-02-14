#ifndef REACTOR_H
#define REACTOR_H
#include "drawable.h"

class drawable;
class World;

class reactor
{
    public:
        virtual ~reactor(){};
        virtual void collision_check(drawable& d) const = 0;
        virtual void mouse_pos( World& w) const = 0 ;

    protected:

    private:
};

#endif // REACTOR_H
