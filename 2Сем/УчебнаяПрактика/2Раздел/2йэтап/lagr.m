function lagr = lagr(x, y, s)
    %Поиск по Лагранжу
    res=0;
    for i =1:1:length(x)
        upst(i)=1; %числитель
        downst(i)=1; %знаменатель
       for m = 1:1:length(x)
          if m~=i
             upst(i)=(s-x(m))*upst(i); %заполняем
             downst(i) = downst(i)* (x(i)-x(m));
          end

       end
       poly(i) = upst(i)/downst(i); %шаг за шагом по формуле Лагранжа получаем результат
       slag(i) =poly(i)*y(i);
       res = res+ slag(i);
    end
    lagr=res %вывод
end