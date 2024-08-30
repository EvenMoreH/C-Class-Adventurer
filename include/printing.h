#ifndef printing_H_
#define printing_H_

//put your function headers here

void toString(char *input, const char *format, ...);

void formattedText(char *printout);

void customText(char *printout, int sleepBefore, int sleepAfter);

void newLine (int lines);

void storyText(char *textToWrite);

void storyTextUnformatted(char *textToWrite);
#endif