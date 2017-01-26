/*
  Name: projSigmaPrompt
  Copyright: 2012 
  Author: angelesjosephharvey
  Date: 19/06/12 07:51
  Description: assembly toolkit, converters, tables and calculators
*/
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>

void errMsg(int);

void cright(void);
void toUpperCase(char*);
int argcount(char*);
void getOneArgFuncs(char*);
void getArgTwoFuncs(char*);
void helpFunc(int);
void sigma(void);
void gxy(int,int);
void sfx5(void);
void sfx6(void);

int main(){

char ans[34];
char buffer[100];
/*color(0x0f);
printf("Sigma Prompt [Version 2.1.7600]\n");
printf("Copyright (c) 2012 Bluescreen Corporation. All rights reserved.\n\n");
*/
system("title Sigma Prompt");
sigma();    
    do{
       color(0x0f); //Sigma prompt: green
       printf("%c}",228);
       color(0x03);//user input: aqua
       
       gets(buffer);
       color(0x0b);//system: light aqua
       if(strlen(buffer)>33){
          errMsg(1);
          continue;
       }
       else{ 
          strcpy(ans,buffer);
          toUpperCase(ans);
       }
       
       if(strcmp(ans,"EXIT")==0)continue;
       if(ans[0]==' ')continue;
       if(strcmp(ans,"\0")==0)continue;
       //program proper here
       
       int argNum = argcount(ans);
       
       
       if(argNum==1)getOneArgFuncs(ans);
       else if(argNum==2)getArgTwoFuncs(ans);
       else errMsg(2);
       
    }while(strcmp(ans,"EXIT")!=0);
    
    return 0;
}

void errMsg(int i){
   color(0x0c);//errormsg red
   switch(i){
         case 1:
              printf(" Error 0x01: Max input exceeded.\n");
              break;
         case 2:
              printf(" Error 0x02: Invalid arguments.\n");
              break;
         case 3:
              printf(" Error 0x03: Missing argument for 'CONV' command.\n");
              break;
         case 4:
              printf(" Error 0x04: Missing parameter for 'HEXC' command.\n");
              break;
         case 5:
              printf(" Error 0x05: Missing parameter for 'HEXT' command.\n");
              break;
         case 7:
              printf(" Error 0x07: Parameter format is not correct -,+.\n");
              break;
         case 9:
              printf(" Error 0x09: Invalid base.\n");
              break;
         case 10:
              printf(" Error 0x0A: Invalid HEX digits found.\n");
              break;
         case 11:
              printf(" Error 0x0B: Invalid DECIMAL digits found.\n");
              break;
         case 12:
              printf(" Error 0x0C: Invalid OCTAL digits found.\n");
              break;
         case 13:
              printf(" Error 0x0D: Invalid BINARY digits found.\n");
              break;
         case 14:
              printf(" Error 0x0E: Out of range.\n");
              break;
         case 15:
              printf(" Error 0x0F: Unsupported base.\n");
              break;
         case 16:
              printf(" Error 0x10: Missing parameter for 'ASCII' command.\n");
              break;
         case 17:
              printf(" Error 0x11: Parameter format is not correct -l, -a, -n, -h, -i.\n");
              break;
         case 18:
              printf(" Error 0x12: Invalid input.\n");
              break;
         //default:
   }
}

void toUpperCase(char *s){
     int i;
     for(i=0;*(s+i)!='\0';i++){
        *(s+i) = toupper(*(s+i));
     }
}

int argcount(char *s){
    int x=0;
    int c=1;
    for(;*(s+x)!='\0'; x++ ){
        if((x>=0)&&(*(s+(x-1))==' '))c++;
        /*
          if there's a space before a character, counter + 1.
        trailing zeros are not yet covered..
        */
    }
    return c;      
}


