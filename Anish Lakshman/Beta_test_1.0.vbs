Set objShell = WScript.CreateObject("WScript.Shell")
strDesktop = objShell.SpecialFolders("Desktop")
Set objFSO = CreateObject("Scripting.FileSystemObject")

' Create 5 folders on the desktop
For i = 1 To 60
    strFolderName = "HACKED" & i
    strFolder = strDesktop & "\" & strFolderName
    
    ' Check if folder already exists
    If objFSO.FolderExists(strFolder) Then
       WScript.Echo "Folder already exists: " & strFolder
    Else
       ' Create the folder
       Set objFolder = objFSO.CreateFolder(strFolder)
       WScript.Echo "Folder created: " & strFolder
    End If
Next

Set wshshell = wscript.CreateObject("WScript.Shell")
for i = 1 To 50
Wshshell.run "Notepad"
wscript.sleep 50
wshshell.sendkeys "R"
wscript.sleep 50
wshshell.sendkeys "A"
wscript.sleep 50
wshshell.sendkeys "T"
wscript.sleep 50
wshshell.sendkeys "E"
wscript.sleep 50
wshshell.sendkeys " "
wscript.sleep 50
wshshell.sendkeys "W"
wscript.sleep 50
wshshell.sendkeys "I"
wscript.sleep 50
wshshell.sendkeys "T"
wscript.sleep 50
wshshell.sendkeys "H"
wscript.sleep 50
wshshell.sendkeys " "
wscript.sleep 50
wshshell.sendkeys "S"
wscript.sleep 50
wshshell.sendkeys "P"
wscript.sleep 50
wshshell.sendkeys "E"
wscript.sleep 50
wshshell.sendkeys "C"
wscript.sleep 50
wshshell.sendkeys "T"
wscript.sleep 50
wshshell.sendkeys "A"
wscript.sleep 50
wshshell.sendkeys "C"
wscript.sleep 50
wshshell.sendkeys "U"
wscript.sleep 50
wshshell.sendkeys "L"
wscript.sleep 50
wshshell.sendkeys "A"
wscript.sleep 50
wshshell.sendkeys "R"
wscript.sleep 200
Next
