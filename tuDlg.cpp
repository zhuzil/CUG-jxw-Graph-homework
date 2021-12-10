
// tuDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "tu.h"
#include "tuDlg.h"
#include "afxdialogex.h"
#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

struct dot {
	int x;
	int y;
	int c;
};
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtuDlg 对话框



CtuDlg::CtuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, editst);
	//DDX_Control(pDX, IDC_EDIT4, editend);
}

BEGIN_MESSAGE_MAP(CtuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtuDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_ZT, &CtuDlg::OnClickedZt)
	//	ON_BN_CLICKED(IDC_JX, &CtuDlg::OnClickedJx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CtuDlg 消息处理程序

BOOL CtuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//SetTimer(1, 1000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CClientDC dc(this);

	for (int k = 0; k < 3; k++) {

		CWnd* p = (CStatic*)GetDlgItem(IDC_DFS + k);//静态文本框
		CRect rect;
		p->GetClientRect(&rect);

		//p->ScreenToClient(&rect);
		GetDlgItem(IDC_DFS + k)->GetWindowRect(&rect);//获取控件的屏幕坐标
		ScreenToClient(&rect);//转换为对话框上的客户坐标
		CPen cPen_q;//创建画笔
		cPen_q.CreatePen(PS_SOLID, 2, RGB(128, 128, 128));
		dc.SelectObject(cPen_q);

		//画点
		for (int i = 0; i < 10; i++) {
			string t = "1";
			t[0] += i;
			if (t[0] == ':') {
				t = "10";
			}
			CString str(t.c_str());

			dc.Ellipse(rect.left + x[i] - 10, rect.top + y[i] - 10, rect.left + x[i] + 10, rect.top + y[i] + 10);
			dc.TextOut(rect.left + x[i], rect.top + y[i], str);
		}

	}

	draw();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CtuDlg::draw() {
	CClientDC dc(this);

	for (int k = 0; k < 3; k++) {

		CWnd* p = (CStatic*)GetDlgItem(IDC_DFS + k);//静态文本框
		CRect rect;
		p->GetClientRect(&rect);

		//p->ScreenToClient(&rect);
		GetDlgItem(IDC_DFS + k)->GetWindowRect(&rect);//获取控件的屏幕坐标
		ScreenToClient(&rect);//转换为对话框上的客户坐标

		//画线
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (mp[i][j] != maxValue) {
					CPen cPen;//创建画笔


					if (color[k][i][j] == 1) {
						cPen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
					}
					else if (color[k][i][j] == 2) {
						cPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
						dc.SetDCPenColor((255, 0, 0));
					}
					else {
						cPen.CreatePen(PS_SOLID, 2, RGB(128, 128, 128));
					}

					dc.SelectObject(cPen);

					//起点
					dc.MoveTo(rect.left + x[i], rect.top + y[i]);

					//终点
					dc.LineTo(rect.left + x[j], rect.top + y[j]);

				}
			}
		}

	}

}

void CtuDlg::dfs(int a) {
	dfstag[a] = 1;
	stack<int> sta;
	sta.push(a);
	//tag[a] = true;
	for (int i = 0; i < 10; i++) {
		int bz = 0;
		vector<dot> vv;
		int t = 0;
		do {
			t = sta.top();
			for (int j = 0; j < 10; j++) {
				if (!dfstag[j] && mp[t][j] != maxValue) {
					dot d;
					d.x = t;
					d.y = j;
					d.c = color[0][t][j];
					vv.push_back(d);
					color[0][t][j] = 2;//可能值
					color[0][j][t] = 2;//可能值
				}
				if (!dfstag[j] && mp[t][j] != maxValue && bz == 0) {
					sta.push(j);
					bz = 1;
				}
			}

			if (bz == 0) {
				sta.pop();
			}
		} while (bz == 0 && !sta.empty());
		draw();
		Sleep(1000);

		//还原
		for (int j = 0; j < vv.size(); j++) {
			color[0][vv[j].x][vv[j].y] = vv[j].c;
			color[0][vv[j].y][vv[j].x] = vv[j].c;
		}
		if (!sta.empty())dfstag[sta.top()] = true;

		if (!sta.empty()) {
			int x1 = sta.top();
			sta.pop();
			int x2 = sta.top();
			sta.push(x1);
			color[0][x1][x2] = 1;
			color[0][x2][x1] = 1;
		}

	}

}

