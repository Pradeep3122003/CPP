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
    key=capitalize(key);
    keycheck();
  
  }

 string capitalize(string a)
{
   
 for(int i=0;i<a.size();i++)
{
  if (a[i] >90 && a[i]!=' ')
  {
    a[i]-=32;
  }

  if(a[i]==74)
  {
    a[i]=73;
  }
}
return a;
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

int row(char a)
{
  for(int i=0;i<5;i++)
     {
       for(int j=0;j<5;j++)
       {
          if(kgraph[i][j] == a)
          {
             return i;
          }
       }
       
     }
return 0;
}

int col(char a)
{
 for(int i=0;i<5;i++)
     {
       for(int j=0;j<5;j++)
       {
          if(kgraph[i][j] == a)
          {
             return j;
          }
       }
       
     }
return 0;
}

void encrypt()
{
  int c=0;
  temp="";
  cout<<"Enter message: ";
  cin.ignore();
  getline(cin,input);
  input=capitalize(input);
  
  for(int i=0;i<input.size();i++)
{

if(input[i]!=' ')
{
  
  temp+=input[i];
  c++;
}
}
input=temp;
temp="";

for(int i=0;i<input.size();i+=2)
{
  if(input[i]==input[i+1])
  {
    
     temp+=input[i];
     temp+="X";
    
     c++;
     i-=1;
     
     
  }
  else
{
  temp+=input[i];
  temp+=input[i+1];
  
}
}
input=temp;
temp="";
cout<<"Input: "<<input<<endl;
cout<<"Length: "<<c<<endl;

for(int i=0;i<input.size();i+=2)
{
  int h1,v1,h2,v2;
  h1=row(input[i]);
  v1=col(input[i]);
  h2=row(input[i+1]);
  v2=col(input[i+1]);
  if(h1==h2)
  {
    output+=kgraph[h1][(v1+1)%5];
    output+=kgraph[h2][(v2+1)%5];
  }
  else if(v1==v2)
  {
   output+=kgraph[(h1+1)%5][v1];
   output+=kgraph[(h2+1)%5][v2];
  }
  else{
   output+=kgraph[h1][v2];
   output+=kgraph[h2][v1];
  }
  
}
cout<<"Cipher: "<<output;
output="";
cout<<"\n----------------------------------"<<endl;
}

void decrypt()
{
  cout<<"Enter Cipher: ";
  cin.ignore();
  getline(cin,input);
  input=capitalize(input);
  for(int i=0;i<input.size();i+=2)
{
  int h1,v1,h2,v2;
  h1=row(input[i]);
  v1=col(input[i]);
  h2=row(input[i+1]);
  v2=col(input[i+1]);
  if(h1==h2)
  {
    output+=kgraph[h1][(v1-1)%5];
    output+=kgraph[h2][(v2-1)%5];
  }
  else if(v1==v2)
  {
   output+=kgraph[(h1-1)%5][v1];
   output+=kgraph[(h2-1)%5][v2];
  }
  else{
   output+=kgraph[h1][v2];
   output+=kgraph[h2][v1];
  }
  
}
cout<<"Cipher: "<<input;
cout<<"Message: "<<output;
output="";
cout<<"\n----------------------------------"<<endl;

}
void choice()
{
 int i=0;
 while(1==1)
{
  cout<<"1. Key  2. Encrypt  3. Decrypt  4. Graph"<<endl;
  cout<<"Option: ";
  cin>>i;
  switch(i){
  case 1: keycheck();
         break;
  case 2: encrypt();
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
