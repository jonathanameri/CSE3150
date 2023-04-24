#include "ECMazeGame.cpp"   // Hack!
#include <iostream>
using namespace std;

int main()
{
  MazeGame game1;
  game1.CreateMaze();
  //ASSERT_EQ(game1.GetTotPrize(),2);
  cout << "game1 prize: " << game1.GetTotPrize() << endl;

  BombedMazeGame game2;
  game2.CreateMaze();
  //ASSERT_EQ(game2.GetTotPrize(),-20);
  cout << "game2 prize: " << game2.GetTotPrize() << endl;

  EnchantedMazeGame game3;
  game3.CreateMaze();
  //ASSERT_EQ(game3.GetTotPrize(),40);
  cout << "game3 prize: " << game3.GetTotPrize() << endl;
}
