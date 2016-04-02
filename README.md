# TicTacToe

TicTacToe is a simple tictactoe game created with raylib library. I've created this for school purposes, so maybe the software is not perfect.

[<img src="resources/icon.png" width=200>](resources/icon.png)

## Description

TicTacToe is a simple tictactoe game created with Raylib library. I've created this for school purposes, so maybe the software is not perfect. I wrote basic classes to use Raylib functions for a "OOP" view; these are in `src/base` folder. These classes can also be used for other projects.

I'm not english, so there are lots of errors! You can help me to fix these!

## Dependence

* raylib (1.4 version).

## Build

TicTacToe only uses raylib library; this library supports multiple platform (Window, GNU/Linux, Mac and others), but I've created a Makefile that works only on GNU/Linux (because I'm learning to create it); thus TicTacToe works with all platforms, but for now it works only on GNU/Linux. If you want to help me, write me!

### Build raylib library

You can build raylib by reading official Wiki; [here](https://github.com/raysan5/raylib/wiki/Compile-your-game-for-GNU-Linux) there is the guide for Ubuntu. It's **strongly recommended** move the library on standard directories (so at the point in the guide you have to follow it).

### Build TicTacToe

You need to download TicTacToe form Github repository; after you can compile the project:

    git clone https://github.com/LelixSuper/TicTacToe.git tictactoe
    cd tictactoe/
    make

It produces an executable, you can move it everywhere **BUT** he goes along with the `resources` folder!
You can also use `make clean` to clean the folder.

## Play

[<img src="screenshots/default.png" width=400>](screenshots/default.png)
[<img src="screenshots/win.png" width=400>](screenshots/win.png)

### How to play
You can use the **left mouse button** to place marks on the grid. After a game, you can restart clicking on the "New Game" button. There is also the quit and help button.

You can start the software in a CLI with the `--help` or `--version` parameter, that provides some useful information.

## Known bugs

*No bugs? Really?*

## To do list

I'm really busy with the school, but if I can, i would like to add these things:
* Improve makefile to support more platforms; [must, technological]
* Add a very simple AI (so also add a settings window); [should, functional]
* Add the support of arrow keys (thus also enter button); [should, functional]
* Add a very basis animation for graphic elements. [should, not functional]

## Contact

For bugs report, advice or feedbacks please send an email to *emanuele98(at)openmailbox(dot)org*, or contact me with Telegram (my nickname is [**LelixSuper**](http://telegram.me/LelixSuper)).

## Contributors

* [Leandro Rolih](http://ilresanmto.deviantart.com/) for creating graphics elements.
* [Domenico Verde](https://github.com/LordRibblesdale) for translating the entire project.

## License

The software is relased under the [MIT license](https://opensource.org/licenses/MIT), while the graphic elements are distribuited under [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/). Please view "LICENSE" file for more information.
