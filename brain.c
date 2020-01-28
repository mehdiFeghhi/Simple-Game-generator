#include <stdio.h>
extern char full_page[];
extern int tele_pos[];

int abs(int number);
void brain(char detail[],int width , int height){

    extern char full_page[];
    extern int tele_pos[];
    int map = tele_pos[5];
    int amod,ofogh,distance;
    int point_distance[] = {0,0};
    float therepoint=0;
    for(amod = 10; amod >-11; amod --){
        if(amod +(tele_pos[3]/width) > height -1|| amod +(tele_pos[3]/width) < 1 )
            continue;

        for(ofogh= -(10 - abs(amod)) ; ofogh + abs(amod) < 11 ; ofogh++ ){
            if(ofogh +(tele_pos[3]%width) > width|| ofogh +(tele_pos[3]%width) < 0 )
                continue;
            if(full_page[tele_pos[3]+ofogh+amod*width] < 0||full_page[tele_pos[3]+ofogh+amod*width]>map)
                continue;



            if(full_page[tele_pos[3]+ofogh+amod*width] == '.'){

                distance = abs(ofogh)+ abs(amod);
                if(therepoint < (1.0/distance)){
                    therepoint = 1.0/distance;
                    point_distance [0]= amod;
                    point_distance[1] = ofogh;
                }

            }
            else if (full_page[tele_pos[3]+ofogh+amod*width]== 'F'){

                    distance = abs(ofogh)+ abs(amod);
                    if(therepoint < 5.0/distance){
                        therepoint = 5.0/distance;
                        point_distance[0]= amod;
                        point_distance[1] = ofogh;
                }

             }

        }

    }

    if(point_distance[0] < 0){
        if(full_page[tele_pos[3]-width] != 'B'||full_page[tele_pos[3]-width] != '!'||full_page[tele_pos[3]-width] != 'O')
            detail[1]= '8';
        }
    else if(point_distance[1] < 0){
            if(full_page[tele_pos[3]-1] != 'B'||full_page[tele_pos[3]-1] != '!'||full_page[tele_pos[3]-1] != 'O')
                detail[1]= '4';

        }
    else if(point_distance[0] > 0){
        if(full_page[tele_pos[3]+width] != 'B'||full_page[tele_pos[3]+width] != '!'||full_page[tele_pos[3]+width] != 'O')
            detail[1]= '5';
        }
    else if(point_distance[1] > 0){
            if(full_page[tele_pos[3]+1] != 'B'||full_page[tele_pos[3]+1] != '!'||full_page[tele_pos[3]+1] != 'O')
                detail[1]= '6';

        }

    else{
        if(detail[1]== '8'){
           if(full_page[tele_pos[3]-width] == 'B'||full_page[tele_pos[3]-width] == '!'||full_page[tele_pos[3]-width] == 'O')
                detail[1]= '5';

        }
        else if(detail[1]== '5'){
           if(full_page[tele_pos[3]+width] == 'B'||full_page[tele_pos[3]+width] == '!'||full_page[tele_pos[3]+width] == 'O')
                detail[1]= '8';

        }

        else if(detail[1]== '4'){
           if(full_page[tele_pos[3]-1] == 'B'||full_page[tele_pos[3]-1] == '!'||full_page[tele_pos[3]-1] == 'O')
                detail[1]= '6';

        }

        else if(detail[1]== '6'){
           if(full_page[tele_pos[3]+1] == 'B'||full_page[tele_pos[3]+1] == '!'||full_page[tele_pos[3]+1] == 'O')
                detail[1]= '4';

        }
    }






}



int abs(int number){
if (number < 0)
    return number*-1;
return number;
}
