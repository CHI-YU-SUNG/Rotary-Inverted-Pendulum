% for j=1:10
clear;
close all;clc;
if (exist('S','var'))              %�ˬdS��data�ܼƬO�_�s�b�A�p���N�|�۰ʲM��
    fclose(S);
    clear S;
end
S = serial('COM14');                %***S��serial port
S.BaudRate = 115200;
fopen(S);

while(S.BytesAvailable == 0)        %read from the input buffer,�P�_s�O�_��Data�i��
end

Data = [];                          %�NData�M��

for i = 1:120                       % 512 samples/per i
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
Data5=[];
Data6=[];
Data7=[];
Data8=[];

for i=1:floor(length(Data)/10)       %floor:���o�̱��񥿼ƪ���
    Data1(i) = Data(2+10*(i-1));     %�s�b�ĴX��Data����m
    Data2(i) = Data(3+10*(i-1)); 
    Data3(i) =Data(4+10*(i-1));
    Data4(i) =Data(5+10*(i-1));
    Data5(i) =Data(6+10*(i-1));
    Data6(i) = Data(7+10*(i-1));
    Data7(i) =Data(8+10*(i-1));
    Data8(i) = Data(9+10*(i-1));
end

alpha2=(Data6*256+Data5-50000)*pi/1000;          %C is a constant after the transformation of the unit. You guys have to change it!

figure(1);
plot(alpha2)             % *256�G�O��Data�V����8��byte�A�ҥH�i���� high byte��low byte
ylabel('\alpha')
grid on;

beta2=-(Data2*256+Data1-5000)*pi/1000+pi;

figure(2);
plot(beta2)             
ylabel('\beta')
grid on;
%bbb = beta2;
aa= alpha2;
bb=beta2;