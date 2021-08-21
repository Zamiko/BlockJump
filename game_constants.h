/*
 * game_constants.h
 *
 *  Created on: Jun 3, 2021
 *      Author: Nexus
 */

#ifndef GAME_CONSTANTS_H_
#define GAME_CONSTANTS_H_

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define GREEN           0x07E0
#define CYAN            0x07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define OLIVE           0x7BE0
#define DARKGREEN       0x03E0
#define GAME_BACKGROUND 0x7BEF
#define MAIN_SCREEN_COLOR  0x000F
#define MAROON          0x7800

//Obstacles
#define STEP_HEIGHT 5
#define STEP_WIDTH 16
#define MIN_STEP_CUSHION 15

//DURING GAME
#define NUM_STEPS 3

//Character
#define PLYR_HEIGHT 17
#define PLYR_WIDTH 9

//Physics
//#define GRAVITY -1
#define JUMP 7
#define BOUNCES 8
#define BOUNCE_RANGE (BOUNCES * JUMP)

#define BOUNDARY 84


//MAIN SCREEN
#define START_SETTING_Y 40
#define GRAVITY_SETTING_Y 50
#define HIGHS_SETTING_Y 60
#define CURSOR_R 1



#endif /* GAME_CONSTANTS_H_ */
