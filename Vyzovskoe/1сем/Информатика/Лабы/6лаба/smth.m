clear %������� ������
func = input("������� �������: f(x) = ", 's'); %������ ������� � ������������

[left,right] = test2(); %������ � �������� ������ ���������

f=eval(['@(x)' func ]); %���������� ��
x = left:(abs(left)+abs(right))/14:right; %���������� ������� �� 15 ��

for i=1:1:15
   res(i)=integral(f,left,x(i)); % ���������� ������� �� ��. ���������
end
buff = eval(func)
printtable(x,buff,res) %������ �������

for i =1:1:15
    max_res(i) = max(res); 
    min_res(i) = min(res);
end

subplot(1,2,1) %������ �������
plot(x, res,'m-', x, res, "gs", "LineWidth", 2.25)
hold on
plot(x,max_res,"k:", "lineWidth", 0.2) %����� ���� ��
hold on
plot(x,min_res,"k:", "lineWidth", 0.2) %����� ��� ��
hold on

xlabel x
ylabel y
grid on
legend(func, func, "max","min")

subplot(1,2,2)
plot(x, res,"-b", "LineWidth", 1)
hold on
plot(x,max_res,"k:", "lineWidth", 0.2)%����� ���� ��
hold on
plot(x,min_res,"k:", "lineWidth", 0.2)%����� ��� ��
hold on
grid on
xlabel x
ylabel y
legend(func, "max","min")