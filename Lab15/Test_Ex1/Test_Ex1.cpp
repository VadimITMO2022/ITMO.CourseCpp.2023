#include <iostream>
#include <map>
#include <string>
using namespace std;
 
struct  {
    std::string name;
    char grade;
} StudentGrade;

int main()
{
    string name;

    // ��������� map
  std::map<std::string, char> map;
 
  // ���������� ����������
  for (int i = 0; i < 3; i++){
      cout << "Enter name: ";
      cin >> StudentGrade.name;
      cout << "Enter score: ";
      cin >> StudentGrade.grade;

      name = StudentGrade.name;
      map[name] = StudentGrade.grade;
      cout << endl;
  } 

 // ������ �� ����������

  for (auto it = map.begin(); it != map.end(); ++it)
  {
      std::cout << it->first << "'s grade is " << it->second << std::endl;
  }
 
  return 0;
}