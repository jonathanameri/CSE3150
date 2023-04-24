#include "ECSportsPlayer.h"
#include <iostream>
using namespace std;

// test code
void Test()
{
  // ATP Master series Indian Wells: held in March (3), rank 60 or higher
  ECTournament trATPMaster(3, 60);

  // create various players
  // player 1: rank 100. NOT qualified. 
  ECSportsPlayerRanked p1(100);
  bool f1 = p1.CanPlay(trATPMaster);
  if( f1 )
  {
    cout << "Player 1: qualified\n";
  }
  else
  {
    cout << "Player 1: NOT qualified\n";
  }
  // player 2: rank 10. Qualified.
  ECSportsPlayerRanked p2(10);
  bool f2 = p2.CanPlay(trATPMaster);
  if( f2 )
  {
    cout << "Player 2: qualified\n";
  }
  else
  {
    cout << "Player 2: NOT qualified\n";
  } 
  // player 3: rank 20, injured on March. NOT qualified.
  ECSportsPlayerRanked p3(20);
  ECSportsPlayerInjured p3i(p3, 3);
  bool f3 = p3i.CanPlay(trATPMaster);
  if( f3 )
  {
    cout << "Player 3: qualified\n";
  }
  else
  {
    cout << "Player 3: NOT qualified\n";
  }
  // player 4: rank 15, displined from Feb to April. NOT qualified.
  ECSportsPlayerRanked p4(15);
  ECSportsPlayerDisciplined p4d(p4, 2, 4);
  bool f4 = p4d.CanPlay(trATPMaster);
  if( f4 )
  {
    cout << "Player 4: qualified\n";
  }
  else
  {
    cout << "Player 4: NOT qualified\n";
  }  
  // player 5: rank 35, injured at June, Displined from Sept to November. Qualified.
  ECSportsPlayerRanked p5(35);
  ECSportsPlayerInjured p5i(p5, 6);
  ECSportsPlayerDisciplined p5id(p5i, 9, 11);
  bool f5 = p5id.CanPlay(trATPMaster);
  if( f5 )
  {
    cout << "Player 5: qualified\n";
  }
  else
  {
    cout << "Player 5: NOT qualified\n";
  }
  // player 6: rank 120, wild-card, injured at September. Qualified.
  ECSportsPlayerRanked p6(120);
  ECSportsPlayerWildcard p6w(p6);
  ECSportsPlayerInjured p6wi(p6w, 9);
  bool f6 = p6wi.CanPlay(trATPMaster);
  if( f6 )
  {
    cout << "Player 6: qualified\n";
  }
  else
  {
    cout << "Player 6: NOT qualified\n";
  }  
  // player 7: rank 150, disiplined between June to July, wild-card. Qualified.
  ECSportsPlayerRanked p7(150);
  ECSportsPlayerDisciplined p7i(p7, 6,7);
  ECSportsPlayerWildcard p7iw(p7i);
  bool f7 = p7iw.CanPlay(trATPMaster);
  if( f7 )
  {
    cout << "Player 7: qualified\n";
  }
  else
  {
    cout << "Player 7: NOT qualified\n";
  }
}

int main()
{
  Test();
}

