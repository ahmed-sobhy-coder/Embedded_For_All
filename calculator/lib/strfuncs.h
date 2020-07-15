#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__
#include "stdint.h"
#include  "math.h" 
#include "string.h"
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
//search int8_tin string
int8_t charSearch(int8_t* str, int8_t ch);
/* convert string to float*/
double strToFloat(int8_t* str);
/*insert new int8_tin string */
void insertChar(int8_t* str, int8_t ch, int8_t index);
/* delete int8_tfrom string */
void  delChar(int8_t* str, int8_t index);
/*check if two strings are matched*/
int8_t strIsContain(int8_t* str1, int8_t* str2) ; 
/*get the index of str2 in str1*/
uint8_t getStrIndex(int8_t* str1, int8_t* str2) ;
/*delete str1 from str2*/
void delStr(int8_t* str1,int8_t*str2) ;
//this function returns 1 if int8_tis in string & return 0 if not
int8_t isContainCh(int8_t* str, int8_t ch);
#endif
