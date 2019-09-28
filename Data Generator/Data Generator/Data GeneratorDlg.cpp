
// Data GeneratorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Data Generator.h"
#include "Data GeneratorDlg.h"
#include "afxdialogex.h"
#include "ArgSetting.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Global Variable

DataList List;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CDataGeneratorDlg dialog



CDataGeneratorDlg::CDataGeneratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATAGENERATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_INVERSE, m_InverseOperation);
}

BEGIN_MESSAGE_MAP(CDataGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_SETTING, &CDataGeneratorDlg::OnBnClickedSetting)
	ON_BN_CLICKED(ID_GENERATE, &CDataGeneratorDlg::OnBnClickedGenerate)
	ON_BN_CLICKED(ID_CANCEL, &CDataGeneratorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK_INVERSE, &CDataGeneratorDlg::OnBnClickedCheckInverse)
END_MESSAGE_MAP()


// CDataGeneratorDlg message handlers

BOOL CDataGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_TipsIteration.Create(this);
	m_TipsIteration.AddTool(GetDlgItem(IDC_ITERATION), L"迭代次数越高，逆向运算准确度越高");
	m_TipsIteration.SetDelayTime(200);
	m_TipsIteration.SetTipTextColor(RGB(255, 255, 255));
	m_TipsIteration.SetTipBkColor(RGB(96, 96, 96));
	m_TipsIteration.Activate(TRUE);

	GetDlgItem(IDC_ITERATION_)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ITERATION)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAX_ELE_)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAX_ELE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAX_V_)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAX_V)->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDataGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_CLOSE)
		CDialogEx::OnCancel();
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDataGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDataGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDataGeneratorDlg::OnBnClickedSetting()
{
	// TODO: 在此添加控件通知处理程序代码
	ArgSetting Dlg;
	Dlg.DoModal();
}


void CDataGeneratorDlg::OnBnClickedGenerate()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSelect = m_InverseOperation.GetCheck();
	CString CStmp;
	CStmp.Empty();
	MeasureData m_Data[4];
	if (nSelect == 0)
	{
		m_Data[0] = GetMeasureData(IDC_VOLTAGE1, 1, m_Data[0]);
		m_Data[0] = GetMeasureData(IDC_TIME1, 2, m_Data[0]);
		m_Data[1] = GetMeasureData(IDC_VOLTAGE2, 1, m_Data[1]);
		m_Data[1] = GetMeasureData(IDC_TIME2, 2, m_Data[1]);
		m_Data[2] = GetMeasureData(IDC_VOLTAGE3, 1, m_Data[2]);
		m_Data[2] = GetMeasureData(IDC_TIME3, 2, m_Data[2]);
		m_Data[3] = GetMeasureData(IDC_VOLTAGE4, 1, m_Data[3]);
		m_Data[3] = GetMeasureData(IDC_TIME4, 2, m_Data[3]);

		for (int i = 0; i < 4; i++)
		{
			m_Data[i] = List.ForwardOperation(m_Data[i]);
		}
	}
	else if (nSelect == 1)
	{
		m_Data[0] = GetMeasureData(IDC_DECIATION1, 3, m_Data[0]);
		m_Data[1] = GetMeasureData(IDC_DECIATION2, 3, m_Data[1]);
		m_Data[2] = GetMeasureData(IDC_DECIATION3, 3, m_Data[2]);
		m_Data[3] = GetMeasureData(IDC_DECIATION4, 3, m_Data[3]);

		for (int i = 0; i < 4; i++)
		{
			m_Data[i] = GetMeasureData(IDC_ITERATION, 4, m_Data[i]);
			m_Data[i] = GetMeasureData(IDC_MAX_ELE, 5, m_Data[i]);
			m_Data[i] = GetMeasureData(IDC_MAX_V, 6, m_Data[i]);
			m_Data[i] = List.InverseOperation(m_Data[i]);
		}
	}

	if (!SetMeasureData(m_Data))
	{
		MessageBox(L"Some error occours.", L"Error", MB_OK);
	}
	
	//CDialogEx::OnOK();
}


void CDataGeneratorDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

