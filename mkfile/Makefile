
CC = g++
CFLAGS = -Wall -fexceptions -g -Weffc++ -Wextra -Wall -std=c++17
default: sfml_obs_mode

sfml_obs_mode: main.o sfml_win.o shape_obj.o
	$(CC) -L/usr/local/lib -L/usr/lib -L/usr/local/lib/x86_64-linux-gnu -o bin/Debug/sfml_obs_mode obj/Debug/main.o obj/Debug/src/sfml_win.o obj/Debug/src/shape_obj.o  -O2  -lpthread -lallegro -lsfml-system -lsfml-graphics -lsfml-window -lcrypto -lrabbitmq -lGL -lfftw3 -lsfml-audio

maio.o: main.cpp ./include/sfml_win.h ./include/shape_obj.h
	$(CC) $(CFLAGS) -I./include -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c /home/snake/Cods/CodeBlocks/sfml_obs_mode/main.cpp -o obj/Debug/main.o

sfml_win.o: sfml_win.cpp ./include/sfml_win.h
	$(CC) $(CFLAGS) -I./include -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c /home/snake/Cods/CodeBlocks/sfml_obs_mode/src/sfml_win.cpp -o obj/Debug/src/sfml_win.o


shape_obj.o: shape_obj.cpp ./include/shape_obj.h
	$(CC) -$(CFLAGS) -std=c++17 -I./include -I/usr/local/lib -I/usr/lib -I/usr/local/lib/x86_64-linux-gnu -c /home/snake/Cods/CodeBlocks/sfml_obs_mode/src/shape_obj.cpp -o obj/Debug/src/shape_obj.o