void CtuDlg::prim(int a) {


	//prim
	for (int i = 0; i < 10; i++) {
		dist[i] = maxValue;
	}
	
	dist[a] = 0;

	//dijkstra
	for (int i = 0; i < 10; i++) {
		ddist[i] = maxValue;
	}
	ddist[a] = 0;

	//dfs
	dfstag[a] = 1;

	sta.push(a);

	for (int i = 0; i < 10; i++)
	{

	}

	draw();
}

void CtuDlg::dijkstra(int a) {
	for (int i = 0; i < 10; i++) {
		ddist[i] = maxValue;
	}
	ddist[a] = 0;
	int dtag = 0;

	for (int i = 0; i < 10; i++)
	{
		int dt = -1;

		vector<dot> dvec;
		//t随便初始化了一个不存在的结点，它最终用来存储未确定最小距离的结点，且该结点与其它结点相比目前到起点的距离最小
		for (int j = 0; j < 10; j++) {
			if (dst[j] == 0 && (dt == -1 || ddist[dt] > ddist[j]))
				dt = j;

			if (!dst[j] && ddist[j] != maxValue) {
				dot d;
				d.x = dpre[j];
				d.y = j;
				d.c = color[1][dpre[j]][j];
				dvec.push_back(d);
				color[2][dpre[j]][j] = 2;//可能值
				color[2][j][dpre[j]] = 2;//可能值
			}
		}


		draw();
		//Sleep(1000);

		dtag = 1;
		//还原

		for (int j = 0; j < dvec.size(); j++) {
			color[2][dvec[j].x][dvec[j].y] = dvec[j].c;
			color[2][dvec[j].y][dvec[j].x] = dvec[j].c;
		}

		dst[dt] = true;

		color[2][dpre[dt]][dt] = 1;
		color[2][dt][dpre[dt]] = 1;
		//用结点t依次取更新其它结点到起点的距离，dist[i] = min(dist[i], dist[t] + g[t][i]);
		for (int j = 0; j < 10; j++)
			if (ddist[j] > ddist[dt] + mp[dt][j] && !dst[j])
			{
				ddist[j] = ddist[dt] + mp[dt][j];//更新距离
				dpre[j] = dt;//从 t 到 j 的距离更短，j 的前驱变为 t.
			}

	}


}


//thread a;
void CtuDlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	a = -1;
	dfszh = 0;
	tag = 0;
	dtag = 0;


	jsq = 0;
	press = 0;
	for (int i = 0; i < 10; i++) {
		dfstag[i] = 0;
		st[i] = 0;
		pre[i] = 0;
		dst[i] = 0;
		dpre[i] = 0;
		for (int j = 0; j < 10; j++) {
			color[0][i][j] = 0;
			color[1][i][j] = 0;
			color[2][i][j] = 0;
		}
	}
	CString str1, str2;
	editst.GetWindowText(str1);//中序
	//editend.GetWindowText(str2);//前序/后序
	string kk = CT2CA(str1);
	//string b = CT2CA(str2);
	start = atoi(kk.c_str());
	//myend = atoi(b.c_str());

	
	a = 1;
	//dfs(start-1);
	prim(start - 1);
	SetTimer(1, 1000, NULL);
	//dijkstra(start - 1);
}


void CtuDlg::OnClickedZt()
{
	// TODO: 在此添加控件通知处理程序代码
	if (press == 0) {
		press = 1;
	}
	else {
		press = 0;
	}
}



void CtuDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (a == 1 && jsq < 10 && press == 0) {

		jsq++;
		int t = -1;
		vector<dot> vec;
		for (int j = 0; j < 10; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}

			if (!st[j] && dist[j] != maxValue) {
				dot d;
				d.x = pre[j];
				d.y = j;
				d.c = color[1][pre[j]][j];
				vec.push_back(d);
				color[1][pre[j]][j] = 2;//可能值
				color[1][j][pre[j]] = 2;//可能值
			}

		}

		///////////////////////////djkstra
		int dt = -1;

		vector<dot> dvec;
		//t随便初始化了一个不存在的结点，它最终用来存储未确定最小距离的结点，且该结点与其它结点相比目前到起点的距离最小
		for (int j = 0; j < 10; j++) {
			if (dst[j] == 0 && (dt == -1 || ddist[dt] > ddist[j]))
				dt = j;

			if (!dst[j] && ddist[j] != maxValue) {
				dot d;
				d.x = dpre[j];
				d.y = j;
				d.c = color[2][dpre[j]][j];
				dvec.push_back(d);
				color[2][dpre[j]][j] = 2;//可能值
				color[2][j][dpre[j]] = 2;//可能值
			}
		}
		///////////////////////////djkstra

		int bz = 0;
		vector<dot> vv;
		int tt = 0;
		if (dfszh == 1) {
			///////////////dfs
			do {
				tt = sta.top();
				for (int j = 0; j < 10; j++) {
					if (!dfstag[j] && mp[tt][j] != maxValue) {
						dot d;
						d.x = tt;
						d.y = j;
						d.c = color[0][tt][j];
						vv.push_back(d);
						color[0][tt][j] = 2;//可能值
						color[0][j][tt] = 2;//可能值
					}
					if (!dfstag[j] && mp[tt][j] != maxValue && bz == 0) {
						sta.push(j);
						bz = 1;
					}
				}

				if (bz == 0) {
					sta.pop();
				}
			} while (bz == 0 && !sta.empty());
			///////////////dfs
		}

		draw();


		if (tag != 0) {
			//Sleep(1000);
		}
		tag = 1;
		//还原

		for (int j = 0; j < vec.size(); j++) {
			color[1][vec[j].x][vec[j].y] = vec[j].c;
			color[1][vec[j].y][vec[j].x] = vec[j].c;
		}

		st[t] = true;
		color[1][pre[t]][t] = 1;
		color[1][t][pre[t]] = 1;

		for (int j = 0; j < 10; j++) {
			if (dist[j] > mp[t][j] && !st[j])//从 t 到节点 j 的距离小于原来距离，则更新。
			{
				dist[j] = mp[t][j];//更新距离
				pre[j] = t;//从 t 到 j 的距离更短，j 的前驱变为 t.
			}
		}

		///////////////////dijkstra还原
		for (int j = 0; j < dvec.size(); j++) {
			color[2][dvec[j].x][dvec[j].y] = dvec[j].c;
			color[2][dvec[j].y][dvec[j].x] = dvec[j].c;
		}

		dst[dt] = true;

		color[2][dpre[dt]][dt] = 1;
		color[2][dt][dpre[dt]] = 1;
		//用结点t依次取更新其它结点到起点的距离，dist[i] = min(dist[i], dist[t] + g[t][i]);
		for (int j = 0; j < 10; j++)
			if (ddist[j] > ddist[dt] + mp[dt][j] && !dst[j])
			{
				ddist[j] = ddist[dt] + mp[dt][j];//更新距离
				dpre[j] = dt;//从 t 到 j 的距离更短，j 的前驱变为 t.
			}
		//////////////////

		if (dfszh == 1) {
			/////////////////dfs还原
			for (int j = 0; j < vv.size(); j++) {
				color[0][vv[j].x][vv[j].y] = vv[j].c;
				color[0][vv[j].y][vv[j].x] = vv[j].c;
			}
			if (!sta.empty())dfstag[sta.top()] = true;

			if (!sta.empty()) {
				int x1 = sta.top();
				sta.pop();
				int x2 = sta.top();
				sta.push(x1);
				color[0][x1][x2] = 1;
				color[0][x2][x1] = 1;
			}
			/////////////////dfs还原
		}
		dfszh = 1;
		for (int i = 0; i < 10; i++) {
			pout[ok][i] = dist[i];
			outt[ok][i] = ddist[i];
		}
		ok++;

	}else if(press==0) {
		ofstream out("dist.csv");
		out << "Prim dist" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				out << pout[i][j] << ",";
			}
			out << endl;
		}

		out << "Dijkstra dist" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				out << outt[i][j] << ",";
			}
			out << endl;
		}

		out.close();
		draw();
	}




	if (nIDEvent == 1 && nPress == 1)

	{

		OnClickedZt();
		nPress--;

	}

	if (bStatic == TRUE)

	{

		KillTimer(1);

	}
	CDialogEx::OnTimer(nIDEvent);
}
