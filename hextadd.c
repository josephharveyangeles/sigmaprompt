void hextadd(){
     short int i,j;
     color(0x0f);
     printf("  ");
     for(i=0;i<=15;i++){
        printf(" %2X",i);
     }
     putchar('\n');
          
     for(j=0;j<=15;j++){
      color(0x0f);printf(" %X",j);
      color(0x0b);
      for(i=0+j;i<=15+j;i++){printf(" %2X",i);}
      printf("\n");
      }
}
