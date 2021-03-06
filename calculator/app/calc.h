#ifndef __CALC_H__
#define __CALC_H__
#include "stdint.h"
#include  "math.h"
#include "strFuncs.h"
#include "array.h"
#include "uart.h"
#include "bluetooth.h"
/* even operators like >= or <= or ==*/
typedef enum
{
    POWER = '0',        //** 
    GREATER_THEN_EQUAL, //>=
    LESS_THEN_EQUAL,    //<=
    EQUALITY,           //==
    NOTEQUAL,           //!=
    SHLEFT,             //<<
    SHRIGHT,            //>>
    LOGICAND,           //&&
    LOGICOR,            //||
} CALC;
typedef enum
{
    NO_ERROR,     //there is no error
	INVALID_BRACES, //there is error in braces
    INVALID_OPER,   //there is error in operators
	INVALID_NO_PREV,      //there is no previous result
	INVALID_CONVERSION,
	INVALID_EXPRESSION,
	INVALID_CHAR,
	INVALID_OPERAND,
} ERROR_TYPE;
int8_t isUnaryMinus(int8_t* str, int8_t index);
/*handle all () in string */
ERROR_TYPE handleParenthesis(int8_t* str)  ;

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
double calculator(int8_t* str);
 /* 
  this function is used to do operations in the previous result
  it simply remove ans string from expression and replaces it with the previous value
*/
ERROR_TYPE handleAns(int8_t* str, double* nums, uint8_t prev);
#endif
