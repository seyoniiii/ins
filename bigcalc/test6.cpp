// error
#include "bigcalc.h"
using namespace std;
int main() {
  string sp="11281857738134276057", sq="12816927078642145829";
  string sE="18792916937660333425261547412492472441",
         sD="42966491611203519136543725443717471721",
         sP="SKU";
  string temp;
  int i = 0;
  char c;
  BigUnsigned p=stringToBigUnsigned(sp), q=stringToBigUnsigned(sq);
  BigUnsigned n=p*q, s=(p-1)*(q-1), E=stringToBigUnsigned(sE),
         D=stringToBigUnsigned(sD), ss, C, P;
  // int b8=256, b16=b8*b8;
  // P = sP[0]*b16 + sP[1]*b8 + sP[2];
  for (i=0;i<sP.length();i++) {// SKU길이만큼 반복 0 1 2
        P += sP[sP.length()-i-1]<<(8+i);
        //P가 1101010이런식인것을 문자가 16진수라서 한개씩 잘라서 10진수로바꿈
  }


  cout << "p=" << p << ", q=" << q << ", s=" << s << ",\n";
  cout << "n=" << n << ", E=" << E << ", D="<< D << endl;
  cout << "P = " << P << endl << endl;
  C = modexp(P, E, n);
  cout << "C = " << P<<"^E mod n = " << C << endl;
  P = modexp(C, D, n);
  cout << "P = " << C<<"^D mod n = " << P << ", sP = ";

  i = 0;
  do {
      temp = bigUnsignedToString(P);//평문 스트링을 템프에 저장
      sP[sP.length()-i-1] = atoi(temp.c_str());
      //계산결과 숫자를 -> 문자로 바꿔서 sP에 하나씩 저장
      P = P>>8; //16진수로 다시 바꿈
      i++;
  } while(P != 0); //숫자를 하나씩 문자로 바꿔서 그 값을 저장
  cout << sP << endl;
  system("pause");
/*
  c = (int) P % b8; sP[0] = c;
  c = (int) P % b16; sP[1] = c;
  c = (int) P / b16; sP[2] = c;
  cout << sP << endl;
*/
  return 0;
}
/*
p=11281857738134276057, q=12816927078642145829, s=144598747941281633860705886241
160694368,
n=144598747941281633884804671057937116253, E=18792916937660333425261547412492472
441, D=42966491611203519136543725443717471721
P = 5458773

C = 5458773^E mod n = 119233399908809306152508725127701598913
P = 119233399908809306152508725127701598913^D mod n = 5458773, sP = �����Ϸ���
�ƹ� Ű�� �����ʽÿ� . . .
*/
