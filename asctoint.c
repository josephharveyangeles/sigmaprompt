void asctoint(){
    char x, buffer[20];
    char flag ='y';
    
    do{
         color(0x0b);
         printf(" char: ");
         color(0x03);
         gets(buffer);
         color(0x0b);
         if(strcmp(buffer,"/q")==0)break;
         else if(strlen(buffer)>1){
            errMsg(1);
            flag = 'n';
            continue;
         }
         else{
         x = buffer[0];
         printf(" int: %dD, %XH\n",x,x);
         flag = 'y';
         }
    }while(flag == 'n');


}

