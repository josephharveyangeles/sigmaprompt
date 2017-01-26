
void charstream(){
     char flag = 'y';
     char cstream[100], buffer[200], *s = cstream;
     int i;
     
     do{
          color(0x0b);
          printf(" char seq: ");
          color(0x03);
          gets(buffer);
          color(0x0b);
          if(strlen(buffer)>99){
             errMsg(1);
             flag = 'y';
             continue;
          }
          else{
          strcpy(cstream,buffer);
          }
          
          if(strcmp(cstream,"/q")==0){
             flag = 'y';
             continue;
          }
          else{
               for(i=0;*(s+i)!='\0';i++){
                  color(0x0f);
                  printf("  %c ",*(s+i));
                  color(0x0b);
                  printf("= %3dD, %2XH\n",*(s+i),*(s+i));
               }
          flag = 'y';
          }
     }while(flag=='n');


}
