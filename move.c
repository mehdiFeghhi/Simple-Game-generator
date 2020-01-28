#include <stdio.h>
#include <stdlib.h>
extern char full_page[]; // ground of game that we want move on it
extern int tele_pos[];      // it has five index first and secent is for our teleport position and third and forth is for our player possition five of them is width of ground
void eat(int player,int next , int before,int point[]); // this function help when the player fall on the point or teleport
void  move(char detail[],int point[],int with){ //detail = position players + width + movement ...............this function help us to move our player

        if ( detail[1] == '8'){           //at first when possition of player two was toward of  up he/she go up if there are'nt any wall or block or player
                if ((full_page[tele_pos[3]-with] != '!') && (full_page[tele_pos[3]-with] != 'B' ) &&(full_page[tele_pos[3]-with] !='O') ){
                    if (full_page[tele_pos[3]-with] == '.' || full_page[tele_pos[3]-with] == 'F' || full_page[tele_pos[3]-with] == 'T'){
                        eat(1 , tele_pos[3]-with , tele_pos[3],point); // if there are any point or big point it ear function help us .
                        full_page[tele_pos[3]] = 'X';
                        }
                    else {
                        full_page[tele_pos[3]] = ' ';
                        tele_pos[3] -= with ;           //it replace place of player with empty places.
                        full_page[tele_pos[3]] = 'X';
                        }
                }
       }
       else if (detail[1] == '5'){       // if possition player two was toward of  down
            if ((full_page[tele_pos[3]+with] != '!') && (full_page[tele_pos[3]+with] != 'B') && (full_page[tele_pos[3]+with] != 'O')){
                    if(full_page[tele_pos[3]+with] =='.' || full_page[tele_pos[3]+with] == 'F' || full_page[tele_pos[3]+with] == 'T'){
                        eat(1,tele_pos[3]+with,tele_pos[3],point);
                        full_page[tele_pos[3]] = 'X';
                        }
                    else {
                        full_page[tele_pos[3]] = ' ';
                        tele_pos[3] += with ;
                        full_page[tele_pos[3]] = 'X';
                    }
            }
        }
        else if (detail[1] == '6'){   // if possition of player two was toward right
            if ( (full_page[tele_pos[3]+1] != '!' ) && (full_page[tele_pos[3]+1] != 'B' ) &&(full_page[tele_pos[3]+1] != 'O')){
                if(full_page[tele_pos[3]+1] =='.' || full_page[tele_pos[3]+1] == 'F' || full_page[tele_pos[3]+1] == 'T' ){
                        eat(1,tele_pos[3]+1,tele_pos[3],point);
                        full_page[tele_pos[3]] = 'X';
                        }
                else {
                    full_page[tele_pos[3]] = ' ';
                    tele_pos[3]+= 1;
                    full_page[tele_pos[3]] = 'X';
                }
            }

       }
       else if (detail[1] == '4'){  // if possition of player two was toward left

            if ((full_page[tele_pos[3]-1] != '!') && (full_page[tele_pos[3]-1] != 'B') &&(full_page[tele_pos[3]-1]) !='O'){
                if(full_page[tele_pos[3]-1] =='.' || full_page[tele_pos[3]-1] == 'F'|| full_page[tele_pos[3]-1] == 'T'){
                        eat(1,tele_pos[3]-1,tele_pos[3],point);
                        full_page[tele_pos[3]] = 'X';
                        }
                else {
                    full_page[tele_pos[3]] = ' ';
                    tele_pos[3] -= 1;
                    full_page[tele_pos[3]] = 'X';
                }
            }

        }
       if ( detail[0] == 'W'){  //player one toward to up
                if ( (full_page[tele_pos[2]-with] != '!') && (full_page[tele_pos[2]-with] != 'B' )&&(full_page[tele_pos[2]-with] !='X')){
                    if(full_page[tele_pos[2]-with] =='.' || full_page[tele_pos[2]-with] == 'F'|| full_page[tele_pos[2]-with] == 'T'){
                        eat(0,tele_pos[2]-with,tele_pos[2],point);
                        full_page[tele_pos[2]] = 'O';
                        }
                    else {
                        full_page[tele_pos[2]] = ' ';

                        tele_pos[2] -= with ;
                        full_page[tele_pos[2]] = 'O';

                    }
                }
                }

       else if (detail[0] == 'S'){ // player one toward to down
            if ((full_page[tele_pos[2]+with] != '!' )&& (full_page[tele_pos[2]+with] != 'B' ) &&(full_page[tele_pos[2]+with] !='X')){
                    if(full_page[tele_pos[2]+with] =='.' || full_page[tele_pos[2]+with] == 'F'|| full_page[tele_pos[2]+with] == 'T'){
                        eat(0,tele_pos[2]+with,tele_pos[2],point);
                        full_page[tele_pos[2]] = 'O';
                        }
                    else {
                        full_page[tele_pos[2]] = ' ';
                        tele_pos[2]+= with;
                        full_page[tele_pos[2]] = 'O';
                    }
            }
        }
        else if (detail[0] == 'D'){ // player one toward to right
            if ( (full_page[tele_pos[2]+1] != '!' ) && (full_page[tele_pos[2]+1] != 'B' ) &&(full_page[tele_pos[2]+1] != 'X')){
                if(full_page[tele_pos[2]+1] =='.' || full_page[tele_pos[2]+1] == 'F' || full_page[tele_pos[2]+1] == 'T' ){
                        eat(0,tele_pos[2]+1,tele_pos[2],point);
                        full_page[tele_pos[2]] = 'O';
                        }
                else {
                    full_page[tele_pos[2]] = ' ';
                    tele_pos[2]+= 1;
                    full_page[tele_pos[2]] = 'O';
                }
            }
       }
       else if (detail[0] == 'A'){ // player one toward left
            if ((full_page[tele_pos[2]-1] != '!') && (full_page[tele_pos[2]-1] != 'B') &&(full_page[tele_pos[2]-1]) !='X'){
                if(full_page[tele_pos[2]-1] =='.' || full_page[tele_pos[2]-1] == 'F'|| full_page[tele_pos[2]-1] == 'T'){
                        eat(0,tele_pos[2]-1,tele_pos[2],point);
                        full_page[tele_pos[2]] = 'O';
                        }
                else {
                    full_page[tele_pos[2]] = ' ';
                    tele_pos[2] -= 1;
                    full_page[tele_pos[2]] = 'O';
                }
            }
       }

}

