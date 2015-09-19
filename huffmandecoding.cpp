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
//	string str="‡)è+N€/äşö[aÒ~ÃÎé;ÓáÊz°‹^ú!ŞƒS¨¾	>Iã™”të¡uk¾¼2í-ĞÓÑ†Ü†Ù‡ÖM-ß}p:e:è]Zï¯»Kt4ôD¡·Ã.Öügó£ğYdÅ“ó÷„uíOÅõíğñá¾·ø)Á'µ8:4hS[ñœCÒúô>úø>íz£ì4¾«âÑy¨²}õôj!z›Ø²v¢õå¨ïjuĞV 8_Éıì¶Ã¤ù‡Òm‡(‡S5:à¯¼köj}# ¿j,Ÿ[â¥¼!8‹'íD:Ó Éıì¶Ã¤ı#·ô }_³ßÑÍá7·ô4ış,™ï®j7íJ™©×Äm_{øènËtN³vÚ‚¢dÑšûSòÄ§1áœÆ=\|µ{Úqj_YÍ‹·½ûRaçtZ½iĞ…üŸŞËl:OÍûSö=ÛçŞŸj!é¿¥l#½Mx€æ‹êå¯‹RúÎl]¼ì}ïĞûë‚'¤púÖÃËWè…èp±v,¯µ>‘‰ùÍaû®ßá‡ßá-æ ş‘j÷Şüì}ï«ãíşrù«´Ø»{~‚´èÂşOïe¶'–¯WÇÛôÍñhOF»rmÉµcƒæ|9ü9OC¾£^ôô¢zŒ‹t7–Æ|5‰Âôì8xq†ì2mÉ·&Ü›L<î:	3YÙáê<<ö¿%¾rÁå«áê<2ù£½-ğúCjh}dÛ“nM¹6äÛ“nM°å y‡ÒC‚´QøzWÜ%ªéènñİ¬LÉ·&Ü›rmÉ¶7ŸSĞµ„Z÷ÑôôEğIòOÈ!wµ}Cç Ç]«]õá—in†ˆ”bdCSf=	:Á`ğúCi¤6¿‡ÅCXyİ'ClÃê>8}Câ!ñHGú8¸Ñ÷F³f°ùèÂ9ì:ù7¡µÉ¾pûÉ¾j6.ĞùğúÉ¾Ë'¼¦aóá«'†Vu8Y×|¶QdáóĞ¨8e*\›rmÉ· áÈTù9xvJô‚rvOCXfò}èj€ÃĞÕäÿ†°öNÉĞÑ‡d¡¯B¡¤7†¨9ˆ& şNA’†¨&äèf>K'Cô$5Aü›rmÉµ¹Z‹´Çš‹'öQòyÀô!bÕ94†ßÉC^…CHoPrL5Aüœ‚y(j‚aşN†a£ä²t?BCT= Ò …A0ì’O†rr…@zÉĞÄ?†°ÎN@aĞÕ‡ ÒíÉ¸…è<%«1âŞu9Œ¥K·&ä9OA&¹‘ššø~e=ÊT©väÜBøf@÷§¥©k¡*íÉ¹Sáç=‡¡¼Æ&„ ,ê„7Û“r§ „~NÔ²g ¡Dİ.Ü›å=	-ñ_j|;5ğüQCt©väÜ‡)èZÂ-";
////	cout<<codeof('a')<<" "<<codeof('b')<<" "<<codeof('r')<<" "<<codeof('c')<<" "<<codeof('d')<<endl;
//cout<<str<<endl;
	string text=regenerateText(decoded);
	cout<<text.length();
	freopen(regenfile,"w",stdout);
	cout<<text;
	return 0;
}

