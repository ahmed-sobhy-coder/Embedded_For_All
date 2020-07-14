#include "stringManip.h"
int8_t* IntToStr(int32_t num){
  static int8_t string[10];
  uint32_t arr[10];
  int32_t temp=num ;
  uint8_t counter1=0;
  uint8_t counter2=0;
  /*=================== BREAK THE NUMBER and store it in the array ======================*/
  if(num==0){
    string[counter1++]='0';
    string[counter1++]='\r';
    string[counter1++]='\n';
    string[counter1]='\0';
  }
  else if(num>=0){
    while(temp){
      arr[counter2] = temp%10;
      temp/=10;
      counter2++;
    }
    /*============================== REARRANGE ARRAY========================*/
    for(counter1=0;counter1<(counter2/2);counter1++){
      arr[counter1]+=arr[(counter2-1)-counter1];
      arr[(counter2-1)-counter1]=arr[counter1]-arr[(counter2-1)-counter1];
      arr[counter1]-=arr[(counter2-1)-counter1];
    }
    /*============================== STORE int8_tACTERS =======================*/
    for(counter1=0;counter1<counter2;counter1++){
      string[counter1]=arr[counter1]+'0';
    }
    //string[counter1++]='\r';
    //string[counter1++]='\n';
    string[counter1]='\0'; 
  }
  else{
    string[0]='-'; 
    counter2++; 
    temp= temp *-1; 
    while(temp){
      arr[counter2] = temp%10;
      temp/=10; 
      counter2++;
    }
    /*============================== REARRANGE ARRAY========================*/
    for(counter1=1;counter1<(counter2/2);counter1++){
      arr[counter1]+=arr[(counter2-counter1)];
      arr[counter2-counter1]=arr[counter1]-arr[counter2-counter1];
      arr[counter1]-=arr[counter2-counter1];
    }
    /*============================== STORE int8_tACTERS =======================*/
    for(counter1=1;counter1<counter2;counter1++){
      string[counter1]=arr[counter1]+'0';
    }
    string[counter1++]='\r';
    string[counter1++]='\n';
    string[counter1]='\0'; 
  }
  return string ;
  
}
int8_t * Float_To_string_conversion(double float_num, uint8_t precision){
  static int8_t string[20];
  int32_t integer_part,float_part;
  int32_t temp;
  int8_t counter1=0,counter2=0,counter=0;
  if(float_num>=0){ //+ve float number
    integer_part=(int32_t) float_num ;
    temp=integer_part;
    if(temp > 0){
      while(temp){
        string[counter2++] = (temp%10) + '0';
        temp/=10;
      }
    }
    else{
      string[counter2++]=0+'0';
    }
    for(counter1=0;counter1<(counter2/2);counter1++){
      string[counter1]^= string[(counter2-1)-counter1];
      string[(counter2-1)-counter1]^= string[counter1];
      string[counter1]^= string[(counter2-1)-counter1];
    }
    string[counter2++]='.';
    counter1=counter2;
    float_part=(int32_t)(float_num-integer_part)*Get_Power(10,precision);
    if(float_part > 0){
      while(float_part){
        string[counter2++] = (float_part%10) + '0';
        float_part/=10;
      }
    }
    else{
      string[counter2++]=0+'0';
    }
    for(counter=0;counter<(counter2-counter1)/2;counter++){
      string[counter1+counter]^=string[(counter2-1)-counter];
      string[(counter2-1)-counter]^=string[counter1+counter];
      string[counter1+counter]^= string[(counter2-1)-counter];
    }
    string[counter2++]='\r';
    string[counter2++]='\n'; 
    string[counter2]='\0';
  }
  else{  // negative float number
    string[counter2++]='-';
    counter1=counter2;
    integer_part =(int32_t) float_num*-1 ;
    temp=integer_part;
    if(temp > 0){
      while(temp){
        string[counter2++] = (temp%10) + '0';
        temp/=10;
      }
    }
    else{
      string[counter2++]=0+'0';  
    }
    for(counter=0;counter<(counter2-counter1)/2;counter++){
      string[counter1+counter]^=string[(counter2-1)-counter];
      string[(counter2-1)-counter]^=string[counter1+counter];
      string[counter1+counter]^= string[(counter2-1)-counter];
    }
    string[counter2++]='.';
    counter1=counter2;
    float_part=(int32_t)((float_num*-1)-integer_part)*Get_Power(10,precision);
    if(float_part > 0){
      while(float_part){
        string[counter2++] = (float_part%10) + '0';
        float_part/=10;
      }
    }
    else{
      string[counter2++]=0+'0';
    }
    for(counter=0;counter<(counter2-counter1)/2;counter++){
      string[counter1+counter]^=string[(counter2-1)-counter];
      string[(counter2-1)-counter]^=string[counter1+counter];
      string[counter1+counter]^= string[(counter2-1)-counter];
    }
  }		
  string[counter2++]='\r';
  string[counter2++]='\n'; 
  string[counter2]='\0';
  return string;
}
uint8_t strLen(int8_t* string){
  uint8_t counter=0;
  while(*string++!='\0') counter++;
  return counter;
}
uint8_t Slen_without_CR(int8_t* string){
  uint8_t counter=0;
  while(*string++!='\r') counter++;
  return counter;
}
void string_copy(int8_t* string1,int8_t* string2){
  uint8_t counter=0;
  while(*string2!='\0'){
    string1[counter++]=*string2++;
  }
  string1[counter]='\0';
}
int32_t String_To_integer_Conversion(int8_t* string){
  uint32_t length =	strLen(string);
  uint32_t num=0 ;
  while(length){
    if((*string>='0')&&(*string<='9')){
      num += (*string++ -'0') *Get_Power(10,--length);
    }
    else{
      break ;
    }
  }
  return num ;
}
int32_t string_cmp(int8_t*string1,int8_t* string2){
  uint8_t counter =0;
  uint8_t length_string1 = strLen(string1);
  uint8_t length_string2 = strLen(string2);
  counter= 0;
  if(length_string1 == length_string2){
    while((*string1 == *string2)&&(*string1!='\0')&&(*string2!='\0')){
      counter++;
      string1++;
      string2++;
    }
    if(counter==length_string1){
      return 0;
    }
  }
  
  return -1;
}

int8_t Is_Contain(int8_t* string, int8_t* str) {
	uint32_t str_len = strLen(str);
	uint32_t string_len = strLen(string);
	uint32_t string_index = 0, matched = 0;
	if (str_len>string_len) return 0;
	while (string_len>=str_len) {
		if (string[string_index] == str[matched]) {
			matched++;
			if (matched== str_len) {
				return 1;
			}
		}
		else {
			matched = 0;
		}
		string_index++;
		string_len--;
	}
	return 0;
}
/* reverse string */
void strRev(int8_t* str){
   uint8_t lstChrIndx= strLen(str)-1; //last char index 
   uint8_t count=0,temp=0;//initialize variables
	for(count=0;count<(lstChrIndx/2);count++)//loop until swapping is done
  {
		   temp=str[count]; // temporary var to carry the content of location
		   str[count]=str[lstChrIndx-count];//swap between first & chars
		   str[lstChrIndx-count]=temp;// swap between last & first chars
	}
}
