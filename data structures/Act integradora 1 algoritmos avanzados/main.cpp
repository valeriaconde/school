#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

string transmission1;
string transmission2;

// si el contenido de los archivos mcode1.txt, mcode2.txt y mcode3.,txt están contenidos en los archivos transmission1.txt y transmission2.txt 
void Zfunction(string str, int Z[]) {
	int n = str.length();
	int l = 0, r = 0, k;

	for (int i = 1; i < n; ++i) {
		if (i > r) {
			l = r = i;

			while (r<n && str[r-l] == str[r])	r++;
			
      Z[i] = r-l;
			r--;
		} else {
			k = i-l;

			if (Z[k] < r-i+1)	 {
        Z[i] = Z[k];
      } else {
				l = i;
				while (r<n && str[r-l] == str[r]) r++;

				Z[i] = r-l;
				r--;
			}
		}
	}
}

bool search(string text, string pattern) {
	string tmp = pattern + "$" + text;
	int l = tmp.length();

	int Z[l];
  Zfunction(tmp, Z);

  for (int i = 0; i < l; ++i) {
		if (Z[i] == pattern.length()) {
      cout << "true " << i - pattern.length() -1 << endl;
      return 1;
    }
	}
  return 0;
}

void findOcurrences() {
  ifstream mcode1("mcode1.txt");
  ifstream mcode2("mcode2.txt");
  ifstream mcode3("mcode3.txt");
  
  string line;
  while(getline(mcode1, line)) {
   if(!search(transmission1, line)) cout << "false" << endl;
  }

  while(getline(mcode2, line)) {
    if(!search(transmission1, line)) cout << "false" << endl;
  }

  while(getline(mcode3, line)) {
    if(!search(transmission1, line)) cout << "false"  << endl;
  }

  mcode1.close();
  mcode2.close();
  mcode3.close();

  mcode1.open("mcode1.txt");
  mcode2.open("mcode2.txt");
  mcode3.open("mcode3.txt");

  while(getline(mcode1, line)) {
    if(!search(transmission2, line)) cout << "false" << endl;
  }

  while(getline(mcode2, line)) {
    if(!search(transmission2, line)) cout << "false" << endl;
  }

 while(getline(mcode3, line)) {
    if(!search(transmission2, line)) cout << "false" << endl;
  }

  mcode1.close();
  mcode2.close();
  mcode3.close();
}

// Longest common palindrome 
vector <int> createLPS(string transmission){
	int n = transmission.size();
	vector <int> palindrome(n, 1);
	int left = 0;
	int right = -1;
	int current, j;
	for (int i = 0; i < n; i++){
		if (i > right) {
			current = 0;
			}
		else {
			j = left + right - i;
			current = min(palindrome[j], right - i);
			}
			while (i - current >= 0 && i + current < n && transmission[i - current] == transmission[i + current]) current++;
	
			if (transmission[i - current] != transmission[i + current]) current--;

			palindrome[i] = current;
			if (i + current > right){
				left = i - current;
				right = i + current;
			}
		}
	return palindrome;
}

void LongestCommonPalindrome(string transmission){
	string aux = "$";

	for (int i = 0; i < transmission.size(); i++){
		aux.push_back(transmission[i]);
		aux.push_back('$');
	}

	int len = 0;
	int index = 1;
	vector<int> longest_palindrome;

	longest_palindrome = createLPS(aux);

	for(int i = 0; i < longest_palindrome.size(); i++){
		if(longest_palindrome[i] > len){
			len = longest_palindrome[i];
			index = i - longest_palindrome[i];
		}
	}

	cout << index/2 <<" "<< index/2 + len - 1 <<endl;
}

// Longest common substring
pair<int, pair<int,int>> LCSubStr(string tr1, string tr2, int m, int n, vector<vector<int>> &LCSuff){ 
	int result = 0;
	int posX=0, posY=0 ;

	 for (int i = 0; i <= m; i++) { 
		 for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) LCSuff[i][j] = 0;

			else if (tr1[i - 1] == tr2[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				if (result < LCSuff[i][j]){
					result = LCSuff[i][j];
					posX = i;
					posY = j;
				}
			} else {
				LCSuff[i][j] = 0;
			}
		}
	}
	return make_pair(result, make_pair(posX, posY));
}

void LongestCommonSubstring (string tr1, string tr2){
	int m = tr1.size();    
	int n = tr2.size();

	vector<vector<int>> LCSuff(m + 1);
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			LCSuff[i].push_back(0);
		}
	}

	pair<int, pair<int,int>> result = LCSubStr(tr1, tr2, m, n, LCSuff);

	cout << result.second.first - result.first <<" "<< result.second.first-1 << endl;
	cout <<  result.second.second - result.first <<" "<< result.second.second-1 << endl;

}

string ReadFile (string file_name){
	ifstream file(file_name);
	string line; 
	string transmission;

	while (file >> line){
		if (!line.empty()){
			transmission += line + '\n';
		}
	}
	file.close();
	return transmission;
}

int main() {
  transmission1 = ReadFile("transmission1.txt");
	transmission2 = ReadFile("transmission2.txt");

  // Find occurences of malicious code inside transmission files - index 0
  findOcurrences();
	cout << endl;

	// Longest Common Palindrome for Transmission file #1 - index 0
	LongestCommonPalindrome(transmission1);

	// Longest Common Palindrome for Transmission file #2 - index 0
	LongestCommonPalindrome(transmission2);
	cout<< endl;

	// Longest Common Substring for both transmission files - index 0
	LongestCommonSubstring(transmission1, transmission2);

  return 0;
}