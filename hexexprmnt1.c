#include<stdio.h>
#include<math.h>

void toUpperC(char*);
int isHex(char*);
int toDec(char*,int);
int getHexfrmAF(char);


int main(){
    char ans[21];
    do{
    putchar(228);        
    gets(ans);
    toUpperC(ans);
    if(strcmp(ans,"EXIT")==0)continue;
    
    //if(isHex(ans)==0)printf("hex value!\n");
    if(isHex(ans)!=0){printf("non hex vaue!\n");continue;}
    
    printf("%sH = %dD\n",ans,toDec(ans,16));
    
    }while(strcmp(ans,"EXIT")!=0);
    return 0;
}

void toUpperC(char *s){
     int i =0;
     for(;*(s+i)!='\0';i++){
     *(s+i) = toupper(*(s+i));
     }
}

int isHex(char *s){
    int i;
    for(i=0;*(s+i)!='\0';i++){
       if(!isxdigit(*(s+i)))
       return 1;
    }
    return 0;
}    

int toDec(char *s,int base){
    
    int j = strlen(s);
    int i, num =0;
    long int fnum =0;
    
    for(i=0;j>0;i++){
       if(!isdigit(*(s+i)))
          num = (int)(*(s+i))-55;
       else
          num = (int)(*(s+i)) - 48; //ascii value '0' = 48
    fnum += num *((int)pow(base,--j));
    }
    
return fnum;
}

int getHexfrmAF(char h){
    switch(h){
              case 'A':return 10;
              case 'B':return 11;
              case 'C':return 12;
              case 'D':return 13;
              case 'E':return 14;
              case 'F':return 15;
    }

}
