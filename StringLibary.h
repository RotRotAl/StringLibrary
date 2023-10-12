#pragma once
#include <stdlib.h>
#ifndef __STRING
typedef char* string;
#define STRINGSIZE 256
#define __STRING
#endif // !__STRING

#ifndef __BOOL
#define BOOL char
#define true 1
#define false 0
#define __BOOL
#endif // !__BOOL


//get a string and retruns his length 
int GetStringLength(string);

//get a char and retruns if its part of a string
BOOL IsCharPartOfString(string, char);


//get a char and retruns the place of it in the string
int InsexOf(string, char);

//retruns how many times char is in string
unsigned short CountCharInString(string, char);

// retruns true if the two given strings are equal
BOOL IsEqual(string, string);

//Gets a string and retruns the same string without corupting the orignal string
void Copy(string, string);

//gets two string and them to each without corupting them the result will be in the third string
//exp. reateANewStringByAddingTwoStrings("XXX" "YYY" res) res will store after the func "XXXYYY"
string concatStrings(string, string);

//retruns true if a is part of b
BOOL IsSubstring(string, string);

//replace any instancte of a in b to c
BOOL Replace(string, string, string);

//take 123 retruns "123"
string StringParseOfInt(int);

//retruns the offset of a val in arr
int IndexInArr(string val, string arr[], int len);