#include "calc.h"
int8_t numOpers = 0;
uint8_t error;
char class0[4] = { '!', '~', '\0' };
char class1[4] = { '*', '/', '%', '\0' };
char class2[3] = { '+', '-', '\0' };
char class3[3] = { '<', '>', '\0' };
char class4[4] = { '&','^','|','\0' };
typedef enum
{
    ADD = '0',
    SUB,
    MUL,
    DIV,
    REM,
    POWER,
    GREATER_THEN,
    LESS_THEN,
    GREATER_THEN_EQUAL,
    LESS_THEN_EQUAL,
    EQUALITY,
    NOTEQUAL,
    EQUAL,
    SHLEFT,
    SHRIGHT,
    AND,
    OR,
    XOR,
    NOT,
    LOGICNOT,
    ADD_LOGINOT,
    SUB_LOGICNOT,
    MUL_LOGICNOT,
    DIV_LOGICNOT,
    LOGICAND,
    LOGICOR,
    GREATRNOT,
    LESSNOT,
    NOTADD,
    NOTNEGADD,
    NOTSUB,
    NOTNEGSUB,
    NOTMUL,
    NOTNEGMUL,
    NOTDIV,
    NOTNEGDIV,
    NOTREM,
    NOTNEGREM,
    SHIFT,

} calc;
calc OPER;
uint8_t Size = 0;
int8_t isUnaryMinus(int8_t* str, int8_t index) {//check if '-' is minus or sub operator
    int result;// returns 1 if it is minus operator , and 0 if it is sub operator 
    /* if the character before '-' is valid opertor, '-' is unary minus */
    /*if '-' exists at the begining of string, it is unary minus*/
    if (((str[index] == '-') && (str[index - 1]) == -1) || ((str[index] == '-') && (index == 0)))
    {
        result = 1;//return it is unary minus
    }
    else
    {
        result = 0;//it is sub operator 
    }
    return result; //return the result
}

/* convert string of digits to real number*/

int8_t isOperator(int8_t oper)
{
    int8_t result = 0; //return -1 means it is not valid operator
    if ((oper == '*') || (oper == '/') || (oper == '%') || (oper == '+') || (oper == '-'))
    {
        result = 1; // result 1 means it is valid operator
    }
    return result;
}

void extractOpers(int8_t* str, int8_t* opers)
{
    int8_t count1 = 0;//is used a s counter for all chars in string
    int8_t count2 = 0;//is used as a counter
    int8_t digit = 1;//flag to indicate that the next place if for digit not operator
                     //by default it it is 1 which means by default the next place if for digit
    int8_t unaryMnus = 0;
    numOpers = 0;
    while (str[count1] != '\0')
    {
        if ((isContainCh(class0, str[count1]) == 1))
        {
            if (isUnaryMinus(str, count1) == 1)
            {
                opers[count2] = '$';
                count2++;
                digit = 0;
            }
            else {
                opers[count2] = str[count1];
                str[count1] = -2;
                numOpers++;
                count2++;
                digit = 1;
            }
        }
        else if ((isContainCh(class1, str[count1]) == 1)
            || (isContainCh(class2, str[count1]) == 1))
        {
            if (isUnaryMinus(str, count1) == 1)
            {
                opers[count2] = '$';
                count2++;
                digit = 0;
            }
            else
            {
                opers[count2] = str[count1];
                str[count1] = -1;
                numOpers++;
                count2++;
                digit = 1;
            }
        }
        else  if ((isContainCh(class3, str[count1]) == 1) && (isContainCh(class3, str[count1 + 1]) == 1))

        {
            if (str[count1] == '>')opers[count2] = SHRIGHT;
            else if (str[count1] == '<')opers[count2] = SHLEFT;

            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((isContainCh(class3, str[count1]) == 1) && (str[count1 + 1] == '='))

        {
            if (str[count1] == '>')opers[count2] = GREATER_THEN_EQUAL;
            else if (str[count1] == '<')opers[count2] = LESS_THEN_EQUAL;
            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }

        else  if (isContainCh(class3, str[count1]) == 1)

        {
            if (str[count1] == '>')opers[count2] = GREATER_THEN;
            else if (str[count1] == '<')opers[count2] = LESS_THEN;
            str[count1] = -1;
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '=') && ((str[count1 + 1] == '=')))

        {
            opers[count2] = EQUALITY;
            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '!') && ((str[count1 + 1] == '=')))

        {
            opers[count2] = NOTEQUAL;
            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }

        else  if ((str[count1] == '&') && ((str[count1 + 1] == '&')))

        {
            opers[count2] = LOGICAND;
            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '|') && ((str[count1 + 1] == '|')))

        {
            opers[count2] = LOGICOR;
            str[count1] = -1;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if (isContainCh(class4, str[count1]) == 1)
        {
            opers[count2] = str[count1];
            str[count1] = -1;
            numOpers++;
            digit = 1;
            count2++;
        }
        else if (digit == 1) {
            opers[count2] = '$';
            count2++;
            digit = 0;
        }
        count1++;
    }
    opers[count2] = '\0';
}

