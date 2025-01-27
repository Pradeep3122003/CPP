#include <iostream>
using namespace std;





class playfair{

public:
  string input, output, set="ABCDEFGHIKLMNOPQRSTUVWXYZ";
  string key, temp;
  char kgraph[5][5];
  
  playfair(){
  
    cout<<"\nEnter key: ";
    cin>>key;
    capitalize();
    keycheck();
  
  }

 void capitalize()
{
   
 for(int i=0;i<key.size();i++)
{
  if (key[i] >90)
  {
    key[i]-=32;
  }

  if(key[i]==74)
  {
    key[i]=73;
  }
}
}

  void keycheck()
{

temp+=key[0];
  for(int i=1;i<key.size();i++)
  {
    for(int j=0;j<temp.size();j++)
    {
      if(temp[j] == key[i])
      {
         break;
      }
      else if( j == temp.size()-1)
      {
        temp+=key[i];
      }
    }
  }
  key=temp;
  string strength= (key.length() > 5)?"good":"normal";
  cout<<"-----------------------------"<<endl;
  cout<<"Key : "<<key<<endl;
  cout<<"Key size: "<<key.length()<<endl;
  cout<<"Key strength: "<<strength<<endl;
  cout<<"Continue/recreate?(y/n): ";
  char c;
  cin>>c;
  if ( c == 'n' )
  {
    playfair();
  }
  
graph();   
}

  void graph()
  {
int l=0;
   for(int i=0;i<set.size();i++)
  {
    for(int j=0;j<key.size();j++)
    {
      if(set[i] == key[j])
      {
         break;
      }
      else if( j == key.size()-1)
      {
        temp+=set[i];
      }
    }
    
  }
 
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
   kgraph[i][j]=temp[l++];
}
}

   
cout<<"-----------------------------"<<endl;
choice();
}

void graphdis()
{
     for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
   cout<<kgraph[i][j]<<"\t";
}
cout<<endl;
}
cout<<"\n----------------------------------"<<endl;
}

void choice()
{
 int i=0;
 while(1==1)
{
  cout<<"1. Key  2. Encrypt  3. Decrypt  4. Graph"<<endl;
  cin>>i;
  switch(i){
  case 1: keycheck();
         break;
  case 4: graphdis();
         break;
  default: cout<<"Unknown option"<<endl;
         break;
}
}
}
 
};


int main()
{

 playfair obj1;
 
return 0;
}
