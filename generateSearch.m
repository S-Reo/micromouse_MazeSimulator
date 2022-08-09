
%car = 0; %北
%x = 1;
%y = 2;
%route = generateSearc(x,y,car);

%引数は、新しい区画に入った時の座標と、方角
function route = generateSearch(x,y,car) % 次の目標座標までの経路配列を返す
%%経路サンプル
    %x = [1; 2;5];
    %y = [3; 4;6];
    %route = [x y];
    %%
    global M
    global myM 
   
    %disp("壁情報, デバッグ"); %1の32の壁は1101じゃないといけない 向き確認、
    %今いる座標の（0から15）を取得
    myM(x,y) = M(x,y);
    %disp(M(x,y)); %9になってる
    %今いる座標の壁の有無を表す1×4行列に変換
    now_wall = M16toW4nn(x,y);
    %disp(now_wall);
    %1×4行列と今の方角から前後左右の壁の情報を取得
    w = getNowWall(car,now_wall);
    %前後左右の壁の情報から進行方向を決定
    %disp(w);
    %元の方角と進行方向から座標を更新
    %ここまで0.04秒くらい
    dir = uint8(0);
    if w(1,4) == 0 %左||
        dir = uint8(3);
    elseif w(1,1) == 0%前 8,10
        dir = uint8(0);
        %h = viscircles(ax,[x*0.5 y*0.5],0.3);
    elseif w(1,2) == 0%右
        dir = uint8(1);
    elseif w(1,3) == 0%後
        dir = uint8(2);
    end %ここは0.000004くらい
    
    [x, y] = changeposition(x,y,dir,car);
    %disp(x);
    %disp(y);
    route = [x;y];
    %setXY(x,y);
    % 移動した方向と現在の方角から新しい方角に変更
    %car = changecardinal(dir);
end


function nn = M16toW4nn(x,y)
    
    %disp("(=_=)");
    
    global M 
    %tic
    bit = zeros(1, 4);
    dec = int16(M(x,y));
    devider8 = int16(8);
    devider4 = int16(4);
    devider2 = int16(2);
    devider1 = int16(1);
    
    
    %0.006480
    %toc
    %disp();
    %debug = [x y];
    %disp(debug);
    %debug2 = [q r];
    %disp(debug2);
    q = dec./devider8;
    if  q
        bit(1,4) = 1;
        dec = dec - 8;
    else
        bit(1,4) = 0;
    end%0.001470 →0.000783
    
    q = dec./devider4;
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,3) = 1;
        dec = dec - 4;
    else
        bit(1,3) = 0;
    end
    q = dec./devider2;
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,2) = 1;
        dec = dec - 2;
        
    else
        bit(1,2) = 0;
    end

    q = dec./devider1;
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,1) = 1;
    else
        bit(1,1) = 0;
    end
    %disp(bit);
    
    nn = bit;
    %disp(nn);
    
end
%{
function nn = M16toW4nn(x,y)
    
    %disp("(=_=)");
    
    global M 
    %tic
    bit = zeros(1, 4);
    dec = sym(M(x,y));
    q = 1;
    
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
    %disp();
    %debug = [x y];
    %disp(debug);
    %debug2 = [q r];
    %disp(debug2);
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
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,3) = 1;
        dec = dec - 4;
        if r == 0
            bit(1,1) = 0;
            bit(1,2) = 0;
            %bit(1,4) = 0;
            nn = bit;
            return
        end
    else
        bit(1,3) = 0;
    end
    
    [q, r]=quorem(dec,sym(2));
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,2) = 1;
        dec = dec - 2;
        if r == 0
            bit(1,1) = 0;
            %bit(1,3) = 0;
            %bit(1,4) = 0;
            nn = bit;
            return
        end
    else
        bit(1,2) = 0;
    end

    [q]=quorem(dec,sym(1));
    %debug2 = [q r];
    %disp(debug2);
    if q
        bit(1,1) = 1;
    else
        bit(1,1) = 0;
    end
    %disp(bit);
    
    nn = bit;
    %disp(nn);
    
end
%}
function w = getNowWall(car,wall)
    w = zeros(1,4);
    c = rem(uint8(car),uint8(4));
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
function [x, y] = changeposition(x,y,dir,car) %現在の方角と、選んだ進行方向から、xyを更新
    
    d = rem(uint8(dir),uint8(4));
    c = rem(uint8(car),uint8(4));
    %disp("c car d dir X Y")
    %debug = zeros(1,6);
    %debug = [c car d dir x y];
    %disp(debug);
    if c == 0 %北
        if d == 0
            x = x;
            y = y + 1;
        elseif d == 1
            x = x + 1;
            y = y;
        elseif d == 2
            x = x;
            y = y - 1;
        elseif d == 3 
            x = x - 1;
            y = y;
        end
    elseif c == 1%東
        if d == 0
            x = x + 1;
            y = y;
        elseif d == 1
            x = x;
            y = y - 1;
        elseif d == 2
            x = x - 1;
            y = y;
        elseif d == 3
            x = x;
            y = y + 1;
        end
    elseif c == 2 %南
        if d == 0
            x = x;
            y = y - 1;
        elseif d == 1
            x = x - 1;
            y = y;
        elseif d == 2
            x = x;
            y = y + 1;
        elseif d == 3
            x = x + 1;
            y = y;
        end
    elseif c == 3 %西
        if d == 0
            x = x - 1;
            y = y;
        elseif d == 1
            x = x;
            y = y + 1;
        elseif d == 2
            x = x + 1;
            y = y;
        elseif d == 3
            x = x;
            y = y - 1;
        end
    end
    
                
end