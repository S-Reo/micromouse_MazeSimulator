% mazedrawer

%縦線プロット

%横線プロット
f=figure;
figure(1);
plot([1,1],[1,31])

hold on

p = plot([3,3],[3,4]);
p.Color = "black";

xlim([0 31])
ylim([0 31])
%fprintf("あいうえお : %s",f.Color)
%%線のクラス 関数

classdef BasicLine
