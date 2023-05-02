#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
class A
{
	public:
		int a,b,c;
		A() {};
		A(int aa,int bb,int cc)
		{
			a = aa;
			b = bb;
			c = cc;
		}
};
struct compare
{
	bool operator() (const A &th,const A &other)
	{
		if((th.a == other.a) && (th.b == other.b) && (th.c == other.c))
			return false;
		else
		{
			if( th.a != other.a)
				return th.a < other.a;
			else if(th.b != other.b)
				return th.b < other.b;
			else
				return th.c < other.c;
		}
	}
};

int main()
{
	A aa(1,2,3);
	A bb(1,2,3);
	A cc(2,7,8);
	A dd(1,2,3);
	A ee(2,3,3);
	A gg(2,3,3);
	A hh(1,2,3);
//	vector<A> SA;
//	SA.push_back(aa);
//	SA.push_back(bb);
//	//SA.push_back(cc);
//	SA.push_back(dd);
//	
//	sort(SA.begin(),SA.end(),compare());
	set<A,compare> ff;
	ff.insert(aa);
	ff.insert(bb);
	ff.insert(cc);
	ff.insert(dd);
	ff.insert(ee);
	ff.insert(gg);
	ff.insert(hh);
	cout<<ff.size()<<endl;
}

