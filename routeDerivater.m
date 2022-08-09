function Route = routeDerivater(x1, y1, x2, y2)
    % 二地点の座標を結ぶ、最短経路を求める
    global M %壁
    % ゴールがx2,y2. 
%% 壁が既知の状態で解く。→ 現在の壁の状態から解く
    % 評価値マップを作成
    global N 
    E = zeros(N,N);



%% 経路を示すxyの組み合わせの行列をRouteに返す
    % Route列を追加して、x,yを連結していく
    Route;

end