void extractNums(int8_t* str, int32_t* nums, int8_t* opers)
{
    int8_t count = 0;//points to next char in string
    int8_t nextNum = 0;//points to next num
    int8_t index = 0;//index to the place to hold number
    int8_t nPers = numOpers;//to store number of operators
    int8_t notoper = 0;
    while (str[count] != '\0')//loop all chars except nul
    {
        if ((str[count] == -2)) //it is logical not operator '!' or betwise not  
        {
            nextNum = count + 1;//get the number after ! operator,nextNum points to next number, 
            count++;//skip that operator
            nPers--;//decrease number of operators
        }
        if (str[0] == -1) { //this means work in the previous result
            nextNum = count + 1;//get the number after ! operator,nextNum points to next number, 
            count++;//skip that operator
            nPers--;//decrease number of operators
        }
        if ((str[count] == -1))//it may be any operator except not
        {
            str[count] = '\0'; //replace operator with null
            while (opers[index] != '$')//loop until find '$' which means it is a valid index to store number
            {
                nums[index] = 0;//fill invalid places with zeros,
                index++;//increment counter
            }
            nums[index] = strToInt(str + nextNum);//store the number 
            nextNum = count + 1;//get the number after operator,nextNum points to next number 
            index++;//increment counter 3 to get a new place to hold the new number
            nPers--;//decrease number of operators
        }
        /*store the last number*/
        if (nPers == 0)//if numbr of operators is 0
        {
            while (opers[index] != '$')//loop until find '$' which means it is a valid index to store number
            {
                nums[index] = 0; //fill invalid places with zeros,
                index++; //increment counter
            }
            nums[index] = strToInt(str + nextNum);//store the last number
            break;//stop looping
        }
        count++;//increment counter
    }
}
void extractFnums(int8_t* str, double* Fnums, int8_t* opers) {
    int8_t count = 0;//points to next char in string
    int8_t nextNum = 0;//points to next num
    int8_t index = 0;//index to the place to hold number
    int8_t nPers = numOpers;//to store number of operators
    int8_t notoper = 0;
    while (str[count] != '\0')//loop all chars except nul
    {
        if ((str[count] == -2)) //it is logical not operator '!' or betwise not  
        {
            nextNum = count + 1;//get the number after ! operator,nextNum points to next number, 
            count++;//skip that operator
            nPers--;//decrease number of operators
        }
        if (str[0] == -1) { //this means work in the previous result
            nextNum = count + 1;//get the number after ! operator,nextNum points to next number, 
            count++;//skip that operator
            nPers--;//decrease number of operators
        }

        if ((str[count] == -1))//it may be any operator except logical not or betwise not
        {
            str[count] = '\0'; //replace operator with null
            while (opers[index] != '$')//loop until find '$' which means it is a valid index to store number
            {
                Fnums[index] = 0;//fill invalid places with zeros,
                index++;//increment counter
            }
            Fnums[index] = strToFloat(str + nextNum);//store the number 
            nextNum = count + 1;//get the number after operator,nextNum points to next number 
            index++;//increment counter 3 to get a new place to hold the new number
            nPers--;//decrease number of operators
        }
        /*store the last number*/
        if (nPers == 0)//if numbr of operators is 0
        {
            while (opers[index] != '$')//loop until find '$' which means it is a valid index to store number
            {
                Fnums[index] = 0; //fill invalid places with zeros,
                index++; //increment counter
            }
            Fnums[index] = strToFloat(str + nextNum);//store the last number
            break;//stop looping
        }
        count++;//increment counter
    }
}

