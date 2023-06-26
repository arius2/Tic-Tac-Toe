#include <bits/stdc++.h>
using namespace std;

// creating a class to place main functions in
class TicTacToe
{
  char draw[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // an array to draw the checkboard
  int Cdraw[9];                                                 // an array to store the value of each checkboard

public:
  int turn = 0; // to decide if it is X's Turn or O's Turn

  void setX(int a) // will be used to set the value of X in a the/ checkboard
  {
    if (draw[a] == 'X' || draw[a] == 'O')
    {
      cout << endl
           << "INVALID. TRY AGAIN" << endl;
    }
    else
    {
      draw[a] = 'X';
      turn = 1;
      Cdraw[a] = 1;
    }
  }
  void setO(int b) // will be used to set the value of O in the checkboard
  {
    if (draw[b] == 'X' || draw[b] == 'O')
    {
      cout << endl
           << "INVALID. TRY AGAIN" << endl;
    }
    else
    {
      draw[b] = 'O';
      turn = 0;
      Cdraw[b] = 2;
    }
  }

  void Draw(void) // a function to draw the checkboard in
  {
    cout << endl
         << ' ' << draw[0] << ' ' << '|' << ' ' << draw[1] << ' ' << '|' << ' ' << draw[2] << endl;
    cout << "---|---|---" << endl;
    cout << ' ' << draw[3] << ' ' << '|' << ' ' << draw[4] << ' ' << '|' << ' ' << draw[5] << endl;
    cout << "---|---|---" << endl;
    cout << ' ' << draw[6] << ' ' << '|' << ' ' << draw[7] << ' ' << '|' << ' ' << draw[8] << endl
         << endl;
  }

  bool CheckWin() // function to check who won
  {
    if ((Cdraw[0] == 1 && Cdraw[1] == 1 && Cdraw[2] == 1) || (Cdraw[3] == 1 && Cdraw[4] == 1 && Cdraw[5] == 1) || (Cdraw[6] == 1 && Cdraw[7] == 1 && Cdraw[8] == 1) || (Cdraw[0] == 1 && Cdraw[3] == 1 && Cdraw[6] == 1) || (Cdraw[1] == 1 && Cdraw[4] == 1 && Cdraw[7] == 1) || (Cdraw[2] == 1 && Cdraw[5] == 1 && Cdraw[8] == 1) || (Cdraw[0] == 1 && Cdraw[4] == 1 && Cdraw[8] == 1) || (Cdraw[2] == 1 && Cdraw[4] == 1 && Cdraw[6] == 1))
    {
      return true;
    }
    if ((Cdraw[0] == 2 && Cdraw[1] == 2 && Cdraw[2] == 2) || (Cdraw[3] == 2 && Cdraw[4] == 2 && Cdraw[5] == 2) || (Cdraw[6] == 2 && Cdraw[7] == 2 && Cdraw[8] == 2) || (Cdraw[0] == 2 && Cdraw[3] == 2 && Cdraw[6] == 2) || (Cdraw[1] == 2 && Cdraw[4] == 2 && Cdraw[7] == 2) || (Cdraw[2] == 2 && Cdraw[5] == 2 && Cdraw[8] == 2) || (Cdraw[0] == 2 && Cdraw[4] == 2 && Cdraw[8] == 2) || (Cdraw[2] == 2 && Cdraw[4] == 2 && Cdraw[6] == 2))
    {

      return true;
    }
    return false;
  }

  void WinX() // What to print if X won
  {
    cout << endl
         << "X WON! THANK YOU FOR PLAYING!" << endl;
    turn = -1;
  }
  void WinY() // What to print if O won
  {
    cout << endl
         << "O WON! THANK YOU FOR PLAYING!" << endl;
    turn = -1;
  }

  bool check_draw() // To check if the game ends in draw
  { 
    int count=0;
    for(int i=0;i<9;i++){
      if(draw[i] == 'X' || draw[i] == 'O')
            count++;
    }
    if (count==9 && !CheckWin())
      return true;
    else
      return false;
  }

  void Game_Draw() // what to print if game ends in draw
  {
    cout << endl
         << "DRAW." << endl;
    turn = -1;
  }
};

int main()
{

  TicTacToe a; // creating an object to play the game

  // a.Draw();

  cout << endl
       << "WELCOME TO TIC TAC TOE" << endl
       << "SELECT A NUMBER IN EACH TURN FROM 1 TO 9 TO PLACE X AND O RESPECTIVELY." << endl;
  //  Select a number in each turn to place X and O respectively.

  int X, O; // to take in value put in by X and O

  while (a.turn != -1) // when turn is 0, it will be X's turn, when turn is 1, it will be Y's turn, when turn is -1, game will end
  {
    a.Draw();
    if (a.turn == 0)
    {
      cout << endl
           << "X's TURN" << endl;
      cin >> X;
      if (X > 0 && X < 10)
      {
        a.setX(X - 1);
        if (a.CheckWin())
        {

          a.Draw();
          a.WinX();
        }

        else if (a.check_draw())
        {
          a.Draw();
          a.Game_Draw();
        }
      }
      else
      {
        cout << endl
             << "INVALID. TRY AGAIN";
        a.turn = -1;
      }
    }
    else
    {
      cout << endl
           << "O's TURN" << endl;
      cin >> O;
      if (O > 0 && O < 10)
      {
        a.setO(O - 1);
        if (a.CheckWin())
        {

          a.Draw();
          a.WinY();
        }
        else if (a.check_draw())
        {
          a.Draw();
          a.Game_Draw();
        }
      }
      else
      {
        cout << endl
             << "INVALID. TRY AGAIN" << endl;
        a.turn = -1;
      }
    }
  }
  system("pause");
  return 0;
}
