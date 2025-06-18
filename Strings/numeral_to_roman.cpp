

#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    string m[] = {"","M","MM","MMM"};
    string h[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string t[] = {"","X","XX","XXX","LV","V","VX","VXX","VXXX","XC","C"};
    string o[] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
    
    string thousands = m[num/1000];
    string hundreds = h[(num%1000)/100];
    string tens = t[(num%100)/10];
    string ones = o[num%10];
    
    string ans = thousands + hundreds + tens + ones;
    return ans;
}

int main()
{
    int num = 2314;
    cout<<intToRoman(num);
    return 0;
}



//second approach
int printRoman(int number)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;    
    while(number>0)
    {
      int div = number/num[i];
      number = number%num[i];
      while(div--)
      {
        cout<<sym[i];
      }
      i--;
    }
}



