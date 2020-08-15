close all;clc;
load('position.mat');
alpha1=alpha1-0.1871;
for i=22:15360
    alpha2(i-21)=alpha1(i);
end

ratio= 5/max(alpha2);
alpha2=alpha2*ratio;
plot(alpha2)