#include<bits/stdc++.h>
#include "bitChar.h"
#include "HuffmanTree.h"
using namespace std;
#define ul unsigned long
ul f[257];
ul toInt(string s)
{
	ul x=0;
//	cout<<s.length()<<endl;
	for(int i=0;i<s.length();i++)
	{
		x=(s[i]-'0') + x*10;
	}
	return x;
}
int main()
{
	char fname[200],freqfile[200] , regenfile[200];
	cout<<"Enter file path:";
	cin>>fname;
	clock_t tStart = clock();
	ifstream inf1(fname);
	bitChar bc;
	string decoded=bc.readByBits(inf1);
//	cout<<decoded;
	inf1.close();
	int i;
	for(i=0;i<strlen(fname);i++)
	{
		freqfile[i]=fname[i];
		regenfile[i]=fname[i];
		if(fname[i]=='.') break;
	}
	freqfile[i]='\0';
	regenfile[i]='\0';
	strcat(freqfile,".freq");
	strcat(regenfile,"expanded.txt");

	freopen(freqfile,"r",stdin);
	string line;
	while(getline(cin,line))
	{
		string ch="" , frq="";
		i=0;

		while(line[i]!=' ')
		{
			ch+=line[i++];
		}
		i++;
		while(line[i]!='\0')
		{
			frq+=line[i++];
		}

		ul idx=toInt(ch);
		ul freq=toInt(frq);

		f[idx]=freq;
	}	
	populatepq(f);
	buildHuffmanTree();
	treetraversal(root,0);

	string text=regenerateText(decoded);
//	cout<<text;
	printf("Time taken to decompress: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	freopen(regenfile,"w",stdout);
	cout<<text;
	return 0;
}

