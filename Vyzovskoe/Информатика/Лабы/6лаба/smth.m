clear %очистка памяти
func = input("Введите функцию: f(x) = ", 's'); %запрос функции у пользователя

[left,right] = test2(); %запрос и проверка границ интервала

f=eval(['@(x)' func ]); %объявление АФ
x = left:(abs(left)+abs(right))/14:right; %построение вектора на 15 эл

for i=1:1:15
   res(i)=integral(f,left,x(i)); % построение вектора со зн. интеграла
end
buff = eval(func)
printtable(x,buff,res) %рисуем таблицу

for i =1:1:15
    max_res(i) = max(res); 
    min_res(i) = min(res);
end

subplot(1,2,1) %рисуем графики
plot(x, res,'m-', x, res, "gs", "LineWidth", 2.25)
hold on
plot(x,max_res,"k:", "lineWidth", 0.2) %линия макс зн
hold on
plot(x,min_res,"k:", "lineWidth", 0.2) %линия мин зн
hold on

xlabel x
ylabel y
grid on
legend(func, func, "max","min")

subplot(1,2,2)
plot(x, res,"-b", "LineWidth", 1)
hold on
plot(x,max_res,"k:", "lineWidth", 0.2)%линия макс зн
hold on
plot(x,min_res,"k:", "lineWidth", 0.2)%линия мин зн
hold on
grid on
xlabel x
ylabel y
legend(func, "max","min")