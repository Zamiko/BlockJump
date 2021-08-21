
/* These functions are based on the Arduino test program at
*  https://github.com/adafruit/Adafruit-SSD1351-library/blob/master/examples/test/test.ino
*
*  You can use these high-level routines to implement your
*  test program.
*/

// TODO Configure SPI port and use these libraries to implement
// an OLED test program. See SPI example program.

#include "hw_types.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "game_constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hw_memmap.h"
#include "gpio.h"
#include <string.h>
#include <ctype.h>

#include <stdbool.h>

extern int cursor_x;
extern int cursor_y;

float p = 3.1415926;


//*****************************************************************************
//  function delays 3*ulCount cycles
void delay(unsigned long ulCount){
	int i;

  do{
    ulCount--;
		for (i=0; i< 65535; i++) ;
	}while(ulCount);
}


//*****************************************************************************
void testfastlines(unsigned int color1, unsigned int color2) {
	unsigned int x;
	unsigned int y;

   fillScreen(BLACK);
   for (y=0; y < height()-1; y+=8) {
     drawFastHLine(0, y, width()-1, color1);
   }
	 delay(100);
   for (x=0; x < width()-1; x+=8) {
     drawFastVLine(x, 0, height()-1, color2);
   }
	 delay(100);
}

//*****************************************************************************

void testdrawrects(unsigned int color) {
	unsigned int x;

 fillScreen(BLACK);
 for (x=0; x < height()-1; x+=6) {
   drawRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color);
	 delay(10);
 }
}

//*****************************************************************************

void testfillrects(unsigned int color1, unsigned int color2) {

	unsigned char x;

 fillScreen(BLACK);
 for (x=height()-1; x > 6; x-=6) {
   fillRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color1);
   drawRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color2);
	 delay(10);
 }
}

//*****************************************************************************

void testfillcircles(unsigned char radius, unsigned int color) {
	unsigned char x;
	unsigned char y;

  for (x=radius; x < width()-1; x+=radius*2) {
    for (y=radius; y < height()-1; y+=radius*2) {
      fillCircle(x, y, radius, color);
			delay(10);
    }
  }
}

//*****************************************************************************

void testdrawcircles(unsigned char radius, unsigned int color) {
	unsigned char x;
	unsigned char y;

  for (x=0; x < width()-1+radius; x+=radius*2) {
    for (y=0; y < height()-1+radius; y+=radius*2) {
      drawCircle(x, y, radius, color);
			delay(10);
    }
  }
}

//*****************************************************************************

void testtriangles() {
  int color = 0xF800;
  int t;
  int w = width()/2;
  int x = height()-1;
  int y = 0;
  int z = width()-1;

  fillScreen(BLACK);
  for(t = 0 ; t <= 15; t+=1) {
    drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
		delay(10);
  }
}

//*****************************************************************************

void testroundrects() {
  int color = 100;

	int i;
  int x = 0;
  int y = 0;
  int w = width();
  int h = height();

  fillScreen(BLACK);

  for(i = 0 ; i <= 24; i++) {
    drawRoundRect(x, y, w, h, 5, color);
    x+=2;
    y+=3;
    w-=4;
    h-=6;
    color+=1100;
  }
}

//*****************************************************************************
void testlines(unsigned int color) {
	unsigned int x;
	unsigned int y;

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(0, 0, x, height()-1, color);
   }
	 delay(10);
   for (y=0; y < height()-1; y+=6) {
     drawLine(0, 0, width()-1, y, color);
   }
	 delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(width()-1, 0, x, height()-1, color);
   }
	 delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(width()-1, 0, 0, y, color);
   }
	 delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(0, height()-1, x, 0, color);
   }
	 delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(0, height()-1, width()-1, y, color);
   }
	 delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(width()-1, height()-1, x, 0, color);
   }
	 delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(width()-1, height()-1, 0, y, color);
   }
	 delay(100);

}

//*****************************************************************************

