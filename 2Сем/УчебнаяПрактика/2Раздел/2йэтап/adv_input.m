function adv_input = adv_input(str)
%��������, ��� ������������ ���� ������ �����
    while 1  
        error = 0;
        data = str2num(input(str, 's'));
        res = isnan(data);
   
        for i = 1:1:length(res)
           if res(i)==1 & data(i)~="." & data(i)~=" "
               
               fprintf("������, ������� �� �����\n")
               error = 1;
               break;
               
           end
        end
        if error ==0
           adv_input = data;
           break
        end
    end
end