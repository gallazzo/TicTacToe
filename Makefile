# TicTacToe Makefile
#
# This is a modified version of makefile template of raylib repository. The original version is licensed
# under the unmodified zlib/libpng license.
#
# Thw new version is licensed under the MIT license
#
# Copyright (c) 2016 Emanuele Petriglia (LelixSuper) <emanuele98@openmailbox.org>
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

#**************************************************************************************************
#
#   raylib - Advance Game
#
#   makefile to compile advance game for desktop platforms, Raspberry Pi and HTML5 (emscripten)
#
#   Copyright (c) 2014 Ramon Santamaria (Ray San - raysan@raysanweb.com)
#    
#   This software is provided "as-is", without any express or implied warranty. In no event 
#   will the authors be held liable for any damages arising from the use of this software.
#
#   Permission is granted to anyone to use this software for any purpose, including commercial 
#   applications, and to alter it and redistribute it freely, subject to the following restrictions:
#
#     1. The origin of this software must not be misrepresented; you must not claim that you 
#     wrote the original software. If you use this software in a product, an acknowledgment 
#     in the product documentation would be appreciated but is not required.
#
#     2. Altered source versions must be plainly marked as such, and must not be misrepresented
#     as being the original software.
#
#     3. This notice may not be removed or altered from any source distribution.
#
#**************************************************************************************************

# define raylib platform to compile for
# possible platforms: PLATFORM_DESKTOP PLATFORM_RPI PLATFORM_WEB
# WARNING: To compile to HTML5, code must be redesigned to use emscripten.h and emscripten_set_main_loop()
PLATFORM ?= PLATFORM_DESKTOP

# determine PLATFORM_OS in case PLATFORM_DESKTOP selected
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    # No uname.exe on MinGW!, but OS=Windows_NT on Windows! ifeq ($(UNAME),Msys) -> Windows
    ifeq ($(OS),Windows_NT)
        PLATFORM_OS=WINDOWS
        LIBPATH=win32
    else
        UNAMEOS:=$(shell uname)
        ifeq ($(UNAMEOS),Linux)
            PLATFORM_OS=LINUX
            LIBPATH=linux
        else
        ifeq ($(UNAMEOS),Darwin)
            PLATFORM_OS=OSX
            LIBPATH=osx
        endif
        endif
    endif
endif

# define compiler: gcc for C program, define as g++ for C++
ifeq ($(PLATFORM),PLATFORM_WEB)
    # define emscripten compiler
    CXX = emcc
else
ifeq ($(PLATFORM_OS),OSX)
    # define llvm compiler for mac
    CXX = clang
else
    # define default C++ compiler
    CXX = g++
endif
endif

# define compiler flags:
#  -O2         defines optimization level
#  -Wall       turns on most, but not all, compiler warnings
#  -std=C++11  use standard C++ from 2011 revision
ifeq ($(PLATFORM),PLATFORM_RPI)
    CXXFLAGS = -O2 -std=c++11 -Wall -fgnu89-inline
else
    CXXFLAGS = -O2 -std=c++11 -Wall
endif
ifeq ($(PLATFORM),PLATFORM_WEB)
    CXXFLAGS = -O2 -std=c++11 -Wall -s USE_GLFW=3 --preload-file resources --shell-file ../../templates/web_shell/shell.html
    #-s ASSERTIONS=1            # to check for memory allocation errors (-O1 disables it)
    #-s ALLOW_MEMORY_GROWTH=1   # to allow memory resizing
    #-s TOTAL_MEMORY=16777216   # to specify heap memory size (default = 16MB)
endif

# define any directories containing required header files
ifeq ($(PLATFORM),PLATFORM_RPI)
    INCLUDES = -I. -I../../src -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads
endif
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    # add standard directories for GNU/Linux
    ifeq ($(PLATFORM_OS),LINUX)
        INCLUDES = -I. -I../src -I/usr/local/include/raylib/
    else
        INCLUDES = -I. -I../../src -IC:/raylib/raylib/src
        # external libraries headers
        # GLFW3
            INCLUDES += -I../../external/glfw3/include
        # GLEW - Not required any more, replaced by GLAD
            #INCLUDES += -I../external/glew/include
        # OpenAL Soft
            INCLUDES += -I../../external/openal_soft/include
    endif
endif

# define library paths containing required libs
ifeq ($(PLATFORM),PLATFORM_RPI)
    LFLAGS = -L. -L../../src -L/opt/vc/lib