void lcdTestPattern(void)
{
  unsigned int i,j;
  goTo(0, 0);

  for(i=0;i<128;i++)
  {
    for(j=0;j<128;j++)
    {
      if(i<16){writeData(RED>>8); writeData((unsigned char) RED);}
      else if(i<32) {writeData(YELLOW>>8);writeData((unsigned char) YELLOW);}
      else if(i<48){writeData(GREEN>>8);writeData((unsigned char) GREEN);}
      else if(i<64){writeData(CYAN>>8);writeData((unsigned char) CYAN);}
      else if(i<80){writeData(BLUE>>8);writeData((unsigned char) BLUE);}
      else if(i<96){writeData(MAGENTA>>8);writeData((unsigned char) MAGENTA);}
      else if(i<112){writeData(BLACK>>8);writeData((unsigned char) BLACK);}
      else {writeData(WHITE>>8); writeData((unsigned char) WHITE);}
    }
  }
}
/**************************************************************************/
void lcdTestPattern2(void)
{
  unsigned int i,j;
  goTo(0, 0);

  for(i=0;i<128;i++)
  {
    for(j=0;j<128;j++)
    {
      if(j<16){writeData(RED>>8); writeData((unsigned char) RED);}
      else if(j<32) {writeData(YELLOW>>8);writeData((unsigned char) YELLOW);}
      else if(j<48){writeData(GREEN>>8);writeData((unsigned char) GREEN);}
      else if(j<64){writeData(CYAN>>8);writeData((unsigned char) CYAN);}
      else if(j<80){writeData(BLUE>>8);writeData((unsigned char) BLUE);}
      else if(j<96){writeData(MAGENTA>>8);writeData((unsigned char) MAGENTA);}
      else if(j<112){writeData(BLACK>>8);writeData((unsigned char) BLACK);}
      else {writeData(WHITE>>8);writeData((unsigned char) WHITE);}
    }
  }
}

/**************************************************************************/
int updateCursor(int cursor_pos_y){
    //delete previous cursor position
    fillCircle(5,cursor_pos_y,CURSOR_R,MAIN_SCREEN_COLOR);

    //draw new cursor
    int new_cur;
    if (cursor_pos_y == START_SETTING_Y)
        new_cur = GRAVITY_SETTING_Y;
    if (cursor_pos_y == GRAVITY_SETTING_Y)
        new_cur = HIGHS_SETTING_Y;
    if (cursor_pos_y == HIGHS_SETTING_Y)
        new_cur = START_SETTING_Y;

    fillCircle(5,new_cur,CURSOR_R,BLACK);
    printf("new cursor: %d\n", new_cur);
    return new_cur;
}

int mainScreen(void){
    char name[10] = "Block Jump";
    // Paint BackGround
    fillScreen(GREEN);
    fillRect(3,3, 127-6, 127-6, MAIN_SCREEN_COLOR);

    //Display title
    int i;
    int cord = 10;
    for (i=0; i<10; i++){
        drawChar(cord,10, name[i], BLACK, MAIN_SCREEN_COLOR, 2);
        cord += 11;
    }
    drawLine(10,30, 127-10, 30, BLACK);

    //Display Options
    char start[5] = "Start";
    cord = 10;
    for (i=0; i<5; i++){
        drawChar(cord,START_SETTING_Y, start[i], BLACK, MAIN_SCREEN_COLOR, 1);
        cord += 6;
    }

    char g[16] = "Gravity Settings";
    cord = 10;
    for(i=0; i<16; i++){
        drawChar(cord,GRAVITY_SETTING_Y, g[i], BLACK, MAIN_SCREEN_COLOR, 1);
        cord += 6;
    }


    char hs[11] = "High Scores";
    cord = 10;
    for (i=0; i<11; i++){
        drawChar(cord,HIGHS_SETTING_Y, hs[i], BLACK, MAIN_SCREEN_COLOR, 1);
        cord += 6;
    }

    //Draw Cursor
    fillCircle(5,START_SETTING_Y,CURSOR_R,BLACK);
    int cursor = START_SETTING_Y;
    //polling for SW3 and SW2
    while(1)
    {
        if(GPIOPinRead(GPIOA1_BASE, 0x20)){ //SW3 pressed
            printf("SW3 pressed\n");
            break;
        }

        if(GPIOPinRead(GPIOA2_BASE, 0x40)){ //SW2 pressed
            printf("SW2 pressed\n");
            cursor = updateCursor(cursor);

        }
    }


    return cursor;
}

void GameOverBanner(void)
{ //Size of screen 127 x 127
    fillScreen(BLACK);
    char gg[9] = "GAME OVER";
    int x = 30;
    int y = 20;
    int i;
    for (i=0; i<9; i++){
        if (gg[i] == ' '){
            y = 40;
            x = 30;
            continue;
        }
        drawChar(x,y, gg[i], WHITE, BLACK, 2);
        x += 20;
    }

    delay(450); //1sec == 50


}

