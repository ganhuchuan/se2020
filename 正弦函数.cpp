#include<iostream>
using namespace std;
#define N 8
#define PI 3.14
class func
{
public:
	double m_x;
	func(double t_x)
	{
		m_x=t_x;
	}
	double choice_sintime(double m_x); //����������ֵ���зֶ�
	double choice_costime(double m_x); //����������ֵ���зֶ�
    void sin();  //���Һ���
	void cos();  //���Һ���
};
double func::choice_sintime(double m_x)
{
	double k_x=fmod(m_x,2*PI);
	if(k_x>=0&&k_x<=PI)   //0-PIʱ��ֱ�����
		return k_x;
	else
		return -(k_x-PI);   //PI-2PIʱ���൱��0-PIֵȡ��
}
double func::choice_costime(double m_x)
{
	double k_x=fmod(m_x,2*PI);
	if(k_x>=0&&k_x<=PI)
		return k_x;
	else
		return 2*PI-k_x;   //PI-2PIʱ�����������PI�Գ�
}
void func::sin()
{
	double x=choice_sintime(m_x);
	double sum=0;
    int n_n=0;
	for(int n=0;n<N;n++)
	{
		int m=1;
		double x_x=x;
		for(int j=1;j<=2*n+1;j++)
			m*=j;    //2n+1�Ľ׳�
		n_n=pow(-1,n);   //������
		x_x=pow(x_x,2*n+1);   //x��2n+1�η�
		sum+=(x_x/m)*n_n;
	}
	cout<<"sin("<<m_x<<")="<<sum<<endl;
}
void func::cos()
{
	double x=choice_sintime(m_x);
	double sum=0;
    int n_n=0;
	for(int n=1;n<N;n++)   //��x��ƽ����ʼ��ϵ��
	{
		int m=1;
		double x_x=x;
		for(int j=1;j<=2*n;j++)
			m*=j;  //2n�Ľ׳�
		n_n=pow(-1,n);    //������
		x_x=pow(x_x,2*n);   //x��2n�η�
		sum+=(x_x/m)*n_n;
	}
	cout<<"cos("<<m_x<<")="<<1+sum<<endl;
}
void test01()
{
	double choice;
	cout<<"ѡ��1-����ֵ��2-�Ƕ�ֵ:"<<endl;
	cin>>choice;
	if(choice==1)
	{
		double t_x;
		cout<<"���뻡��ֵ��";
		cin>>t_x;
		func* ptr=new func(t_x);   //��������ָ��
     	ptr->sin();
		delete ptr;
	}
	else if(choice==2)
	{
		double t;
		cout<<"����Ƕ�ֵ��";
		cin>>t;
		t=t/180.0*PI;  //�Ƕ�ֵת��Ϊ����ֵ
		func* ptr=new func(t);
	    ptr->sin();
		delete ptr;
	}
	else
		cout<<"��������"<<endl;	
	system("pause");
	system("cls");
}
void test02()
{
	double choice;
	cout<<"ѡ��1-����ֵ��2-�Ƕ�ֵ:"<<endl;
	cin>>choice;
	if(choice==1)
	{
		double t_x;
		cout<<"���뻡��ֵ��";
		cin>>t_x;
		func* ptr=new func(t_x);
		ptr->cos();
		delete ptr;
	}
	else if(choice==2)
	{
		double t;
		cout<<"����Ƕ�ֵ��";
		cin>>t;
		t=t/180.0*PI;
		func* ptr=new func(t);
	    ptr->cos();
		delete ptr;
	}
	else
		cout<<"��������"<<endl;
	system("pause");
	system("cls");
}
int main()
{
	int select;
	while(true)
	{
		cout<<"ѡ��Ҫʵ�ֵĺ���  1-���Һ���  2-���Һ���  0-�˳�����"<<endl;
		cin>>select;
		switch(select)
		{
		case 1:
			test01();
			break;
		case 2:
			test02();
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}