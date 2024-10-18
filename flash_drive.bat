@echo off
chcp 65001
setlocal

set flash_drive=E:\

if not exist "%flash_drive%" (
    echo Flash drive not found.
    exit /b
)

echo Copying files to a flash drive...
xcopy "D:\example.txt\*.*" "%flash_drive%" /s /i /y

echo Copying completed.
pause