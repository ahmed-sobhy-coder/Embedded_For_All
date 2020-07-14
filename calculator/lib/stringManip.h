#ifndef __STRINGMANIP_H__
#define __STRINGMANIP_H__
#include "bitManip.h"
#include "stdint.h"
#include  "math.h" 
int8_t * IntToStr(int32_t num);
int8_t * Float_To_string_conversion(double float_num, uint8_t precision);
uint8_t strLen(int8_t* string);
uint8_t Slen_without_CR(int8_t* string);
void string_copy(int8_t* string1,int8_t* string2);
int32_t String_To_integer_Conversion(int8_t* string);
int32_t string_cmp(int8_t*str1,int8_t* str2);
int8_t Is_Contain(int8_t* string, int8_t* str);
/* reverse string */
void strRev(int8_t* str);
#endif
