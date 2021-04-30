#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
string alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-,.()";
string espacio=" ";
int modulo(int a, int n){
   int q=a/n;
   int r;
   if (a<0){
     q=q-1;
   }
   return r=a-(q*n);
   }
int euclides(int x1, int x2){
 int q;
 int r=1;
 int eu;
 while(r!=0){
  q=x1/x2;
  r=modulo(x1,x2);
  x1=x2;
  eu=x2;
  x2=r;}
 return eu;}
int euclides_ext(int a, int b) {
  int r1=a,r2=b;
  int s1=1,s2=0;
  int t1=0,t2=1;
  int r,s,t;
  while (r2 > 0) {
    int q = r1 / r2;
    r=r1-(q*r2);
    r1=r2;
    r2=r;
    s=s1-(q*s2);
    s1=s2;
    s2=s;
    t=t1-(q*t2);
    t1=t2;
    t2=t;
  }
  return s1;}
int inverso_multiplicativo(int a, int b){
  int inversa = euclides_ext(a,b);
  if(inversa<0){
    inversa=modulo(inversa,b);
  }
  return inversa;}
string cifrado_afin(int a, int b, string mensaje){
  string cifrado;
   for(int j=0;j<mensaje.length();j++){
      for(int i=0;i<alfabeto.length();i++){
       if(mensaje[j]==espacio[0]){
       cifrado=cifrado+espacio[0];
       break;
       }
    if(mensaje[j]==alfabeto[i]){
      if(i*a+b>alfabeto.length()){
        cifrado=cifrado+alfabeto[modulo((i*a+b),alfabeto.length())];
      }
      else
      {cifrado=cifrado+alfabeto[i*a+b];
     }}}}
   return cifrado;}
string decifrado_afin(int a, int b, string mensaje){
  string decifrado;
  for(int j=0;j<mensaje.length();j++){
      for(int i=0;i<alfabeto.length();i++){
       if(mensaje[j]==espacio[0]){
       decifrado=decifrado+espacio[0];
       break;
       }
    if(mensaje[j]==alfabeto[i]){
      if(a*(i-b)>alfabeto.length()&&a*(i-b)<0){
        decifrado=decifrado+alfabeto[modulo(a*(i-b),alfabeto.length())];
      }
      else
      {decifrado=decifrado+alfabeto[a*(i-b)];
     }}}}
   return decifrado;}
int main() {
  srand(time(NULL));
  int a,b,clave;
  string mensaje,respuesta;
  cout<<alfabeto.length()<<endl;
  a= 0+modulo(rand(),alfabeto.length());
  while(euclides(a,alfabeto.length())!=1 ){
    a=0+ modulo(rand(),alfabeto.length());
  }
  b=0+modulo(rand(),alfabeto.length());
  cout<<"Las claves son "<<a<<" y "<<b<<endl;
  cout<<"Ingrese el mensaje a ser cifrado o que sera decifrado:\n";
 getline(cin,mensaje);
 cout<<"Desea cifrar o decifrar\n";
 cin>>respuesta;
 if(respuesta=="cifrar"){
 cout<<cifrado_afin(a,b,mensaje)<<endl;
 }
 else{
  cout<<"Ingrese a y b\n";
  cin>>a>>b;
  a=inverso_multiplicativo(a, b);  
  cout<<inverso_multiplicativo(a, b)<<endl;
  cout<<decifrado_afin(a,b,mensaje)<<endl;
}
}


