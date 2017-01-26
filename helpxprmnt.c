#include<stdio.h>
void help(int);
int main(){
    int x;
    for(;;){
       printf("%c}",228);
       scanf("%d",&x);
       help(x);
    }
    
}

void help(int i){
     switch(i){  
        default: color(0x0f);
                 printf(" For more information on a specific command. type COMMAND /?\n");
                 printf(" ASCII");color(0x0b);printf("   Displays the American Standard Code for Information Interchange.\n");
                 color(0x0f);
                 printf(" CONV ");color(0x0b);printf("   Converts a number into different bases.\n");
                 color(0x0f);
                 printf(" CLS  ");color(0x0b);printf("   Clears the screen.\n");
                 color(0x0f);
                 printf(" HEXC ");color(0x0b);printf("   Add or Subtract Hex values.\n");
                 color(0x0f);
                 printf(" HEXT ");color(0x0b);printf("   Displays addition or subtraction Hex table.\n");
                 color(0x0f);
                 printf(" SIGMA");color(0x0b);printf("   Displays program information.\n");
     }
}
