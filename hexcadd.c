void hexcadd(){
   char buffer[20];
   char hex1[10];
   char hex2[10];
   char flag = '0';
   char qflag = 'x';
   long int num1 =0,num2=0,hexsum =0;
   
   for(;;){
           
   do{
   color(0x0b);   
   printf(" Input 1st Hex: ");
   color(0x03);
   
   gets(buffer);
   
   if(strlen(buffer)>9){
      errMsg(1);
      continue;
      }
      
   strcpy(hex1,buffer);
   toUpperCase(hex1);
   
   if(strcmp(hex1,"/Q")==0){
   flag = '1';
   qflag = '1';
   continue;
   }
   
   int base = getBase(hex1);
   
   
   if(isHex(hex1)!=0){
     errMsg(10);
     continue;
   }
   else if((base!=16)&&(base!=10)&&(base!=8)&&(base!=2)){
     errMsg(9);
     continue;
   }
   else if(base!=16){
     errMsg(15);
     continue;
   }
   else if(strlen(hex1)>6){
     errMsg(14);
     continue;
   }
   else{
    num1 = toDec(hex1,16);
    flag = '1';
   }
   
   }while(flag=='0');
   
   flag = '0';
   if(qflag!='x')break;
   
   do{
   color(0x0b);   
   printf(" Input 2nd Hex: ");
   color(0x03);
   gets(buffer);
   
   if(strlen(buffer)>9){
      errMsg(1);
      continue;
      }
      
   strcpy(hex2,buffer);
   toUpperCase(hex2);
   
   if(strcmp(hex2,"/Q")==0){
   flag = '1';
   qflag = '1';
   continue;
   }
   
   int base = getBase(hex2);
   
   
   if(isHex(hex2)!=0){
     errMsg(10);
     continue;
   }
   else if((base!=16)&&(base!=10)&&(base!=8)&&(base!=2)){
     errMsg(9);
     continue;
   }
   else if(base!=16){
     errMsg(15);
     continue;
   }
   else if(strlen(hex2)>6){
     errMsg(14);
     continue;
   }
   else{
    num2 = toDec(hex2,16);
    flag = '1';
   }
   
   }while(flag=='0');
   
   hexsum = num1 + num2;
   if(qflag!='x')break;
   else if(hexsum>268435455){
        errMsg(14);
   }
   else{
        color(0x0b);
        printf(" Sum: %XH\n      %dD\n",hexsum,hexsum);
        break;
   }
   
   }
   
}
