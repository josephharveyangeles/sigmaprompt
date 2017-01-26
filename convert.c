int getBase(char*);
int isHex(char*);
int isDec(char*);
int isOct(char*);
int isBin(char*);
long int toDec(char*,int);
char*toBin(long int);

void convert(char *s){
    int base = getBase(s);
    long int decimal;
    
    switch(base){
        
        case 16: if(isHex(s)!=0)errMsg(10);
                 else{
                      (strlen(s)>7)?errMsg(14):printf("       %dD\n       %oO\n       %sB\n",toDec(s,16),toDec(s,16),toBin(toDec(s,16)));                      
                 }
                 break;
        case 10: decimal = atol(s);
                 if(isDec(s)!=0)errMsg(11);
                 else if(decimal>268435455)errMsg(14);
                 else{
                      (strlen(s)>9)?errMsg(14):printf("       %XH\n       %oO\n       %sB\n",decimal,decimal,toBin(decimal));                      
                 }
                 break;
        case 8:  if(isOct(s)!=0)errMsg(12);
                 else{
                      (strlen(s)>10)?errMsg(14):printf("       %XH\n       %dD\n       %sB\n",toDec(s,8),toDec(s,8),toBin(toDec(s,8)));                      
                 }
                 break;
        case 2:  if(isBin(s)!=0)errMsg(13);
                 else{
                      (strlen(s)>29)?errMsg(14):printf("       %XH\n       %dD\n       %oO\n",toDec(s,2),toDec(s,2),toDec(s,2));                      
                 }
                 break;
        default: errMsg(9);
    }
}


int getBase(char *s){
   
   int i = strlen(s);
   i--;
   
   if(*(s+i)=='H'){
      *(s+i)='\0';
      return 16;
   }
   else if(*(s+i)=='D'){
      *(s+i)='\0';
      return 10;
   }
   else if(*(s+i)=='O'){
      *(s+i)='\0';
      return 8;
   }
   else if(*(s+i)=='B'){
      *(s+i)='\0';
      return 2;
   }
   else if(isdigit(*(s+i))){
      return 10;
   }
   else if(isxdigit(*(s+i))){
      return 16;
   }
   else return 0;
}

int isHex(char *s){
    int i = 0;
    for(;*(s+i)!='\0';i++){
        //if not 0-9 or A-F
        if(!isxdigit(*(s+i)))
       return 1;
    }
    return 0;
}

int isDec(char *s){
    int i = 0;
    for(;*(s+i)!='\0';i++){
        //if not 0 - 9
        if((((int)(*(s+i)))<48)||(((int)(*(s+i)))>57))
        return 1;
    }
    return 0;
}

int isOct(char *s){
    int i = 0;
    for(;*(s+i)!='\0';i++){
        //if not 0 - 7
        if((((int)(*(s+i)))<48)||(((int)(*(s+i)))>55))
        return 1;
    }
    return 0;
}

int isBin(char *s){
    int i = 0;
    for(;*(s+i)!='\0';i++){
        //if not 0 - 9
        if((((int)(*(s+i)))<48)||(((int)(*(s+i)))>49))
        return 1;
    }
    return 0;
}

long int toDec(char *s,int base){
    
    int j = strlen(s);
    int i, num =0;
    long int fnum =0;
    
    for(i=0;j>0;i++){
       if(!isdigit(*(s+i)))
          num = ((int)(*(s+i)))-55;
       else
          num = (int)(*(s+i)) - 48; //ascii value '0' = 48
    fnum += num *((long int)pow(base,--j));
    }
    
return fnum;
}

char* toBin(long int num){
      static char bin[28] = "000000000000000000000000000";
      int i, j = 0;
      char *s = bin;
      
      for(i=0;*(s+i)!='\0';i++)*(s+i)='0';
      
      for(i=27;i>=0;i--){
         if(num>=(long int)pow(2,i)){
            bin[j++] = '1';
            num-=(long int)pow(2,i);
            }
         else
            bin[j++];
      }
      
      while(*s!='1')s++;
      
      return s;
}
