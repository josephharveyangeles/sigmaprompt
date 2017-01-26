void cstrcat(char*,char);
void convert(char*);
void hexcadd(void);
void hexcminus(void);
void hextadd(void);
void hextminus(void);

void getArgTwoFuncs(char *s){
     char argA[18]="\0";
     char argB[18]="\0";
     //int i =0;
     for(;*s!=' ';s++){
        cstrcat(argA,*s);
     }
     while(*s==' ')s++;
     for(;(*s!='\0')&&(*s!=' ');s++){
         cstrcat(argB,*s);
     }
     //printf(" argument one: %s.\n argument two: %s.\n",argA,argB);
     
     if(strcmp(argA,"CONV")==0){
        //printf(" %s command found!\n",argA);
        if(strcmp(argB,"/?")==0)helpFunc(2);
        else convert(argB);
     }
     else if(strcmp(argA,"HEXC")==0){
        //printf(" %s command found!\n",argA);
        if(strcmp(argB,"+")==0)hexcadd();
        else if(strcmp(argB,"-")==0)hexcminus();
        else if(strcmp(argB,"/?")==0)helpFunc(4); 
        else errMsg(7);
     }
     else if(strcmp(argA,"HEXT")==0){
        //printf(" %s command found!\n",argA);
        if(strcmp(argB,"+")==0)hextadd();
        else if(strcmp(argB,"-")==0)hextminus();
        else if(strcmp(argB,"/?")==0)helpFunc(5);
        else errMsg(7);
     }
     else if(strcmp(argA,"ASCII")==0){
        //printf(" %s command found!\n",argA);
        if(strcmp(argB,"-L")==0)ascflist();
        else if(strcmp(argB,"-A")==0)asctoint();//ascii to int
        else if(strcmp(argB,"-I")==0)intoasc();//int to ascii
        else if(strcmp(argB,"-H")==0)hextoasc();//hex to ascii
        else if(strcmp(argB,"-N")==0)charstream();//char sequence
        else if(strcmp(argB,"/?")==0)helpFunc(1);
        else errMsg(17);
     }
     else if((strcmp(argA,"CLS")==0)&&(strcmp(argB,"/?")==0))helpFunc(3);
     else if((strcmp(argA,"SIGMA")==0)&&(strcmp(argB,"/?")==0))helpFunc(6);
     else if((strcmp(argA,"COPYRIGHT")==0)&&(strcmp(argB,"/?")==0))helpFunc(7);

     else {
          color(0x0c);
          printf(" Error 0x08: '%s' is not recognized as a valid command.\n",argA);
          }
}

void cstrcat(char *x, char y){
     int i=0;
     while(*(x+i)!='\0')i++;
     if(*(x+i)=='\0'){
     *(x+i)= y;
     *(x+(i+1))='\0';
     }

}
