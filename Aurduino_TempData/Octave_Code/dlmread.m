% Reading a text file with temperature data collected from the BMP-180 and read
% via the arduino and saved onto an SD card 
% Depending on the situation, tweak the code to represent the current temperature
% Data Readings. Learn lots, and have fun!

clear all;
clc;
T=textread("PTDATAFarmBasement.TXT","%f");% import temperature data form PTDATA.TXT
T1=transpose(T); % transpose the text file rows into columns
vec=columns(T1); % this makes sure the vector size is correct
t0=.25.*vec.*(1/60).*(1/60); % number hours during data measurement 
t=linspace(0,t0,vec);% to find the number of data points inter the code
% "columns(T1)" to make sure that the vector size matches.
% the arduino is taking readings every .250 seconds, and there were 
% vec data points, implying that vec*.250=#seconds...Thanks for your time.
m=mean(T1) % average temperature
m1=num2str(m) % Not used, was expirementing with strings 
mod=mode(T1) % Most occured temp value
med=median(T1) % Middle value
tm=min(T1)  % Minimum temperature
tmax=max(T1) % Maximum Temperature
rang=range(T1) % Temperature Range
%tp=polyfit(t,T1,4);
%tp1=6.1682e-03.*t.^4-4.0587e-02.*t.^3+5.7655e-02.*t.^2-9.6588e-02.*t+6.3885e+01;
hold on;
grid on;
%plot(t,T1,"marker",'.',"markersize",6);
plot(t,T1);
%plot(t,tp1);
%text(10,64.3,"Average Temp=60.8 F  Tmax=65.3 F Tmin=57.92 F  TRange=7.38 F");

xlabel("T Hours");
ylabel("Temperature deg F");
title("Temperature Readings vs.Time Farm Bas");
%saveas(1,"Tempwall","pdf");
