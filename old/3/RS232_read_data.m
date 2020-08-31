% for j=1:10
clear;
close all;clc;
if (exist('S','var'))              %檢查S的data變數是否存在，如有就會自動清除
    fclose(S);
    clear S;
end
S = serial('COM14');                %***S為serial port
S.BaudRate = 115200;
fopen(S);

while(S.BytesAvailable == 0)        %read from the input buffer,判斷s是否有Data進來
end

Data = [];                          %將Data清空

for i = 1:120                       % 512 samples/per i
    Data = [Data;fread(S)];         %讀取S的Data
end
fclose(S);

idx222 = find(Data==222);           %宣告Data == 222 為header
idx253 = find(Data==253);           %宣告Data == 253 為terminator
first_idx = idx222(1);
Data=Data(first_idx:end);           %由header到terminator：驗證Data傳送是否完整
Data1=[];
Data2=[];
Data3=[];
Data4=[];
Data5=[];
Data6=[];
Data7=[];
Data8=[];

for i=1:floor(length(Data)/10)       %floor:取得最接近正數的值
    Data1(i) = Data(2+10*(i-1));     %存在第幾個Data的位置
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
plot(alpha2)             % *256：是指Data向左移8個byte，所以可分成 high byte跟low byte
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