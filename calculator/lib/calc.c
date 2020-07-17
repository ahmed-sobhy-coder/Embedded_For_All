#include "calc.h"
int8_t numOpers = 0;
uint8_t error;
uint8_t hex;
uint8_t bin;
uint8_t dec;
static int8_t class0[5] = { '!', '~','-','+','\0' }; // unary operators
static int8_t class1[4] = { '*', '/', '%', '\0' };  //  arithmetic operatos
static int8_t class2[3] = { '+', '-', '\0' };//arithmetic operators
static int8_t class3[3] = { '<', '>', '\0' }; //logical operatos
static int8_t class4[4] = { '&','^','|','\0' };//bitwise operators
typedef enum
{
    BRACES_ERROR,
    OPER_ERROR,
    NO_ERROR,
} ERROR_TYPE;
calc OPER;
ERROR_TYPE ER;

uint8_t Size = 0;
/*check if given character is operator*/
int8_t isOperator(int8_t oper)
{
    int8_t result = 0; //return -1 means it is not valid operator
    if ((strIsContainCh(class0, oper) == 1) ||   //in case char is in class0 string
        (strIsContainCh(class1, oper) == 1) ||  //in case char is in class1 2tring
        (strIsContainCh(class2, oper) == 1) ||    //in case char is in class1 string
        (strIsContainCh(class3, oper) == 1) ||   //in case char is in class3 string
        (strIsContainCh(class4, oper) == 1)      //in case char is in class4 string
        )
    {
        result = 1; // result 1 means it is valid operator
    }
    return result;   //return result
}
int8_t isUnary(int8_t* str, int8_t index) {//check if '-' is minus or sub operator
    int result;// returns 1 if it is minus operator , and 0 if it is sub operator 
    /* if the character before '-' is valid opertor, '-' is unary minus */
    /*if '-' exists at the begining of string, it is unary minus*/
    if (((strIsContainCh(class0, str[index]) == 1) && (str[index - 1] == -1)) || // in case the char is unary operator and the previous char is unary operator
        ((strIsContainCh(class0, str[index]) == 1) && (str[index - 1] == -2)) || // in case the char is unary operator and the previous char is even operator
        ((strIsContainCh(class0, str[index]) == 1) && (index == 0)) //in case the first char is unary operator
        )
    {
        result = 1;//return it is unary minus
    }
    else
    {
        result = 0;//it is sub operator 
    }
    return result; //return the result
}
/* */
uint8_t isDigitChar(int8_t ch)
{
	   int8_t result=0;
	   if((ch>='0')&&(ch<='9'))
	   {
		result=1;
	   }
	   return result;
}
void extractOpers(int8_t* str, int8_t* opers)
{
    int8_t count1 = 0;//is used a s counter for all chars in string
    int8_t count2 = 0;//is used as a counter
    int8_t digit = 1;//flag to indicate that the next place if for digit not operator
                     //by default it it is 1 which means by default the next place if for digit  
    numOpers = 0;
    while (str[count1] != '\0')
    {
        while ((strIsContainCh(class0, str[count1]) == 1) && isUnary(str, count1))  //if it is unary operator
        {
            if(str[count1]=='-'||str[count1]=='+')
			{
                 opers[count2] = '$';
                 count2++;
                 digit = 0;			
			}
			else
			{
			opers[count2] = str[count1];   //store operator
            str[count1] = -1; //replace operator with -1, it is indicator to exctrac nums function that this place is for operator
            numOpers++; //increase numbre of opers
            count2++;  //make counter2 poits to next place to place a new char
            digit = 1;//it is flag indicate the next char after operator is for number			
			}
		   count1++;  //get the next number 
        }
        if ((strIsContainCh(class1, str[count1]) == 1) ||     //in case it is * / % operator
            ((strIsContainCh(class2, str[count1]) == 1) &&    // in case it is + or -  operators
                (isUnary(str, count1) == 0))  //it is not a unary operator
            )
        {
            if (str[count1] == '*' && str[count1 + 1] == '*')
            {
                opers[count2] = POWER;
                delChar(str, count1 + 1);
            }
            else
            {
                opers[count2] = str[count1];
            }
            str[count1] = -2;
            numOpers++;
            count2++;
            digit = 1;
            // }
        }
        else  if ((strIsContainCh(class3, str[count1]) == 1) && (strIsContainCh(class3, str[count1 + 1]) == 1))

        {
            if (str[count1] == '>')opers[count2] = SHRIGHT;
            else if (str[count1] == '<')opers[count2] = SHLEFT;

            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((strIsContainCh(class3, str[count1]) == 1) && (str[count1 + 1] == '='))

        {
            if (str[count1] == '>')opers[count2] = GREATER_THEN_EQUAL;
            else if (str[count1] == '<')opers[count2] = LESS_THEN_EQUAL;
            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }

        else  if (strIsContainCh(class3, str[count1]) == 1)

        {
            if (str[count1] == '>')opers[count2] = GREATER_THEN;
            else if (str[count1] == '<')opers[count2] = LESS_THEN;
            str[count1] = -2;
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '=') && ((str[count1 + 1] == '=')))

        {
            opers[count2] = EQUALITY;
            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '!') && ((str[count1 + 1] == '=')))

        {
            opers[count2] = NOTEQUAL;
            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }

        else  if ((str[count1] == '&') && ((str[count1 + 1] == '&')))

        {
            opers[count2] = LOGICAND;
            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if ((str[count1] == '|') && ((str[count1 + 1] == '|')))

        {
            opers[count2] = LOGICOR;
            str[count1] = -2;
            delChar(str, count1 + 1);
            numOpers++;
            digit = 1;
            count2++;
        }
        else  if (strIsContainCh(class4, str[count1]) == 1)
        {
            opers[count2] = str[count1];
            str[count1] = -2;
            numOpers++;
            digit = 1;
            count2++;
        }
        if (digit == 1) {
            if ((strIsContainCh(class0, str[count1+1])) == 1)
              {
                    digit = 0;
                }
                else if( str[count1+1])
                {
            opers[count2] = '$';
            count2++;
            digit = 0;
            //}

        }
        count1++;
    }
    opers[count2] = '\0';
}
void extractFnums(int8_t* str, double* Fnums, int8_t* opers) {
    int8_t count = 0;//points to next int8_tin string
    int8_t nextNum = 0;//points to next num
    int8_t index = 0;//index to the place to hold number
    int8_t nPers = numOpers;//to store number of operators
    while (str[count] != '\0')//loop all chars except nul
    {
        while ((str[count] == -1)) //it is logical not operator '!' or betwise not  
        {
            nextNum = count + 1;//get the number after ! operator,nextNum points to next number, 
            count++;//skip that operator
            nPers--;//decrease number of operators
        }
        if ((str[count] == -2))//it may be any operator except logical not or betwise not
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
    uint8_t len = strLen(opers);
    double result;

    for (c1 = strLen(opers) - 1; c1 >= 0; c1--)
    {
            if (opers[c1] == '!')
            {
                result = !nums[c1 + 1];
                nums[c1] = result;
                delChar(opers, c1);
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
        if (opers[c1] == POWER)
        {
            result = getPower(nums[c1 - 1], nums[c1 + 1]);
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

ERROR_TYPE strRules(int8_t* str)
{
    ER = NO_ERROR;
    if ((strIsContainCh(str, ')') == 1) && (isOperator(str[charSearch(str, ')') - 1])))
    {
        ER = OPER_ERROR;
    }
    if (isOperator(str[strLen(str) - 1]) == 1 || (isOperator(str[0]) == 1))
    {
        if ((str[0] == '-') && ((str[1] >= '0') || (str[1] <= '9')))
        {
            //result is 1
        }
        else
        {
            print("ERROR..\n");
        }
    }
    if (strIsContain(str, "()"))
    {
        ER = BRACES_ERROR;
        error = 1;
    }
    return ER;
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
    uint8_t valid = 1;
    while (strIsContainCh(str, '(') == 1) {
        firstBraceIndx = charSearch(str, '(');
        if (strIsContainCh(str + firstBraceIndx + 1, ')'))
        {
            SecondBraceIndx = charSearch(str, ')');
            strCopy(p, str + SecondBraceIndx + 1);
            str[SecondBraceIndx] = '\0';
            extractOpers(str + firstBraceIndx + 1, opers);
            extractFnums(str + firstBraceIndx + 1, fnums, opers);
            result = strCalc(fnums, opers);
            ptr = floatToStr(result, 3);
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
        else
        {
            error = 1;
        }
    }
}
void handleAns(int8_t* str, double* nums, uint8_t prev)
{
    uint8_t index;
    if (prev == 1)
    {
        while (strIsContain(str, "ans") == 1)
        {
            index = getStrIndex(str, "ans");
            delStr(str, "ans");
            insertStr(str, floatToStr(nums[0], 4), index);
        }
        while (strIsContain(str, "ANS") == 1)
        {
            index = getStrIndex(str, "ANS");
            delStr(str, "ANS");
            insertStr(str, floatToStr(nums[0], 4), index);
        }
    }
    else
    {

    }
}
void typeConverstionandle(int8_t* str, double* preValue, uint8_t prev)
{
    if ((strIsContain(str, "hex") == 1) && (strLen(str) == 3) && prev == 1)
    {
        delStr(str, "hex"); //delete "ans" to be replaced by the previous result but in hex
        hex = 1;
    }
    if (strIsContain(str, "hex("))
    {
        if (strIsContain(str, ")") && (str[charSearch(str, ')') + 1] == '\0'))
        {
            handleParenthesis(str);
            delStr(str, "hex"); //delete "hex" to be replaced by the previous result but in hex
            *preValue = strToFloat(str);
            prev = 1;
            hex = 1;
        }
        else
        {
            error = 1;
        }
    }
}
double calculator(int8_t* str)
{
    int8_t opers[20];//is used to store operators after extracting them from str
    static double nums[20];//is used to store numbers after extracting them from str
    double result;
    static uint8_t prev = 0;//flag to indicate, that you can work in the previous result
    remStrSpace(str);//remove all spaces in stirng 
    typeConverstionandle(str, nums, prev);
    handleParenthesis(str);
    handleAns(str, nums, prev);

    //  if (strRules(str) == 1)
     // {
    extractOpers(str, opers);
    extractFnums(str, nums, opers);
    result = strCalc(nums, opers);
    prev = 1;
    //}
    //else {
      //  error = 1;
    //}
    return result;
}
