@echo  off
SETLOCAL

cls

echo =========================== git status =================================
git pull
pause

echo =========================== git status =================================
git status
pause

echo/
echo/
set /p "commit_message=Enter your commit message: "

echo =========================== git add -A =================================
git add -A
echo/
echo/
echo =========================== git commit -m "My Message" =================
git commit -m %commit_message%
echo/
echo/
echo =========================== git push ===================================
git push
echo/
echo/
echo =========================== git status =================================
git status
echo/
echo/


ENDLOCAL