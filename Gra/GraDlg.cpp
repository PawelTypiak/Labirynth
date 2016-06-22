
// GraDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Gra.h"
#include "GraDlg.h"
#include "afxdialogex.h"
#include "openGLview.h" 
#include <gl\glut.h> 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

openGLview gl;  


void display(void) 
{ 
gl.display(); 
} 
void resize(int w, int h) 
{ 
gl.resize(w, h); 
} 
void keyboard(unsigned char key, int x, int y) 
{ 
gl.keyboard(key, x, y); 
}
void animacja(int value) 
{ 
gl.animacja(); 
glutTimerFunc(30,animacja,0); 
} 
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGraDlg dialog




CGraDlg::CGraDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGraDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CGraDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGraDlg message handlers

BOOL CGraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGraDlg::OnPaint()
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
HCURSOR CGraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGraDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
	

}


void CGraDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//ustawienie kolorów, precyzji i g³êbi 
glutInitWindowSize (800, 600);// ustawiamy pocz¹tkow¹ wielkosc okna 
glutInitWindowPosition (200, 100);// poczatkowa pozycja okna (lewy górny róg)   
glutCreateWindow("openGL test");//tworzymy nowe okno 
// ustawienie odpowiednich funkcji, które bêd¹ wywo³ywane przy odpowiednich zdarzeniach: 
glutDisplayFunc(display);//ustawiamy funkcje display 
glutReshapeFunc(resize);//ustawiamy funkcje resize
glutKeyboardFunc(keyboard); 
char * nazwa1 = new char;
nazwa1 = "mur.bmp"; // nazwa pliku z tekstura 
for(int j=0;j<6;j++)
{
for(int i=0;i<14;i++)
{
		 gl.poziom[0]->sciana[i]->boki[j]->loadTextureFromFile( nazwa1 );
}
for(int i=0;i<18;i++)
{
		 gl.poziom[1]->sciana[i]->boki[j]->loadTextureFromFile( nazwa1 );
}
for(int i=0;i<17;i++)
{
		 gl.poziom[2]->sciana[i]->boki[j]->loadTextureFromFile( nazwa1);
}
for(int i=0;i<19;i++)
{
		 gl.poziom[3]->sciana[i]->boki[j]->loadTextureFromFile( nazwa1 );
}
}
char * nazwa2 = new char;
nazwa2 = "podloga.bmp"; // nazwa pliku z tekstura 
for(int i=0;i<6;i++)
{
	gl.poziom[0]->podstawa->podloga[i]->loadTextureFromFile( nazwa2 );
	gl.poziom[1]->podstawa->podloga[i]->loadTextureFromFile( nazwa2 );
	gl.poziom[2]->podstawa->podloga[i]->loadTextureFromFile( nazwa2 );
	gl.poziom[3]->podstawa->podloga[i]->loadTextureFromFile( nazwa2 );
}
glutTimerFunc(30,animacja,0); //ustawiamy funkcje timera 
this->ShowWindow(SW_HIDE);// ukrywamy g³ówne okno 
glutMainLoop(); //uruchamiamy pêtlê openGL
}
