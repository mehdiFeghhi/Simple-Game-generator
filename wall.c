# include <stdlib.h>
extern char full_page[];
extern int tele_pos[];
void wall(int inform[]){
    extern int tele_pos[];
    extern char full_page[];
    int width = inform[0] ;
    int lenght = inform[1] ;
    int done = inform[3];
    int map = width*lenght;
    full_page[map] = '\0';
    int wr_page;
    for(wr_page = 0; wr_page < map ; wr_page++){
        if(wr_page % width == 0 || wr_page % width == width-1 || wr_page < width || wr_page > map - width )
            full_page[wr_page] = '!';
    }


    int block  = 4;
    while(inform[block] != -1){
        full_page[inform[block]+ inform[block+1] * width]= 'B';
        block += 2;

    }
    int random_number ;
    while  (done >= 0){
          random_number = rand() % (map - 1) ;
          if (full_page[random_number] == ' '){
                full_page[random_number] = '.' ;
                done-- ;
          }
    }
    int positon_of_teleAndPosi = 0 ;
    while ( positon_of_teleAndPosi < 2 ){
        random_number = rand() % (map - 1) ;
        if (full_page[random_number] == ' '){
            full_page[random_number] = 'T';
            tele_pos[positon_of_teleAndPosi] = random_number ;
            positon_of_teleAndPosi++ ;


        }
    }
    while (positon_of_teleAndPosi < 3){
        random_number = rand() % (map - 1) ;
        if (full_page[random_number] == ' '){

                full_page[random_number] = 'O' ;
                tele_pos[positon_of_teleAndPosi] = random_number ;
                positon_of_teleAndPosi++ ;
        }
    }
    while (positon_of_teleAndPosi < 4 ){
        random_number = rand() % (map - 1) ;
        if (full_page[random_number] == ' '){
                full_page[random_number] = 'X' ;
                tele_pos[positon_of_teleAndPosi] = random_number ;
                positon_of_teleAndPosi++ ;
        }
    }


    while (positon_of_teleAndPosi < 5 ){
        random_number = rand() % (map - 1) ;
        if (full_page[random_number] == ' '){
            full_page[random_number] = 'F' ;
            positon_of_teleAndPosi++ ;
        }
    }


    tele_pos[5]=map;

}

