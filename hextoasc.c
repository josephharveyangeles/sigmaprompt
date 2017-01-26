long int toDec(char*,int);
int getBase(char*);
int isHex(char*);

void hextoasc(){
    long int x;
    char buffer[20];
    char flag = 'y';
    
    do{
         color(0x0b);
         printf(" hex: ");
         color(0x03);
         gets(buffer);
         color(0x0b);
         
         if(strcmp(buffer,"/q")==0)break;
         
         toUpperCase(buffer);
         
         if(getBase(buffer)!=16){
            errMsg(9);
            flag ='n';
            continue;
         }
         else if(isHex(buffer)!=0){
            errMsg(10);
            flag ='n';
            continue;
         }
         else if(strlen(buffer)>2){
            errMsg(14);
            flag = 'n';
            continue;
         }
         else{
            
         x = toDec(buffer,16);
         if(x>255){
           errMsg(14);
           flag = 'n';
           continue;
         }
         else{
           switch(x){
               case 0: printf(" char: (null)\n");break;
               case 7: printf(" char: (beep)\n");break;
               case 8: printf(" char: (backspace)\n");break;
               case 9: printf(" char: (tab)\n");break;
               case 10:printf(" char: (line feed)\n");break;
               case 13:printf(" char: (carriage return)\n");break;
               case 32:printf(" char: (space)\n");break;
               case 255:printf(" char: (blank)\n");break;
               default: printf(" char: %c\n",x);
           }
           flag = 'y';
         }
         }
    }while(flag =='n');
}




