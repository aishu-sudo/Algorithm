#include <bits/stdc++.h>
using namespace std;
#define DNA_size 700

string daughter_DNA = "";
string girl_DNA[7];

int LCS(string &test_DNA)
{
  int lcs_table[DNA_size + 1][DNA_size + 1];
  for (int i = 0; i <= DNA_size; i++)
  {
    for (int j = 0; j <= DNA_size; j++)
    {
      if (i == 0 || j == 0)
        lcs_table[i][j] = 0;
      else if (daughter_DNA[i - 1] == test_DNA[j - 1])
        lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
      else
        lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
    }
  }
  int index = lcs_table[DNA_size][DNA_size];
  return index;
}

int main()
{
  string string_sequence[4] = {"AT", "TA", "CG", "GC"};
  srand(time(NULL));
  for (int i = 0; i < DNA_size / 2; i++)
  {
    int randNum = rand() % 4;
    daughter_DNA = daughter_DNA + string_sequence[randNum];
  }
  cout << "Annie's daughter's DNA :" << endl << daughter_DNA << endl;
  for (int j = 0; j < 7; j++)
  {
    for (int i = 0; i < DNA_size / 2; i++)
    {
      int randNum = rand() % 4;
      girl_DNA[j] = girl_DNA[j] + string_sequence[randNum];
    }
  }
  vector<int> lcs_size;
  int match = 0;
  double maxi = 0;
  for (int i = 0; i < 7; i++)
  {
    lcs_size.push_back(LCS(girl_DNA[i]));
    double accuracy = ((double)lcs_size[i] / daughter_DNA.size()) * 100;
    if (accuracy >= maxi)
    {
      maxi = accuracy;
      match = i;
    }
    cout << "Accuracy of girl " << i + 1 << " with Annie's daughter is " << accuracy << "%" << endl;
  }
  cout << endl;
  cout << "The highest accuracy is " << maxi << "%" << endl;
  cout << "Girl " << match + 1 << " is the most likely match to be Annie's daughter." << endl;
}
