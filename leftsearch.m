function leftsearch(ax,n)
  
    global N 
    global M
    global myM 
    N = n;
    setMouse(N)
    setmyWall();
    setAxis(ax);
    goal_x = 17;
    goal_y = 16;
    x = 1;
    y = 1;
    setXY(x,y);
    car = uint16(0);
    dir = uint16(0);
    %start
    y = y + 1;
    setXY(x,y);
    t = timer('TimerFcn', 'stat=false; disp(''Timer!'')','StartDelay',10);
    start(t)
    stat=true;
    disp("OK");
    while(stat==true)
        while x ~= goal_x || y ~= goal_y
            disp("壁情報, デバッグ");
            %今いる座標の（0から15）を取得
            myM(x,y) = M(x,y);
            %今いる座標の壁の有無を表す1×4行列に変換
            now_wall = M16toW4nn(x,y);
            %1×4行列と今の方角から前後左右の壁の情報を取得
            w = getNowWall(car,now_wall);
            %前後左右の壁の情報から進行方向を決定
            disp(w);
            %元の方角と進行方向から座標を更新
            if w(1,4) == 0 %左||
                dir = 3;
            elseif w(1,1) == 0%前 8,10
                dir = 0;
                %h = viscircles(ax,[x*0.5 y*0.5],0.3);
            elseif w(1,2) == 0%右
                dir = 1;
            elseif w(1,3) == 0%後
                dir = 2;
            end
            [x, y] = changeposition(dir,car);
            setXY(x,y);
            % 移動した方向と現在の方角から新しい方角に変更
            car = changecardinal(dir);
            % 移動先の座標に円を描画
            drawMouse(x,y);
            pause(0.1);
        end
        disp("Fin");
        stat = false;

    end

    disp(myM);
    
end
%向いている方角と壁の1×4行列から、前後左右の壁の状態を返す
function w = getNowWall(car,wall)
    w = zeros(1,4);
    c = rem(car,4);
    if  c == 0
        %北
        if wall(1,1) == 1
            w(1,1) = 1;
        end
        if wall(1,2) == 1
            w(1,2) = 1;
        end
        if wall(1,3) == 1
            w(1,3) = 1;
        end
        if wall(1,4) == 1
            w(1,4) = 1;
        end
    
    elseif  c == 1
        %東
        if wall(1,1) == 1 %北
            w(1,4) = 1; %左
        end
        if wall(1,2) == 1 %東
            w(1,1) = 1; %前
        end
        if wall(1,3) == 1 %南
            w(1,2) = 1; %右
        end
        if wall(1,4) == 1 %西
            w(1,3) = 1; %後ろ
        end
    
    elseif  c == 2
        %南
        if wall(1,1) == 1
            w(1,3) = 1;
        end
        if wall(1,2) == 1
            w(1,4) = 1;
        end
        if wall(1,3) == 1
            w(1,1) = 1;
        end
        if wall(1,4) == 1
            w(1,2) = 1;
        end
    
    elseif  c == 3
        %西向き
        if wall(1,1) == 1 %北
            w(1,2) = 1; %右
        end
        if wall(1,2) == 1 %東
            w(1,3) = 1; %後ろ
        end
        if wall(1,3) == 1 %南
            w(1,4) = 1; %左
        end
        if wall(1,4) == 1 %西
            w(1,1) = 1; %後ろ
        end
    end
        %右
        %16の数値を1×4行列に直す関数を呼ぶ

end
function setXY(x,y)
    global X 
    global Y 
    X = x;
    Y = y;
end
function [x, y] = changeposition(dir,car) %現在の方角と、選んだ進行方向から、xyを更新
    global X 
    global Y 
    d = rem(dir,4);
    c = rem(car,4);
    debug = zeros(1,6);
    debug = [c car d dir X Y];
    disp(debug);
    if c == 0 %北
        if d == 0
            x = X;
            y = Y + 1;
        elseif d == 1
            x = X + 1;
            y = Y;
        elseif d == 2
            x = X;
            y = Y - 1;
        elseif d == 3 
            x = X - 1;
            y = Y;
        end
    elseif c == 1%東
        if d == 0
            x = X + 1;
            y = Y;
        elseif d == 1
            x = X;
            y = Y - 1;
        elseif d == 2
            x = X - 1;
            y = Y;
        elseif d == 3
            x = X;
            y = Y + 1;
        end
    elseif c == 2 %南
        if d == 0
            x = X;
            y = Y - 1;
        elseif d == 1
            x = X - 1;
            y = Y;
        elseif d == 2
            x = X;
            y = Y + 1;
        elseif d == 3
            x = X + 1;
            y = Y;
        end
    elseif c == 3 %西
        if d == 0
            x = X - 1;
            y = Y;
        elseif d == 1
            x = X;
            y = Y + 1;
        elseif d == 2
            x = X + 1;
            y = Y;
        elseif d == 3
            x = X;
            y = Y - 1;
        end
    end
    
                
end
function car = changecardinal(dir)
    global Car 
    
    if dir == 0 %前
        car = Car;
    elseif dir == 1 %右
        car = Car + 1;
    elseif dir == 2 %後ろ
        car = Car + 2;
    elseif dir == 3 %左
        car = Car - 1;
    else
        disp("carが変更されていない!");
    end
    Car = car;
end
function setmyWall
    global myW 
    myW = [0 1 1 1];
end
    
function setMouse(n)
    global Car
    global Dir 
    global X 
    global Y 
    global myM 
    global N
    N = n;
    myM = zeros(N,N);

    %壁配列を作成
    initWall(N);
    %壁配列を16パターンに変換
    %変換したものをmyMに入れる
    for y = 1:N
        for x = 1:N
            myM(x,y) = W4nntoM16(x,y);
        end
    end
    
    Car = uint16(0);
    Dir = uint16(0);
    X = 1;
    Y = 1;
end

function drawMouse(x,y)
    global myAxis
    %h = viscircles([x-0.5 y-0.5],0.3,myAxis);
    %clc
    rectangle(myAxis,"Position",[x-0.7 y-0.7 0.4 0.4],"Curvature",[1 1],'FaceColor','r');
end
function setAxis(ax)
    global myAxis
    myAxis = ax;
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
    global M 
    bit = zeros(1, 4);
    dec = M(x,y);
    %disp(dec);
    [q, r]=quorem(sym(dec),sym(8)); %西
    if  q == 1
        bit(1,4) = 1;
        dec = dec - 8;
    else
        bit(1,4) = 0;
    end
    [q, r]=quorem(sym(dec),sym(4));%南
    if q == 1
        bit(1,3) = 1;
        dec = dec - 4;
    else
        bit(1,3) = 0;
    end
    [q, r]=quorem(sym(dec),sym(2));
    if q == 1
        bit(1,2) = 1;
        dec = dec - 2;
    else
        bit(1,2) = 0;
    end
    [q, r]=quorem(sym(dec),sym(1));
    if q == 1
        bit(1,1) = 1;
    else
        bit(1,1) = 0;
    end
    %disp(bit);
    
    nn = bit;

end
function Var16toNN(x,y) % 座標の16進数情報を、描画処理用の配列に渡すための壁情報配列に格納
    global W  
    global N
    pos = (y-1)*N + x;
    bit = M16toW4nn(x,y);
    W(1, pos) = bit(1,1);
    W(2, pos) = bit(1,2);
    W(3, pos) = bit(1,3);
    W(4, pos) = bit(1,4);
    %disp(pos);
end