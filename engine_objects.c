// objects
#define OBJ_AIR 1
#define OBJ_TANK 2
#define OBJ_FISH1 3
#define OBJ_BUBBLE 4
#define OBJ_SEAWEED 5
#define OBJ_FISH2 6
#define OBJ_FISH3 7
#define OBJ_FISHT2 8
#define OBJ_FISHT3 10
#define OBJ_CASTLE 9
#define OBJ_DUCK 11

#define X_MIN 2
#define X_MAX 36

#define Y_MIN 3
#define Y_MAX 26

#define MSG_Y 7

int i;

char *fish1[6] = {
    "><>",
    "<><",

    ">()",
    "()<",

    ">O",
    "O<",

};

char *fish2l[3] = {
    "\003 __ ",
    "\003/o \\/ ",
    "\003\\__/\\ "
};

char *fish2r[3] = {
    "\007  __",
    "\007\\/ o\\",
    "\007/\\__/"
};


char *fish3l[5] = {
    "\003  / ",
    "\003 /\\ ",
    "\003<')=< ",
    "\003 \\/ ",
    "\003  \\ "
};

char *fish3r[5] = {
    "\003  \\",
    "\003  /\\",
    "\003>=)'>",
    "\003  \\/",
    "\003  /"
};

/*
  \ 
  /\ 
>=)'> 
  \/  
  /
	
  /
 /\
<')=<
 \/
  \ 
 __
/o \/|                               
\__/\|  
 */



void executeUpdate()
{
    switch (objects[currentObject].type)
    {
            //        case OBJ_FISH1:
            //            fish1Update();
            //            break;		
        case OBJ_AIR:
            airUpdate();
            break;
        case OBJ_TANK:
            tankUpdate();
            break;
        case OBJ_BUBBLE:
            bubbleUpdate();
            break;
        case OBJ_SEAWEED:
            seaweedUpdate();
            break;
        case OBJ_FISH2:
            fish2Update();
            break;
        case OBJ_FISH3:
            fish3Update();
            break;
        case OBJ_FISHT2:
            fishT2Update();
            break;
        case OBJ_FISHT3:
            fishT3Update();
            break;
        case OBJ_CASTLE:
            castleUpdate();
            break;
        case OBJ_DUCK:
            duckUpdate();
            break;
    }
}

void castleUpdate()
{
	
    printText("\007 |> v-v-v-v  |>", objects[currentObject].x, objects[currentObject].y - 4);
    printText("\007/_\\ |     | /_\\", objects[currentObject].x, objects[currentObject].y - 3);
    printText("\007|o|'''''''''|o| ", objects[currentObject].x, objects[currentObject].y - 2);
    printText("\007| |[]  _  []| |", objects[currentObject].x, objects[currentObject].y - 1);
    printText("\007| |   |#|   | |", objects[currentObject].x, objects[currentObject].y);
    
	if (rand()%10 == 0)
		printText("\007<|  v-v-v-v <| ", objects[currentObject].x, objects[currentObject].y - 4);
}

void fishT2Update()
{
    char color;

    if (objects[currentObject].x == 0 || objects[currentObject].x > 33)
    {
        //objects[currentObject].active = 0;
        printText("      ", objects[currentObject].x, objects[currentObject].y);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 1);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 2);

        color = rand() % 7 + 1;
        objects[currentObject].y = rand() % 10 + 5;

        switch (objects[currentObject].data[0])
        {
            case '0':
                objects[currentObject].x = 30;
                fish2l[0][0] = color;
                fish2l[1][0] = color;
                fish2l[2][0] = color;
                objects[currentObject].active = 0;
                return;
                break;
            case '1':
                objects[currentObject].x = 1;
                fish2r[0][0] = color;
                fish2r[1][0] = color;
                fish2r[2][0] = color;
                objects[currentObject].active = 0;

                return;
                break;
        }

        return;
    }

    switch (objects[currentObject].data[0])
    {
        case '0':
            objects[currentObject].x--;
            break;
        case '1':
            objects[currentObject].x++;
            break;
    }

    for (i = 0; i < 3; i++)
    {
        switch (objects[currentObject].data[0])
        {
            case '0':
                printText(fish2l[i], objects[currentObject].x, objects[currentObject].y + i);
                break;
            case '1':
                printText(fish2r[i], objects[currentObject].x, objects[currentObject].y + i);
                break;
        }
    }

    if (rand()%20 == 0) addObject(OBJ_BUBBLE,objects[currentObject].x,objects[currentObject].y,".");
}

