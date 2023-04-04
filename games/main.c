#include <stdio.h>
#include <time.h> //rand
#include <stdlib.h> //rand
#include <stdbool.h>
int prnt(int inp) {
    if (inp==3) {
        printf("-");
    }
    else if (inp==1) {
        printf("X");
    } else if (inp==0) {
        printf("O");
    } else {
        return 1;
    } return 0;
}
int tries=0;
int render(int tl, int tm, int tr,
           int ml, int mm, int mr,
           int bl, int bm, int br){
    prnt(tl);
    printf(" ");
    prnt(tm);
    printf(" ");
    prnt(tr);
    printf("\n");

    prnt(ml);
    printf(" ");
    prnt(mm);
    printf(" ");
    prnt(mr);
    printf(" -- ");
    printf("%d",tries);
    printf("\n");

    prnt(bl);
    printf(" ");
    prnt(bm);
    printf(" ");
    prnt(br);
    printf("\n");
    printf("_____\n");
}
char * toreturn[9]={
        "tl","tm","tr","ml","mm","mr","bl","bm","br"
    };
int p[]={3,3,3,
         3,3,3,
         3,3,3};
int winner=3;
bool checkwin() {
    if ((p[0]==0&&p[1]==0&&p[2]==0) || (p[0]==1&&p[1]==1&&p[2]==1)) return true; //top row
    else if ((p[3]==0&&p[4]==0&&p[5]==0) || (p[3]==1&&p[4]==1&&p[5]==1)) return true; //middle row
    else if ((p[6]==0&&p[7]==0&&p[8]==0) || (p[6]==1&&p[7]==1&&p[8]==1)) return true; //bottom row

    else if ((p[0]==0&&p[3]==0&&p[6]==0) || (p[0]==1&&p[3]==1&&p[6]==1)) return true; //left column
    else if ((p[1]==0&&p[4]==0&&p[7]==0) || (p[1]==1&&p[4]==1&&p[7]==1)) return true; //middle column
    else if ((p[2]==0&&p[5]==0&&p[8]==0) || (p[2]==1&&p[5]==1&&p[8]==1)) return true; //right column
    else return false;
}
char * getInput() {
    int y=rand()%10;
    int raw=y;
    char * inp=toreturn[raw];
    if (p[raw]!=3) {
        getInput();
    } else {
        return inp;
    }
}
int main(int argc, char ** argv) {
    srand(time(NULL));
    render(3,3,3,3,3,3,3,3,3);
    
    // render(p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[8]);
    
    int move=0;

    while (1) {
        move=tries%2;
        tries++;
        char * inp;
        if (tries>9) {
            return 0;
        } else {
            inp=getInput();
        }
        // printf("%d",tries);
        if (checkwin()==true) break;
        
        if(inp=="tl" && p[0]==3){
            p[0]=move;
        } if(inp== "tm" && p[1]==3){
            p[1]=move;
        } if(inp== "tr" && p[2]==3){
            p[2]=move;

        } if(inp== "ml" && p[3]==3){
            p[3]=move;
        } if(inp== "mm" && p[4]==3){
            p[4]=move;
        } if(inp== "mr" && p[5]==3){
            p[5]=move;

        } if(inp== "bl" && p[6]==3){
            p[6]=move;
        } if(inp== "bm"&& p[7]==3){
            p[7]=move;
        } if(inp== "br"&& p[8]==3){
            p[8]=move;
        }
        
        render(p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[8]);
    }
    
}