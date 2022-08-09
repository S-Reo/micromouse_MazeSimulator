%% 自分用スクリプト

%% 迷路用の16進数配列に格納
function convertmazedata(maze_size, walldata)

%[maze_size, walldata,filename] = getMazeMatrix();

%%外壁と東の壁を1にした壁配列を生成 (4 × N*N行列)
%disp("initWall");

initWall(maze_size);

%配列スタートはx=1,y=maze_size。


%% N * N行列を作成
%disp("initM");

initM(maze_size);


%% 壁のテキストデータを、自分用の壁のN*N行列に格納し、壁の行列に
%disp("for文変換");
for y = maze_size:-1:1
    for x = 1:1:maze_size
        setM(x,maze_size+1-y,walldata(y,x));
        

        %m = getM;
        %disp(m(x,17-y));
        %disp(m);
        %w = getW;
        %disp(w(1:4,(17-y-1)*maze_size + x));
    end
end

Var16toNN();

%%
%m = getM;
%w = getW;


%% 壁描画用の配列
% 1で初期化
%disp("描画配列作成");
%initRraw(ones(maze_size,maze_size-1));
%initRcolumn(ones(maze_size-1,maze_size));
initRraw(ones(maze_size,maze_size));
initRcolumn(ones(maze_size,maze_size));

% 壁判定用の行列から壁描画用の行列に変換
%disp("描画配列変換");

W4NNtoDraw();

%rraw = getRraw();
%rcolumn = getRcolumn();
%Mから壁配列に変換

%disp(dec2hex(wall));
end

%
function initM(n)
    global M
    M = zeros(n,n);
end
function m = getM
    global M
    m = M;
end
function setM(x,y,val)
    global M 
    M(x,y) = val;
end

% Wから16進数はできた
% Wから16進数の行列に格納

% 4NNからdraw %一括変換する
function W4NNtoDraw 
    %端を参照しない. Drawは端の領域無
    %
    %global W 
    global Rraw
    global Rcolumn
    global N 
    %columnの(n,4)がおかしい
    w = getW();
    for y = 1:N
        for x = 1:N
            pos = (y-1)*N + x;
            if x ~= N && y ~= N
                %columnのxはN-1まで
                %rawのyはN-1まで
                Rraw(x,y) = w(1,pos);   %北
                Rcolumn(x,y) = w(2,pos);     %東

                %disp(Rcolumn(x,y));
                %disp("あ");disp(y);disp(x);
            elseif y == N && x ~= N
                Rcolumn(x,y) = w(2,pos);     %東
                
            elseif x == N && y ~= N
                Rraw(x,y) = w(1,pos);   %北
                %disp("あ");disp(y);disp(x);
            end
            % 東と北だけで大丈夫
            %Rraw(x,y) = W(3,pos);      %南
            %Rcolumn(x,y) = W(4,pos);   %西
        end
    end
    
end
function initRraw(val)
    global Rraw 
    % = zeros(nw-1,nh);
    Rraw = val;
end
function initRcolumn(val)
    global Rcolumn 
    % = zeros(nw-1,nh);
    Rcolumn = val;
end
function setRraw(a,b,val)
    global Rraw
    Rraw(a,b) = val;
end
function setRcolumn(a,b,val)
    global Rcolumn
    Rcolumn(a,b) = val;
end
function rraw = getRraw
    global Rraw
    rraw = Rraw;
end 
function rcolumn = getRcolumn
    global Rcolumn
    rcolumn = Rcolumn;
end 
function val = getR(n,raw,column)
    if n == 1
        global Rcolumn
        val = Rcolumn(raw,column);
    end
    if n == 2
        global Rraw
        val = Rraw(raw,column);
    end
end
% drawから4NN
function DrawtoW4NN
    
end

function NNtoVar16(x,y)%座標の壁情報を、アルゴリズムで使用するための16進数配列に格納
    global M
    M(x,y) = W4nntoM16(x,y);
