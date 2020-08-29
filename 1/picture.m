clear;
close all ;clc;
load('ID.mat');

figure;plot(alpha_smooth),title('alpha'),xlabel('time(ms)'),ylabel('degree')
figure;plot(alpha_prime1_smooth2),title('alpha speed'),xlabel('time(ms)'),ylabel('degree') 

figure;plot(beta1),title('beta'),xlabel('time(ms)'),ylabel('degree')

 for i = 1:(length(alpha_prime1_smooth2)-1)
    if(alpha_prime1_smooth2(i+1) - alpha_prime1_smooth2(i)>=0)
        alpha_prime2(i) = (alpha_prime1_smooth2(i+1) - alpha_prime1_smooth2(i))/0.001;  %0.001秒取一次值
    else
        alpha_prime2(i)=alpha_prime2(i-1);
    end
 end
 a=[alpha_prime1_smooth2];
 for i=1:15358
     a(i,2)=5;
 end
 a=a(1:5000,:);
 y=alpha_prime2(1:5000)';
 x=inv(a'*a)*a'*y




