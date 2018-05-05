What is a bad USB?
	BadUSB is a dangerous USB security flaw that allows attackers to turn a simple USB device into a keyboard, which can then be used to type malicious commands into the victim's compute. 

Purpose:
	The purpose of this project is to show that different kind of malicious activity can be done with  micro controller. Another motivation for this project is to show that how easily general people can loose important data without noticing simple things. 
  
  
  
Project Description:
	We are expecting that attacker can be present physically to that device and he can connect the USB-storage & micro controller while destructing the user from the monitor or display of the computer. Assuming that the hacker can not touch keyboard or mouse before the user as he is destructing the user from looking into monitor. The project require first 10-20 sec of destruction from monitor and after that destruction from monitor wont be necessary. 

	When this device would connect then first there will be a shortcut created which will take the user to fake online login page of a popular site. Then this usb will install a software (vlc) which require admin privileges. By this step we want to show that regular users pc can be infected with malicious code such as key logger as we can get admin privileges. Finally specific folder or specific type of file can be hijacked without any visual appearance with the last segment of the code.  This part copy document folder of the user and copy it to a folder of pendrive. While this part starts caps lock led blinks for sometimes to confirm the hacker that they have reached this segment and when the caps lock led blink again the hacker can remove the micro controller form the device . Again the micro controller also blinks continuously after all the code executes.

Target victim’s:  general people
Attack type : physical attacks
Expected Attacking methods : social engineering 
Target platform: Windows


Equipment's:
    • pen drive
    • digispark micro controller

Working principle :
	To run this badusb the only necessary step is to connect the usb device with the computer while its logged in by the target user. After plugging this device computer will detect it as USB human interface device  and give full access as Human interface device . 
 
About digispark micro controller:
	Its a low power micro controller with Attiny 85 micro processor. More about digispark and ATtiny85 :
http://digistump.com/products/1
https://www.microchip.com/wwwproducts/en/ATtiny85

File theft:
Step 1:
powershell ".((gwmi win32_volume -f 'label=''_''').Name+'d.cmd')"
. means run
Gwmi : Get-WmiObject
(gwmi win32_volume -f 'label=''_''').Name  : gives the drive latter 

finally opens powershell run (gwmi win32_volume -f 'label=''_''').Name to get the drive letter of the pendrive which is named as“_” . Then run d.cmd file.

Step 2:
d.cmd then runs and open power shell without logo and its also in hidden mode which means nothing in the shell will be displayed. Then it will turn on and off caps lock to mae sure that we successfully found the location of the pen drive and d.cmd is working. In the end of d.cmd we start I.vbs and e.vbs. Where %~d0  means drive letter of the batch files.

Step 3:
i.vbs
CreateObject("Wscript.Shell").Run """" & WScript.Arguments(0) & """", 0, False
it runs all the bath files invisibly 

Step 4:
Creates a directories in the pen drive and name it “NSUCSE_navid” . Then use xcopy command to copy all the files in documents folder of the current user directory with specific commands so that no prompt or permission is asked. 

Shortcut corruption:
This will corrupt the shortcut and let the bad actor execute anything secretly or visibly. In this project we are corrupting firefox shortcut and when it opens it takes us to certain website.

Installation with admin privileges :
In this part we are showing that any admin privileges can be gained easily and a external executable software can be installed. We have used vlc to prove it. A bad actor can do a lot of damage with such privileges.




Some abbreviation and links


Gwmi : Get-WmiObject 
The Get-WmiObject cmdlet gets instances of Windows Management Instrumentation (WMI) classes or information about the available WMI classes. To specify a remote computer, use the ComputerName parameter. If the List parameter is specified, the cmdlet gets information about the WMI classes that are available in a specified namespace. If the Query parameter is specified, the cmdlet runs a WMI query language (WQL) statement.

https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/get-wmiobject?view=powershell-5.1

Windows Script Host (WSH) 
http://digistump.com/board/index.php/topic,894.0.html
%~d0  means drive letter of the batch files

% is an alias for the ForEach-Object cmdlet.
A cmdlet is a lightweight command that is used in the Windows PowerShell environment.