void getOneArgFuncs(char *s){
     if(strcmp(s,"HELP")==0)helpFunc(0);
     else if(strcmp(s,"ASSKIT")==0)printf("%s command found.\n",s);//assKitFunc();
     else if(strcmp(s,"HARVEY")==0){sigma();sfx5();}
     else if(strcmp(s,"SIGMA")==0)sigma();
     else if(strcmp(s,"COPYRIGHT")==0)cright();
     else if(strcmp(s,"CLS")==0)system("cls");
     else if(strcmp(s,"CONV")==0)errMsg(3);
     else if(strcmp(s,"HEXC")==0)errMsg(4);
     else if(strcmp(s,"HEXT")==0)errMsg(5);
     else if(strcmp(s,"ASCII")==0)errMsg(16);
     else if(strcmp(s,"EXITV")==0){sfx6();exit(0);}
     else {
          color(0x0c);
          printf(" Error 0x06: '%s' command does not exist.\n",s);
          }
}
void helpFunc(int i){
     switch(i){ 
        case 1:  color(0x0b);
                 printf(" Displays the American Standard Code for Information Interchange.\n\n");
                 color(0x0f);
                 printf(" ASCII [-L] [-A] [-I]\n\n"); color(0x0b);
                 printf("  -L   Displays all the ASCII values in a list.\n");
                 printf("  -N   Converts a character sequence into ASCII values.\n");
                 printf("  -A   Show the ASCII value of a character.\n");
                 printf("  -H   Show the character of an ASCII value(Hex).\n");
                 printf("  -I   Show the character of an ASCII value(Decimal).\n\n\n");
                 break;
        case 2:  color(0x0b);
                 printf(" Converts a number into different bases.\n\n");
                 color(0x0f);
                 printf(" CONV [NUMBER][ H | D | O | B ]\n\n"); color(0x0b);
                 printf("   H   Convert a Hexadecimal to Decimal, Octal and Binary.\n");
                 printf("   D   Convert a Decimal to Hexadecimal, Octal and Binary.\n");
                 printf("   O   Convert an Octal to Hexadecimal, Decimal and Binary.\n");
                 printf("   B   Convert a Binary to Hexadecimal, Decimal and Octal.\n\n\n");
                 break;
        case 3:  color(0x0b);
                 printf(" Clears the screen.\n\n");
                 color(0x0f);
                 printf(" CLS\n\n\n");
                 break;
        case 4:  color(0x0b);
                 printf(" Perform Addition or Subtraction on Hex values.\n\n");
                 color(0x0f);
                 printf(" HEXC [ + | - ]\n\n"); color(0x0b);
                 printf("   +   Perform addition on two Hex values.\n");
                 printf("   -   Perform subtraction on two Hex values.\n\n\n");
                 break;
        case 5:  color(0x0b);
                 printf(" Displays the addition or subtraction Hex table.\n\n");
                 color(0x0f);
                 printf(" HEXT [ + | - ]\n\n"); color(0x0b);
                 printf("   +   Displays the addition Hex table.\n");
                 printf("   -   Displays the subtraction Hex table.\n\n");
                 printf(" Match the row and column to get the corresponding answer.\n\n\n");
                 break;
        case 6:  color(0x0b);
                 printf(" Displays program information.\n\n");
                 color(0x0f);
                 printf(" SIGMA\n\n\n");
                 break;
        case 7:  color(0x0b);
                 printf(" Displays copyright information.\n\n");
                 color(0x0f);
                 printf(" COPYRIGHT\n\n\n");
                 break;
        default: color(0x0f);
                 printf(" For more information on a specific command. type COMMAND /?\n");
                 printf(" ASCII");color(0x0b);    printf("      Displays the American Standard Code for Information Interchange.\n");
                 color(0x0f);
                 printf(" CONV ");color(0x0b);    printf("      Converts a number into different bases.\n");
                 color(0x0f);
                 printf(" CLS  ");color(0x0b);    printf("      Clears the screen.\n");
                 color(0x0f);
                 printf(" HEXC ");color(0x0b);    printf("      Perform Addition or Subtraction Hex values.\n");
                 color(0x0f);
                 printf(" HEXT ");color(0x0b);    printf("      Displays the addition or subtraction Hex table.\n");
                 color(0x0f);
                 printf(" SIGMA");color(0x0b);    printf("      Displays program information.\n");
                 color(0x0f);
                 printf(" COPYRIGHT");color(0x0b);printf("  Displays copyright information.\n\n");
                 
     }
}

