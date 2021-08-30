// Daniela Garza A00829404
// Valeria Conde A01281637
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

const int ERR = 999;
map<int, vector<int>> matrix;
map<int, string> tipos;


// returns column from matrix 
int filter(char c) {
  if (c >= '0' && c <= '9') return 0;
  if (c == '.') return 1;
  if (c == 'e' || c == 'E') return 2;
  if (c == '-') return 3; 
  if (c == '+' || c == '*' || c == '=' || c == '^' || c == '(' || c == ')') return 4;
  if (c == ' ') return 5;
  if (c == '/') return 6;
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 7;
  if (c == '_') return 8;
  return 9;
}

void lexerAritmetico(string fileName) {
  ifstream txtFile(fileName);
  // reads line by line from file
  string line;
  //do something with string
  while(getline(txtFile, line)) {
    int index = 0; 
    int lastState;
    while (index < line.size()) {
      string tmp = "";
      int state = 0;
      do {
        char c = line[index];
        index++;
        state = matrix[state][filter(c)];
        if (state != 0) {
          if (state != ERR) {
            tmp += c; lastState = state;
            } else index--;
        }
      } while (index < line.length() && state != ERR);
      cout << tmp << "  " << tipos[lastState] << endl;
    }
  }
  txtFile.close();
}

void buildMatrix(){
  matrix[0] = {100, ERR, 101, 102, 102, 0, 103, 101, ERR, ERR};
  matrix[100] = {100, 1, 2, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[101] = {101, ERR, ERR, ERR, ERR, ERR, ERR, 101, 101, ERR};
  matrix[102] = {ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[103] = {ERR, ERR, ERR, ERR, ERR, ERR, 104, ERR, ERR, ERR};
  matrix[1] = {105, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[2] = {106, ERR, ERR, 3, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[104] = {104, 104, 104, 104, 104, 104, 104, 104, 104, 104};
  matrix[105] = {105, ERR, 2, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[3] = {106, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  matrix[106] = {106, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR};
  tipos[100] = "Entero"; 
  tipos[101] = "Variable";
  tipos[102] = "Operador";
  tipos[103] = "División";
  tipos[104] = "Comentario";
  tipos[106] = "Potencia";
  tipos[105] = "Flotante";
}


int main() {
  buildMatrix();
  string fileName = "archivo.txt";
  lexerAritmetico(fileName);
  return 0;
}