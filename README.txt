A simple game based on Conway's Game of Life:
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

The only lib you are going to need in order to make and run is SFML, to install use:
sud apt update
sudo apt install libsfml-dev

making the game:
clone git@github.com:ardeshiri/GOL.git
cd GOL/
make clean
make release
./bin/Release/sfml_obs_mode

controls (move the mouse on the screen and use keyboard to draw):
'C': is used to clear the screen.
'E': is used to erase a point.
'L': draws a blinker.
'B': draws a block.
'T': draws a toad.
'H': draws a bee-hive:
'S': draws a spaceship.
'G': draws a glider.
'D': draws a dot. As you can see in the rules of the game a single dot can not survive and dies immediately after a tick, so you have to use 'p' to pause, use dot to draw, and again 'p' to play.
'O': draws a boat.
'U': draws a tub or flower.
