#ifndef GAMEMANAGER
    #define GAMEMANAGER

    #include "engine.h"

    #include <GL/freeglut.h>

    // NOT NECESSITIES
    #include <vector>
    #include <map>

class GameManager
{
    private :
        Engine *engine = nullptr;

    public :
        GameManager() {};
        GameManager(Engine *engine): engine(engine) {}; // DO NOT MODIFY THIS

        void init(); // DO NOT MODIFY THIS
        void update(); // DO NOT MODIFY THIS
};

#endif