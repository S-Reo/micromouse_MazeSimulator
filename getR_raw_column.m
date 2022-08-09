function [maze_size,filename] = getR_raw_column
        %%テキストファイルの選択
    [filename, pathname] = uigetfile({'*.txt'}, 'Select the Maze Text about DrawMatrix');
    new_filename = sprintf("%s%s",pathname,filename);
    %new_filename = 'MazeTextData/MM2021MM.png.txt';
    %% ファイルから行列変数に格納
    m = readmatrix(new_filename,'FileType','text'); %'TrimNonNumeric'true,,'FileType','text' 
    
    %% サイズを取得
    sz = size(m);
    maze_size = sz(1,1); %行数だけ取得
    disp("インポート後")
    disp(m);
    %% RrawとRcolumnに切り分けて格納
    global Rraw
    global Rcolumn
    r = m;
    r(:,maze_size+1:1:2*maze_size) = [];
    c = m;
    c(:,1:1:maze_size) = [];
    Rraw = r; % N行 2*N列で保存してあるのをカット
    Rcolumn = c;
    %C = setdiff(Rraw,Rcolumn);
    
    
    f = msgbox(sprintf('迷路サイズは %d です', maze_size)); % 迷路サイズの表示
    f.Position(1:2) = [500 100];
    disp(f.Position);
end