/*   string calculator function */

int8_t isFloat(double num) {
    uint8_t result = 0;
    double fpart = num - ((int32_t)num);
    if (fpart > 0.0)
    {
        result = 1;
    }
    return result;
}
double strCalc(double* nums, int8_t* opers)
{
    int8_t c1 = 0;
    int8_t c2 = 0;
    uint8_t len = strLen(opers);
    double result;

    for (c1 = strLen(opers) - 1; c1 >= 0; c1--)
    {
        if (opers[c1] == '!')
        {
            result = !nums[c1 + 1];
            nums[c1] = result;
            delChar(opers, c1 + 1);
            delDoubleElement(nums, c1 + 1, len);
            len -= 1;
            c1 = strLen(opers) - 1;
        }
        if (opers[c1] == '~')
        {
            if (isFloat(nums[c1 + 1]) == 1)
            {
                continue;
            }
            else
            {
                result = ~((int32_t)(nums[c1 + 1]));
                nums[c1] = result;
                delChar(opers, c1 + 1);
                delDoubleElement(nums, c1 + 1, len);
                len -= 1;
                c1 = strLen(opers) - 1;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == '*')
        {
            result = nums[c1 - 1] * nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == '/')
        {
            result = nums[c1 - 1] / nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == '%')
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] % (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == '+')
        {
            result = nums[c1 - 1] + nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == '-')
        {
            result = nums[c1 - 1] - nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == SHRIGHT)
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] >> (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
        if (opers[c1] == SHLEFT)
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] << (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == GREATER_THEN_EQUAL)
        {

            result = (nums[c1 - 1] >= nums[c1 + 1]);
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == LESS_THEN_EQUAL)
        {

            result = (nums[c1 - 1] <= nums[c1 + 1]);
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == GREATER_THEN)
        {

            result = nums[c1 - 1] > nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == LESS_THEN)
        {

            result = nums[c1 - 1] < nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == EQUALITY)
        {

            result = nums[c1 - 1] == nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
        if (opers[c1] == NOTEQUAL)
        {

            result = nums[c1 - 1] != nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == '&')
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] & (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == '^')
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] ^ (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == '|')
        {
            if ((isFloat(nums[c1 - 1]) == 1) || (isFloat(nums[c1 - 1]) == 1))
            {
                continue;
            }
            else
            {
                result = (int32_t)nums[c1 - 1] | (int32_t)nums[c1 + 1];
                nums[c1 - 1] = result;
                delChar(opers, c1 + 1);
                delChar(opers, c1);
                delDoubleElement(nums, c1 + 1, len);
                delDoubleElement(nums, c1, len);
                len -= 2;
                c1 = 0;
            }

        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == LOGICAND)
        {

            result = nums[c1 - 1] && nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
    }
    for (c1 = 0; c1 < strLen(opers); c1++)
    {
        if (opers[c1] == LOGICOR)
        {

            result = nums[c1 - 1] || nums[c1 + 1];
            nums[c1 - 1] = result;
            delChar(opers, c1 + 1);
            delChar(opers, c1);
            delDoubleElement(nums, c1 + 1, len);
            delDoubleElement(nums, c1, len);
            len -= 2;
            c1 = 0;
        }
    }


    return nums[0];
}

