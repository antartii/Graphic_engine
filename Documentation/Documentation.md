# Documentation

Here is the documentation of the Anta’s graphic engine.

This is written as a basic, plain, boring documentation so if you want to learn how to use it step by step or by having exercices please go to the “Tutorial” page.

# Before we start

## 1. Infos

- **Language : C++**
- **Currently maintained OS : Linux (Fedora 38)**
- **Compilation method : g++ with Makefile**
- **Output file (after compilation) : anta_graphic_engine**

## 2. Compilation

The entire project runs using the `Makefile` at the root of the project.

This Makefile automatically use all of the `.cpp` files from the `src` directory recursively and include all of the `.h` file from the `includes` directory recursively.

*We currently don’t have a support for windows so you might encounter errors or problems while compiling*

### Prerequisites

Make sure to have installed the `freeglut` librairy before starting compiling the program.

**To use other static library dependencies** (.a files) :

*Line 14*

```bash
	DEPENDENCIES_PATH = path/to/your/dependency/folder   \
											path/to/another/dependency/folder
```

**To include other librairies flags** :

*Line 8*

```bash
CFLAGS = $(CFLAGS_INCLUDES) -W -Wextra -lGL -lGLU -lglut -mylibrairy
```

## 3. README & Documentations

You can directly ask to change the [`README.md`](http://README.md) from the root of the project by doing a pull request, Please add notes of your changes and why do you want it to change in your commit title (grammatical errors, informal paragraphs, irrelevant informations, deprecated informations, etc…).

For modifying the Documentations please send a message at [fireslidefr@gmail.com](mailto:fireslidefr@gmail.com) (we currently don’t have a tickets system be we’re looking forward to make one)

## 4. Coding with us

*You can freely use the program for your personnal project and we would be so happy to see you developping your own program with our code !*

But if you feel like giving a helping hand, you can ask a pull request by following our rules :

**Commits**

Commits title are the most important part, we should be able to see on wich features you worked on by only reading the commit title. We recommend using this template for title :

```bash
[PLUGIN_NAME or CORE] name_or_description_of_the_features | UPDATE or CREATE
```

**PLUGIN_NAME or CORE** : Defining if your working on the core (engine.cpp, engine.h, main.cpp, utils.cpp, utils.h or Makefile) or on  a plugin (we consider, documentations and README files as a plugin)

**name_or_description_of_the_features** : Defining what you’ve done in a little sentence

**UPDATE or CREATE** : Defining if you are creating a new plugin or if you are updating one (please send UPDATE when you’re working on the CORE).

**Documentations**

If you’re working on something new or that you’re changing a lot of logic from a previous code, please explains in a short community_documentation.txt files what you’ve done.

If you used mathematical formula, you can explain them by sending us the wikipedia page of if it is easier for you.

For any optimizations please make sure to detail us why this is a optimisation by giving us sources.

## 5. Our TODO list

We currently working on some of thoses features :

- Shapes 2D for circles and curves based 2D shapes
- Text, Buttons, image and animation handling
- Storage based from the .UAT project of Anta

# Core

*The core of the project is a basic set of functions, class and variables made to be only a little piece of a big puzzle*

## Engine

*The Engine class is the core class of everything, it handle every actions inputed and outputed while the program is running.*

The class is defined in the `engine.h` file and defines it’s functions on the `engine.cpp` file. It is dependent of the `utils.h` file.

- **Initialisation**
    
    You can setup an uninitialized Engine class by just creating them :
    
    ```c
    Engine engine;
    ```
    
    Or initialize them directly by setting up argc and argv
    
    ```c
    Engine engine(argc, argv);
    ```
    
- **Variables**
    - **private** :
        
        `int argc` : Stores the number of arguments while launching the program;
        
        `char **argv` : Stores the arguments while launching the program
        
        `unsigned int display_mode`  : Stores the display mode that will be used by freeglut (Set at `GLUT_DOUBLE | GLUT_RGB` by default).
        
        `std::string window_title` : Title from the top bar of the window (set at “window” by default)
        
        `Size window_size` : Size of the window (set at 300 x 300 by default)
        
        `Coordinates window_position` : Position coordinates of the window from the screen viewport (at [0, 0] by default)
        
        `int fps` : refresh rate of the Engine::update() function, it is equaled to how much time the update() function is used a second (set at 60 by default)
        
        `static Engine *instance` : Instance of the engine for global variables `Engine *` purposes.
        
        `std::vector<void (*)()> mod_init_functions` : Array of all function that will be played from plugins before the start of the program.
        
        `int mod_init_functions_count` : Number of init() function from the Array of mod functions
        
        `std::vector<void (*)(int, int)> mod_update_functions` : Array of all function that will be played from plugins every time the engine.update() function will be played.
        
        `int mod_update_functions_count` : Number of update() function from the Array of mod functions
        
        `std::vector<void (*)()> mod_display_functions` : Array of all function that will be played from plugins every time the engine.display() function will be played (please draw everything on the display function).
        
        `int mod_display_functions_count`  : Number of display() function from the Array of mod functions
        
- **Functions**
    - **Public :**
        
        `void add_mod_update_function(void (*mod_update_function)(int, int))` 
        
        *Add an external static function to be played every time `engine.upate()` is played*
        
        `void add_mod_display_function(void (*mod_display_function)())` 
        
        Add an external static function to be played everytime `engine.display()` is played
        
        `void add_mod_init_function(void (*add_init_display_function)())`
        
        Add an external static function to be played when `engine.init()` is played
        
        `Size get_window_size(void)`
        
        Returns the current size of the window
        
        `void set_window_title(std::string title)`
        
        Set the title on the top bar of the window
        
        `void set_window_size(Size size)` 
        
        Set the size of the window (only works on init window size, don’t dinamycally change the size of the window)
        
        `void set_window_pos(Coordinates pos)`
        
         Set the position of the window (only work on init, don’t change pos dinamically)
        
        `void init()` 
        
        Function that will be played at the start of the program, usually used to setup value.
        
        `void start()` 
        
        Function that will be played to launch the program
        
        `void update(int fps, int value)` 
        
        Will be played in a loop as a rate of 600  `fps` 
        
        `void display()`
        
        Used to showing things on the screen.
        
        `void reshape(int w, int h)` 
        
        Used everytime the window is reshaped
        
        `static void set_instance(Engine *engine)` 
        
        Set the instance for the global variable usage.
        
        `static int get_fps()`
        
        Get the current fps set for the engine, works only if an instance is set, also works as a global fps.
        
        `static void update_callback(int value)`
        
        static callback for the update() function,  works only if an instance is set
        
        `static void display_callback()`
        
        static callback for the display() function,  works only if an instance is set
        
        `static void reshape_callback(int w, int h)`
        
        static callback for the reshape function,  works only if an instance is set
        

# Plugins

[Shapes_2D](Plugins/Shapes_2D.md)