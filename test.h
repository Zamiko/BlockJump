/*
 * test.h
 *
 *  Created on: May 14, 2021
 *      Author: Nexus
 */

#ifndef TEST_H_
#define TEST_H_

void delay(unsigned long ulCount);
void testfastlines(unsigned int color1, unsigned int color2);
void testdrawrects(unsigned int color);
void testfillrects(unsigned int color1, unsigned int color2);
void testfillcircles(unsigned char radius, unsigned int color);
void testdrawcircles(unsigned char radius, unsigned int color);
void testtriangles();
void testroundrects();
void testlines(unsigned int color);
void lcdTestPattern(void);
void lcdTestPattern2(void);

int updateCursor(int cursor_pos_y);
int mainScreen(void);
void GameOverBanner(void);
void drawPlayer(int x0, int y0, unsigned int color);
int getRandomStepWidth();
int getRandomStepYCord();
int getRandomStepXCord(int min, int max);
void drawStep(int x0, int y0, int width);
void eraseStep(int x0, int y0, int width);
int updateGravityScreen();
void showHighScores();

int * get_allscores(const char* mssg);
int * update_allscore(int* sscores, int insert_idx, int plyr_score);
char** get_allnames(const char* mssg);
char** update_allnames(const char* mssg,  int insert_idx);
char* getUpdatedMssg(int plyr_score, char**NAMES, int*SCORES, bool isHS);

#endif /* TEST_H_ */
