close all;clc;
load('speed.mat');
figure;
plot(alpha1),title('alpha poistion'),xlabel('time(count)'),ylabel('rad');
figure;
plot(alpha_prime1_smooth2),title('alpha speed'),xlabel('time(count)'),ylabel('rad/sec');    