void drawPlayer(int x0, int y0, unsigned int color){
    fillRect(x0,y0,PLYR_HEIGHT,PLYR_WIDTH,color); //Top Body

    if (color == BLACK){
        fillRect(x0,y0,7,PLYR_WIDTH,BLACK); //Lower Body
    }
    else{
        fillRect(x0,y0,7,PLYR_WIDTH,DARKGREEN); //Lower Body
    }
}

int getRandomStepWidth(){
    srand(time(0));
    int w = (rand() % (STEP_WIDTH + 1 - PLYR_WIDTH/3)) + PLYR_WIDTH/3;
    return w;
}

int getRandomStepYCord(){ //actual y axis
    srand(time(0));
    int y = (rand() % (127- PLYR_WIDTH/3 + 1 - 0)) + 0;
    return y;
}

int getRandomStepXCord(int min, int max){ //actual x axis
    srand(time(0));
    int x = (rand() % (max - min + 1)) + min;
    return x;
}


void drawStep(int x0, int y0, int width){
   fillRect(x0, y0, STEP_HEIGHT, width, MAROON);
}

void eraseStep(int x0, int y0, int width){
   fillRect(x0, y0, STEP_HEIGHT, width, BLACK);
}

int updateGravityScreen(){
    char name[11] = "New Gravity";
    // Paint BackGround
    //fillScreen(GREEN);
    fillRect(3,3, 127-6, 127-6, MAIN_SCREEN_COLOR);

    //Display title
    int i;
    int cord = 2;
    for (i=0; i<11; i++){
        drawChar(cord,10, name[i], BLACK, MAIN_SCREEN_COLOR, 2);
        cord += 11;
    }
    drawLine(10,30, 127-10, 30, BLACK);

    //Display Message
    cord = 10;
    char message[19] = "Pick a value (1-6):";
    for (i=0; i<19; i++){
        drawChar(cord,40, message[i], BLACK, MAIN_SCREEN_COLOR, 1);
        cord += 6;
    }


    //polling for SW3 and SW2
    int g = 1;
    drawChar(127/2,60, g+'0', BLACK, MAIN_SCREEN_COLOR, 2);
    while(1)
    {
        if(GPIOPinRead(GPIOA1_BASE, 0x20)){ //SW3 pressed
            printf("SW3 pressed\n");
            break;
        }

        if(GPIOPinRead(GPIOA2_BASE, 0x40)){ //SW2 pressed
            printf("SW2 pressed\n");
            drawChar(127/2,60, g+'0', MAIN_SCREEN_COLOR, MAIN_SCREEN_COLOR, 2);
            g = (g < 6) ? g+1 : 1;
            drawChar(127/2,60, g+'0', BLACK, MAIN_SCREEN_COLOR, 2);
        }
    }

    return g;
}

