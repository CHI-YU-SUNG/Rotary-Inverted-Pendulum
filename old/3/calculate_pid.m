clc;
clear;
Sigma=[2.1241    1.0055    0.1290  131.1380];
Rho=[ 0.0862    0.1820    0.3244    1.5248];
P=[-1 -9 -90];
KP=((P(1)*P(2)+P(2)*P(3)+P(3)*P(1))*(1-Sigma(1)*Rho(2))+Sigma(4)-Rho(3)*Sigma(3))/(-1*Sigma(1)*Rho(4));
KI=((-1*P(1)*P(2)*P(3))*(1-Sigma(1)*Rho(2))+Rho(3)*Sigma(4))/(-1*Sigma(1)*Rho(4));
KD=((-P(1)-P(2)-P(3))*(1-Sigma(1)*Rho(2))-Sigma(3)-Rho(3))/(-1*Sigma(1)*Rho(4));
