#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<bits/stdc++.h>
#define ul unsigned long
using namespace std;
char code[200];
vector<string> v(257);
ul freq[257]; 
struct node	
{
	node *left;
	node *right;
	ul weight;
	char ch;	  
	node(node *l,node *r, ul w,char c)
	{
		left=l;
		right=r;
		weight=w;
		ch=c;
	}
};

struct nodecomp	
{
	bool operator()(node *l, node *r)  
  	{  
      return l->weight > r->weight;  
  	}
};

priority_queue<node* , vector<node*> , nodecomp > pq;
node *root;

node *getnode()		
{
	node *t = new node(NULL,NULL,0,'\0');
	return t;
}

node *merge(node *&n1,node *&n2)		
{
	node *n3 = getnode();
	n3->left = n1;
	n3->right = n2;
	n3->weight = n1->weight + n2->weight;
	n3->ch = '\0';
	return n3;
}

node *buildHuffmanTree()		
{
	while(pq.size()!=1)
	{
		node *n1 = pq.top();
		pq.pop();
		node *n2 = pq.top();
		pq.pop();
//		cout<<"merging "<<n1->weight<<" "<<n2->weight<<endl;
		node *n3 = merge(n1,n2);
		pq.push(n3);
	}
	
	root = pq.top();
	pq.pop();
}

bool isleaf(node *t)		
{
	return (t->left==NULL && t->right==NULL);
}

void treetraversal(node *t,int id)
{
	if(t)
	{
		if(isleaf(t))
		{
			code[id]='\0';
			string s="";
			for(int i=0;i<strlen(code);i++)
			s+=code[i];
			v[t->ch]=code;
//			cout<<t->ch<<" "<<code<<endl;
		}
		
		if(t->left)
		{
			code[id]='0';
			treetraversal(t->left,id+1);
		}
		
		if(t->right)
		{
			code[id]='1';
			treetraversal(t->right,id+1);
		}
		
	}
}

void populatepq(string text)
{
	for(ul i=0;i<text.length();i++)
	{
		freq[text[i]]++;
	}
	for(int i=0;i<257;i++)
	{
		if(freq[i])
		{
			char c = i;
			cout<<freq[i]<<" "<<c<<endl;
			pq.push(new node(NULL,NULL,freq[i],c));
		}
	}
}

string regenerateText(string bits)
{
	string text="";
	node *t=root;
		for(int i=0;i<bits.length()-1;i++)
		{
			if(t)
			{
				
				if(bits[i]=='0')
				t=t->left;
				else if(bits[i]=='1')
				t=t->right;
				if(isleaf(t))
				{
//					cout<<" "<<bits[i]<<" "<<t->ch;
					text+=t->ch; t=root;
				}
			}
		}
		return text;
}

void populatepq(ul f[])
{
	for(int i=0;i<257;i++)
	freq[i]=f[i];
	 
	for(int i=0;i<257;i++)
	{
		if(freq[i])
		{
			char c = i;
//			cout<<freq[i]<<" "<<c<<endl;
			pq.push(new node(NULL,NULL,freq[i],c));
		}
	}
	
}

string codeof(char c)
{
	return v[c];
}

ul freqof(int id)
{
	return freq[id];
}


#endif