void showHighScores(int *SCORES, char **NAMES){
    //transfer int scores into string
    char snum0[5];
    char snum1[5];
    char snum2[5];
    char snum3[5];
    char snum4[5];

    sprintf(snum0, "%i", SCORES[0]);
    sprintf(snum1, "%i", SCORES[1]);
    sprintf(snum2, "%i", SCORES[2]);
    sprintf(snum3, "%i", SCORES[3]);
    sprintf(snum4, "%i", SCORES[4]);

    char name[11] = "High Scores";
        // Paint BackGround
        fillRect(3,3, 127-6, 127-6, MAIN_SCREEN_COLOR);

        //Display title
        int i;
        int cord = 2;
        for (i=0; i<11; i++){
            drawChar(cord,10, name[i], BLACK, MAIN_SCREEN_COLOR, 2);
            cord += 11;
        }
        drawLine(10,30, 127-10, 30, BLACK);


        //Display High scores
        int Y_POS = 40;
        ////////////// 0
        cord = 10;
        for (i=0; i<5; i++){
           if(isdigit(snum0[i])){
               drawChar(cord, Y_POS, snum0[i], BLACK, MAIN_SCREEN_COLOR, 1);
               cord +=6;
           }

        }
        cord +=6;
        printf("Will print name:\n");
        printf("%s\n", NAMES[0]);
        for (i=0; i<strlen(NAMES[0]); i++){
            if(NAMES[0][i]!= NULL){
                drawChar(cord, Y_POS, NAMES[0][i], BLACK, MAIN_SCREEN_COLOR, 1);
                cord +=6;
            }
        }
        Y_POS += 10;
        //////////////////
        ////////////// 1
        cord = 10;
        for (i=0; i<5; i++){
           if(isdigit(snum1[i])){
               drawChar(cord, Y_POS, snum1[i], BLACK, MAIN_SCREEN_COLOR, 1);
               cord +=6;
           }

        }
        cord +=6;
        printf("Will print name:\n");
        printf("%s\n", NAMES[1]);
        for (i=0; i<strlen(NAMES[1]); i++){
            if(NAMES[1][i]!= NULL){
                drawChar(cord, Y_POS, NAMES[1][i], BLACK, MAIN_SCREEN_COLOR, 1);
                cord +=6;
            }
        }
        Y_POS += 10;
        //////////////////
        ////////////// 2
        cord = 10;
        for (i=0; i<5; i++){
           if(isdigit(snum2[i])){
               drawChar(cord, Y_POS, snum2[i], BLACK, MAIN_SCREEN_COLOR, 1);
               cord +=6;
           }

        }
        cord +=6;
        printf("Will print name:\n");
        printf("%s\n", NAMES[2]);
        for (i=0; i<strlen(NAMES[2]); i++){
            if(NAMES[2][i]!= NULL){
                drawChar(cord, Y_POS, NAMES[2][i], BLACK, MAIN_SCREEN_COLOR, 1);
                cord +=6;
            }
        }
        Y_POS += 10;
        //////////////////
        ////////////// 3
        cord = 10;
        for (i=0; i<5; i++){
           if(isdigit(snum3[i])){
               drawChar(cord, Y_POS, snum3[i], BLACK, MAIN_SCREEN_COLOR, 1);
               cord +=6;
           }

        }
        cord +=6;
        printf("Will print name:\n");
        printf("%s\n", NAMES[3]);
        for (i=0; i<strlen(NAMES[3]); i++){
            if(NAMES[3][i]!= NULL){
                drawChar(cord, Y_POS, NAMES[3][i], BLACK, MAIN_SCREEN_COLOR, 1);
                cord +=6;
            }
        }
        Y_POS += 10;
        //////////////////
        ////////////// 4
        cord = 10;
        for (i=0; i<5; i++){
           if(isdigit(snum4[i])){
               drawChar(cord, Y_POS, snum4[i], BLACK, MAIN_SCREEN_COLOR, 1);
               cord +=6;
           }

        }
        cord +=6;
        printf("Will print name:\n");
        printf("%s\n", NAMES[4]);
        for (i=0; i<strlen(NAMES[4]); i++){
            if(NAMES[4][i]!= NULL){
                drawChar(cord, Y_POS, NAMES[4][i], BLACK, MAIN_SCREEN_COLOR, 1);
                cord +=6;
            }
        }
        //////////////////
        //////////////////
        //////////////////


        //polling for SW3 and SW2
        while(1)
        {
            if(GPIOPinRead(GPIOA1_BASE, 0x20)){ //SW3 pressed
                printf("SW3 pressed\n");
                break;
            }

            if(GPIOPinRead(GPIOA2_BASE, 0x40)){ //SW2 pressed
                printf("SW2 pressed\n");
            }
        }
}

int * get_allscores(const char* mssg){
    int i;
    int postfirst_left_brack_index;
    int postfirst_right_brack_index;
    char scores_str[100];
    static int scores_int[5];

    //find all scores indices aka whatever is inside the first brackets
    for (i=0; i < strlen(mssg); i++){
        if (mssg[i] == '[')
            postfirst_left_brack_index = i+1;
        if (mssg[i] == ']'){
            postfirst_right_brack_index = i-1;
            break;
        }
    }

    //assign all the values to scores_str
    strncpy(scores_str, mssg+postfirst_left_brack_index,postfirst_right_brack_index-postfirst_left_brack_index+1);
    scores_str[postfirst_right_brack_index-postfirst_left_brack_index+1] = '\0';
    //printf("from get_allscores:\n%s\n", scores_str);


    //get the actual number from a string
    //credit: https://stackoverflow.com/questions/13399594/how-to-extract-numbers-from-string-in-c
    char *p = scores_str;
    i = 0;
    while (*p) { // While there are more characters to process...
        if ( isdigit(*p) || ( (*p=='-'||*p=='+') && isdigit(*(p+1)) )) {
            // Found a number
            int val = strtol(p, &p, 10); // Read number
            //printf("%d:", val); // and print it.
            scores_int[i] = val;
            printf("%d\n", scores_int[i]); // and print it.
            i += 1;
        } else {
            // Otherwise, move on to the next character.
            p++;
        }
    }

    return scores_int;

}

