function [maze_size,m,filename] = getMazeMatrix

%% テキストファイルから迷路データをそのまま取得する
% 引数 : 無し
% 戻り値 : 行列, 行列サイズ

    %%テキストファイルの選択
    [filename, pathname] = uigetfile({'*.txt'}, 'Select the Maze Text');
    new_filename = sprintf("%s%s",pathname,filename);
    %new_filename = 'MazeTextData/MM2021MM.png.txt';
    %% ファイルから行列変数に格納
    m = readmatrix(new_filename,'FileType','text'); %'TrimNonNumeric'true,,'FileType','text' 
    sz = size(m);
    maze_size = sz(1,1);
    f = msgbox(sprintf('迷路サイズは %d です', maze_size)); % 迷路サイズの表示
    f.Position(1:2) = [500 100];
    disp(f.Position);
    %%
    %disp(new_filename);
    %disp(m);
    %disp(sz(1,1));
end