void ascflist(){
   int i;
   color(0x0f);
   printf(" (null) ");
   color(0x0b);
   printf(" %3dD %3XH\n",0,0);

  for(i=1;i<=6;i++){
     color(0x0f);
     printf("       %c",i);
     color(0x0b);
     printf(" %3dD %3XH\n",i,i);
  }
  
   color(0x0f);
   printf(" (beep) ");
   color(0x0b);
   printf(" %3dD %3XH\n",7,7);
   
   color(0x0f);
   printf("(bspace)");
   color(0x0b);
   printf(" %3dD %3XH\n",8,8);
   
   color(0x0f);
   printf(" (tab)  ");
   color(0x0b);
   printf(" %3dD %3XH\n",9,9);
   
   color(0x0f);
   printf("(lfeed) ");
   color(0x0b);
   printf(" %3dD %3XH\n",10,10);
   
   color(0x0f);
   printf("       %c",11);
   color(0x0b);
   printf(" %3dD %3XH\n",11,11);
   
   color(0x0f);
   printf("       %c",12);
   color(0x0b);
   printf(" %3dD %3XH\n",12,12);
   
   
   color(0x0f);
   printf("(cretrn)");
   color(0x0b);
   printf(" %3dD %3XH\n",13,13);
   
  for(i=14;i<=31;i++){
     color(0x0f);
     printf("       %c",i);
     color(0x0b);
     printf(" %3dD %3XH\n",i,i);
  }
  
   color(0x0f);
   printf("(space) ");
   color(0x0b);
   printf(" %3dD %3XH\n",32,32);

   for(i=33;i<=254;i++){
     color(0x0f);
     printf("       %c",i);
     color(0x0b);
     printf(" %3dD %3XH\n",i,i);
  }
  
  color(0x0f);
   printf("(blank) ");
   color(0x0b);
   printf(" %3dD %3XH\n",255,255);

}