void eat(int player ,int next , int before , int point[]){ // in this function we nead postiont of player and point_(how mach he/she eat point ) of player

            int i , random_number;
            if (full_page[next] == '.'){

                point[player] += 1;     //each point have one value
                full_page[before] = ' ';
                tele_pos[player+2] = next ;
                while  (1){
                    random_number = rand() % (tele_pos[5] - 1) ; // we want to find random home that was empty
                    if (full_page[random_number] == ' '){
                            full_page[random_number] = '.' ;
                            break;
                    }
                }
            }
            else if (full_page[next] == 'F'){ // each big point have ten value

                point[player] += 10;
                full_page[before] = ' ';
                tele_pos[player+2] = next;
                while  (1){
                    random_number = rand() % (tele_pos[5] - 1) ;
                    if (full_page[random_number] == ' '){
                            full_page[random_number] = 'F' ;
                            break;
                    }

                }
            }
             else { // if next home was teleport we must put player on possition of other teleport and remove teleport and replace it place

                    for (i = 0; i < 2 ;i++){
                        if (tele_pos[i] != next)
                            tele_pos[player+2] = tele_pos[i];
                            full_page[before] = ' ';
                            full_page[next] = ' ';

                    }

                    for (i = 0 ; i  <= 1 ; i++){
                            random_number = rand() % (tele_pos[5] - 1) ;
                            if (full_page[random_number] == ' ' && random_number != tele_pos[player+2]){
                                    full_page[random_number] = 'T';
                                    tele_pos[i] = random_number ;
                                    }
                            else
                                i--;
                            }

            }
}








