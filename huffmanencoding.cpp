#include<bits/stdc++.h>
#include "bitChar.h"
#include "HuffmanTree.h"
using namespace std;
#define ul unsigned long

string text,line;
char fpath[200] ,nfile[200] , newfile[200]={'E',':'} ,freqfile[200];

ul getsize(char *filename)
{
	streampos begin,end;
  ifstream myfile (filename, ios::binary);
  begin = myfile.tellg();
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  return end-begin;
}

void filesave()
{
	int i;
	
	for(i=strlen(fpath)-1;i>=0;i--)
	{
		if(fpath[i]==92) break;
	}
	
	int k=0;
	
	for(int j=i;fpath[j]!='.';j++)
	nfile[k++]=fpath[j];
	
	nfile[k]='\0';
	strcat(newfile,nfile);
	strcpy(freqfile,newfile);
	strcat(newfile,".dat");
	strcat(freqfile,".freq");
	cout<<newfile<<endl;
	
	ofstream of1(newfile) , of2(freqfile);
	bitChar bchar;
	for(int j=0;j<257;j++)
	{
		if(freqof(j))
		of2<<j<<" "<<freqof(j)<<endl;
	}
	of2.close();
string encoded="";
	for(ul j=0;j<text.length();j++)
	{
		int x=text[j];
		encoded+=codeof(text[j]);
//		cout<<codeof(text[j])<<endl;
	}
	cout<<encoded<<endl;
	bchar.setBITS(encoded);
		bchar.insertBits(of1);
	of1.close();
	
}

int main()
{
	printf("Enter File path to compress:");
	cin>>fpath;
	freopen(fpath,"r",stdin);
	
	text="";
	while(getline(cin,line))
	{
		text+=line;
	}	
	cout<<text.length()<<endl;
	populatepq(text);
	
	cout<<"Compressing file....."<<endl;
	
	buildHuffmanTree();
	
	treetraversal(root,0);
	
	filesave();
	
	cout<<"Original size..."<<getsize(fpath)<<" bytes."<<endl;
	
	cout<<"Size after compression..."<<getsize(newfile)<<" bytes."<<endl;
	
}
