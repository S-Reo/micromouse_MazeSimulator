function DrawMaze(fg,ax)
    global N
    global Rcolumn
    global Rraw
    x1 = 1;
    y1 = 0;
    x2 = 1;
    y2 = 1;
    nw = N;
    nh = N;

    raw=1;
    column=1;
    figure(fg);
    %disp("DrawMazeのwhile文");
    %tic
    while x2 <= nw-1
        
        while y2 <= nh
        %h = drawline(uax,'SelectedColor','black','Position',[x1 y1; x2 y2],'Visible','on');
        %plot([x1 x2],[y1 y2],'Color','black','ButtonDownFcn',@linuCallback,'LineWidth',1.8);
        r1 = rectangle(ax,'Position',[x1-0.05 y1+0.1 0.1 1-0.2],'FaceColor','k','ButtonDownFcn',@lineCallback);
        r1.UserData = [1 raw column];
        if Rcolumn(raw,column) == 1 %N×N-1
            r1.FaceColor = 'k';%'#D7E5EE';%'#DEE4E9'; %グレー
            r1.LineStyle = '-';
            r1.LineWidth = 0.5;
            r1.EdgeColor = 'k';
        else
            r1.FaceColor = 'w';
            r1.LineStyle = '-';
            r1.LineWidth = 0.5;
            r1.EdgeColor = 'w';
        end

        %Rraw(raw, column) =uint8(1);
        y2 = y2 + 1;
        y1 = y1 + 1;
        hold on;
        column = column+1;
        end
    
    y1 = 0;
    y2 = 1;
    x1 = x1 + 1;
    x2 = x2 + 1;
    raw = raw+1;
    column = 1;
    
    end
    
    hold on;
    column = 1;
    raw = 1;
    x1 = 0;
    y1 = 1;
    x2 = 1;
    y2 = 1;
    while y2 <= nh-1
        while x2 <= nw
        %h = drawline(uax,'SelectedColor','black','Position',[x1 y1; x2 y2],'Visible','on');
        %plot([x1 x2],[y1 y2],'Color','black','ButtonDownFcn',@linuCallback,'LineWidth',1.8);
        r2 = rectangle(ax,'Position',[x1+0.1 y1-0.05 1-0.2 0.1],'FaceColor','k','ButtonDownFcn',@lineCallback);
        r2.UserData = [2 raw column];
        if Rraw(raw,column) == 1
            r2.FaceColor = 'k';%'#D7E5EE';%'#DEE4E9'; %グレー
            r2.LineStyle = '-';
            r2.LineWidth = 0.5;
            r2.EdgeColor = 'k';
        else
            r2.FaceColor = 'w';
            r2.LineStyle = '-';
            r2.LineWidth = 0.5;
            r2.EdgeColor = 'w';
        end
        %Rcolumn(raw, column) = uint8(2);
        x2 = x2 + 1;
        x1 = x1 + 1;
        raw = raw + 1;
        hold on;
        end
    
    y1 = y1+1;
    y2 = y2+1;
    x1 = 0;
    x2 = 1;
    column = column + 1;
    raw = 1;
    end
    
    xlim([0 N]);
    ylim([0 N]);
    pbaspect([1 1 1]);
    %pause(0.3);
    %toc
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
        disp("あああ");
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

function setRraw(a,b,val)
    global Rraw
    Rraw(a,b) = val;
end
function setRcolumn(a,b,val)
    global Rcolumn
    Rcolumn(a,b) = val;
end