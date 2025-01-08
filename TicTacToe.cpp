#include <iostream>
#include <cstdlib>


//Forward declarations
void Xmove(); // Function to input X's move
void Omove(); // Function to input O'x move
int updateboard(int row, int column, int n); // Function to update board
int ValidMove(int row); // Function to valid move
int main(); // Main function is used in other function, called here for maintaining scope

//Global variables
char board[3][3];
int row,column, factor;

// Function to check if player is won
void winning(){
    if((board[0][0]==board[0][1] && board[0][1] == board[0][2] && board[0][2] =='X' || board[1][0]==board[1][1] && board[1][1] == board[1][2] && board[1][2] =='X' || board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][2]=='X') || (board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[2][0]=='X' || board[0][1]==board[1][1]&& board[1][1]==board[2][1] && board[2][1]=='X' || board[0][2]==board[1][2]&& board[1][2]==board[2][2] && board[2][2]=='X') || (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]=='X' || board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]=='X')){
        std::cout<<"Player X won the game!!"; 
        factor = 1;
    }
    else{
        if((board[0][0]==board[0][1] && board[0][1] == board[0][2] && board[0][2] =='O' || board[1][0]==board[1][1] && board[1][1] == board[1][2] && board[1][2] =='O' || board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][2]=='O') || (board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[2][0]=='O' || board[0][1]==board[1][1]&& board[1][1]==board[2][1] && board[2][1]=='O' || board[0][2]==board[1][2]&& board[1][2]==board[2][2] && board[2][2]=='O') || (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]=='O' || board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]=='O')){
            std::cout<<"Player O won the game!!";
            factor = 1;
        }
        else{
            factor = 0;
        }
    }
}

// Xmove() funtion validates X's move
void Xmove(){
    std::cout<<"X's tern - "<<std::endl;
    std::cout<<"Enter row number: ";
    std::cin>>row;
    ValidMove(row);
    std::cout<<"Enter column number: ";
    std::cin>>column;
    ValidMove(column);
    updateboard(row,column,1);
    system("cls");
}

//Reason to make 2 different function i.e Xmove and Omove is because updateboard function is passed with integer (0 or 1)
//which defines is function is called from X's turn or O's turn, 1 is passed to make sure it's X's move, 0 for O's move

// Omove() function validates O's move
void Omove(){
std::cout<<"Y's tern - "<<std::endl;
    std::cout<<"Enter row number: ";
    std::cin>>row;
    ValidMove(row);
    std::cout<<"Enter column number: ";
    std::cin>>column;
    ValidMove(column);
    updateboard(row,column,0);
    system("cls");
}

// Update function is called after each move to update the board
int updateboard(int row, int column, int n){
    // n represents from where the function is called, 1 == X's move, 0 == O's move.
    if(n == 1){
        if(board[row-1][column-1] == 'X' || board[row-1][column-1] == 'O'){
            std::cout<<"Can't overwrite, enter valid move"<<std::endl;
            Xmove();
        }else{
        board[row-1][column-1] = 'X';
        }
    }
    else{
        if(board[row-1][column-1] == 'X' || board[row-1][column-1] == 'O'){
            std::cout<<"Can't overwrite, enter valid move"<<std::endl;
            Omove();
        }
        else{
        board[row-1][column-1] = 'O';
        }
    }
}

// ValidMove() checks if the entered move is correct or not
int ValidMove(int Move){
    if(Move != 1 && Move!=2 && Move!=3){
        std::cout<<"Enter valid input!"<<std::endl;
        std::cout<<"Move: ";
        std::cin>>Move;
        ValidMove(Move);
    }
}

// Display() function to print the whole board along with current positions
void display(){
    std::cout<<"               Welcome to the game of TicTacToe"<<std::endl;
    std::cout<<"This is two players game where you require one friend for playing it"<<std::endl;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] == 'A'){
                if(j!=2)
                std::cout<<"   |";
                else{
                    std::cout<<"   ";
                }
            }
            else{
                if(j!=2){
                std::cout<<" "<<board[i][j]<<" |";
                }
                else{
                    std::cout<<" "<<board[i][j]<<" ";
                }
            }
        }
        std::cout<<std::endl;
    }
}
// enggame() function is checked if the board is completely filled, if it's filled and no winning condition is matched, game repeats
void endgame(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] == 'A'){
                break;
            }
            else{
                if(i==2 && j==2){    
                    std::cout<<"No one won, would you like to continue?"<<std::endl;
                    std::cout<<"1 - continue     2 - Exit"<<std::endl;
                    int decision;
                    std::cin>>decision;
                    if(decision==1){
                        main();
                    }
                    else{
                        factor = 5;
                    }
                }
            }
        }
    }
}

// main game function where game is played with tall the move, display, winning and endgame functions
void game(){
    display();
    while(factor == 0){
        Xmove();
        display();
        winning();
        if(factor == 1){
            break;
        }
        else{
            endgame();
            if(factor == 0){
                Omove();
                display();
                winning();
            }
        }
    }
}

int main(){
    factor = 0;
    for(int i = 0; i <3; i++){
        for(int j = 0; j<3; j++){
            board[i][j] = 'A';
        }
    }
    game();
}
// Thanks for reading the code
// code can be improved using classes and objects (Object oriented scope);