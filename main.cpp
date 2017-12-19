#include<iostream>
#include<sstream>
#include<ctime>
#include <iomanip>
#include"BigInt.h"
#include"Rsa.h"
using std::cout;
using std::endl;
using std::cin;

void menu()
{//菜单显示函数
	cout<<"==========Welcome to use RSA encoder=========="<<endl;
	cout<<"               e.encrypt 加密              "<<endl;
	cout<<"               d.decrypt 解密              "<<endl;
	cout<<"               s.setkey 重置               "<<endl;
	cout<<"               p.print 显示               "<<endl;
	cout<<"               q.quit 退出                 "<<endl;
	cout<<"input your choice:"<<endl;
}

bool islegal(const string& str)
{//判断输入是否合法
	for(string::const_iterator it=str.begin();it!=str.end();++it)
		if(!isalnum(*it))//不是字母数字
			return false;
	return true;
}

bool decode(Rsa& rsa)
{//解密
	string str;
	do
	{
		cout<<">输入16进制数据:";
		cin>>str;
	}while(cin && str.length()<1);
	if(!cin || islegal(str)==false)
		return false;
	BigInt c(str);
	
	long t1=clock();
	BigInt m=rsa.decodeByPr(c);
	long t2=clock();
	cout<<"用时:"<<(t2-t1)<<"ms."<<endl;

	cout<<"密文:"<<c<<endl
		<<"明文:"<<m<<endl;
	return true;
}

bool encry(Rsa& rsa,BigInt& c)
{//加密
	string str;
	do
	{
		cout<<">输入16进制数据:";
		cin>>str;
	}while(cin && str.length()<1);
	if(!cin || islegal(str)==false)
		return false;
	BigInt m(str);

	c=rsa.encryptByPu(m);

	cout<<"明文:"<<m<<endl
		<<"密文:"<<c<<endl;
	return true;
}

void print(Rsa& rsa)
{//输出
	cout<<rsa<<endl;
}

void init(Rsa& rsa,int n)
{//初始化

	cout<<"初始化...."<<endl;
	long t1=clock();
	rsa.init(n);
	long t2=clock();
	cout<<"初始化完成."<<endl;
	cout<<"用时:"<<(t2-t1)/1000<<"s."<<endl;
}

int go()
{//控制函数
	char ch;
	string str;
	Rsa rsa;
	BigInt c,m;
	cout<<"输入位数:"<<endl;
	int n;
	cin>>n;
	init(rsa,n/2);
	cout<<rsa<<endl;

	while(true)
	{
		menu();//菜单显示
		cout<<">";
		cin>>str;
		if(!cin)
			return 0;
		
		if(str.length()<1)
			cout<<"重新输入"<<endl;
		else
		{
			ch=str.at(0);
			switch(ch)
			{
			case 'e':
			case 'E':
				encry(rsa,c);//加密
				break;
			case 'd':
			case 'D':
				decode(rsa);//解密
				break;
			case 's':
			case 'S':
				go();//重新开始初始
				break;
			case 'p':
			case 'P':
				print(rsa);//输出公私钥信息
				break;
			case 'q':
			case 'Q':
				return 0;
			}
		}
	}
}

string string_to_hex(const string& str) //transfer string to hex-string  
{  
    string result;//="0x";  
    string tmp;  
    std::stringstream ss;  
    for(int i=0;i<str.size();i++)  
    {  
        ss<<std::hex<<std::setw(2) <<std::setfill('0')<<int(str[i])<<endl;  
        ss>>tmp;  
        cout<<tmp<<endl;
        result+=tmp;  
    }  
    return result;  
}  

int main()
{
	//go();
	// N:00000E05
	// p:00000025
	// q:00000061
	// e:00010001
	// d:00000881
	Rsa rsa1;
	std::string str_orig="abcdefhilmnorsuxyz";
	cout<<"mingwen==="<<str_orig<<endl;
	string hex_in = string_to_hex(str_orig);
	cout<<hex_in<<endl;

	BigInt b_info(hex_in);
	cout<<"mingwen=num=="<<b_info<<endl;

	// const BigInt in_e("101");//257
	// const BigInt in_n("815BD9A1");//2170280353
	// const BigInt in_d("4B7F4921");//1266632993
	const BigInt in_e("010001");//257
	const BigInt in_n("00e7b0dd45eba985ea1eb2fd7a7237e654ff0e40c9e5818d9348aa2df7fc04e7e2a429c3e9031eb2b217bb10fd1370ead89b33dd2233a54e035e37d39ba63db3d138926cdc9a01e8b6a8ef84949b9f1a3bd4fe0adeeb3b9d84fb7af98f20d089c75197a94884b8a03400d73c3fcaa0dc1fad1ac2cb0e304c73198521dcf1e50779");//2170280353
	const BigInt in_d("0554c882a75d8b3b4be18a7b9acd367b9632d9c2cb89239cd3fb367b924cfa98f8760d8ffb0665ce3b458eaa841c010b62e6da9bc2dc76e314f3ebe694f8ae7e82bd7e8e3b7cbb17d4f14263d4c328bd5d16566004098953b851dbb87f802a38af73ccb9bfec9eaee7fac92b6daad96d7d49e90d68e5460a148aeb22334e6c41");//1266632993
	// 	const BigInt in_e("11");//17
	// const BigInt in_n("CA1");//3233
	// const BigInt in_d("AC1");//2753
	// const BigInt in_e("3");//2299 2679 156 3014 867 1705 1399 2699 874 1633 754 558 2574 1236 2990 652 2069
	// const BigInt in_n("21");
	// const BigInt in_d("7");
    //ostream<<b_info<<endl;
	// const BigInt in_e("00010001");
	// const BigInt in_n("00000E05");
	// const BigInt in_d("00000881");
	BigInt test_BigInt(7);
	cout<<"test="<<test_BigInt<<" "<<test_BigInt.moden(5,20)<<endl;
	cout<<std::hex<<(unsigned int)(-((unsigned int) (0x815BD9A1)-(unsigned int )(0x207FC0D)))<<endl;
	// cout<<std::hex<<(unsigned int)(-((unsigned int) (0x207FC0D)-(unsigned int )(0x815BD9A1)))<<endl;
	// cout<<std::hex<<(unsigned int)(0xFFFFFFFF+0x1+((unsigned int) (0x207FC0D)-(unsigned int )(0x815BD9A1)))<<endl;

	std::stringstream ss; 
	ss<<b_info<<endl;
	std::string tmp;
	std::string sum4;
	for(int i=0;i<ss.str().length();i++)
	{
		if(i>0 && i%4==0)
		{
			cout<<"=sum4==="<<sum4<<endl;
			BigInt group4(sum4);
			cout<<i<<"=group4==="<<group4<<endl;
			BigInt miwen = rsa1.encryptByPr(group4,in_e,in_n);
			cout<<"miwen==="<<miwen<<endl;
			BigInt hex_out = rsa1.decodeByPu(miwen,in_d,in_n);
			cout<<"hex_out==="<<hex_out<<endl;
			sum4="";
			// cout<<"=sum4==="<<sum4<<endl;
			// BigInt group4(sum4);
			// cout<<i<<"=group4==="<<group4<<endl;
			// BigInt miwen = rsa1.encryptByPr(group4,0x11,0xCA1);
			// cout<<"miwen==="<<miwen<<endl;
			// BigInt hex_out = rsa1.decodeByPu(miwen,0xAC1,0xCA1);
			// cout<<"hex_out==="<<hex_out<<endl;
			// sum4="";
			cout<<endl;
		}
		//ss>>tmp;
		sum4+=ss.str()[i];
	}

}