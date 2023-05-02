#include<iostream>
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std;

//vector������ǳ����ƣ�Ҳ��Ϊ�������� 
//vector����ͨ��������������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
//��̬��չ����������ԭ�пռ�֮����¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ���ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�
//vector��������֧��������ʵĵ��������ռ������� 



//----------------------------------------------------------------------------------
//vector�Ĺ��� ����ԭ��
/*
vector<T> v;                   //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯�� 
vector( v.begin(), v.end() );  //��v��[begin(),end())�����е�Ԫ�ؿ��������� 
vector(n, elem);               //���캯����n��elem����������
vector(const vector &vec);     //�������캯�� 
*/

void Printvector(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	//1.
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	Printvector(v1);
	//2.
	vector<int> v2(v1.begin(),v1.end());
	Printvector(v2);
	//3.
	vector<int> v3(10,6); //10������6
	Printvector(v3); 
	//4.
	vector<int> v4(v1); //�������� 
	Printvector(v4); 
}
 
 
//----------------------------------------------------------------------------------
//vector��ֵ���� ����ԭ��
/*
vector& operator=(const vector *vec);  //����= 
assign(beg,end);                       //��[begin��end)�����е����ݿ�����ֵ������  
assign(n,elem);                        //��n��elem������ֵ������ 
*/ 

void test2()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//operator=
	vector<int> v2;
	v2 = v1;
	Printvector(v2);
	//2.
	vector<int> v3;
	v3.assign(v1.begin(),v1.end());
	Printvector(v3);
	//3.
	vector<int> v4;
	v4.assign(10,8); //10��8 
	Printvector(v4);	
}

 
 
//----------------------------------------------------------------------------------
//vector������С ����ԭ�� 
/*
empty();                   //�ж������Ƿ�Ϊ��
capacity();                //����������
size();                    //������Ԫ�صĸ���
resize(int num);           //����ָ�������ĳ���Ϊnum�����߳�������Ĭ��ֵ(0)�����λ��
                           //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
resize(int num, int elem); //����ָ�������ĳ���Ϊnum�����߳�������elemֵ�����λ�� 
                           //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ�� 
*/ 
void test3()
{
    vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	cout << "�Ƿ�Ϊ�գ�" << v1.empty() << endl;
	cout << "������С��" << v1.size() << endl; 
	cout << "����������" << v1.capacity() << endl; 
	
	//������С
//	v1.resize(15);   //ʣ�µ�0��� 
//	Printvector(v1); 
	
	v1.resize(15,66); //ʣ�µ���66���
    Printvector(v1); 
    
    v1.resize(5);   //������ɾ�� 
    Printvector(v1); 
} 

//----------------------------------------------------------------------------------
//vector������ɾ�� ����ԭ��
/*
push_back(ele);   //β��
pop_back();       //βɾ
iterator insert(const_iterator pos, elem);  //������ָ��λ��pos����Ԫ��ele,����������λ�� 
void insert(const_iterator pos, int count, elem); //������ָ��λ��pos����count��Ԫ��ele  
void insert(const_iterator pos, const_iterator start, const_iterator end);
//posλ�ò���[start,end)��������ݣ��޷���ֵ

iterator erase(const_iterator pos);        //ɾ��������posָ��Ԫ��,������һ������λ�ã��������� 
iterator erase(const_iterator start, const_iterator end); 
//ɾ����������start��end֮���Ԫ��[start,end)��������һ������λ�ã��������� 
clear();                          //�������������Ԫ�� 
*/ 

void test4()
{
    vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	v1.pop_back();
	Printvector(v1); 
	
	//����
	v1.insert(v1.begin(),100); //ͷ�壬��һ�������ǵ����� 
	Printvector(v1);  
	
	v1.insert(v1.begin(),2,1000);
	Printvector(v1);  
	//ɾ��
	//vector<int>::iterator it = v1.erase(v1.begin());      
	v1.erase(v1.begin());    //ͷɾ������Ҳ�ǵ�����
	Printvector(v1); 
	
	v1.erase(v1.begin()+1, v1.end()); //ֻ�����˵�һ���� 
    Printvector(v1);
    //���
	v1.clear();
	Printvector(v1); 
}
 

