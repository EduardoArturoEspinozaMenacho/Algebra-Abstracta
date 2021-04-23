#include <iostream>
#include<string.h>
using namespace std;
string cesar_cifrado(string mensaje,int clave){
 string cifrado;
 string espacio=" ";
 int apoyo;
 string alfabeto_minusculas="abcdefghijklmnopqrstuvwxyz";
   string alfabeto_mayusculas="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     for(int j=0;j<mensaje.length();j++){
      for(int i=0;i<alfabeto_minusculas.length();i++){
       if(mensaje[j]==espacio[0]){
       cifrado=cifrado+espacio[0];
       break;
       }
    if(mensaje[j]==alfabeto_minusculas[i]){
      if(i+clave>alfabeto_minusculas.length()){
      apoyo=(alfabeto_minusculas.length()%i)+clave-1;
      if(apoyo==0){
      cifrado=cifrado+"a"; 
      cout<<"a";
      }
      else{
      cifrado=cifrado+alfabeto_minusculas[apoyo];}  }
      else
      {cifrado=cifrado+alfabeto_minusculas[i+clave];}
     }

      if(mensaje[j]==alfabeto_mayusculas[i]){
      if(i+clave>alfabeto_minusculas.length()){
      apoyo=(alfabeto_minusculas.length()%i)+clave-1;
      if(apoyo==0){
      cifrado=cifrado+"a"; 
      cout<<"a";
      }
      else{
      cifrado=cifrado+alfabeto_mayusculas[apoyo];}  }
      else
      {cifrado=cifrado+alfabeto_mayusculas[i+clave];}
     }
   }}
   return cifrado;
  
}
string cesar_decifrado(string mensaje,int clave){
  string decifrado;
  string espacio=" ";
 int apoyo;
 string alfabeto_minusculas="abcdefghijklmnopqrstuvwxyz";
   string alfabeto_mayusculas="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     for(int j=0;j<mensaje.length();j++){
      for(int i=0;i<alfabeto_minusculas.length();i++){
       if(mensaje[j]==espacio[0]){
       decifrado=decifrado+espacio[0];
       break;
       }
    if(mensaje[j]==alfabeto_minusculas[i]){
      if(i+clave>alfabeto_minusculas.length()){
      apoyo=(alfabeto_minusculas.length()%i)-clave+1;
      if(apoyo==0){
      decifrado=decifrado+"a"; 
      cout<<"a";
      }
      else{
      decifrado=decifrado+alfabeto_minusculas[apoyo];}  }
      else
      {decifrado=decifrado+alfabeto_minusculas[i-clave];}
     }

      if(mensaje[j]==alfabeto_mayusculas[i]){
      if(i+clave>alfabeto_minusculas.length()){
      apoyo=(alfabeto_minusculas.length()%i)-clave+1;
      if(apoyo==0){
      decifrado=decifrado+"a"; 
      cout<<"a";
      }
      else{
      decifrado=decifrado+alfabeto_mayusculas[apoyo];}  }
      else
      {decifrado=decifrado+alfabeto_mayusculas[i-clave];}
     }
   }}
   return decifrado;
  
}
int main() {
  string respuesta;  
  string mensaje;
  int clave;
  cout<<"Ingrese el mensaje a ser cifrado o que sera decifrado:\n";
  getline(cin,mensaje);
  cout<<"Ingrese la clave:\n";
  cin>>clave;
  cout<<"¿Desea cifrar o decifrar?\n";
  cin>>respuesta;
  if(respuesta=="cifrar"){
  cout<<cesar_cifrado(mensaje,clave);}
  else{
  cout<<cesar_decifrado(mensaje,clave);
  }
  }
