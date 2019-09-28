#pragma once


// ArgSetting 对话框

class ArgSetting : public CDialogEx
{
	DECLARE_DYNAMIC(ArgSetting)

public:
	ArgSetting(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ArgSetting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedArgok();
	afx_msg void OnBnClickedArgcancel();
	virtual BOOL OnInitDialog();
	CEdit m_Density;
	CEdit m_GRAVITY;
	CEdit m_Viscosity;
	CEdit m_Length;
	CEdit m_Correction;
	CEdit m_AtmosPressure;
	CEdit m_Distance;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
