#include <iostream>
using namespace std;

class hill{
public:
  string input, output;
  int key[5][5], r;

  hill(){
   cout<<"Key matrix rows/columns: ";
   cin>>r;
   
   cout<<"\n---------------------------"<<endl;
   newkey();
  }
  
  void newkey()
  { 
    cout<<"Enter key matrix:"<<endl;
    for(int i=0;i<r;i++){
      for(int j=0;j<r;j++){
         cin>>key[i][j];
      }
    }
    cout<<"\n----------------The key---------------------"<<endl;
    for(int i=0;i<r;i++){
      for(int j=0;j<r;j++){
         cout<<key[i][j]<<"\t";
      }
        cout<<endl;
    }
    cout<<"Continue/re-enter(y/n): ";
    char a;
    cin>>a;
    if(a=='n')
    {
      hill();
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
     cout<<"\n---------------------------"<<endl;
     cout<<"1. New Key  2. Encrypt  3. Decrypt"<<"\noption: ";
     cin>>a;

     switch(a)
     {
       case 1: newkey();
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
  
 

  
}

void decrypt()
{
  
  
  
}

};



int main()
{

hill obj1;

return 0;
}
