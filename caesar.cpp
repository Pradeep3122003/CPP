#include <iostream>
using namespace std;

class caesar{
public:
  string input, output;
  int key;

  caesar(){
   cout<<"Enter key: ";
   cin>>key;
   cout<<"\n---------------------------"<<endl;
   keycheck();
  }
  
  void keycheck()
  { 
    key=key%26;
    string s=(key > 13)?"Great":"Good";
    cout<<"Key: "<<key<<endl;
    cout<<"Strength: "<<s<<endl;
    cout<<"Continue/re-enter(y/n): ";
    char a;
    cin>>a;
    if(a=='n')
    {
      caesar();
    }
    else
    {
     choice();
    }

  }

  void choice()
  {
     int a;
     while(1==1)
     {
     cout<<"1. Key  2. Encrypt  3. Decrypt"<<"\noption: ";
     cin>>a;

     switch(a)
     {
       case 1: keycheck();
           break;
       case 2: encrypt();
            break;
       case 3: decrypt();
            break;
       default: cout<<"\nWrong option"<<endl;
            break;
     }
    }
  }

void encrypt()
{
  input="";
  output="";
  cout<<"Message: ";
  cin>>input;
  for(int i=0;i<input.size();i++)
  {
   output+=input[i]+key;
  }
  cout<<"\nCipher: "<<output;
  
}

void decrypt()
{
  input="";
  output="";
  cout<<"Cipher: ";
  cin>>input;
  for(int i=0;i<input.size();i++)
  {
   output+=input[i]-key;
  }
  cout<<"\nDecrypt: "<<output;
  
}

};



int main()
{

caesar obj1;

return 0;
}
