# Microsoft Developer Studio Project File - Name="Crea2K6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Crea2K6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Crea2K6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Crea2K6.mak" CFG="Crea2K6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Crea2K6 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Crea2K6 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Crea2K6 - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Crea2K6 - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Crea2K6 - Win32 Release"
# Name "Crea2K6 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AideDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Crea2K6.cpp
# End Source File
# Begin Source File

SOURCE=.\Crea2K6.rc
# End Source File
# Begin Source File

SOURCE=.\Crea2K6Doc.cpp
# End Source File
# Begin Source File

SOURCE=.\Crea2K6View.cpp
# End Source File
# Begin Source File

SOURCE=.\Entite.cpp
# End Source File
# Begin Source File

SOURCE=.\FontPredefDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageFondDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageRessource.cpp
# End Source File
# Begin Source File

SOURCE=.\ImagetteDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Img.cpp
# End Source File
# Begin Source File

SOURCE=.\LesImagesRessources.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Picture.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintData.cpp
# End Source File
# Begin Source File

SOURCE=.\RedimDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Texte.cpp
# End Source File
# Begin Source File

SOURCE=.\TexteDialog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AideDialog.h
# End Source File
# Begin Source File

SOURCE=.\constantes.h
# End Source File
# Begin Source File

SOURCE=.\Crea2K6.h
# End Source File
# Begin Source File

SOURCE=.\Crea2K6Doc.h
# End Source File
# Begin Source File

SOURCE=.\Crea2K6View.h
# End Source File
# Begin Source File

SOURCE=.\Entite.h
# End Source File
# Begin Source File

SOURCE=.\FontPredefDlg.h
# End Source File
# Begin Source File

SOURCE=.\ImageFondDlg.h
# End Source File
# Begin Source File

SOURCE=.\ImageRessource.h
# End Source File
# Begin Source File

SOURCE=.\ImagetteDlg.h
# End Source File
# Begin Source File

SOURCE=.\Img.h
# End Source File
# Begin Source File

SOURCE=.\LesImagesRessources.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Picture.h
# End Source File
# Begin Source File

SOURCE=.\PrintData.h
# End Source File
# Begin Source File

SOURCE=.\RedimDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Texte.h
# End Source File
# Begin Source File

SOURCE=.\TexteDialog.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Crea2K6.ico
# End Source File
# Begin Source File

SOURCE=.\res\Crea2K6.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Crea2K6Doc.ico
# End Source File
# Begin Source File

SOURCE=.\res\EiB.ico
# End Source File
# Begin Source File

SOURCE=.\res\policepr.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
