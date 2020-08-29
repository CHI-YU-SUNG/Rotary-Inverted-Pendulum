alpha=5.49;
beta=58.47;
vs=5;
h=0.01;
x0=0;
x=zeros(1,1000);
t=zeros(1,1000);

k0=h*(-alpha*x0+beta*vs);
k1=h*(-alpha*(x0+k0/2)+beta*vs);
k2=h*(-alpha*(x0+k1/2)+beta*vs);
k3=h*(-alpha*(x0+k2)+beta*vs);
x(1)=x0+(k0+2*k1+2*k2+k3)/6;
t(1)=h;

for n=1:999
    k0=h*(-alpha*x(n)+beta*vs);
    k1=h*(-alpha*(x(n)+k0/2)+beta*vs);
    k2=h*(-alpha*(x(n)+k1/2)+beta*vs);
    k3=h*(-alpha*(x(n)+k2)+beta*vs);
    x(n+1)=x(n)+(k0+2*k1+2*k2+k3)/6;
    t(n+1)=t(n)+h;
end

plot(t,x),title('runge kutta'),xlabel('time(s)'),ylabel('votage');
