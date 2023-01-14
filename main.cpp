#include <iostream>
#include <string>
using namespace std;

bool checkWinner(char list[3][3]){
    if((list[0][0] == list[1][1] && list[0][0] == list[2][2] && list[1][1] == list[2][2]) && (list[0][0] != ' ' && list[1][1] != ' ' && list[2][2] != ' ')){
        return true;
    }
    if((list[0][0] == list[0][1] && list[0][0] == list[0][2] && list[0][1] == list[0][2]) && (list[0][0] != ' ' && list[0][1] != ' ' && list[0][2] != ' ')){
        return true;
    }
    if((list[1][0] == list[1][1] && list[1][0] == list[1][2] && list[1][1] == list[1][2]) && (list[1][0] != ' ' && list[1][1] != ' ' && list[1][2] != ' ')){
        return true;
    }
    if((list[2][0] == list[2][1] && list[2][0] == list[2][2] && list[2][1] == list[2][2]) && (list[2][0] != ' ' && list[2][1] != ' ' && list[2][2] != ' ')){
        return true;
    }
    if((list[0][0] == list[1][0] && list[0][0] == list[2][0] && list[1][0] == list[2][0]) && (list[0][0] != ' ' && list[1][0] != ' ' && list[2][0] != ' ')){
        return true;
    }
    if((list[0][1] == list[1][1] && list[0][1] == list[2][1] && list[1][1] == list[2][1]) && (list[0][1] != ' ' && list[1][1] != ' ' && list[2][1] != ' ')){
        return true;
    }
    if((list[0][2] == list[1][2] && list[0][2] == list[2][2] && list[1][2] == list[2][2]) && (list[0][2] != ' ' && list[1][2] != ' ' && list[2][2] != ' ')){
        return true;
    }
    if((list[0][2] == list[1][1] && list[0][2] == list[2][0] && list[1][1] == list[2][0]) && (list[0][2] != ' ' && list[1][1] != ' ' && list[2][0] != ' ')){
        return true;
    }
    return false;
}

void print(char list[3][3]){
    cout<<"Current board: "<<endl;
    cout<<" "<<list[0][0]<<" | "<<list[0][1]<<" | "<<list[0][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<list[1][0]<<" | "<<list[1][1]<<" | "<<list[1][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<list[2][0]<<" | "<<list[2][1]<<" | "<<list[2][2]<<endl;
}

bool checkFormat(string locationInput){
    bool first;
    bool second;
    bool third;
    if(locationInput[0] == '1' || locationInput[0] == '2' || locationInput[0] == '3'){
        first = true;
    }else{
        first = false;
    }
    if(locationInput[2] == '1' || locationInput[2] == '2' || locationInput[2] == '3'){
        second = true;
    }else{
        second = false;
    }
    if(locationInput[1] == '-'){
        third = true;
    }else{
        third = false;
    }
    if(first && second && third){
        return true;
    }
    return false;
}

void playerMove(string name, char symbol, char list[3][3]){
    string location;


    while(true){
        if(symbol == 'X'){
            cout<<name<<", please enter your move: ";
            cin>>location;
        }
        if(symbol == 'O'){
            cout<<name<<", please enter your move: ";
            cin>>location;
        }
        if(checkFormat(location)){
            char xLocation = location[0];
            char yLocation = location[2];
            int x =  (int)xLocation - 48;
            int y = (int)yLocation - 48;
            if(list[x - 1][y - 1] == ' ' && symbol == 'X'){
                list[x - 1][y -1] = symbol;
                break;
            }else if(list[x - 1][y - 1] == ' ' && symbol == 'O'){
                list[x - 1][y - 1] = symbol;
                break;
            }else{
                cout<<"That location is already full!"<< endl;
                continue;
            }
        }else{
            cout<<"Please enter correct move format!"<<endl;
            continue;
        }
    }

}

void playGame(string p1Name, char firstSign, string p2Name, char secondSign, int & p1Score, int & p2Score){
    char board[3][3] ={{' ',' ',' '},{' ',' ',' '}, {' ',' ',' '} };
    print(board);
    int moveCounter = 0;
    while(true){
        playerMove(p1Name, firstSign, board);
        moveCounter++;
        if(checkWinner(board)){
            cout<<p1Name<<" is the winner!"<<endl;
            p1Score++;
            break;
        }
        if(moveCounter >= 9){
            cout <<"The game ended in a draw!" << endl;
            break;
        }
        print(board);


        playerMove(p2Name, secondSign, board);
        moveCounter++;
        if(checkWinner(board)){
            cout<<p2Name<<" is the winner!"<<endl;
            p2Score++;
            break;
        }
        print(board);
    }

}

int main() {
    string p1name, p2name;
    cout<<"Welcome to Tic-Tac-Toe!"<<endl;
    cout<<"Player 1, please enter your name: ";
    cin>>p1name;
    cout<<"Hello, "<<p1name<<". You are going to play with X"<<endl;
    cout<<"Player 2, please enter your name: ";
    cin>>p2name;
    cout<<"Hello, "<<p2name<<". You are going to play with O"<<endl;
    cout<<endl;


    int playerOneScore = 0, playerTwoScore = 0;

    cout<<"Starting a new game..."<<endl;
    playGame(p1name, 'X', p2name, 'O', playerOneScore, playerTwoScore);
    cout<<"Current Scores: "<<endl;
    cout<<p1name<<": "<<playerOneScore<<"   "<<p2name<<": "<<playerTwoScore<<endl<<endl;
    cout<<"Starting a new game..."<<endl;
    playGame(p2name, 'O', p1name, 'X', playerTwoScore, playerOneScore);
    cout<<"Current Scores: "<<endl;
    cout<<p1name<<": "<<playerOneScore<<"   "<<p2name<<": "<<playerTwoScore<<endl<<endl;


    cout<<"Final Scores: "<<endl;
    cout<<p1name<<": "<<playerOneScore<<"   "<<p2name<<": "<<playerTwoScore<<endl;


    if(playerOneScore == playerTwoScore){
        cout<<"The overall game ended in a draw!"<<endl;
    }else if(playerOneScore > playerTwoScore){
        cout<<p1name<<" is the overall winner!"<<endl;
    }else{
        cout<<p2name<<" is the overall winner!"<<endl;
    }
    return  0;
}


