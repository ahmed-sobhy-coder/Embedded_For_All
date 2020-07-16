#include "strfuncs.h"
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
    uint8_t lstChrIndx = strLen(str) - 1; //last int8_tindex
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
//search int8_tin string
int8_t charSearch(int8_t* str, int8_t ch)
{
    volatile int8_t index = -1; //if the int8_tis not exist return -1, else return the index
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
    int8_t fpart = 0;//it is flag, rises when the int8_t'.' is found 
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
                num += (str[count] - '0') * ((double)1 / getPower(10, ++pcount)); //convert int8_tto real number

            }
        }
        else //calculating the integer part
        {

            num += (str[count] - '0') * getPower(10, --len);//conver int8_tto integer

        }
        count++; //increase the counter
    }
    if (neg == 1) //it is negative number
    {
        num *= -1; //to be a negative number
    }
    return num; //return integer number
}


/*insert new int8_tin string */
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
//this function returns 1 if int8_tis in string & return 0 if not
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
/* delete int8_tfrom string */
void  delChar(int8_t* str, int8_t index) {
    uint8_t len = strLen(str);//get the length of string
    uint8_t count;//is used as a counter
    for (count = index; count < len; count++) //start from the index of the required position
                                              //to delete, loop len-1 number of time
    {
        str[count] = str[count + 1];//shift elements
    }
}
/*get the index of str2 in str1*/
uint8_t getStrIndex(int8_t* str1, int8_t* str2)
{
    uint32_t str_len1 = strLen(str1);  //store string length of the first string
    uint32_t str_len2 = strLen(str2);  //the length of second string
    uint32_t matched = 0;  //count number of matched characters
    int8_t index = -1; //initially we don't know the index of str2 so it is -1
    uint8_t count; // is used as a counter for chars
    if (str_len1 >= str_len2)
    {
        while (str1[count] != '\0')
        {  //str_len1 must be greater than str_len2 to continue loop
            if (str1[count] == str2[matched]) //if the chars matched of str1&str2
            {
                if (matched == 0)
                {
                    index = count;   //the index of first int8_tin string 
                }
                matched++;  //increase the matching chars counter
                if (matched == str_len2)  //if str1 & str2 matched
                {
                    break;//stop looping
                }
            }
            else
            {
                matched = 0; //reset the the matching counter
                index = -1;      //reset index
            }
            count++; //increase the index counter, which points to the next char
        }
    }
    return index;   //return index
}
/*delete str1 from str2*/
void delStr(int8_t* str1, int8_t* str2)
{
    uint8_t index;//get the index of str2
    uint8_t len = strLen(str2);//get the length of str2
    uint8_t count;//is used as a counter for chars
    if (strIsContain(str1, str2))
    {
        index = getStrIndex(str1, str2);//get the index of str2
        count = index;
        while (count < index + len)  //loop each char in str2
        {
            delChar(str1, index); //delete character
            count++;  //increment counter
        }
    }
}
//insert str2 in str1
void insertStr(int8_t* str1, int8_t* str2, uint32_t index)
{
    uint32_t count = 0;  //is used as a counter for chars
    uint32_t nochars = strLen(str1) - 1;
    if (index < nochars)  //check if str1 has that index
    {
        while (str2[count] != '\0')//loop all chars in str2 except null
        {
            str1[index + count] = str2[count];  //insert every char in str2 to str1
            count++; //increment counter
        }

    }

}
void rearrange(int8_t* str)
{
    uint32_t count = 0;
    uint32_t len = strLen(str);
    for (count = 0; count < (len / 2); count++)
    {
        str[count] += str[len - count - 1];
        str[len - count - 1] = str[count] - str[len - count - 1];
        str[count] -= str[len - count - 1];
    }
}
//convert double number to hex and store the result in string 
int8_t* convDoubleToHexStr(double num, uint8_t precision)
{
    int32_t ipart = (int32_t)num; //get the integer part of number 
    double fpart = num - ipart;//get the float part of number 
    uint8_t count = 0;//points to next location to store char
    uint32_t div, rem;//div is used to store the result of the division
    static int8_t str[20];  //str stores hexa number as characters
    double mul;    //is used for multiplication between 16 and float part
    uint32_t count1 = 0; //is used as a counter for next char to be allocated after decimal point

    if (num == 0)    //if double number is 0
    {
        str[count++] = '0';    //store 0
        str[count++] = '.';    //storer decimal point
        while (count1 < precision)  //how many digits you want after decimal point is determined by precision
        {
            str[count + count1] = '0';//store 0 after decimal point
            count1++; //increment counter 
        }
        str[count + count1] = '\0'; //terminal by null
    }
    else
    {
        div = ipart;//div initially stores ipart
        while (div)  //loop until div becomes 0
        {
            rem = div % 16; //rem stores the reminder
            str[count] = "0123456789ABCDEF"[rem]; //store char
            count++;//increment counter
            div /= 16;  //divide by 16
        }
        str[count] = '\0';    //terminate string with null
        rearrange(str); //rearrange string
        if (fpart > 0.0)     //if the float part is more than 0
        {
            str[count++] = '.';  // store '.' char which is the decimal point 
            while (count1 < precision)    //how many digits you want after decimal point is determined by precision
            {
                mul = fpart * 16;//multiply the float part by 16
                str[count + count1] = "0123456789ABCDEF"[(uint32_t)mul];//store hex digit as char
                fpart = mul - (int32_t)mul;   //get the float part which is after decimal point
                count1++; //increment counter1
            }
            str[count + count1] = '\0'; //terminate string with null
        }

    }
    return str; //return string 
}
//convert double number to binary and store the result in string 
int8_t* convDoubleToBinStr(double num, uint8_t precision)
{
    int32_t ipart = (int32_t)num; //get the integer part of number 
    double fpart = num - ipart;//get the float part of number 
    uint8_t count = 0;//points to next location to store char
    uint32_t div, rem;//div is used to store the result of the division
    static int8_t str[20];  //str stores hexa number as characters
    double mul;    //is used for multiplication between 16 and float part
    uint32_t count1 = 0; //is used as a counter for next char to be allocated after decimal point
    if (num == 0)    //if double number is 0
    {
        str[count++] = '0';    //store 0
        str[count++] = '.';    //storer decimal point
        while (count1 < precision)  //how many digits you want after decimal point is determined by precision
        {
            str[count + count1] = '0';//store 0 after decimal point
            count1++; //increment counter 
        }
        str[count + count1] = '\0'; //terminal by null
    }
    else
    {
        div = ipart;//div initially stores ipart
        while (div)  //loop until div becomes 0
        {
            rem = div % 2; //rem stores the reminder
            str[count] = "01"[rem]; //store char
            count++;//increment counter
            div /= 2;  //divide by 2
        }
        str[count] = '\0';    //terminate string with null
        rearrange(str); //rearrange string
        if (fpart > 0.0)     //if the float part is more than 0
        {
            str[count++] = '.';  // store '.' char which is the decimal point 
            while (count1 < (precision * 4))    //how many digits you want after decimal point is determined by precision
            {
                mul = fpart * 2;//multiply the float part by 16
                str[count + count1] = "01"[(uint32_t)mul];//store binary digit as char
                fpart = mul - (int32_t)mul;   //get the float part which is after decimal point
                count1++; //increment counter1
            }
            str[count + count1] = '\0'; //terminate string with null
        }
    }
    return str; //return string 
}
int8_t* intToStr(int32_t num)
{
    int32_t ipart; //get the integer part of number 
    uint8_t count = 0;//points to next location to store char
    uint32_t div, rem;//div is used to store the result of the division
    static int8_t str[20];  //str stores hexa number as characters
    double mul;    //is used for multiplication between 16 and float part
    uint32_t count1 = 0; //is used as a counter for next char to be allocated after decimal point
    uint8_t neg = 0;
    if (num == 0)    //if integer number is 0
    {
        str[count++] = '0';    //store 0
        str[count++] = '.';    //storer decimal point
        str[count + count1] = '\0'; //terminal by null
    }
    else
    {
        if (num < 0) //in case it is negative number 
        {          
            num = num * -1;//div initially stores ipart
            str[count++] = '-';
            neg = 1;
        }
        div = num;//div initially stores ipart
        while (div)  //loop until div becomes 0
        {
            rem = div % 10; //rem stores the reminder
            str[count] = "0123456789"[rem]; //store char
            count++;//increment counter
            div /= 10;  //divide by 10
        }
        str[count] = '\0';    //terminate string with null  
        if (neg == 1)
        {
            rearrange(str + 1); //rearrange string		
        }
        else
        {
            rearrange(str); //rearrange string				
        }
    }
    return str; //return string 
}