//----------------------------------------------------------------------------------
//vector�������ݵĴ�ȡ 
/*
at(int Index);   //��������Index��ָ������ �������±��Ƿ�Խ�磩 
operator[];      //��������Index��ָ������ �������飩
front();         //���������е�һ��Ԫ��
back();          //���������� ���һ��Ԫ�� 
*/ 

void test5()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//���� 
	for(int i=0; i<v1.size(); i++)
	{
		//cout << v1[i] << " ";
		cout << v1.at(i) << " ";
	}
	cout << endl;
	
	cout << v1.front() << endl;	//0 
	cout << v1.front() << endl;	//0
	
	cout << v1.back() << endl; //9
	cout << v1.back() << endl; //9
} 



//----------------------------------------------------------------------------------
//vector������������
//swap(vec);  //������vec�뱾���Ԫ�ػ���
 
void test6()
{
	//1.����ʹ��
	cout << "����ǰ��" << endl; 
	vector<int> v1; 
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	Printvector(v1);
	vector<int> v2;
	for(int i=9; i>=0; i--)
	{
		v2.push_back(i);
	}
	Printvector(v2);
	
	cout << "������" << endl;
	v1.swap(v2);
	Printvector(v1); 
	Printvector(v2); 
	
	//2.ʵ����;
	vector<int> v;
	for(int i=0; i<100000; i++)
	{
		v.push_back(i);
    }
	cout << "v������Ϊ��" << v.capacity() << endl; 
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
	
	v.resize(3);
	cout << "����ǰ��" << endl;
	cout << "v������Ϊ��" << v.capacity() << endl; 
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
	
	vector<int> (v).swap(v);    
	//vector<int> (v);�൱�����ÿ������캯����ʼ����һ����������
	//�����������capacity����ԭ��v��size��Ȼ�󻥻���������������������ָ��ԭ�����capacity
	//������������ڸ��н������Զ����գ����Դ�capacity�ͱ������ˣ���vָ����Сcapacity 
	cout << "������" << endl; 
	cout << "v������Ϊ��" << v.capacity() << endl; 
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
		 
}



//----------------------------------------------------------------------------------
//vectorԤ���ռ�
//����vector�ڶ�̬��չʱ����չ���� //ע����reserve(Ԥ��) ���� reverse(�ߵ�) 
//����ԭ��  reserve(int len);      //����Ԥ��len�� Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��� 

void test7()
{
	vector<int> v;
	int num = 0;// ��¼���ٴ���
	int*p = NULL;
	for(int i=0; i<100000; i++)
	{
		v.push_back(i);
		if(p != &v[0]) //��¼�ռ��ƶ��˼��Σ����ǿ����˼��� 
		{
			p = &v[0];
			++num;
		}
	} 
	cout << num << endl; 
	
	//����reserveԤ���ռ�
	//��������һ��ʼ��֪��Ҫ���100000�����ݣ���ֱ��Ԥ��100000�����Ͳ���ÿ�β������¿����� 
	vector<int> v2;
	v2.reserve(100000); 
	int num2 = 0;// ��¼���ٴ���
	int* p2 = NULL;
	for(int i=0; i<100000; i++)
	{
		v2.push_back(i);
		if(p2 != &v[0]) //��¼�ռ��ƶ��˼��Σ����ǿ����˼��� 
		{
			p2 = &v[0];
			++num2;
		}
	} 
	cout << num2 << endl; 
}





int main()
{
//	test1(); 
//	test2(); 
//	test3(); 
//	test4(); 
//	test5(); 
//	test6(); 
	test7(); 
	return 0;
}