end
function Var16toNN % 座標の16進数情報を、描画処理用の配列に渡すための壁情報配列に格納
    global W  
    global N
    for y = N:-1:1
        for x = 1:1:N
            
            pos = (y-1)*N + x;
            
            
            bit = M16toW4nn(x,y);
            
            
            W(1, pos) = bit(1,1);
            W(2, pos) = bit(1,2);
            W(3, pos) = bit(1,3);
            W(4, pos) = bit(1,4);
            
        end
    end
    %disp(pos);
end



function initWall(n)
    global W 
    global N 
    N = n;
    W = zeros(4,N*N);

    for cnt = 0:N-1
        W(1,(N*(N-1)) + cnt+1) = 1; %北
        W(2,N + (N*cnt)) = 1;       %東
        W(3,1 + cnt) = 1;           %南
        W(4,1 + (N*cnt)) = 1;       %西
    end
    %スタート時の右壁もある
    W(2,1) = 1;
end
function w = getW()
    global W 
    w = W;
end
function c = W4nntoM16(x,y) %nは1辺の区画数
    %W(座標)から値を取得し、1×4行列を作成。
    %1×4行列の組み合わせから文字を決定。ビットで。
    global W
    global N
    num = (y-1)*N + x;
    bit = W(1,num);
    bit = bit + 2*W(2,num);
    bit = bit + 4*W(3,num);
    bit = bit + 8*W(4,num);
    c = bit;
end
function nn = M16toW4nn(x,y)
    
    disp("(=_=)");
    
    global M 
    %tic
    bit = zeros(1, 4);
    dec = sym(M(x,y));
    
    
    %{
    先にsym宣言した場合
    経過時間は 0.000124 秒です。宣言の処理
    経過時間は 0.005934 秒です。quoremの処理
    %}
    %{
    quorem内で変換した場合
    経過時間は 0.005820 秒です。
    %}
    %tic
    
    [q, r]=quorem(dec,sym(8)); %西
    %0.006480
    %toc
    
    if  q
        bit(1,4) = 1;
        dec = dec - 8;
        if r == 0
            bit(1,1) = 0;
            bit(1,2) = 0;
            bit(1,3) = 0;
            nn = bit;
            return
        end
    else
        bit(1,4) = 0;
    end%0.001470 →0.000783
    [q, r]=quorem(dec,sym(4));%南
    if q
        bit(1,3) = 1;
        dec = dec - 4;
        if r == 0
            bit(1,1) = 0;
            bit(1,2) = 0;
            bit(1,4) = 0;
            nn = bit;
            return
        end
    else
        bit(1,3) = 0;
    end
    
    [q, r]=quorem(dec,sym(2));
    if q
        bit(1,2) = 1;
        dec = dec - 2;
        if r == 0
            bit(1,1) = 0;
            bit(1,3) = 0;
            bit(1,4) = 0;
            nn = bit;
            return
        end
    else
        bit(1,2) = 0;
    end

    [q, r]=quorem(dec,sym(1));
    if q
        bit(1,1) = 1;
        if r == 0
            bit(1,4) = 0;
            bit(1,2) = 0;
            bit(1,3) = 0;
            nn = bit;
            return
        end
    else
        bit(1,1) = 0;
    end
    %disp(bit);
    
    nn = bit;
    
end
function lineCallback(src,~)
    
    persistent i
    if isempty(i)
        i = 0;
    end
    
    if rem(i,2)
        src.FaceColor = 'k';%'#D7E5EE';%'#DEE4E9'; %グレー
        src.LineStyle = '-';
        src.LineWidth = 0.5;
        src.EdgeColor = 'k';
    else
        src.FaceColor = 'w';
        src.LineStyle = '-';
        src.LineWidth = 0.5;
        src.EdgeColor = 'w';
    end

    %クリックされたときに01をどこに書き込むべきかがわかればいい
    % UserDataを変換すれば、16進数に置きなおせる状態
    %disp(src.UserData(1,3));
    
    if src.UserData(1, 1) == 1
        disp(src.UserData);

        setRcolumn(src.UserData(1,2),src.UserData(1,3),rem(i,2));
        %disp("あああ");
    end
    if src.UserData(1, 1) == 2
        disp(src.UserData);
        setRraw(src.UserData(1,2),src.UserData(1,3),rem(i,2));
    end
        
    i = i + 1;
    if i==2
        i=0;
    end
end