void intoasc(){
    int x;
    char buffer[20];
    char flag = 'y';
    
    do{
         color(0x0b);
         printf(" int: ");
         color(0x03);
         gets(buffer);
         color(0x0b);
         if(strcmp(buffer,"/q")==0)break;
         
         toUpperCase(buffer);
         if(getBase(buffer)!=10){
            errMsg(9);
            flag ='n';
            continue;
         }
         else if(isDec(buffer)!=0){
            errMsg(11);
            flag ='n';
            continue;
         }
         else if(strlen(buffer)>3){
            errMsg(1);
            flag = 'n';
            continue;
         }
         else{
         x = atoi(buffer);
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

int hasAlpha(char *s){
    int i;
    for(i=0;*(s+i)!='\0';i++){
      if(isalpha(*(s+i)))
        return 1;
    }
return 0;
}
