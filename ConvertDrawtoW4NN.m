function ConvertDrawtoW4NN
    
disp("コンバート: W,");

    %% 壁配列に変換
    DrawtoW4NN();
    global N
    global W 
    global Rcolumn
    %disp(Rcolumn(1,32));
    %disp(W(2,N*(N-1)+1));
    %% 壁配列からMazeのN*N行列に変換(0~15)の値
    
    for y = 1:N
        for x = 1:N
            NNtoVar16(x,y);
        end
    end

%disp(W(2,N*(N-1)+1));
end

function DrawtoW4NN
    global N
    initWall(N);
        %端を参照しない. Drawは端の領域無
   
    global Rraw
    global Rcolumn
    global W 
    %columnの(n,4)がおかしい
    %disp("xy");
    for y = 1:(N-1)
        for x = 1:(N-1)
            pos = (y-1)*N + x;
            %disp(pos);
            %disp(x);
            %disp(y);
            W(1,pos) = Rraw(x,y); %北
            W(2,pos) = Rcolumn(x,y);%東
            W(3,pos+N) = Rraw(x,y); %南
            W(4,pos+1) = Rcolumn(x,y);%西
            %disp(W(2,pos));
        end
    end

    %disp("xのみ");
    for x = 1:(N-1)
        pos = N*(N-1)+x;
        %disp(pos);
        %disp(x);
        W(2,pos) = Rcolumn(x,N);
        W(4,pos+1) = Rcolumn(x,N);
        %disp(W(2,pos));
    end

    for y = 1:(N-1)
        pos = y*N;
        W(1,pos) = Rraw(N,y);
        W(3,pos+N) = Rraw(N,y);
    end
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

function NNtoVar16(x,y)%座標の壁情報を、アルゴリズムで使用するための16進数配列に格納
    global M
    M(x,y) = W4nntoM16(x,y);
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