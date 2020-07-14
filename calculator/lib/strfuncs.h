#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__
#include "stdint.h"
#include  "math.h" 
int8_t* intToStr(int32_t num);
void floatToStr(double float_num, uint8_t precision, int8_t* string);
int8_t* floatToStrWithReturn(double float_num, uint8_t precision);
uint8_t strLen(int8_t* string);
uint8_t Slen_without_CR(int8_t* string);
void strCopy(int8_t* str1, int8_t* str2);
//convert string to integer value
int32_t strToInt(int8_t* str);
int32_t strCmp(int8_t* str1, int8_t* str2);
/*check if two strings are matched*/
int8_t strIsContain(int8_t* str1, int8_t* str2);
/* reverse string */
void strRev(int8_t* str);
/* check if the string contains only digits*/
int8_t isStrOfDigits(int8_t* str);
//search char in string
int8_t charSearch(int8_t* str, int8_t ch);
/* convert string to float*/
double strToFloat(int8_t* str);
/*print every element in array */
/*get string from user */
void getStr(int8_t* str);
/*insert new char in string */
void insertChar(int8_t* str, int8_t ch, int8_t index);
/* delete char from string */
void  delChar(int8_t* str, int8_t index);
#endif