int * update_allscore(int* sscores, int insert_idx, int plyr_score){
    static int new_scores[5];
    int i;
    printf("Updating allscores...\n");
    for(i=0; i<5; i++){
        if (insert_idx == i){
            new_scores[i] = plyr_score;
            i += 1;
            break;
        }
        else{
            new_scores[i] = sscores[i];
        }
    }
    //remaining
    for(i; i<5; i++){
        new_scores[i] = sscores[i-1];
    }


    //Print the scores for reassurance
    printf("New scores:\n");
    for(i=0; i<5; i++){
        printf("%d\n", new_scores[i]);
    }
    return new_scores;
}

char** get_allnames(const char* mssg){
    int i;
    int left_brack_count=0;
    int right_brack_count=0;
    int postsecond_left_brack_index;
    int postsecond_right_brack_index;
    char names_str[100];
    bool assignRindex = true;
    bool assignLindex = true;
    char new_names[5][15];
    char**updated_new_names = (char**)malloc(sizeof(char*)*5);


    //find all scores indices aka whatever is inside the first brackets
    for (i=0; i < strlen(mssg); i++){
        if (mssg[i] == '[')
            left_brack_count+=1;
        if (mssg[i] == ']'){
            right_brack_count+=1;
        }

        if (right_brack_count == 2 && assignRindex){
            postsecond_right_brack_index = i-1;
            assignRindex = false;
        }
        if (left_brack_count == 2 && assignLindex){
            postsecond_left_brack_index = i+1;
            assignLindex = false;
        }

    }

    //assign all the values to scores_str
    strncpy(names_str, mssg+postsecond_left_brack_index,postsecond_right_brack_index-postsecond_left_brack_index+1);
    names_str[postsecond_right_brack_index-postsecond_left_brack_index+1] = '\0';
    printf("from get_allnames:\n%s\n", names_str);

    //tokenize string to pull actual names
    char *token = strtok(names_str, ",");
    i =0;
    while(token != NULL){
        char one_name[15];
        strncpy(one_name, token+1, strlen(token)-2 );
        one_name[strlen(token)-2] = '\0';
        printf("TOKEN: %s, ONE_NAME: %s\n", token, one_name);
        strcpy(new_names[i],one_name);
        printf("i: %d, one_name: %s\n", i, new_names[i]);
        i = i+ 1;
        token = strtok(NULL, ",");

    }


    for(i=0; i<5; i++){
        updated_new_names[i]=(char*)malloc(15);
        strcpy(updated_new_names[i],new_names[i]);
    }

    return updated_new_names;
}

