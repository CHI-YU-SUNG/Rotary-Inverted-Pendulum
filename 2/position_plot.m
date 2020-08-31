close all;clc;
load('position.mat');
plot(alpha1),title('alpha poistion'),xlabel('time(count)'),ylabel('rad');
plot((beta1-3.14)),title('beta poistion'),xlabel('time(count)'),ylabel('degree');