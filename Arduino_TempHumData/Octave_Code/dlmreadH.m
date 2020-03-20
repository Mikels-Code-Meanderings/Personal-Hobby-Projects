% Reading a text file with Relative Humidity data collected from the Si7021 and read
% via the arduino and saved onto an SD card 
% Depending on the situation, tweak the code to represent the current Humidity
% Data situation. Learn lots, and have fun!

clear all;
clc;
H=textread("HDATA.TXT","%f");% import temperature data form PTDATA.TXT
H1=transpose(H); % transpose the text file rows into columns
vec=columns(H1); % this makes sure the vector size is correct
h0=.25.*vec.*(1/60).*(1/60); % number hours during data measurement 
h=linspace(0,h0,vec);% to find the number of data points inter the code
% "columns(H1)" to make sure that the vector size matches.
% the arduino is taking readings every .250 seconds, and there were 
% vec data points, implying that vec*.250=#seconds...Thanks for your time.

m=mean(H1) % average Humidity
mod=mode(H1) % Most occured Humidity value
med=median(H1) % Middle value
hm=min(H1)  % Minimum Humidity value
hmax=max(H1) % Maximum Humidity value
rang=range(H1) % Humidity Range

hold on;
grid on;

plot(h,H1);


xlabel("T Hours");
ylabel("Relative Humidity %");
title("Relative Humidity vs.Time Farm Basement");
saveas(1,"FarmBaseStove","pdf");
