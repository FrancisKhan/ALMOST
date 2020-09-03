; Name of our application
Name "Almost"

; The file to write
OutFile "Almost_installer.exe"

; Set the default Installation Directory
InstallDir "$PROGRAMFILES64\Almost"

; Set the text which prompts the user to enter the installation directory
DirText "Please choose a directory to which you'd like to install this application."

; ----------------------------------------------------------------------------------
; *************************** SECTION FOR INSTALLING *******************************
; ----------------------------------------------------------------------------------

Section "" ; A "useful" name is not needed as we are not installing separate components

; Set output path to the installation directory. Also sets the working
; directory for shortcuts
SetOutPath $INSTDIR\

File almost.exe
File almost_installer.nsi

WriteUninstaller $INSTDIR\Uninstall.exe

; ///////////////// CREATE SHORT CUTS //////////////////////////////////////

CreateDirectory "$SMPROGRAMS\Almost"


CreateShortCut "$SMPROGRAMS\Almost\Almost.lnk" "$INSTDIR\almost.exe"


CreateShortCut "$SMPROGRAMS\Almost\Uninstall.lnk" "$INSTDIR\Uninstall.exe"

; ///////////////// END CREATING SHORTCUTS ////////////////////////////////// 

; //////// CREATE REGISTRY KEYS FOR ADD/REMOVE PROGRAMS IN CONTROL PANEL /////////

WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Almost" "DisplayName"\
"Almost (remove only)"

WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Almost" "UninstallString" \
"$INSTDIR\Uninstall.exe"

; //////////////////////// END CREATING REGISTRY KEYS ////////////////////////////

SectionEnd

; //////////////////////// APPEND APPLICATION TO PATH ////////////////////////////

; ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "C:\Program Files\Almost"

Section
 
; Set to HKLM
EnVar::SetHKLM
 
; Delete a INSTDIR from a Path
EnVar::DeleteValue "Path" "C:\Program Files\Almost"
Pop $0
DetailPrint "EnVar::DeleteValue returned=|$0|"
  
; Add a INSTDIR to a Path
EnVar::AddValue "Path" "C:\Program Files\Almost"
Pop $0
DetailPrint "EnVar::AddValue returned=|$0|"
  
MessageBox MB_OK "Installation was successful."
  
SectionEnd

; ----------------------------------------------------------------------------------
; ************************** SECTION FOR UNINSTALLING ******************************
; ---------------------------------------------------------------------------------- 

Section "Uninstall"
; remove all the files and folders
Delete $INSTDIR\Uninstall.exe ; delete self
Delete $INSTDIR\almost_installer.nsi
Delete $INSTDIR\almost.exe

RMDir $INSTDIR

; now remove all the startmenu links
Delete "$SMPROGRAMS\Almost\Almost.lnk"
Delete "$SMPROGRAMS\Almost\Uninstall.lnk"
RMDIR "$SMPROGRAMS\Almost"

; Now delete registry keys
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Almost"
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Almost"

; Delete a INSTDIR from a Path
EnVar::SetHKLM
EnVar::DeleteValue "Path" "C:\Program Files\Almost"
Pop $0
DetailPrint "EnVar::DeleteValue returned=|$0|"

SectionEnd
