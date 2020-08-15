close all;clc;
load('speed.mat');
for i =1 :1000
    alpha_prime1_smooth3(i)=alpha_prime1_smooth2(i);
end
for i= 1001:14359
    alpha_prime1_smooth3(i)=mean(alpha_prime1_smooth2(i-1000:i+1000));
end
for i=251 :700
    alpha_prime1_smooth3(i)=mean(alpha_prime1_smooth3(i-250:i+250));
end
plot(alpha_prime1_smooth3);    