clear %������ 

fun = input("������� ������� ���� y=f(x): ", 's'); %����������� �������
[left,right] = test2(); %������ � �������� ������ ���������
step = stepcheck(left,right);

x = left:step:right; %�������� ������� x

eval(fun);       %��������� ������� ������������
printtable(x,y); %������ �������
plot(x,y);       %������ ������
grid on;
xlabel x;
ylabel y;
legend(fun);

