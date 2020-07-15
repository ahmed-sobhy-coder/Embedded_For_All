#ifndef __CALC_H__
#define __CALC_H__
#include "stdint.h"
#include  "math.h"
#include "strFuncs.h"
#include "array.h"
#include "uart.h"
int8_t isUnaryMinus(int8_t* str, int8_t index);
void handleParenthesis(int8_t* str);
/*   string calculator function */
double strCalc(double* nums, int8_t* opers);
/* define rules for calculator in order to detect errors*/
uint8_t rules(int8_t* str);
/*check if the num is int or double */
int8_t isFloat(double num);
/* extract operands from string*/
void extractFnums(int8_t* str, double* Fnums, int8_t* opers) ;
/* extract operators from string*/
void extractOpers(int8_t* str, int8_t* opers);

#endif