#include <lib.h>


#include "engine.c"
#include "game_vars.c"
#include "engine_objects.c"

#define CURSOR_START 10 // #26a,10
#define CURSOR_END 3 // #26a,3



char *copyright = "rax@Sofia2018";

void end()
{
    text();
    cls();
    poke(0x26a, CURSOR_END);
}

void scene1()
{
    initObjects();


    addObject(OBJ_FISH2, 10, 10, "11 >(>");
    addObject(OBJ_FISH2, 20, 20, "22 >(>");
    addObject(OBJ_FISH2, 30, 15, "33 >(>");

    addObject(OBJ_FISH3, 10, 10, "11 <)<");
    addObject(OBJ_FISH3, 20, 20, "22 <)<");
    addObject(OBJ_FISH3, 30, 15, "33 <)<");

    //addObject(OBJ_FISHT2,30,15,"0");
    //addObject(OBJ_FISHT2,30,15,"1");

    //addObject(OBJ_FISHT3,20,15,"0");
    //addObject(OBJ_FISHT3,20,15,"1");

    addObject(OBJ_TANK, 30, 15, "");

    addObject(OBJ_AIR, 5, 25, "");
    addObject(OBJ_CASTLE, 24, 25, "");

    addObject(OBJ_SEAWEED, 1, 25, "\005");
    addObject(OBJ_SEAWEED, 6, 25, "\002");
    addObject(OBJ_SEAWEED, 8, 25, "\003");
    addObject(OBJ_SEAWEED, 19, 25, "\004");

    printText("----------------------------------------....... .... .... ......... .......  ...", 0, 1);
    printText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 0, 26);

    engine();

}

void font()
{
    poke(0xb400 + 95 * 8, 0);
    poke(0xb401 + 95 * 8, 0);
    poke(0xb402 + 95 * 8, 0);
    poke(0xb403 + 95 * 8, 0);
    poke(0xb404 + 95 * 8, 0);
    poke(0xb405 + 95 * 8, 0);
    poke(0xb406 + 95 * 8, 0);
    poke(0xb407 + 95 * 8, 63);
}

void init()
{
    cls();
    paper(0);
    ink(7);
    poke(0x26A, CURSOR_START);
    font();

}

void tank()
{
    scene1();
}

void main()
{

    init();
    tank();
    end();
}
