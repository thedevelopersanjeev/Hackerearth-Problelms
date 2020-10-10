/*Program to find largest and smallest palindrome in a given string*/
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	string pal2,str1,s,c,pal1;
	int length=0,k=0,largest=0,p=0,len1=0,m=0,smallest=0;
	cout<<"Enter a string ";
	cin>>str1;
	/*length of the given string*/
	while(str1[length]!='\0'){
		length++;
	}
	/*Outer loop for taking the number of elements in the subsets starting from 1 to size of the string*/
	for(int i=1;str1[i]!='\0';i++){
		for(int j=0;j<(length-i);j++){
			s="";
			m=0;
			p=i;
			k=j;
			c="";
			len1=0;
			/*Checking subsets*/
			while(p>=0){
				c+=str1[k];
				k++;
				p--;
				len1++;
			}
			/*Calculating the reverse of the above calculated substring*/
			while(c[m]!='\0'){
				s+=c[len1-m-1];
				m++;
			}
			/*Checking if the substring is a palindrome or not*/
			if(s==c){
				if(largest<len1){
					pal1=s;
					largest=len1;
				}
				if(smallest==0 || smallest>len1){
					pal2=s;
					smallest=len1;
				}
			}

		}
	}
	cout<<"largest palindrome is "<<pal1<<endl;
	cout<<"Smallest palindrome is "<<pal2;
	return 0;
}