@echo off
chcp 65001
echo doing deleting 执行删除命令
for /d %%i in (*) do (
    if exist "%%i\x64" (
        echo Deleting x64 folder in "%%i"
        rmdir /s /q "%%i\x64"
    )
)
pause
rmdir /s /q ".vs"
pause