void fishT3Update()
{
    char color;

    if (objects[currentObject].x == 0 || objects[currentObject].x > 33)
    {
        //objects[currentObject].active = 0;
        printText("      ", objects[currentObject].x, objects[currentObject].y);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 1);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 2);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 3);
        printText("      ", objects[currentObject].x, objects[currentObject].y + 4);

        color = rand() % 7 + 1;
        objects[currentObject].y = rand() % 10 + 5;

        switch (objects[currentObject].data[0])
        {
            case '0':
                objects[currentObject].x = 33;
                fish3l[0][0] = color;
                fish3l[1][0] = color;
                fish3l[2][0] = color;
                fish3l[3][0] = color;
                fish3l[4][0] = color;
                objects[currentObject].active = 0;
                return;
                break;
            case '1':
                objects[currentObject].x = 1;
                fish3r[0][0] = color;
                fish3r[1][0] = color;
                fish3r[2][0] = color;
                fish3r[3][0] = color;
                fish3r[4][0] = color;
                objects[currentObject].active = 0;
                return;
                break;
        }

        return;
    }

    switch (objects[currentObject].data[0])
    {
        case '0':
            objects[currentObject].x--;
			if (rand()%20 == 0) addObject(OBJ_BUBBLE,objects[currentObject].x,objects[currentObject].y,".");
            break;
        case '1':
            objects[currentObject].x++;
			if (rand()%20 == 0) addObject(OBJ_BUBBLE,objects[currentObject].x+5,objects[currentObject].y,".");
            break;
    }

    for (i = 0; i < 5; i++)
    {
        switch (objects[currentObject].data[0])
        {
            case '0':
                printText(fish3l[i], objects[currentObject].x, objects[currentObject].y + i);
                break;
            case '1':
                printText(fish3r[i], objects[currentObject].x, objects[currentObject].y + i);
                break;
        }
    }
   

}

//data 0 - len

seaweedUpdate()
{
    int i;

    char *w1;
    char *w2;

    if (rand() % 2)
    {
        w1 = "\002(";
        w2 = "\002)";
    } else
    {
        w1 = "\002)";
        w2 = "\002(";

    }


    for (i = 0; i < objects[currentObject].data[0]; i += 2)
    {
        printText(w1, objects[currentObject].x, objects[currentObject].y - i);
        printText(w2, objects[currentObject].x, objects[currentObject].y - 1 - i);

    }

}

void airUpdate()
{
    //printText("V",objects[currentObject].x,objects[currentObject].y+1);
    if (rand() % 3 == 0)
    {
        addObject(OBJ_BUBBLE, objects[currentObject].x, objects[currentObject].y, "o");
    }
}

void bubbleUpdate()
{
    printChar(32, objects[currentObject].x, objects[currentObject].y);

    switch (objects[currentObject].y)
    {
        case 4:
        case 3:
        case 2:
            objects[currentObject].active = 0;
            return;
            break;
    }

    objects[currentObject].y--;
    objects[currentObject].y--;
    //	objects[currentObject].y --;
    objects[currentObject].x += rand() % 3 - 1;

    switch (objects[currentObject].x)
    {
        case 0: objects[currentObject].x = 1;
    }

    printChar(7, objects[currentObject].x - 1, objects[currentObject].y);
    printChar(objects[currentObject].data[0], objects[currentObject].x, objects[currentObject].y);
}

void tankUpdate()
{
    int rand = rand() % 20;
    //	printText("----------------------------------------... ... .... .... ......... .......  ...",0,2);
    //	//printText("....... .... .... ......... .......  ...",0,2);
    //	printText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",0,26);

	
    switch (counter % 5)
    {
        case 0:
            switch (rand)
            {

                case 7:addObject(OBJ_FISHT2, 33, rand() % 10 + 5, "0");
                    break;
                case 8:addObject(OBJ_FISHT2, 1, rand() % 10 + 5, "1");
                    break;

                case 1:addObject(OBJ_FISHT3, 33, rand() % 10 + 5, "0");
                    break;
                case 2:addObject(OBJ_FISHT3, 0, rand() % 10 + 5, "1");
                    break;

                case 9:addObject(OBJ_DUCK, 32, 0, "");
                    break;
            }
    }

}

void duckUpdate()
{
    objects[currentObject].x--;
    printText("=(')____, ", objects[currentObject].x, objects[currentObject].y);
    printText( "(  =  /-", objects[currentObject].x + 1, objects[currentObject].y + 1);

	if (rand()%7 == 0) printChar('>', objects[currentObject].x, objects[currentObject].y);
	
    if (objects[currentObject].x == 0)
    {
        objects[currentObject].active = 0;
        printText("          ", objects[currentObject].x, objects[currentObject].y);
        printText("----------", objects[currentObject].x, objects[currentObject].y + 1);
    }
}

void fish2Update()
{
    unsigned char speed = (char) objects[currentObject].data[0] - 48;

    printText("    ", objects[currentObject].x, objects[currentObject].y);
    objects[currentObject].x += speed;

    switch (objects[currentObject].x)
    {

        case 37:
        case 38:
        case 39:
            objects[currentObject].data[2] = rand() % 7 + 1;
            objects[currentObject].y = rand() % 15 + 5;
            objects[currentObject].x = 0;

            break;
    }

    printText(objects[currentObject].data + 2, objects[currentObject].x, objects[currentObject].y);

}

void fish3Update()
{
    unsigned char speed = (char) objects[currentObject].data[0] - 48;

    printText("    ", objects[currentObject].x, objects[currentObject].y);
    objects[currentObject].x -= speed;

    switch (objects[currentObject].x)
    {
        case 0:
        case 1:

            objects[currentObject].data[2] = rand() % 7 + 1;
            objects[currentObject].y = rand() % 15 + 5;
            objects[currentObject].x = 36;
            break;
    }

    printText(objects[currentObject].data + 2, objects[currentObject].x, objects[currentObject].y);
}

