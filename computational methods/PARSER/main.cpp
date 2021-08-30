// Daniela Garza A00829404
// Valeria Conde A01281637
/*
Gramatica:
assignation: varID = EXP
EXP: term = term((+|-) term)*
term: factor((*|/|^)factor)*
factor: "(" EXP ")" | (+|-)? constant
constant: varID | int | real
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

const int ERR = 999;
const int INTEGER = 100;
const int VARID = 101;
const int OPERATOR = 102;
const int DIVISION = 103;
const int COMMENT = 104;
const int POWER = 106;
const int FLOAT = 105;
map<int, vector<int>> matrix;
map<int, string> tipos;
vector<string> token;
vector<int> tipoToken;
int index = 0;

ofstream outDoc;

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

void match(string tkn) {
  if(token[index] == tkn) {
    index++;
  } else {
    cout << "ERROR PARSING" << endl;
    outDoc << "<label class=\"error\"> ERROR PARSING </label>\n";
    outDoc << "</body>" << endl;
    outDoc << "</html>" << endl;
    outDoc.close();
    exit(0);
  }
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
      
      //saves token and type in vectors
      token.push_back(tmp);
      tipoToken.push_back(lastState);
    }
    // marks to know the end of line
    token.push_back("$");
    tipoToken.push_back(0);
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
  tipos[INTEGER] = "Entero"; 
  tipos[VARID] = "Variable";
  tipos[OPERATOR] = "Operador";
  tipos[DIVISION] = "División";
  tipos[COMMENT] = "Comentario";
  tipos[POWER] = "Potencia";
  tipos[FLOAT] = "Flotante";
}

// grammar matching functions
void constant() {
  if(tipoToken[index] == VARID) {
    outDoc << "<label class=\"variable\">" << token[index] << "</label>\n";
    match(token[index]);
  } else if (tipoToken[index] == INTEGER) {
    outDoc << "<label class=\"integer\">" << token[index] << "</label>\n";
    match(token[index]);
  } else if (tipoToken[index] == FLOAT) {
    outDoc << "<label class=\"float\">" << token[index] << "</label>\n";
    match(token[index]);
  } else if (tipoToken[index] == POWER) {
    outDoc << "<label class=\"power\">" << token[index] << "</label>\n";
    match(token[index]);
  }
}

void exp();

void factor() {
  if(token[index] == "(") {
    outDoc << "<label class=\"operator\"> ( </label>\n";
    match("(");
    exp();
    outDoc << "<label class=\"operator\"> ) </label>\n";
    match(")");
  } else if(token[index] == "+"){
    outDoc << "<label class=\"operator\"> + </label>\n";
    match("+");
    constant();
  } else if(token[index] == "-") {
    outDoc << "<label class=\"operator\"> - </label>\n";
    match("-");
    constant();
  } else {
    constant();
  }
}

void term() {
  factor();
  while(token[index] == "*" || token[index] == "/" || token[index] == "^") {
    if(token[index] == "*") {
      outDoc << "<label class=\"operator\"> * </label>\n";
      match("*");
    } else if (token[index] == "/") {
      outDoc << "<label class=\"operator\"> / </label>\n";
      match("/");
    } else if (token[index] == "^") {
      outDoc << "<label class=\"operator\"> ^ </label>\n";
      match("^");
    }
    factor();
  }
}

void exp() {
  term();
  while(token[index] == "+" || token[index] == "-") {
    if(token[index] == "+") {
      outDoc << "<label class=\"operator\"> + </label>\n";
      match("+");
    } else if (token[index] == "-") {
      outDoc << "<label class=\"operator\"> - </label>\n";
      match("-");
    }
    term();
  }
}

void assignation() {
  if(tipoToken[index] == VARID) {
    outDoc << "<label class=\"variable\">" << token[index] << "</label>\n";
    match(token[index]);
    outDoc << "<label class=\"operator\"> = </label>\n";
    match("=");
    exp();
  }
}

void parser() {
  outDoc.open("index.html");
  outDoc << "<!DOCTYPE html>" << endl;
  outDoc << "<html>" << endl;
  outDoc << "<head>" << endl;
  outDoc << "<title>Resaltador de Sintaxis</title>" << endl;

  outDoc << "<style>" << endl;
  outDoc << ".integer {color:#002eff;}" << endl;
  outDoc << ".variable {color:#ff0095;}" << endl;
  outDoc << ".operator {color:#00bcff;}" << endl;
  outDoc << ".divison {color:#abdf20;}" << endl;
  outDoc << ".comment {color:#0ca146;}" << endl;
  outDoc << ".power {color:#ffcc00;}" << endl;
  outDoc << ".float {color:#ca00ff;}" << endl;
  outDoc << ".error {color:#ed1225}" << endl;
  outDoc << "</style>" << endl;

  outDoc << "</head>" << endl;
  outDoc << "<body>" << endl;

  while(index < token.size()) {
    assignation();
    if (tipoToken[index] == COMMENT) {
      outDoc << "<label class=\"comment\">" << token[index] << "</label>\n";
      match(token[index]);
    }
    if(token[index] == "$") {
      match("$");
      outDoc << "</br>" << endl;
    } else {
      cout << "ERROR PARSING" << endl;
      outDoc << "<label class=\"error\"> ERROR PARSING </label>\n";
      break;
    }
  }

  outDoc << "</body>" << endl;
  outDoc << "</html>" << endl;
  outDoc.close();
}

int main() {
  buildMatrix();
  string fileName = "archivo.txt";
  lexerAritmetico(fileName);
  parser();
  return 0;
}