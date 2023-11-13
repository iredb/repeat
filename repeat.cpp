/*************************************
 *                                   *
 *  Струк Степан Андреевич           *
 *                                   *
 *  Частота повторений букв          *
 *  и двубуквенных сочетаний         *
 *                                   *
 * https://onlinegdb.com/xCdmz_hx9O  *
 *                                   *
 *************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// return -1 если сочетание символов нашлось впервые, иначе вернет индекс сочетания в массиве всех сочитаний
int doubleCharPlace(vector<string> victor, string combo){
  for (int charIndex = 0; charIndex < victor.size(); ++charIndex) {
    if (victor[charIndex] == combo){
      return charIndex;
    }
  }
  return -1;
}

// return -1 если символ нашелся впервые, иначе вернет индекс символа в массиве всех символов
int charPlace(vector<char> victor, char symbol){
  for (int charIndex = 0; charIndex < victor.size(); ++charIndex){
    if (victor[charIndex] == symbol) {
      return charIndex;
    }
  }
  return -1;
}

int main() {

  vector<char> symbols;
  vector<int> countOfSymbols; // найденные символы, их количества
  
  vector<string> doubleSymbols;
  vector<int> countOfDoubleSymbols; // найденные сочетания, их количества
  
  ifstream file("file.txt");
  string line;
  
  if ( file.is_open() == 0 ) {
    cout << "Не открылось" << endl;
  } else {
    while ( getline(file, line) ){
      
      // проходимся по символам строки
      for (int charIndex = 0; charIndex < line.size(); ++charIndex){
        char symbol1 = tolower(line[charIndex]);
        
        // проходимся по сочетаниям (их в строке на 1 меньше чем символов)
        if (charIndex != line.size() - 1){
          char symbol2 = tolower(line[charIndex + 1]);
          string combo = "";

          combo = combo + symbol1 + symbol2;
          
          int comboNumber = doubleCharPlace(doubleSymbols, combo);
          
          // -1 => сочетание появилось впервые, иначе увеличиваем количество сочетаний на 1 !!!
          if (comboNumber != -1) {
            countOfDoubleSymbols[comboNumber] += 1;
          } else {
            doubleSymbols.push_back(combo);
            countOfDoubleSymbols.push_back(1);
          }
          
        }
        
        int charNumber = charPlace(symbols, symbol1);
        // !!! same
        if (charNumber != -1) {
          countOfSymbols[charNumber] += 1;
        } else {
          symbols.push_back(symbol1);
          countOfSymbols.push_back(1);
        }
      }
        
    }
      
  }
  
  string symbolToFind = "";
  
  cout << "Найти символ: ";
  cin >> symbolToFind;
  cout << endl;
  
  bool found = false;
  
  switch( symbolToFind.size() ){
    case 1:
      {
      char symbol = symbolToFind[0];
      for (int i = 0; i < symbols.size(); ++i){
        if (symbols[i] == symbol) {
          cout << symbolToFind << ": " << countOfSymbols[i] << endl;
          found = true;
          break;
        }
      }
      if (!found) {
        cout << symbol << ": 0" << endl;
      }
      break;
      }
      
    case 2:
      for(int i = 0; i < doubleSymbols.size(); ++i){
        if (doubleSymbols[i] == symbolToFind) {
          cout << symbolToFind << ": " << countOfDoubleSymbols[i] << endl;
          found = true;
          break;
        }
      }
      if (!found) {
        cout << symbolToFind << ": 0" << endl;
      }
      break;
    default:
      cout << ":(" << endl;
  }
  
}
