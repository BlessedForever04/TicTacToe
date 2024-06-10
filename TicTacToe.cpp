#include <iostream>
using namespace std;
void xmove();
void ymove();
int updateboard(int r, int c, int n);
int validr(int r);
int validc(int c);
int main();
char board[3][3];
int r,c, factor;
void winning(){
    if((board[0][0]==board[0][1] && board[0][1] == board[0][2] && board[0][2] =='X' || board[1][0]==board[1][1] && board[1][1] == board[1][2] && board[1][2] =='X' || board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][2]=='X') || (board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[2][0]=='X' || board[0][1]==board[1][1]&& board[1][1]==board[2][1] && board[2][1]=='X' || board[0][2]==board[1][2]&& board[1][2]==board[2][2] && board[2][2]=='X') || (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]=='X' || board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]=='X')){
        cout<<"Player X won the game!!"; 
        factor = 1;
    }
    else{
        if((board[0][0]==board[0][1] && board[0][1] == board[0][2] && board[0][2] =='O' || board[1][0]==board[1][1] && board[1][1] == board[1][2] && board[1][2] =='O' || board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][2]=='O') || (board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[2][0]=='O' || board[0][1]==board[1][1]&& board[1][1]==board[2][1] && board[2][1]=='O' || board[0][2]==board[1][2]&& board[1][2]==board[2][2] && board[2][2]=='O') || (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]=='O' || board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]=='O')){
            cout<<"Player O won the game!!";
            factor = 1;
        }
        else{
            factor = 0;
        }
    }
}
void xmove(){
    cout<<"X's tern - "<<endl;
    cout<<"Enter row number: ";
    cin>>r;
    validr(r);
    cout<<"Enter column number: ";
    cin>>c;
    validc(c);
    updateboard(r,c,1);
}
void ymove(){
cout<<"Y's tern - "<<endl;
    cout<<"Enter row number: ";
    cin>>r;
    validr(r);
    cout<<"Enter column number: ";
    cin>>c;
    validc(c);
    updateboard(r,c,0);
}
int updateboard(int r, int c, int n){
    if(n == 1){
        if(board[r-1][c-1] == 'X' || board[r-1][c-1] == 'O'){
            cout<<"Can't overwrite, enter valid move"<<endl;
            xmove();
        }else{
        board[r-1][c-1] = 'X';
        }
    }
    else{
        if(board[r-1][c-1] == 'X' || board[r-1][c-1] == 'O'){
            cout<<"Can't overwrite, enter valid move"<<endl;
            ymove();
        }
        else{
        board[r-1][c-1] = 'O';
        }
    }
}
int validr(int r){
    if(r != 1 && r!=2 && r!=3){
        cout<<"Enter valid input!"<<endl;
        cout<<"Enter row number: ";
        cin>>r;
        validr(r);
    }
}
int validc(int c){
    if(c != 1 && c!=2 && c!=3){
        cout<<"Enter valid input!"<<endl;
        cout<<"Enter row number: ";
        cin>>c;
        validr(c);
    }
}
void display(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] == 'A'){
                if(j!=2)
                cout<<"   |";
                else{
                    cout<<"   ";
                }
            }
            else{
                if(j!=2){
                cout<<" "<<board[i][j]<<" |";
                }
                else{
                    cout<<" "<<board[i][j]<<" ";
                }
            }
            }cout<<endl;
            if(i!=3){
            }
        }
}
void endgame(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] == 'A'){
                break;
            }
            else{
                if(i==2 && j==2){    
                cout<<"No one won, would you like to continue?"<<endl;
                cout<<"1 - continue     2 - Exit"<<endl;
                int decision;
                cin>>decision;
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
void game(){
    display();
    while(factor == 0){
    xmove();
    display();
    winning();
    if(factor == 1){
        break;
    }
    else{
    endgame();
        if(factor == 0){
        ymove();
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

    cout<<"               Welcome to the game of TicTacToe"<<endl;
    cout<<"This is two players game where you require one friend for playing it"<<endl;
    game();
}
