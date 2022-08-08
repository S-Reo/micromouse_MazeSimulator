%uax = uiaxes;

% 迷路サイズの指定
n = 9;
%
x1 = 1;
y1 = 0;
x2 = 1;
y2 = 1;
while x2 <= n-1
    while y2 <= n
    %h = drawline(uax,'SelectedColor','black','Position',[x1 y1; x2 y2],'Visible','on');
    plot([x1 x2],[y1 y2],'Color','black','ButtonDownFcn',@linuCallback,'LineWidth',1.8);
    %rectangle('Position',[x1 y1 x2 y2]);
    y2 = y2 + 1;
    y1 = y1 + 1;
    hold on;
    end

y1 = 0;
y2 = 1;
x1 = x1+1;
x2 = x2 + 1;
end

x1 = 0;
y1 = 1;
x2 = 1;
y2 = 1;
while y2 <= n-1
    while x2 <= n
    %h = drawline(uax,'SelectedColor','black','Position',[x1 y1; x2 y2],'Visible','on');
    plot([x1 x2],[y1 y2],'Color','black','ButtonDownFcn',@linuCallback,'LineWidth',1.8);
    x2 = x2 + 1;
    x1 = x1 + 1;
    end

y1 = y1+1;
y2 = y2+1;
x1 = 0;
x2 = 1;
end
xlim([0 n]);
ylim([0 n]);
pbaspect([1 1 1]);

function linuCallback(src,~)
    
    persistent i
    if isempty(i)
        i = 0;
    end
    
    if rem(i,2)
        src.LineStyle = ':';
    else
        src.LineStyle = '-';
    end
    i = i + 1;
end
