% for j=1:10
close all;clc;
if (exist('S','var'))               %�ˬdS��data�ܼƬO�_�s�b�A�p���N�|�۰ʲM��
    fclose(S);
    clear S;
end
S = serial('COM14');                %S��serial port
S.BaudRate = 115200;
fopen(S);

while(S.BytesAvailable == 0)        %read from the input buffer,�P�_s�O�_��Data�i��
end

Data = [];                          %�NData�M��
% 
for i = 1:180                     % 512 samples/per i
    Data = [Data;fread(S)];         %Ū��S��Data
end
fclose(S);

idx222 = find(Data==222);           %�ŧiData == 222 ��header
idx253 = find(Data==253);           %�ŧiData == 253 ��terminator
first_idx = idx222(1);
Data=Data(first_idx:end);           %��header��terminator�G����Data�ǰe�O�_����
Data1=[];
Data2=[];
Data3=[];
Data4=[];



for i=1:floor(length(Data)/6)       %floor:���o�̱��񥿼ƪ���
    Data1(i) = Data(2+6*(i-1));     %�s�b�ĴX��Data����m
    Data2(i) = Data(3+6*(i-1));      
    Data3(i) = Data(4+6*(i-1));     %�s�b�ĴX��Data����m
    Data4(i) = Data(5+6*(i-1)); 
   
end
count_t=Data2*256+Data1;
count_t2=Data4*256+Data3;

count_t=count_t;
count_t2=count_t2;

%theta=pi/1000*(Data2*256+Data1);   %2000 �@��
% theta=count_t*pi/1000;
alpha1=count_t*pi/1000;
beta1=((-1)*count_t2*pi/1000)+pi;

beta_smooth=smooth(beta1);
%alpha_smooth=smooth(alpha1);%raw data don't smooth
alpha_smooth=alpha1;
for i = 1:(length(beta_smooth)-1)
    if(beta_smooth(i+1) - beta_smooth(i)<=0)
        beta_prime1(i) = (beta_smooth(i+1) - beta_smooth(i))/0.001;  %0.001����@����
    else
        beta_prime1(i)=beta_prime1(i-1);
    end
end
 beta_prime1_smooth=smooth( beta_prime1,100);
 
 
 for i = 1:(length(alpha_smooth)-1)
    if(alpha_smooth(i+1) - alpha_smooth(i)>=0)
        alpha_prime1(i) = (alpha_smooth(i+1) - alpha_smooth(i))/0.001;  %0.001����@����
    else
        alpha_prime1(i)=alpha_prime1(i-1);
    end
 end

%  for i = 1:(length(alpha_prime1(i))-2)
%      if(i>2)
%          alpha_prime1_s(i)=alpha_prime1(i-2)+alpha_prime1(i-1)+alpha_prime1(i)+alpha_prime1(i+1)+alpha_prime1(i+2);
%      else
%          alpha_prime1_s(i)=alpha_prime1(i);
%      end
%  end
%    
alpha_prime1_smooth=smooth(alpha_prime1,200);
alpha_prime1_smooth2=smooth(alpha_prime1_smooth,100);

figure(1);
subplot(2,1,1);plot(alpha_smooth);title('alpha');
subplot(2,1,2);plot(beta_smooth);title('beta');

figure(2);
subplot(2,1,1);plot(alpha_prime1_smooth2);title('alpha_prime');
subplot(2,1,2);plot(beta_prime1_smooth);title('beta_prime');

grid on;
    

