#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <stack>
#include <fstream>
#define MOD 1000000007
#define LLMAX 9223372036854775807LL
using namespace std;
typedef long long ll;

string intToHex(int x) {
  string hexDigits = "0123456789ABCDEF";

  string ret = "";
  for(int i = 0; i < 2; i++) {
    ret = hexDigits[x % 16] + ret;
    x /= 16;
  }

  return ret;
}

int main() {

  string fileName = "input.in";
  // cin >> fileName;
  ifstream arcEnt(fileName);
  
  int n;
  cin >> n;
  vector<int> hashTable(n, 0);

  char endLine = '\n';
  string line;
  int it = 0;
  while(arcEnt >> line) {
    for(char c : line) {
      hashTable[it] = (hashTable[it] + c) % 256;
      it = (it + 1) % n;
    }

    // endline
    hashTable[it] = (hashTable[it] + endLine) % 256;
    it = (it + 1) % n;
  }

  // si no es multiplo
  for(int i = it; i < n; i++) {
    hashTable[i] = (hashTable[i] + n) % 256;
  }

  string ans = "";
  for(int hash : hashTable) {
    ans += intToHex(hash);
  }

  cout << ans << endl;
  
  arcEnt.close();

  return 0;
}
