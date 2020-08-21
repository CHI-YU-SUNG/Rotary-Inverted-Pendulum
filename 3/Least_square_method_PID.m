
clear,  clc;
load('alpha average.mat', 'aa')
load('beta average.mat', 'bb')
%load bbb;
load('fixed_alpha.mat', 'bbb')
h = 0.001;

% ( 9-7 ) fix alpha
start = 1; 
final = 980;

t = (start-1)*h:h:(final-1)*h;
beta = bbb( start:final );

polyCoe2 = polyfit( t, beta, 5 );

polyCoe2Der = polyder( polyCoe2 );

betaDot = polyval( polyCoe2Der, t );

beta2Dot = polyval( polyder( polyCoe2Der ), t );

E = beta2Dot';
P3 = -betaDot';
P4 = ( sin( beta ) )';
P = [ P3 P4 ];
Sigma2 = inv( P'*P )*P'*E;

Sigma( 3 ) = Sigma2( 1 );
Sigma( 4 ) = Sigma2( 2 );

% (9-7) not fix alpha
tt = 0:h:( length( aa ) - 1 )*h;

alphaN = -aa;
betaN = bb( start:final ) + pi;

polyCoe1N = polyfit( tt, alphaN, 3 );
polyCoe2N = polyfit( t, betaN, 7 );

polyCoe1DerN = polyder( polyCoe1N );
polyCoe2DerN = polyder( polyCoe2N );

alphaDotN = polyval( polyCoe1DerN, t );
betaDotN = polyval( polyCoe2DerN, t );

alpha2DotN = polyval( polyder( polyCoe1DerN ), t );
beta2DotN = polyval( polyder( polyCoe2DerN ), t );


F = ( beta2DotN + Sigma( 3 )*betaDotN - Sigma( 4 )*sin( betaN ) )';
P1 = ( cos( betaN ).*alpha2DotN )';
P2 = ( alphaDotN.^2.*sin( betaN ).*cos( betaN ) )';

P = [ P1 P2 ];
Sigma2 = inv( P'*P )*P'*F;

Sigma( 1 ) = Sigma2( 1 );
Sigma( 2 ) = Sigma2( 2 );

Sigma

%{
% (9-7)
vs = 3;
G = alpha2DotN';
h1 = -( sin( betaN ).^2.*alpha2DotN + 2*alphaDotN.*betaDotN.*sin( betaN ).*cos( betaN ) + Sigma( 1 )/Sigma( 2 )*( -cos( betaN ).*beta2DotN + betaDotN.^2.*sin( betaN ) ) )';
h3 = -alphaDotN';
h4 = vs*ones( final - start + 1, 1 );
H = [ h1 h3 h4 ];

Rho2 = inv( H'*H )*H'*G;

Rho( 1 ) = Rho2( 1 );
Rho( 3 ) = Rho2( 2 );
Rho( 4 ) = Rho2( 3 );
Rho( 2 ) = Rho( 1 )*Sigma( 1 )/Sigma( 2 );

Rho
%}
vs = 3;
G = alpha2DotN';
h1 = (-sin( betaN ).^2.*alpha2DotN - 2*alphaDotN.*betaDotN.*sin( betaN ).*cos( betaN ))';
h2 = (cos( betaN ).*beta2DotN - betaDotN.^2.*sin( betaN ))';
h3 = -alphaDotN';
h4 = vs*ones( final-start+1, 1 );
H = [ h1 h2 h3 h4 ];

Rho = inv( H'*H )*H'*G;
Rho( 2 ) = Rho( 1 )*Sigma( 1 )/Sigma( 2 );
Rho