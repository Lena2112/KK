set PROGRAM="%~1" 

rem раносторонний треугольник
%PROGRAM% 5 5 5 
if ERRORLEVEL 1 goto err 

rem равнобедренный треугольник
%PROGRAM% 6 6 9 
if ERRORLEVEL 1 goto err 

rem обычный треугольник
%PROGRAM% 3 4 5
if ERRORLEVEL 1 goto err 

rem не может быть треугольником
%PROGRAM% 1 5 3 
if ERRORLEVEL 1 goto err

rem стороны не могут быть отрицательными
%PROGRAM%  0 4 -2
if NOT ERRORLEVEL 1 goto err

rem недостаточно параметров
%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded 
exit 0 

:err
echo Program testing failed 
exit 1