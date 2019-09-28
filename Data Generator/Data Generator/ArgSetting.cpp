// ArgSetting.cpp: 实现文件
//

#include "pch.h"
#include "Data Generator.h"
#include "ArgSetting.h"
#include "afxdialogex.h"
#include "DataList.h"

extern DataList List;

// ArgSetting 对话框

IMPLEMENT_DYNAMIC(ArgSetting, CDialogEx)

ArgSetting::ArgSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTING, pParent)
{

}

ArgSetting::~ArgSetting()
{
}

void ArgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DENSITY, m_Density);
	DDX_Control(pDX, IDC_EDIT_GRAVITY, m_GRAVITY);
	DDX_Control(pDX, IDC_EDIT_VISCOSiITY, m_Viscosity);
	DDX_Control(pDX, IDC_EDIT_LENGTH, m_Length);
	DDX_Control(pDX, IDC_EDIT_CORRECTION, m_Correction);
	DDX_Control(pDX, IDC_EDIT_ATMOP, m_AtmosPressure);
	DDX_Control(pDX, IDC_EDIT_DISTANCE, m_Distance);
}


BEGIN_MESSAGE_MAP(ArgSetting, CDialogEx)
	ON_BN_CLICKED(ID_ARGOK, &ArgSetting::OnBnClickedArgok)
	ON_BN_CLICKED(ID_ARGCANCEL, &ArgSetting::OnBnClickedArgcancel)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// ArgSetting 消息处理程序

BOOL ArgSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CString CStmp;
	CStmp.Empty();
	CStmp.Format(L"%d", List.Density);
	m_Density.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.Gravity);
	m_GRAVITY.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.Viscosity);
	m_Viscosity.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.Length);
	m_Length.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.Correction);
	m_Correction.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.AtmosphericPressure);
	m_AtmosPressure.SetWindowTextW(CStmp);
	CStmp.Format(L"%.2f", List.Distance);
	m_Distance.SetWindowTextW(CStmp);
	CStmp.Empty();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ArgSetting::OnBnClickedArgok()
{
	// TODO: 在此添加控件通知处理程序代码

	CString CStmp;
	CStmp.Empty();
	m_Density.GetWindowTextW(CStmp);
	List.Density = _ttoi(CStmp); 
	CStmp.Empty();
	m_GRAVITY.GetWindowTextW(CStmp);
	List.Gravity = _ttof(CStmp);
	CStmp.Empty();
	m_Viscosity.GetWindowTextW(CStmp);
	List.Viscosity = _ttof(CStmp);
	CStmp.Empty();
	m_Length.GetWindowTextW(CStmp);
	List.Length = _ttof(CStmp);
	CStmp.Empty();
	m_Correction.GetWindowTextW(CStmp);
	List.Correction = _ttof(CStmp);
	CStmp.Empty();
	m_AtmosPressure.GetWindowTextW(CStmp);
	List.AtmosphericPressure = _ttof(CStmp);
	CStmp.Empty();
	m_Distance.GetWindowTextW(CStmp);
	List.Distance = _ttof(CStmp);
	CStmp.Empty();

	CDialogEx::OnOK();
}


void ArgSetting::OnBnClickedArgcancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void ArgSetting::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nID == SC_CLOSE)
		CDialogEx::OnCancel();
	CDialogEx::OnSysCommand(nID, lParam);
}
