function lagr = lagr(x, y, s)
    %����� �� ��������
    res=0;
    for i =1:1:length(x)
        upst(i)=1; %���������
        downst(i)=1; %�����������
       for m = 1:1:length(x)
          if m~=i
             upst(i)=(s-x(m))*upst(i); %���������
             downst(i) = downst(i)* (x(i)-x(m));
          end

       end
       poly(i) = upst(i)/downst(i); %��� �� ����� �� ������� �������� �������� ���������
       slag(i) =poly(i)*y(i);
       res = res+ slag(i);
    end
    lagr=res %�����
end