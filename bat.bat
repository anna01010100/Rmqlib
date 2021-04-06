@echo off
echo %cd%

fc test1.txt test1check.txt > nul
if ERRORLEVEL 1 (echo ERROR1) else (echo OK1)

fc test2.txt test2check.txt > nul
if ERRORLEVEL 1 (echo ERROR2) else (echo OK2)

fc test3.txt test3check.txt > nul
if ERRORLEVEL 1 (echo ERROR3) else (echo OK3)

fc test4.txt test4check.txt > nul
if ERRORLEVEL 1 (echo ERROR4) else (echo OK4)

fc test5.txt test5check.txt > nul
if ERRORLEVEL 1 (echo ERROR5) else (echo OK5)

fc test6.txt test6check.txt > nul
if ERRORLEVEL 1 (echo ERROR6) else (echo OK6)

pause