
// Data GeneratorDlg.h : header file
//

#pragma once

#include "DataList.h"

// CDataGeneratorDlg dialog
class CDataGeneratorDlg : public CDialogEx
{
// Construction
public:
	CDataGeneratorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATAGENERATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSetting();
	afx_msg void OnBnClickedGenerate();
	afx_msg void OnBnClickedCancel();
	CButton m_InverseOperation;
	MeasureData GetMeasureData(const int ID, int flag, MeasureData Data);
	BOOL SetMeasureData(MeasureData Data[4]);
	afx_msg void OnBnClickedCheckInverse();
	CToolTipCtrl m_TipsIteration;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
