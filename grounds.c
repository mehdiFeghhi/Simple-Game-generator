#include <stdio.h>
extern char full_page[];
void ground(int width,int point_player1,int point_player2,float time){
    extern char full_page[];
    int go,width_space;
    for(go = 0,width_space = 0;full_page[go] != '\0'; go++, width_space++){
            if(width_space == width){
                printf("\n");
                width_space = 0;
            }
            printf("%c",full_page[go]);

    }
    printf("\n\n\nplayer 1 point\t %d",point_player1);
    printf("\nplayer 2 point\t %d",point_player2);
    printf("\ntime\t %f",time);




}

