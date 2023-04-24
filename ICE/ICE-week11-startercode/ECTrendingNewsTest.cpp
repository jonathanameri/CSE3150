#include "ECTrendingNews.h"
#include <vector>
#include <iostream>
using namespace std;

void ASSERT_EQ(int x, int y)
{
  if( x== y )
  {
    cout << "Match value: " << x << endl;
  }
  else
  {
    cout << "Mismatch: " << x << "  " << y << endl;
  }
}

void Test1()
{
  ECTrendingNews cbsNews;
  ASSERT_EQ(cbsNews.GetTotRevenue(),0);

  ECContractSubscriber cs1(cbsNews);
  ECPayPerClickSubscriber ps1(cbsNews);
  cbsNews.Subscribe(&cs1);
  ASSERT_EQ(cbsNews.GetTotRevenue(),100);
  cbsNews.Subscribe(&ps1);
  ASSERT_EQ(cbsNews.GetTotRevenue(),100);
}

void Test2()
{
  ECTrendingNews cbsNews;
  ECContractSubscriber cs1(cbsNews);
  ECPayPerClickSubscriber ps1(cbsNews);
  ECPayPerClickSubscriber ps2(cbsNews);
  cbsNews.Subscribe(&cs1);
  ASSERT_EQ(cbsNews.GetTotRevenue(),100);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),100);
  cbsNews.Subscribe(&ps1);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),101);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),102);
  cbsNews.Subscribe(&ps2);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),104);
  cbsNews.UnSubscribe(&ps2);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),105);

}

void Test3()
{
  ECTrendingNews cbsNews;
  ECContractSubscriber cs1(cbsNews);
  ECPayPerClickSubscriber ps1(cbsNews);
  cbsNews.Subscribe(&cs1);
  ASSERT_EQ(cbsNews.GetTotRevenue(),100);
  cbsNews.UnSubscribe(&cs1);
  cbsNews.Subscribe(&cs1);
  ASSERT_EQ(cbsNews.GetTotRevenue(),200);
  cbsNews.Subscribe(&ps1);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),201);
  cbsNews.UnSubscribe(&ps1);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),201);
  cbsNews.Subscribe(&ps1);
  cbsNews.Notify();
  ASSERT_EQ(cbsNews.GetTotRevenue(),202);

}

int main()
{
  Test1();
  Test2();
  Test3();
}

