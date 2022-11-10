clear %чистка 

fun = input("Введите функцию вида y=f(x): ", 's'); %запрашиваем функцию
[left,right] = test2(); %запрос и проверка границ интервала
step = stepcheck(left,right);

x = left:step:right; %создание вектора x

eval(fun);       %исполняем функцию пользователя
printtable(x,y); %рисуем таблицу
plot(x,y);       %рисуем график
grid on;
xlabel x;
ylabel y;
legend(fun);

