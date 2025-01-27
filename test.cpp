#include <iostream>
using namespace std;



int main()
{

 string a;
 cin>>a;
 for(int i=0;i<a.size();i++)
{
  if (a[i] >90)
  {
    a[i]-=32;
    cout<<(int) a[i];
  }
}
cout<<a;

return 0;
}
