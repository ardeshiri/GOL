
-------------- Build: Debug in sfml_obs_mode (compiler: GNU GCC Compiler)---------------

g++ -Wall -fexceptions -g -Weffc++ -Wextra -Wall -std=c++17 -Iinclude -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c ./main.cpp -o obj/Debug/main.o
g++ -Wall -fexceptions -g -Weffc++ -Wextra -Wall -std=c++17 -Iinclude -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c ./src/sfml_win.cpp -o obj/Debug/src/sfml_win.o
g++ -Wall -fexceptions -g -Weffc++ -Wextra -Wall -std=c++17 -Iinclude -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c ./src/shape_obj.cpp -o obj/Debug/src/shape_obj.o
g++ -L/usr/local/lib -L/usr/lib -L/usr/local/lib/x86_64-linux-gnu -o bin/Debug/sfml_obs_mode obj/Debug/main.o obj/Debug/src/sfml_win.o obj/Debug/src/shape_obj.o  -O2  -lpthread -lsfml-system -lsfml-graphics -lsfml-window -lcrypto -lrabbitmq -lGL -lfftw3 -lsfml-audio















