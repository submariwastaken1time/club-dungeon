# Who this tutorial is for
This is a tutorial to get people in tutorial hell (that is, knowing what to do from tutorials but not
learning how to make their own things) out of it.

This in all honesty will serve less as a tutorial and more as a gentle submersion into the world of doing your own things.

# What this will entail
This tutorial will go over the steps to make a walking @ demo using EnTT, libtcod and SDL using C++23 and the libtcod project template from the ever helpful HexDecimal.

EnTT will be used as the ECS component, helping manage the entities that the engine uses and significantly cutting down on the amount of reinventing the wheel that has to happen.

SDL will be used to process inputs from the player.

libtcod will be used to handle rendering.

Along with that will be my thought process and the details of how I came up with the engine.

At the end will be a section covering how one could break down certain features into things that are more manageable to implement into their game.

# Some other notes
This is the first tutorial I have ever done and so would like to be given feedback (contact info here)

The source code included is also a good place to reference for veterans, and or people looking to read my half baked code, it is far from perfect but I have went out of my way to ensure close to everything is commented well, beware: it does assume a decent understanding of the libraries listed above

If you are confused about what I mean, 'disambiguation.txt" might be a good place for you to reference.
## First step

So, you've chosen to proceed. Great, the first step is to clone the tutorial branch of this repo, you can do this by typing 'git repo clone --branch tutorial <url of the repo>' (this will clone only the branch "tutorial" of my repo) into your command prompt at a location of your choosing after you have installed git of course, it will make a folder called 'club-dungeon' at your place and populate it with the source code and build system along with the tutorial files. from then on you can check out the txt files in the 'tutorial' folder.

## These are the build instructions that come with the template that I am using:
# How this works

This is a CMake project which uses Vcpkg for dependency management.

You need CMake and a compiler which CMake can recognize.
Vcpkg is setup as a submodule and does not need to be installed separately.

Compiling this program from an IDE such as VSCode will invoke CMake which in turn invokes Vcpkg.
Vcpkg fetches and builds all dependencies required by the project and CMake will compile and link them.
This means you do not have to manually handle dependencies as they are all handled by the toolchain.

The [src/](src/) directory holds a hello world program.
CMake has been configured to compile all `*.cpp` files in this directory to create a new program.
You should edit or replace the sources in this directory to create your program.
If you do not want to use this directory then you can modify which files are collected in [CMakeLists.txt](CMakeLists.txt).

A workflow exists at [.github/workflows/cmake.yml](.github/workflows/cmake.yml) which automatically compiles the program for Windows, macOS, and Ubuntu Linux.
The workflow simply invokes CMake directly, since this setup does not depend on a specific IDE to work.
Actions which pass without fail will provide archived executables to test with, these are temporary and are downloaded from the passing action under *automated-builds*.
To permanently publish these builds you can push an annotated tag named after the version of the build, such as `1.0.0` or `2000.12.30`.

# How to setup

* Make sure you have the correct tools ready.
  * For example on Windows:
    Make sure you install the "Desktop development with C++" workload from the latest [Visual Studio Community Installer](https://visualstudio.microsoft.com/vs/community/),
    install the latest [CMake](https://cmake.org/download/),
    and install [Visual Studio Code](https://code.visualstudio.com/download).
* [Create a new repository from ths template](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/creating-a-repository-from-a-template#creating-a-repository-from-a-template).  **You do not use the GitHub fork button unless you're contributing.**
* [Clone your new repository](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository-from-github/cloning-a-repository).
* Make sure to initialize the `vcpkg` [submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules).  If the `vcpkg` folder is empty or missing then the build process will fail.
  * The command to do this is: `git submodule update --init --recursive`
* Load this project in VS Code and install any recommended plugins.
  Most importantly: *C/C++*, *C++ Intellisense*, and *CMake Tools*.
* Using the CMake Tools plugin you can now build and run this project.  Dependencies will automatically be installed via Vcpkg.
  * On Windows, when CMake Tools asks for a toolkit you should select `Visual Studio Community ... - amd64`.
  * When CMake Tools asks for a project select `libtcod-vcpkg-template`.
* The project will now build and run with F5.
  You should edit the `CMakeLists.txt` script as needed to expand your project.

Now that you know the template works you'll want to take care the following:

* Replace the license in [LICENSE.txt](LICENSE.txt) with your own, see [choosealicense.com](https://choosealicense.com/).
* Modify [vcpkg.json](vcpkg.json) to include any libraries [from Vcpkg](https://vcpkg.info/) that you want to use such as the popular [fmt](https://fmt.dev/latest/index.html) library.
  You'll need to add these libraries to [CMakeLists.txt](CMakeLists.txt) to link them.
* Change `libtcod-vcpkg-template` in [CMakeLists.txt](CMakeLists.txt) and [.github/workflows/cmake.yml](.github/workflows/cmake.yml) to the name of your game.
  You may want to edit other parts of the CMake script as well, such as the included source files.
* Verify the style settings in [.clang-format](.clang-format) and [.editorconfig](.editorconfig).

# Configuring submodules

After you run `git submodule update --init` you can setup the submodules by going into their initialized submodule directories and checking out the desired commits.
See the [Git Documentation on Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules).

To update SDL, libtcod, or any other dependency fetched with `vcpkg` you should go into the `vcpkg` folder and then checkout and pull its `master` branch to get the most recent ports.