MeasureData CDataGeneratorDlg::GetMeasureData(const int ID, int flag, MeasureData Data)
{
	CString CStmp;
	double value = 0;
	CStmp.Empty();
	GetDlgItem(ID)->GetWindowTextW(CStmp);
	if (!CStmp.IsEmpty())
	{
		value = _ttof(CStmp);
	}
	if (flag == 1)  Data.Voltage = value;
	else if (flag == 2) Data.Time = value;
	else if (flag == 3) Data.Deciation = value;
	else if (flag == 4) Data.Iteration = (int)value;
	else if (flag == 5) Data.max_Electronic = (int)value;
	else if (flag == 6) Data.max_Voltage = value;
	return Data;
}

BOOL CDataGeneratorDlg::SetMeasureData(MeasureData Data[4])
{
	CString CStmp;
	CStmp.Empty();
	CStmp.Format(L"%.2f", Data[0].Voltage);
	GetDlgItem(IDC_VOLTAGE1)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[0].Time);
	GetDlgItem(IDC_TIME1)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[0].Charge, Data[0].Index);
	GetDlgItem(IDC_CHARGE1)->SetWindowTextW(CStmp);
	CStmp.Format(L"%d", Data[0].Electronic);
	GetDlgItem(IDC_ELECTRON1)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[0].EleCharge, Data[0].Index2);
	GetDlgItem(IDC_ELECHARGE1)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[0].Deciation);
	GetDlgItem(IDC_DECIATION1)->SetWindowTextW(CStmp);

	CStmp.Format(L"%.2f", Data[1].Voltage);
	GetDlgItem(IDC_VOLTAGE2)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[1].Time);
	GetDlgItem(IDC_TIME2)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[1].Charge, Data[1].Index);
	GetDlgItem(IDC_CHARGE2)->SetWindowTextW(CStmp);
	CStmp.Format(L"%d", Data[1].Electronic);
	GetDlgItem(IDC_ELECTRON2)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[1].EleCharge, Data[1].Index2);
	GetDlgItem(IDC_ELECHARGE2)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[1].Deciation);
	GetDlgItem(IDC_DECIATION2)->SetWindowTextW(CStmp);

	CStmp.Format(L"%.2f", Data[2].Voltage);
	GetDlgItem(IDC_VOLTAGE3)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[2].Time);
	GetDlgItem(IDC_TIME3)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[2].Charge, Data[2].Index);
	GetDlgItem(IDC_CHARGE3)->SetWindowTextW(CStmp);
	CStmp.Format(L"%d", Data[2].Electronic);
	GetDlgItem(IDC_ELECTRON3)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[2].EleCharge, Data[2].Index2);
	GetDlgItem(IDC_ELECHARGE3)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[2].Deciation);
	GetDlgItem(IDC_DECIATION3)->SetWindowTextW(CStmp);

	CStmp.Format(L"%.2f", Data[3].Voltage);
	GetDlgItem(IDC_VOLTAGE4)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[3].Time);
	GetDlgItem(IDC_TIME4)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[3].Charge, Data[3].Index);
	GetDlgItem(IDC_CHARGE4)->SetWindowTextW(CStmp);
	CStmp.Format(L"%d", Data[3].Electronic);
	GetDlgItem(IDC_ELECTRON4)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2fe%d", Data[3].EleCharge, Data[3].Index2);
	GetDlgItem(IDC_ELECHARGE4)->SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", Data[3].Deciation);
	GetDlgItem(IDC_DECIATION4)->SetWindowTextW(CStmp);

	return TRUE;
}


void CDataGeneratorDlg::OnBnClickedCheckInverse()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSelect = m_InverseOperation.GetCheck();
	if (nSelect == 1)
	{
		GetDlgItem(IDC_ITERATION_)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ITERATION)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ITERATION)->SetWindowTextW(L"10");
		GetDlgItem(IDC_MAX_ELE_)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAX_ELE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAX_ELE)->SetWindowTextW(L"12");
		GetDlgItem(IDC_MAX_V_)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAX_V)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAX_V)->SetWindowTextW(L"30");
	}
	else if (nSelect == 0)
	{
		GetDlgItem(IDC_ITERATION_)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ITERATION)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAX_ELE_)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAX_ELE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAX_V_)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAX_V)->ShowWindow(SW_HIDE);
	}
}


BOOL CDataGeneratorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_MOUSEMOVE) 
		m_TipsIteration.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}
