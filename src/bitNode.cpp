#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

#ifndef BIT_NODE
#define BIT_NODE

//定义单个node所使用的变量长度
#define BIT_TYPE int

class bitNode
{
public:
	bitNode();
	bitNode(int i);
	void set(int i);
	bool get(int i);
	bool operator[](int i);
private:
	BIT_TYPE* nodePtr;
};

bitNode::bitNode()
{
	nodePtr=(BIT_TYPE*)calloc(1,sizeof(BIT_TYPE));
}

bitNode::bitNode(int i)
{
	nodePtr=(BIT_TYPE*)malloc(sizeof(BIT_TYPE));
	*nodePtr=1;
	*nodePtr=(*nodePtr)<<i;
}

void bitNode::set(int i)
{
	*nodePtr=(*nodePtr)|(1<<i);
}

bool bitNode::get(int i)
{
	return i==0?(*nodePtr)&1:(*nodePtr)&(1<<i);
}


bool bitNode::operator[](int i)
{
	return i==0?(*nodePtr)&1:(*nodePtr)&(1<<i);
}

#endif

int main()
{
/*	int i=0b10;
	cout<<i<<endl;
	i=i<<2;
	cout<<i<<endl;
//	printf("%x\n",~i>>9);
//	printf("%x\n",i>>9);
	cout<<"node"<<endl; */
	bitNode bn=bitNode(19);
	cout<<bn[0]<<" "<<bn[19]<<" "<<bn[9]<<endl;
	bn.set(9);
	cout<<bn[0]<<" "<<bn[19]<<" "<<bn[9]<<endl;
	return 0;
}
