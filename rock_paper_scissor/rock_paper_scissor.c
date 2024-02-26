#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MAX_LIMIT 20

int game(char choice);

int main(){
char player1[MAX_LIMIT];
char player2[MAX_LIMIT];
char choice;
// int player1points = 0;
// int player2points = 0;
   printf("プレーやー１、お名前を加入して下さい: ");
   if (fgets(player1, MAX_LIMIT, stdin) == NULL) { 
    printf("Fail to read the input stream"); 
   } 
   else { 
    player1[strcspn(player1, "\n")] = '\0'; 
   }
   sleep(1);
   printf("こんにちは %sさん\n", player1);
   printf("コンピューターの名前を加入してください: ");   
   if (fgets(player2, MAX_LIMIT, stdin) == NULL) { 
    printf("Fail to read the input stream"); 
   } 
   else { 
    player2[strcspn(player2, "\n")] = '\0'; 
   } 
   fflush(stdin);
   sleep(1);
   printf("いらっしゃいませ %sさん\n", player2);
   sleep(6);
   printf("では、ゲームを始まります\n");
   sleep(2);
   printf("s は グー, p は パー、z はチョキになっております、一つ選んで下さい");
   scanf(" %c", &choice);
   sleep(1);
   int result = game(choice);
   sleep(1);
return 0;
}

//User wins, returns 1
//Computer wins, returns 0
//If it is a tie, returns -1
int game(char choice){
    srand(time(NULL));
    int player_num;
    int cpu_num; 

//Determine the choice of the humnan player
    if(choice == 's'){ 
        printf("あなたは グー を選びました\n"); 
        player_num = 0;
    }
    if(choice == 'p'){
        printf("あなたは パー を選びました\n"); 
        player_num = 1;
    }
    if(choice == 'z'){
        printf("あなたは チョキ を選びました\n"); 
        player_num = 2;
    }

    sleep(1);

//Determine the choice of the CPU
    int cpu_choice = rand() % 100 + 1;
    if (cpu_choice <= 33){
        printf("コンピューターは グー を選びました\n");
        cpu_num = 0;
    }
    else if(cpu_choice <= 66){
        printf("コンピューターは パー を選びました\n"); 
        cpu_num = 1;
    }
    else if(cpu_choice <= 100){
        printf("コンピューターは チョキ を選びました\n"); 
        cpu_num = 2;
    }

    sleep(1);

//Detrmine the result of the game
    if (player_num == cpu_num){
        printf("相子でしょ、また加入して下さい");
        scanf(" %c", &choice);
        game(choice);
        return -1;
    }
    else if(player_num == cpu_num + 1 || (player_num == 0 && cpu_num == 2)){
        printf("あなたが勝ちました\n");
        return 1;
    }
    else if(cpu_num == player_num + 1|| (cpu_num == 0 && player_num == 2)){
        printf("コンピューターが勝ちました\n");
        return 0;
    }
}

//A char neeeds to be used instead of string because no such thing exists in C

