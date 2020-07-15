#include "strfuncs.h"
int8_t* intToStr(int32_t num)
{
    static int8_t string[10];
    uint32_t arr[10];
    int32_t temp = num;
    uint8_t counter1 = 0;
    uint8_t counter2 = 0;
    /*=================== BREAK THE NUMBER and store it in the array ======================*/
    if (num == 0)
    {
        string[counter1++] = '0';
        string[counter1++] = '\r';
        string[counter1++] = '\n';
        string[counter1] = '\0';
    }
    else if (num >= 0)
    {
        while (temp)
        {
            arr[counter2] = temp % 10;
            temp /= 10;
            counter2++;
        }
        /*============================== REARRANGE ARRAY========================*/
        for (counter1 = 0; counter1 < (counter2 / 2); counter1++)
        {
            arr[counter1] += arr[(counter2 - 1) - counter1];
            arr[(counter2 - 1) - counter1] = arr[counter1]
                - arr[(counter2 - 1) - counter1];
            arr[counter1] -= arr[(counter2 - 1) - counter1];
        }
        /*============================== STORE int8_t ACTERS =======================*/
        for (counter1 = 0; counter1 < counter2; counter1++)
        {
            string[counter1] = arr[counter1] + '0';
        }
        //string[counter1++]='\r';
        //string[counter1++]='\n';
        string[counter1] = '\0';
    }
    else
    {
        string[0] = '-';
        counter2++;
        temp = temp * -1;
        while (temp)
        {
            arr[counter2] = temp % 10;
            temp /= 10;
            counter2++;
        }
        /*============================== REARRANGE ARRAY========================*/
        if (counter2 == 3)
        {
            for (counter1 = 1; counter1 <= (counter2 / 2); counter1++)
            {
                arr[counter1] += arr[(counter2 - counter1)];
                arr[counter2 - counter1] = arr[counter1]
                    - arr[counter2 - counter1];
                arr[counter1] -= arr[counter2 - counter1];
            }
        }
        else
        {
            for (counter1 = 1; counter1 < (counter2 / 2); counter1++)
            {
                arr[counter1] += arr[(counter2 - counter1)];
                arr[counter2 - counter1] = arr[counter1]
                    - arr[counter2 - counter1];
                arr[counter1] -= arr[counter2 - counter1];
            }
        }

        /*============================== STORE int8_tACTERS =======================*/
        for (counter1 = 1; counter1 < counter2; counter1++)
        {
            string[counter1] = arr[counter1] + '0';
        }
        string[counter1] = '\0';
    }
    return string;

}
void floatToStr(double float_num, uint8_t precision,int8_t *string)
{
    int32_t integer_part, float_part;
    int32_t temp;
    int8_t counter1 = 0, counter2 = 0, counter = 0;
    if (float_num >= 0)
    { //+ve float number
        integer_part = (int32_t)float_num;
        temp = integer_part;
        if (temp > 0)
        {
            while (temp)
            {
                string[counter2++] = (temp % 10) + '0';
                temp /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter1 = 0; counter1 < (counter2 / 2); counter1++)
        {
            string[counter1] ^= string[(counter2 - 1) - counter1];
            string[(counter2 - 1) - counter1] ^= string[counter1];
            string[counter1] ^= string[(counter2 - 1) - counter1];
        }
        string[counter2++] = '.';
        counter1 = counter2;
        float_part = (int32_t)(float_num - integer_part)
            * getPower(10, precision);
        if (float_part > 0)
        {
            while (float_part)
            {
                string[counter2++] = (float_part % 10) + '0';
                float_part /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
        string[counter2] = '\0';
    }
    else
    {  // negative float number
        string[counter2++] = '-';
        counter1 = counter2;
        integer_part = (int32_t)float_num * -1;
        temp = integer_part;
        if (temp > 0)
        {
            while (temp)
            {
                string[counter2++] = (temp % 10) + '0';
                temp /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
        string[counter2++] = '.';
        counter1 = counter2;
        float_part = (int32_t)((float_num * -1) - integer_part)
            * getPower(10, precision);
        if (float_part > 0)
        {
            while (float_part)
            {
                string[counter2++] = (float_part % 10) + '0';
                float_part /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
    }
    string[counter2] = '\0';
}
int8_t* floatToStrWithReturn(double float_num, uint8_t precision)
{
    static int8_t string[20];
    int32_t integer_part, float_part;
    int32_t temp;
    int8_t counter1 = 0, counter2 = 0, counter = 0;
    if (float_num >= 0)
    { //+ve float number
        integer_part = (int32_t)float_num;
        temp = integer_part;
        if (temp > 0)
        {
            while (temp)
            {
                string[counter2++] = (temp % 10) + '0';
                temp /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter1 = 0; counter1 < (counter2 / 2); counter1++)
        {
            string[counter1] ^= string[(counter2 - 1) - counter1];
            string[(counter2 - 1) - counter1] ^= string[counter1];
            string[counter1] ^= string[(counter2 - 1) - counter1];
        }
        string[counter2++] = '.';
        counter1 = counter2;
        float_part = (int32_t)(float_num - integer_part)
            * getPower(10, precision);
        if (float_part > 0)
        {
            while (float_part)
            {
                string[counter2++] = (float_part % 10) + '0';
                float_part /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
        string[counter2] = '\0';
    }
    else
    {  // negative float number
        string[counter2++] = '-';
        counter1 = counter2;
        integer_part = (int32_t)float_num * -1;
        temp = integer_part;
        if (temp > 0)
        {
            while (temp)
            {
                string[counter2++] = (temp % 10) + '0';
                temp /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
        string[counter2++] = '.';
        counter1 = counter2;
        float_part = (int32_t)((float_num * -1) - integer_part)
            * getPower(10, precision);
        if (float_part > 0)
        {
            while (float_part)
            {
                string[counter2++] = (float_part % 10) + '0';
                float_part /= 10;
            }
        }
        else
        {
            string[counter2++] = 0 + '0';
        }
        for (counter = 0; counter < (counter2 - counter1) / 2; counter++)
        {
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
            string[(counter2 - 1) - counter] ^= string[counter1 + counter];
            string[counter1 + counter] ^= string[(counter2 - 1) - counter];
        }
    }
    string[counter2] = '\0';
    return string;
}
uint8_t strLen(int8_t* str)
{
    uint8_t count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}
uint8_t Slen_without_CR(int8_t* string)
{
    uint8_t counter = 0;
    while (*string++ != '\r')
        counter++;
    return counter;
}
/* copy to str2 into str1*/
void strCopy(int8_t* str1, int8_t* str2)
{
    uint8_t count = 0;  //is used as a counter
    while (str2[count] != '\0')  //loop all chars except null
    {
        str1[count] = str2[count];  //assign chars to str1 array
        count++;  //increase the counter;
    }
    str1[count] = '\0';  //terminate with null
}
/* convert string of digits to real number*/
int32_t strToInt(int8_t* str)
{
    uint32_t len = strLen(str);
    volatile uint8_t count = 0;
    volatile int32_t num = 0;
    volatile uint8_t neg = 0;
    if ((str[count] == '-') && (len > 1))  //check if it is negative sign
    {
        len--;
        neg = 1;  //rise flag it is negative number
        count++;  //increase the counter
    }
    if (isStrOfDigits(str + count) == -1) //check if str has invalid chars which are not digits
    {
        num = 0; //error
    }
    else
    {
        while (str[count] != '\0')
        {
            if ((str[count] >= '0') && (str[count] <= '9'))
            {
                num += (str[count] - '0') * getPower(10, --len);
                count++; //increase the counter
            }
        }
        if (neg == 1) //it is negative number
        {
            num *= -1; //to be a negative number
        }
    }
    return num; //return integer number
}

int32_t strCmp(int8_t* string1, int8_t* string2)
{
    uint8_t counter = 0;
    uint8_t length_string1 = strLen(string1);
    uint8_t length_string2 = strLen(string2);
    counter = 0;
    if (length_string1 == length_string2)
    {
        while ((*string1 == *string2) && (*string1 != '\0')
            && (*string2 != '\0'))
        {
            counter++;
            string1++;
            string2++;
        }
        if (counter == length_string1)
        {
            return 0;
        }
    }

    return -1;
}
/*check if two strings are matched*/

int8_t strIsContain(int8_t* str1, int8_t* str2)
{
    uint32_t str_len1 = strLen(str1);  //store string length of the first string
    uint32_t str_len2 = strLen(str2);  //the length of second string
    uint32_t index = 0, matched = 0;  //default values for counters
    uint8_t result = 0; //if result =0 means they are not matched,if result =1 , this means they are matched
    if (str_len1 >= str_len2)
    {
        while (str1[index] != '\0')
        {  //str_len1 must be greater than str_len2 to continue loop
            if (str1[index] == str2[matched]) //if the chars matched of str1&str2
            {
                matched++;  //increase the matching chars counter
                if (matched == str_len2)  //if str1 & str2 matched
                {
                    result = 1; //return 1
                }
            }
            else
            {
                matched = 0; //reset the the matching counter
            }
            index++; //increase the index counter, which points to the next char
        }
    }
    else
    {

    }

    return result;
}
/* reverse string */
void strRev(int8_t* str)
{
    uint8_t lstChrIndx = strLen(str) - 1; //last char index
    uint8_t count = 0, temp = 0; //initialize variables
    for (count = 0; count < (lstChrIndx / 2); count++) //loop until swapping is done
    {
        temp = str[count]; // temporary var to carry the content of location
        str[count] = str[lstChrIndx - count]; //swap between first & chars
        str[lstChrIndx - count] = temp; // swap between last & first chars
    }
}
/* check if the string contains only digits*/
int8_t isStrOfDigits(int8_t* str)
{
    int8_t count = 0; // is used as a counter
    int8_t result = 0; //return 1 if all chars are digits
    int8_t len = strLen(str);
    if (len > 0)
    {

        while (str[count] != '\0') //loop all chars except null
        {
            if ((str[count] >= '0') && (str[count] <= '9'))
            {
                count++; //increment the counter
            }
            else
            {
                break;

            }
        }
        if (count == strLen(str))
        {
            result = 1;
        }

    }

    return result;
}
//search char in string
int8_t charSearch(int8_t* str, int8_t ch)
{
    volatile int8_t index = -1; //if the char is not exist return -1, else return the index
    volatile uint8_t count = 0; //is used as a counter
    while (str[count] != '\0') //loop all chars except null
    {
        if (str[count] == ch) //if chars are matched
        {
            index = count; //index will be updated
            break;
        }
        else
        {

            count++; //increase the counter
        }

    }
    return index; //reutr the index
}
double strToFloat(int8_t* str)
{
    uint32_t len;
    volatile uint8_t count = 0; //is used as a count to loop all chars except '\0'
    volatile float num = 0; //num is used to store the float number
    volatile uint8_t neg = 0;//it means its negative number 
    uint8_t pcount = 0; //to count number of powers
    int8_t fpart = 0;//it is flag, rises when the char '.' is found 
    int8_t dotIndex = charSearch(str, '.'); //ge the index of '.'
    if (dotIndex >= 0) {//it has dot '.'
        len = dotIndex; // the length of float part
    }
    else { // it hasn't dot
        len = strLen(str);
    }
    if ((str[count] == '-') && (len > 1))  //check if it is negative sign
    {
        len--;//decrement length , don't count the negative sign 
        neg = 1;  //rise flag it is negative number
        count++;  //increase the counter
    }
    while (str[count] != '\0')// loop all chars except null
    {
        if (str[count] == '.')//if it is '.'
        {
            fpart = 1; //rise fpart flag , to start converting the float part

        }
        else if (fpart == 1)//converting float part
        {
            if ((str[count] >= '0') && (str[count] <= '9'))//if the ch is valid digit
            {
                num += (str[count] - '0') * ((double)1 / getPower(10, ++pcount)); //convert char to real number

            }
        }
        else //calculating the integer part
        {

            num += (str[count] - '0') * getPower(10, --len);//conver char to integer

        }
        count++; //increase the counter
    }
    if (neg == 1) //it is negative number
    {
        num *= -1; //to be a negative number
    }
    return num; //return integer number
}


/*insert new char in string */
void insertChar(int8_t* str, int8_t ch, int8_t index)
{
    int8_t len = strLen(str);//get the length of string
    int8_t count;// count is counter
    for (count = len + 1; count > index; count--)//start loop from the last element which is '\0' until reaching to the index
                                               //of the required position to insert character
    {
        str[count] = str[count - 1];//do shifting of chars in array
    }
    str[count] = ch;//insert character in the required position
}
//this function returns 1 if char is in string & return 0 if not
int8_t isContainCh(int8_t* str, int8_t ch)
{
    int8_t count = 0;//is user as counter
    int8_t result = 0;
    while (str[count] != '\0')
    {
        if (str[count] == ch)
        {
            result = 1;
            break;
        }
        count++;
    }
    return result;
}
/* delete char from string */
void  delChar(int8_t* str, int8_t index) {
    uint8_t len = strLen(str);//get the length of string
    uint8_t count;//is used as a counter
    for (count = index; count < len; count++) //start from the index of the required position
                                              //to delete, loop len-1 number of time
    {
        str[count] = str[count + 1];//shift elements
    }
}