char** update_allnames(const char* mssg,  int insert_idx){
    int i;
    int left_brack_count=0;
    int right_brack_count=0;
    int postsecond_left_brack_index;
    int postsecond_right_brack_index;
    char names_str[100];
    bool assignRindex = true;
    bool assignLindex = true;
    char new_names[5][15];
    //char updated_new_names[5][15];
    char**updated_new_names = (char**)malloc(sizeof(char*)*5);


    //find all scores indices aka whatever is inside the first brackets
    for (i=0; i < strlen(mssg); i++){
        if (mssg[i] == '[')
            left_brack_count+=1;
        if (mssg[i] == ']'){
            right_brack_count+=1;
        }

        if (right_brack_count == 2 && assignRindex){
            postsecond_right_brack_index = i-1;
            assignRindex = false;
        }
        if (left_brack_count == 2 && assignLindex){
            postsecond_left_brack_index = i+1;
            assignLindex = false;
        }

    }

    //assign all the values to scores_str
    strncpy(names_str, mssg+postsecond_left_brack_index,postsecond_right_brack_index-postsecond_left_brack_index+1);
    names_str[postsecond_right_brack_index-postsecond_left_brack_index+1] = '\0';
    printf("from get_allnames:\n%s\n", names_str);

    //tokenize string to pull actual names
    char *token = strtok(names_str, ",");
    i =0;
    while(token != NULL){
        char one_name[15];
        strncpy(one_name, token+1, strlen(token)-2 );
        one_name[strlen(token)-2] = '\0';
        printf("TOKEN: %s, ONE_NAME: %s\n", token, one_name);
        strcpy(new_names[i],one_name);
        printf("i: %d, one_name: %s\n", i, new_names[i]);
        i = i+ 1;
        token = strtok(NULL, ",");

    }


    /////
//    printf("Reprint for reassurance:\n");
//    for (i=0; i<5 ; i++){
//        printf("i: %d, %s\n", i, new_names[i]);
//    }

    //UPDATE NAMES
    printf("Updating names...\n");
    //alocate mem
    for(i=0; i<5; i++){
        updated_new_names[i]=(char*)malloc(15);
    }


    printf("\nUpdating..\n");
    for(i=0; i<5; i++){
        if (insert_idx == i){
            strcpy(updated_new_names[i],"<unknown>");
            i  += 1;
            break;
        }
        else{
            strcpy(updated_new_names[i],new_names[i]);
        }
    }
    //remaining
    printf("====================\n");
    for(i; i<5; i++){
        printf("%s\n",new_names[i-1]);
        strcpy(updated_new_names[i],new_names[i-1]);
    }
    printf("====================\n");

    printf("Print updated names: \n");
    for(i=0; i<5; i++){
        printf("%s\n", updated_new_names[i]);
    }


    return updated_new_names;
}

char* getUpdatedMssg(int plyr_score, char**NAMES, int*SCORES, bool isHS){
    char *mssg;
    mssg = (char*)malloc(750);

    //char mssg[750] = "{\"state\": {\n\r\"desired\" : {\n\r\"allscores\" : [ ";
    //char part1[] = "{\"state\": {\n\r\"desired\" : {\n\r\"allscores\" : [ ";
    strcat(mssg,"{\"state\": {\n\r\"desired\" : {\n\r\"allscores\" : [ ");


    //transfer int scores into string
    char snum0[5];
    char snum1[5];
    char snum2[5];
    char snum3[5];
    char snum4[5];

    sprintf(snum0, "%d", SCORES[0]);
    sprintf(snum1, "%d", SCORES[1]);
    sprintf(snum2, "%d", SCORES[2]);
    sprintf(snum3, "%d", SCORES[3]);
    sprintf(snum4, "%d", SCORES[4]);

    strcat(mssg,"\"");
    strcat(mssg,snum0);
    strcat(mssg,"\",");

    strcat(mssg,"\"");
    strcat(mssg,snum1);
    strcat(mssg,"\",");

    strcat(mssg,"\"");
    strcat(mssg,snum2);
    strcat(mssg,"\",");

    strcat(mssg,"\"");
    strcat(mssg,snum3);
    strcat(mssg,"\",");

    strcat(mssg,"\"");
    strcat(mssg,snum4);
    strcat(mssg,"\" ], ");



    strcat(mssg, "\n\r\"allnames\":[ ");

    //transfer all the jumpers
    strcat(mssg, "\"");
    strcat(mssg, NAMES[0]);
    strcat(mssg, "\",");

    strcat(mssg, "\"");
    strcat(mssg, NAMES[1]);
    strcat(mssg, "\",");

    strcat(mssg, "\"");
    strcat(mssg, NAMES[2]);
    strcat(mssg, "\",");

    strcat(mssg, "\"");
    strcat(mssg, NAMES[3]);
    strcat(mssg, "\",");

    strcat(mssg, "\"");
    strcat(mssg, NAMES[4]);
    strcat(mssg, "\"],");

    //Your score
    strcat(mssg, " \n\r\"yourscore\":");
    strcat(mssg, "\"");
    char s_score[5];
    sprintf(s_score, "%d", plyr_score);
    strcat(mssg, s_score);
    strcat(mssg, "\", \n\r\"hs\" : \"");

    //Set highscore
    if (isHS == true){
        strcat(mssg, "1");
    }
    if (isHS == false){
        strcat(mssg, "0");
    }


    //end
    strcat(mssg, "\"\n\r}}}\n\r\n\r\0");

    printf("Updated Message: \n%s\n", mssg);
    return mssg;

}





