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
	ifstream inf1(fname);
	bitChar bc;
	string decoded=bc.readByBits(inf1);
	cout<<decoded;
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
//	cout<<freqfile<<"  "<<regenfile<<endl;
	freopen(freqfile,"r",stdin);
	string line;
	while(getline(cin,line))
	{
		string ch="" , frq="";
		i=0;
//		cout<<line<<endl;
		while(line[i]!=' ')
		{
			ch+=line[i++];
		}
		i++;
		while(line[i]!='\0')
		{
			frq+=line[i++];
		}
//		cout<<ch<<" ...."<<frq<<endl;
		ul idx=toInt(ch);
		ul freq=toInt(frq);
//		cout<<idx<<" "<<freq<<endl;
		f[idx]=freq;
	}	
	populatepq(f);
	buildHuffmanTree();
	treetraversal(root,0);
//	string str="�)�+N�/���[a�~���;���z��^�!ޞ�S��	>I㙔t�uk��2�-����܆ه�M�-�}p:e:�]Z��Kt4�D���.���g��Ydœ���u�O�����ᾏ��)�'�8:4hS[�C���>��>�z��4�����y��}��j!z�زv����ju�V� 8_���ä����m�(�S5:௼k�j}#��j,�[⥼!8�'�D:Ӡ���ä�#�� }_�����7��4���,��j7�J����m_{��n�tN�vڂ�dњ�S�ħ1��=\|�{ڝqj_Y͋�����Ra�t�Z�i������l:O��S�=��ޟj!����l#�Mx���寋R��l]��}����'�p����W��p�v,���>����a�������-� ��j����}����r����ػ{~�����O�e�'��W�����hOF�rmɵc��|9�9OC��^���z��t7��|5����8xq��2mɷ&ܛL<�:	3Y���<<��%�r����<2����-���Cjh}dۓnM�6�ۓnM�� y���C���Q��z�W�%���n�ݬ�Lɷ&ܛrmɶ7�Sе�Z�����E�I�O�!w�}C��]�]��in����bdCSf=	:�`��Ci�6���CXy�'Cl��>8}C�!�HG�8���F�f����9�:�7��ɾp�ɾj6.����ɾ�'��a��'�Vu8Y�|�Qd��Ш8e*\�rmɷ���T�9xvJ��rvOCXf�}�j���������N����d��B��7��9�&��NA���&��f>K'C�$5A��rmɵ�Z���ǚ��'�Q�y��!b�94���C^�CHoPrL5A���y(j�a�N�a��t?BCT= Ҡ��A0�O�rr�@z���?���N@a��� ��ɸ��<%�1��u9��K�&�9OA&�����~e=�T�v��B�f@����k�*�ɹS��=����&���,�7ۓr����~NԲg��D�.ܛ��=	-�_j|;5��QCt�v�܇)�Z�-";
////	cout<<codeof('a')<<" "<<codeof('b')<<" "<<codeof('r')<<" "<<codeof('c')<<" "<<codeof('d')<<endl;
//cout<<str<<endl;
	string text=regenerateText(decoded);
	cout<<text.length();
	freopen(regenfile,"w",stdout);
	cout<<text;
	return 0;
}

