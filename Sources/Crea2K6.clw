; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCrea2K6View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Crea2K6.h"
LastPage=0

ClassCount=11
Class1=CCrea2K6App
Class2=CCrea2K6Doc
Class3=CCrea2K6View
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDD_DIALOG_IMAGETTE
Resource3=IDR_CURSOR_MENU
Class6=CTexteDialog
Resource4=IDD_DIALOG_AIDE
Class7=CImageFondDlg
Resource5=IDD_DIALOG_IMGFOND
Class8=CImagetteDlg
Resource6=IDD_DIALOG_TEXTE
Class9=CFontPredefDlg
Resource7=IDD_DIALOG_FONTPREDEF
Class10=CAideDialog
Resource8=IDR_MAINFRAME
Class11=CRedimDlg
Resource9=IDD_DIALOG_REDIM

[CLS:CCrea2K6App]
Type=0
HeaderFile=Crea2K6.h
ImplementationFile=Crea2K6.cpp
Filter=N

[CLS:CCrea2K6Doc]
Type=0
HeaderFile=Crea2K6Doc.h
ImplementationFile=Crea2K6Doc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CCrea2K6Doc

[CLS:CCrea2K6View]
Type=0
HeaderFile=Crea2K6View.h
ImplementationFile=Crea2K6View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENU2_RECULEDUNEPOSITION


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FORMAT_INVITATION
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Crea2K6.cpp
ImplementationFile=Crea2K6.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_FORMAT_CARTEDEVISITE
Command13=ID_FORMAT_CARTEDEVOEUX
Command14=ID_FORMAT_CARTEPOSTALE
Command15=ID_FORMAT_INVITATION
Command16=ID_INSERTION_TEXTE
Command17=ID_INSERTION_IMAGE
Command18=ID_RESSOURCES_COULEURDUFOND
Command19=ID_RESSOURCES_IMAGEDEFOND
Command20=ID_RESSOURCES_IMAGETTES
Command21=ID_RESSOURCES_POLICESPRDFINIES
Command22=ID_APP_ABOUT
Command23=ID__AIDE
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FORMAT_CARTEPOSTALE
Command2=ID_EDIT_COPY
Command3=ID_FORMAT_CARTEDEVOEUX
Command4=ID_FORMAT_INVITATION
Command5=ID_FILE_NEW
Command6=ID_FILE_OPEN
Command7=ID_FILE_PRINT
Command8=ID_FILE_SAVE
Command9=ID_FORMAT_CARTEDEVISITE
Command10=ID__AIDE
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
CommandCount=12

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_INSERTION_TEXTE
Command10=ID_RESSOURCES_POLICESPRDFINIES
Command11=ID_INSERTION_IMAGE
Command12=ID_RESSOURCES_IMAGETTES
Command13=ID_RESSOURCES_IMAGEDEFOND
CommandCount=13

[MNU:IDR_CURSOR_MENU]
Type=1
Class=CCrea2K6View
Command1=ID_TO_BACK
Command2=ID_DEPLACER
Command3=ID_DELETE
Command4=ID_MENU0_EDITER
Command5=ID_TO_BACK
Command6=ID_DEPLACER2
Command7=ID_DELETE
Command8=ID_MENU1_REDIMENSIONNER
Command9=ID_MENU2_AJOUTERUNTEXTE
Command10=ID_MENU2_AJOUTERUNEPOLICEPRDFINIE
Command11=ID_MENU2_AJOUTERUNEIMAGE
Command12=ID_MENU2_SUPPRIMERUNIMAGEDEFOND
Command13=ID_MENU2_AJOUTERUNECOULEURDEFOND
Command14=ID_MENU2_AJOUTERUNEIMAGETTE
CommandCount=14

[DLG:IDD_DIALOG_TEXTE]
Type=1
Class=CTexteDialog
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_POLICE,button,1342242816
Control4=IDC_EDIT_CONTENU,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RADIO1,button,1342177289
Control7=IDC_RADIO2,button,1342177289
Control8=IDC_RADIO3,button,1342177289
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON_COULEUR,button,1342242816

[CLS:CTexteDialog]
Type=0
HeaderFile=TexteDialog.h
ImplementationFile=TexteDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CTexteDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_IMGFOND]
Type=1
Class=CImageFondDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_LIST2,listbox,1352728835
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_APPLIQUER1,button,1342242816

[CLS:CImageFondDlg]
Type=0
HeaderFile=ImageFondDlg.h
ImplementationFile=ImageFondDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_APPLIQUER1
VirtualFilter=dWC

[DLG:IDD_DIALOG_IMAGETTE]
Type=1
Class=CImagetteDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_LIST2,listbox,1352728835
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_APPLIQUER,button,1342242816

[CLS:CImagetteDlg]
Type=0
HeaderFile=ImagetteDlg.h
ImplementationFile=ImagetteDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_APPLIQUER
VirtualFilter=dWC

[DLG:IDD_DIALOG_FONTPREDEF]
Type=1
Class=CFontPredefDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_RADIO5,button,1342177289
Control7=IDC_RADIO4,button,1342177289
Control8=IDC_RADIO6,button,1342177289
Control9=IDC_RADIO7,button,1342177289
Control10=IDC_RADIO8,button,1342177289
Control11=IDC_RADIO9,button,1342177289
Control12=IDC_STATIC,static,1342177294

[CLS:CFontPredefDlg]
Type=0
HeaderFile=FontPredefDlg.h
ImplementationFile=FontPredefDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO1
VirtualFilter=dWC

[DLG:IDD_DIALOG_AIDE]
Type=1
Class=CAideDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BUTTON1,button,1342242816

[CLS:CAideDialog]
Type=0
HeaderFile=AideDialog.h
ImplementationFile=AideDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENU1_REDIMENSIONNER
VirtualFilter=dWC

[DLG:IDD_DIALOG_REDIM]
Type=1
Class=CRedimDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CRedimDlg]
Type=0
HeaderFile=RedimDlg.h
ImplementationFile=RedimDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRedimDlg

