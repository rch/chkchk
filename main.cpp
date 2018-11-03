#include "grid.h"
#include <iostream>

void show (std::vector <char> game) {
  int x=0;
  while(x<3) {
    std::cout<<game.at(x);
    ++x;
  }
}

bool check_invalid (unsigned int a, unsigned int b, char X, char O) {
  if (a>2) {std::cout<<"invalide move!"; return true;}
  if (b>2) {std::cout<<"invalide move!"; return true;}
  if (grid(a,b)==O || grid(a,b)==X) {std::cout<<"invalid move!"; return true;}
  return false;
}

bool check_right(std::vector <char> game) {
  for (int v=0;v<3;++v) {
     if (game[v]=='_') {
       return false;
     }
  }
  return true;
}

//to do: make it check the game right, even with '_'
void cout_grid() {
  std::cout<<grid(0,0)<<" "<<grid(0,1)<<" "<<grid(0,2)<<std::endl;
  std::cout<<grid(1,0)<<" "<<grid(1,1)<<" "<<grid(1,2)<<std::endl;
  std::cout<<grid(2,0)<<" "<<grid(2,1)<<" "<<grid(2,2)<<std::endl;
}

void assigne_value_O (int a, int b, char O) {
  grid(a,b)=O;
  std::cout<<"assigne_value_O: " << a << " " << b << std::endl;
  cout_grid();
}

void assigne_value_X (int a,int b, char X) {
  grid(a,b)=X;
  std::cout<<"assigne_value_X: " << a << " " << b << std::endl;
  cout_grid();
}

void check_game (char X) {
    std::vector<char> game;
    //horizontal
    for (unsigned int x=0;x<3;++x) {
        for (unsigned int y=0; y<3; ++y) {
            game.push_back(grid(x,y));
        }
        if (game[0]==game[1] && game[1]==game[2]) {
            if (check_right(game)) {
                if (game[0]==X) {
                    std::cout<<"X won!";
                } else {
                    std::cout<<"O won!";
                }
                exit(0);
            }
        }
        game.clear();
    }
    std::cout << "check_game //vertikal: " << std::endl;
    //vertikal
    for (unsigned int y=0; y<3 ; ++y ) {
        for (unsigned int x=0; x<3 ; ++x) {
            game.push_back (grid (x,y));
        }
        if (game[0] == game[1] && game[0] == game[2]) {
            if (check_right(game)) {
                if (game[0]==X) {
                    std::cout<<"X won!";
                } else {
                    std::cout<<"0 won!";
                }
                exit(0);
            }
        }
        game.clear();
    }
    std::cout << "check_game //diagonal(\\): " << std::endl;
    //diagonal
    if ((grid(0,0)==grid(1,1) && grid(0,0)==grid(2,2))) {
        game.push_back(grid(0,0));
        game.push_back(grid(1,1));
        game.push_back(grid(2,2));
        if (check_right(game)) {
            if (grid(1,1)==X) {
                std::cout<<"X won!";
            } else {
                std::cout<<"O won!";
            }
            exit(0);
        }
    }
    std::cout << "check_game //diagonal(/): " << std::endl;
    if (grid(0,2)==grid(1,1) && grid(1,1)==grid(2,0)) {
        game.push_back(grid(0,2));
        game.push_back(grid(1,1));
        game.push_back(grid(2,0));
        if (check_right(game)) {
            if (grid(1,1)==X) {
                std::cout<<"X won!";
            } else {
                std::cout<<"O won!";
            }
            exit(0);
        }
    }
} // check_game


int main() {

cout_grid();

char O='O';
char X='X';
unsigned int a;
unsigned int b;
unsigned int i;
//bool check=false; //mit funktion check is valid das spiel überprüfen
for (i=1; i<10  ;++i){
  if (i%2==0) {
    std::cin>>a>>b;
      while(check_invalid(a,b,O,X)) { //gives ouput and new input and go again
        std::cin>>a>>b;               //as long as it's true.
      }
    assigne_value_X(a,b,X);
    check_game(X);
  } else {
    std::cin>>a>>b;
     while(check_invalid(a,b,O,X)) { //gives ouput and new input and go again
        std::cin>>a>>b;               //as long as it's true.
      }
    assigne_value_O(a,b,O);
    check_game(X);
  }
}

std::cout<<"draw!";
  return 0;
}
