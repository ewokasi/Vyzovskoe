function solve = solve(x, eps,a,b,c,d)
%������� ������� ������� �������
n=0; %����� �����������
while abs(f(x,a,b,c,d)/f1(x,a,b,c,d))>eps %����������� � �� ������ �������, ���� �� ����� ���������� ��������
  n= n+1;
  x = x-f(x,a,b,c,d)/f1(x,a,b,c,d);
end
solve = x %���������� ��������
end