
// tuDlg.h: 头文件
//

#pragma once
#include <thread>
#include <stack>
using namespace std;

// CtuDlg 对话框
class CtuDlg : public CDialogEx
{
	// 构造
public:
	CtuDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TU_DIALOG };
#endif

protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()



public:
	afx_msg void OnClickedButton1();
	CEdit editst;
	CEdit editend;
	const int maxValue = 100000;
	int mp[10][10] =
	{ {0,750,680,maxValue,maxValue,maxValue,maxValue,maxValue,maxValue,maxValue},
		{750,0,800,650,1140,maxValue,maxValue,maxValue,maxValue,maxValue},
		{680,800,0,820,maxValue,maxValue,maxValue,maxValue,960,maxValue},
		{maxValue,650,820,0,570,maxValue,maxValue,530,1200,maxValue},
		{maxValue,1140,maxValue,570,0,840,maxValue,maxValue,maxValue,maxValue},
		{maxValue,maxValue,maxValue,maxValue,840,0,340,maxValue,maxValue,maxValue},
		{maxValue,maxValue,maxValue,maxValue,maxValue,340,0,900,maxValue,2500},
		{maxValue,maxValue,maxValue,530,maxValue,maxValue,900,0,680,1380},
		{maxValue,maxValue,960,1200,maxValue,maxValue,maxValue,680,0,2600},
		{maxValue,maxValue,maxValue,maxValue,maxValue,maxValue,2500,1380,2600,0}
	};

	int x[10] = { 367,248,367,240,159,30,130,300,400,280 };
	int y[10] = { 20,80,140,200,170,280,300,290,270,320 };
	int color[3][10][10] = { 0 };//1_绿色 0_灰色 2_红色 预选
	int start, myend;
	int outt[10][10] = {0};
	int pout[10][10] = {0};
	int ok = 0;
	//dfs
	int dfstag[10] = { 0 };

	//prim数据
	int dist[10];//dist[i]表示结点i到起点的距离
	bool st[10];//st[i]表示该结点是否确定了最小距离，1是确定，0是未确定
	int pre[10];

	//dijkstra数据
	int ddist[10];//dist[i]表示结点i到起点的距离
	bool dst[10];//st[i]表示该结点是否确定了最小距离，1是确定，0是未确定
	int dpre[10];


	void dijkstra(int a);
	void prim(int a);
	void dfs(int a);
	void draw();

	int tt = 0;
	
	afx_msg void OnClickedZt();
//	afx_msg void OnClickedJx();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int nPress = 0; //用于联合判断“启动”按钮的按下状态
	BOOL bStatic = FALSE; //用于判断程序是否在执行，以便KillTimer（）  

	int a = -1;
	int dfszh = 0;
	int tag = 0;
	int dtag = 0;
	

	int jsq = 0;
	int press = 0;
	stack<int> sta;
};
