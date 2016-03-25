# This is the makefile for compiling the TicTacToe project.
# It's relased under the MIT license, please see "LICENSE" for more information.
# 
# Currently it works only on GNU/Linux operating systems (such as Ubuntu).
# You just type "make" for create the executable, you can also clean the
# directory with "make clean".
#
# In the future I will add the support for other operating systems, and
# improve this very basis makefile.

SHELL = /bin/sh

CXX = g++

VPATH = src src/base

# If you have raylib into standard directory or user directory. It allow
# the inclusion of raylib with simply "#include <raylib.h>"
CPPFLAGS = -I/usr/local/include/raylib/ -I.

LIBDIR = -L.

OBJECTS = tictactoe_main.o tictactoe_core.o tictactoe_main_window.o \
          tictactoe_help_window.o tictactoe_trace.o tictactoe_grid.o \
          tictactoe_game.o  sx_mouse_interaction.o graphic_element.o \
          tictactoe_signs.o

LDFLAGS = -lraylib -lm -lglfw3 -ldl -lpthread -lXxf86vm -lX11 -lGL -lGLU \
          -lXrandr -lXcursor -lXi -lXinerama

CXXFLAGS = -g -O0 -std=c++11 -Wall

.PHONY : all clean

# Executable builds
all : TicTacToe $(OBJECTS)
	@$(CXX) -o TicTacToe $(OBJECTS) $(CXXFLAGS) $(CPPFLAGS) $(LIBDIR) $(LDFLAGS)
	@echo "TicTacToe builded!"

TicTacToe :

# Modules build
tictactoe_main.o : tictactoe_main.cpp tictactoe_core.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

tictactoe_core.o : tictactoe_core.cpp tictactoe_core.h tictactoe_game.h \

				   tictactoe_main_window.h tictactoe_help_window.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

tictactoe_main_window : tictactoe_main_window.cpp tictactoe_main_window.h \
                        tictactoe_game.h tictactoe_grid.h button.h \
                        graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

tictactoe_help_window.o : tictactoe_help_window.cpp tictactoe_help_window.h \
                          graphic_element.h button.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

tictactoe_trace.o : tictactoe_trace.cpp tictactoe_trace.h graphic_element.h \
                    tictactoe_game.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

tictactoe_grid.o : tictactoe_grid.cpp tictactoe_grid.h tictactoe_game.h \
                   tictactoe_trace.h tictactoe_signs.h sx_mouse_interaction.h \
                   graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

tictactoe_signs.o : tictactoe_signs.cpp tictactoe_signs.h graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

tictactoe_game.o : tictactoe_game.cpp tictactoe_game.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

sx_mouse_interaction.o : sx_mouse_interaction.cpp sx_mouse_interaction.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

graphic_element.o : graphic_element.cpp graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean :
	@rm --force TicTacToe *.o
	@echo "Cleaned all build files!"
