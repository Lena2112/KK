set PROGRAM="%~1" 

rem ������������� �����������
%PROGRAM% 5 5 5 
if ERRORLEVEL 1 goto err 

rem �������������� �����������
%PROGRAM% 6 6 9 
if ERRORLEVEL 1 goto err 

rem ������� �����������
%PROGRAM% 3 4 5
if ERRORLEVEL 1 goto err 

rem �� ����� ���� �������������
%PROGRAM% 1 5 3 
if ERRORLEVEL 1 goto err

rem ������� �� ����� ���� ��������������
%PROGRAM%  0 4 -2
if NOT ERRORLEVEL 1 goto err

rem ������������ ����������
%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

rem ������������ ��������
%PROGRAM% 3 m 7
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded 
exit 0 

:err
echo Program testing failed 
exit 1