//convert double number to binary and store the result in string 
int8_t* floatToStr(double num, uint8_t precision)
{
    int32_t ipart; //get the integer part of number 
    double fpart;//get the float part of number 
    uint8_t count = 0;//points to next location to store char
    uint32_t div, rem;//div is used to store the result of the division
    static int8_t str[20];  //str stores hexa number as characters
    double mul;    //is used for multiplication between 16 and float part
    uint32_t count1 = 0; //is used as a counter for next char to be allocated after decimal point
    uint8_t neg = 0;
    if (num == 0)    //if double number is 0
    {
        str[count++] = '0';    //store 0
        str[count++] = '.';    //storer decimal point
        while (count1 < precision)  //how many digits you want after decimal point is determined by precision
        {
            str[count + count1] = '0';//store 0 after decimal point
            count1++; //increment counter 
        }
        str[count + count1] = '\0'; //terminal by null
    }
    else
    {
        if (num < 0) //in case it is negative number 
        {
            num = num * -1;//div initially stores ipart
            str[count++] = '-';
            neg = 1;
        }
        ipart = (int32_t)num; //get the integer part of number 
        fpart = num - ipart;//get the float part of number		
        div = ipart;//div initially stores ipart
        while (div)  //loop until div becomes 0
        {
            rem = div % 10; //rem stores the reminder
            str[count] = "0123456789"[rem]; //store char
            count++;//increment counter
            div /= 10;  //divide by 2
        }
        str[count] = '\0';    //terminate string with null
        if (neg == 1)
        {
            rearrange(str + 1); //rearrange string		
        }
        else
        {
            rearrange(str); //rearrange string				
        }
        if (fpart > 0.0)     //if the float part is more than 0
        {
            str[count++] = '.';  // store '.' char which is the decimal point 
            while (count1 < precision)    //how many digits you want after decimal point is determined by precision
            {
                mul = fpart * 10;//multiply the float part by 16
                str[count + count1] = "0123456789"[(uint32_t)mul];//store binary digit as char
                fpart = mul - (int32_t)mul;   //get the float part which is after decimal point
                count1++; //increment counter1
            }
            str[count + count1] = '\0'; //terminate string with null
        }
    }
    return str; //return string 
}