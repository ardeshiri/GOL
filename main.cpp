#include <iostream>
#include "sfml_win.h"
#include "shape_obj.h"
#include <cmath>
#include "World.h"
#include <random>
#include <map>
using namespace std;

int main()
{

    World wd{};
    sfml_win sw{1000,600,"Game of life"};

    sw.register_drawable(wd);
    sw.register_alive(wd);

////////////////////////////////// 0
    sw.init_all();  /// 1
    sw.run_main_loop();  /// 2
    return 0;
}
