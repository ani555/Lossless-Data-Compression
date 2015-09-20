#include<bits/stdc++.h>
#include "bitChar.h"
#include "HuffmanTree.h"
using namespace std;
#define ul unsigned long
string text;
ul f[257];
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
	}
	
	bchar.setBITS(encoded);
	bchar.insertBits(of1);
	of1.close();
	
}

int main()
{
	printf("Enter File path to compress:");
	cin>>fpath;
	clock_t tStart = clock();
	ifstream ifs(fpath);
	char ch;
	text="";
	while(!ifs.eof())
	{
		ifs.get(ch);
		f[ch]++;
		text+=ch;
	}	
	ifs.close();
	
	populatepq(f);
	
	cout<<"Compressing file....."<<endl;
	
	buildHuffmanTree();
	
	treetraversal(root,0);
	
	filesave();
	
	cout<<"Original size..."<<getsize(fpath)<<" bytes."<<endl;
	
	cout<<"Size after compression..."<<getsize(newfile)<<" bytes."<<endl;
    
    printf("Time taken to compress: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
