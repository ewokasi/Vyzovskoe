function acc = acc(a, b,c,d, n)
x= a:(b-a)/n:b;
i=1;
while i <=n
   diff(i)= -(c*(d-2*c.*x.*x))/(c.*x.*x+d).^(5/2);
   i=i+1;
end

acc = max(abs(diff))*((b-a)^3)/(12*n^2);
end