uint8_t Rules(int8_t* str)
{
    int result = 1;//str does opey to rules
   /* if ((isContainCh(str, '(') == 1) && (isOperator(str[charSearch(str, '(') - 1])))
    {
        result = 0;
        printf("ERROR..\n");
    }*/
    if ((isContainCh(str, ')') == 1) && (isOperator(str[charSearch(str, ')') - 1])))
    {
        result = 0;
        printf("ERROR..\n");
    }
    if (isOperator(str[strLen(str) - 1]) == 1 || (isOperator(str[0]) == 1))
    {
        if ((str[0] == '-') && ((str[1] >= '0') || (str[1] <= '9')))
        {
            //result is 1
        }
        else
        {
            printf("ERROR..\n");
            result = 0;
        }


    }
    return result;
}
void handleParenthesis(int8_t* str)
{
    double fnums[20];
    int8_t opers[20];
    double result;
    int8_t firstBraceIndx;//index of the roud brace
    int8_t SecondBraceIndx;//index of the roud brace
    int8_t* ptr;
    int8_t p[20];
    int count2 = 0;
    int8_t count = 0;
    while (isContainCh(str, '(') == 1) {
        firstBraceIndx = charSearch(str, '(');
        if (isContainCh(str + firstBraceIndx + 1, ')'))
        {
            SecondBraceIndx = charSearch(str, ')');
            strCopy(p, str + SecondBraceIndx + 1);
            str[SecondBraceIndx] = '\0';
            extractOpers(str + firstBraceIndx + 1, opers);
            extractFnums(str + firstBraceIndx + 1, fnums, opers);
            result = strCalc(fnums, opers);
            ptr = floatToStrWithReturn(result, 3);
            count = firstBraceIndx;
            while (str[count] != '\0')
            {
                delChar(str, firstBraceIndx);
            }

            count = 0;
            while (ptr[count] != '\0')
            {
                insertChar(str, ptr[count], firstBraceIndx + count);
                count++;
            }
            while (p[count2] != '\0')
            {
                insertChar(str, p[count2], firstBraceIndx + count);
                count++;
                count2++;
            }
        }
    }
}
 double typeConverstionandle(int8_t* str, double* preValue, uint8_t prev)
{
    int8_t index;//index of the first str in string 
    uint8_t result = 0; //by default it hasn't hex string
    if ((strIsContain(str, "hex") == 1) && (strLen(str) == 3) && prev == 1)
    {
        index = getStrIndex(str, "hex"); //get the index of "hex" in string 
        delstr(str, "hex"); //delete "ans" to be replaced by the previous result but in hex
        result = 1;
    }
    if (strIsContain(str, "hex("))
    {
        if (strIsContain(str, ")") && (str[charSearch(str,')') + 1] == '\0'))
        {
		    handleParenthesis(str);
            delstr(str, "hex"); //delete "hex" to be replaced by the previous result but in hex
           // str[charSearch(str, ')')] = '\0';
            *preValue = strToFloat(str);
			prev=1;
            result = 1;
        }
        else
        {
            error = 1;
            result = 0;
        }
    }
    return result;    //retrun 1 : function has evaluated all ans 
                    //return 0: function can't evaluate str
}
double calculator(int8_t* str)
{
    int8_t opers[20];//is used to store operators after extracting them from str
    double nums[20];//is used to store numbers after extracting them from str
    double result;
    static uint8_t prev = 0;//flag to indicate, that you can work in the previous result
    removeSpaces(str);//remove all spaces in stirng 
    if (typeConverstionandle(str, nums, prev) == 1)
    {
		hex=1;
		result=nums[0];
    }
    else if(error==0)
    {
        if (handleParenthesis(str) == 1 && handleAns(str, nums[0], prev) == 1)
        {
            if (strRules(str) == 1)
            {
                extractOpers(str, opers);
                extractFnums(str, nums, opers);
                result = strCalc(nums, opers);
                prev = 1;
            }
            else {
                error = 1;
            }
        }
        else {
            error = 1;
        }
    }

    return result;
}