void sigma(void){
      int y;
      system("cls");
 	  
    
 	   gxy(33,5);color(0xf0);printf("  ");color(0x00);printf("          ");color(0xf0);printf("  ");
	   gxy(35,6);color(0xf0);printf("  ");color(0x00);printf("      ");color(0xf0);printf("  ");
	   gxy(33,7);printf("              ");
	   gxy(31,8);printf("    ");color(0x30);printf("  ");color(0xf0);printf("      ");color(0x30);printf("  ");color(0xf0);printf("    ");
	   gxy(29,9);printf("                      ");
	   gxy(29,10);printf("  ");color(0x00);printf("  ");color(0xf0);printf("              ");color(0x00);printf("  ");color(0xf0);printf("  ");
 	   gxy(29,11);printf("  ");color(0x00);printf("  ");color(0xf0);printf("              ");color(0x00);printf("  ");color(0xf0);printf("  ");
 	   gxy(29,12);printf("  ");color(0x00);printf("  ");color(0xf0);printf("  ");color(0x00);printf("          ");color(0xf0);printf("  ");color(0x00);printf("  ");color(0xf0);printf("  ");
 	   gxy(35,13);printf("    ");color(0x00);printf("  ");color(0xf0);printf("    ");
       color(0x0b);
       gxy(36,15);printf("%c Prompt\n",228);
       printf("\t\t\t\t Copyright (c)\n");
       printf("\t\t\t       [Version 3.1.7600]\n\n");
       printf("\t\t\t\t   06.22.2012\n\n");
       printf("\t\t\t      josephharveycangeles\n\n\n");
}

void gxy (int x, int y)
{
     COORD coord;
     coord.X = x;     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void sfx5(void){
       
       Beep(196,200);
       Beep(185,200);
       Beep(196,200);
       Beep(165,800);
       Beep(175,400);
       Beep(185,400);
       Beep(196,800);
       Beep(262,800);
       Beep(330,200);
       Beep(330,100);
       Beep(294,400);
       Beep(330,400);
       Beep(349,400);
       Beep(247,400);
       Beep(294,800);
       Beep(262,400);
       Beep(196,200);
       Beep(185,200);
       Beep(196,200);
       Beep(262,800);
}

void sfx6(void){
Beep(262,50);
Beep(277,50);
Beep(294,50);
Sleep(600);
Beep(247,200);
Beep(349,200);
Sleep(400);
Beep(349,200);
Beep(349,300);
Beep(330,300);
Beep(294,300);
Beep(262,200);
Beep(165,200);
Sleep(200);
Beep(165,200);
Beep(131,200);
}

void cright(void){
     color(0x0b);
     system("cls");
    printf("\n\n\t\tPermission to use, copy and distribute SigmaPrompt for\n\t non-commercial purposes provided that this copyright information\n\t and author notice will not be omitted or altered.\n\n");
    printf("\t\tSigma Prompt does not contain any harmful content. Well,\n\t"
           "aside from the 8-bit music beep codes that could possibly annoy\n\t"
           "people when played over and over again, or by using many instance\n\t"
           "of SigmaPrompt simulaneously playing over and over again while\n\t"
           "you bang your head with the beat like a madman while somebody can\n\t"
           "actually see you, could slightly qualify as harmful --to someone\n\telse's eyes.\n\n");
    printf("\t\tSigmaPrompt is mainly written as an aid for assembly\n\t" 
           "language programming. In no event shall the author be held liable\n\t" 
           "for any damage arising from irresponsible use of this software.\n\n\n");

    printf("\t\t\tSigmaPrompt Version[3.1.7600]\n"
           "\t\t\t      Copyright(c) 2012\n" 
           "\t\t\t   by josephharveycangeles\n" 
           "\t\t\t     All rights reserved.\n\n");

}