endif
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    # add standard directories for GNU/Linux
    ifeq ($(PLATFORM_OS),LINUX)
        LFLAGS = -L. -L../../src
    else
        LFLAGS = -L. -L../../src -LC:/raylib/raylib/src
        # external libraries to link with
        # GLFW3
            LFLAGS += -L../../external/glfw3/lib/$(LIBPATH)
        ifneq ($(PLATFORM_OS),OSX)
        # OpenAL Soft
            LFLAGS += -L../../external/openal_soft/lib/$(LIBPATH)
        endif
    endif
endif

# define any libraries to link into executable
# if you want to link libraries (libname.so or libname.a), use the -lname
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(PLATFORM_OS),LINUX)
        # libraries for Debian GNU/Linux desktop compiling
        # requires the following packages:
        # libglfw3-dev libopenal-dev libegl1-mesa-dev
        LIBS = -lraylib -lglfw3 -lGL -lopenal -lm -pthread -ldl -lX11 \
               -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
    else
    ifeq ($(PLATFORM_OS),OSX)
        # libraries for OS X 10.9 desktop compiling
        # requires the following packages:
        # libglfw3-dev libopenal-dev libegl1-mesa-dev
        LIBS = -lraylib -lglfw -framework OpenGL -framework OpenAl -framework Cocoa
    else
        # libraries for Windows desktop compiling
        # NOTE: GLFW3 and OpenAL Soft libraries should be installed
        LIBS = -lraylib -lglfw3 -lopengl32 -lopenal32 -lgdi32
    endif
    endif
endif
ifeq ($(PLATFORM),PLATFORM_RPI)
    # libraries for Raspberry Pi compiling
    # NOTE: OpenAL Soft library should be installed (libopenal1 package)
    LIBS = -lraylib -lGLESv2 -lEGL -lpthread -lrt -lm -lbcm_host -lopenal
endif
ifeq ($(PLATFORM),PLATFORM_WEB)
    # NOTE: Set the correct path to libraylib.bc
    LIBS = ../../src/libraylib.bc
endif

# define additional parameters and flags for windows
ifeq ($(PLATFORM_OS),WINDOWS)
    # resources file contains windows exe icon
    # -Wl,--subsystem,windows hides the console window
    WINFLAGS = C:/raylib/raylib/src/resources -Wl,--subsystem,windows
endif

ifeq ($(PLATFORM),PLATFORM_WEB)
    EXT = .html
endif

# virtual paths
VPATH = src src/base

OBJECTS = tictactoe_main.o tictactoe_core.o tictactoe_main_window.o \
          tictactoe_help_window.o tictactoe_trace.o tictactoe_grid.o \
          tictactoe_game.o  sx_mouse_interaction.o graphic_element.o \
          tictactoe_signs.o

.PHONY : all clean

# Executable builds
all : TicTacToe

TicTacToe : $(OBJECTS)
	@$(CXX) -o TicTacToe$(EXT) $(OBJECTS) $(CXXFLAGS) $(INCLUDES) $(LFLAGS) \
    $(LIBS) -D$(PLATFORM) $(WINFLAGS)
	@echo "TicTacToe builded!"

# Modules build
tictactoe_main.o : tictactoe_main.cpp tictactoe_core.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_core.o : tictactoe_core.cpp tictactoe_core.h tictactoe_game.h \
                   tictactoe_main_window.h tictactoe_help_window.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_main_window.o : tictactoe_main_window.cpp tictactoe_main_window.h \
                        tictactoe_game.h tictactoe_grid.h button.h \
                        graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_help_window.o : tictactoe_help_window.cpp tictactoe_help_window.h \
                          graphic_element.h button.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_trace.o : tictactoe_trace.cpp tictactoe_trace.h graphic_element.h \
                    tictactoe_game.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_grid.o : tictactoe_grid.cpp tictactoe_grid.h tictactoe_game.h \
                   tictactoe_trace.h tictactoe_signs.h sx_mouse_interaction.h \
                   graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_signs.o : tictactoe_signs.cpp tictactoe_signs.h graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

tictactoe_game.o : tictactoe_game.cpp tictactoe_game.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

sx_mouse_interaction.o : sx_mouse_interaction.cpp sx_mouse_interaction.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS) $(INCLUDES)

graphic_element.o : graphic_element.cpp graphic_element.h
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS) $(INCLUDES)

# clean everything
clean:
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(PLATFORM_OS),OSX)
		@rm --force TicTacToe *.o
    else
    ifeq ($(PLATFORM_OS),LINUX)
		@rm --force TicTacToe *.o
    else
		del *.o *.exe
    endif
    endif
endif
ifeq ($(PLATFORM),PLATFORM_RPI)
	@rm --force TicTacToe *.o
endif
ifeq ($(PLATFORM),PLATFORM_WEB)
	del *.o *.html *.js
endif
	@echo Cleaning done!
