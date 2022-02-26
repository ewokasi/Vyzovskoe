function solve = solve(x, eps,a,b,c,d)
%функция решения методом Ньютона
n=0; %номер приближения
while abs(f(x,a,b,c,d)/f1(x,a,b,c,d))>eps %привближаем х по методу ньютона, пока не будет достигнута точность
  n= n+1;
  x = x-f(x,a,b,c,d)/f1(x,a,b,c,d);
end
solve = x %возвращаем значение
end