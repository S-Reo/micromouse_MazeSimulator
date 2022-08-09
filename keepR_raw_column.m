function keepR_raw_column
    global Rraw
    global Rcolumn
    disp("保存時")
    
    R = [Rraw, Rcolumn];
    disp(R);
    [filename, pathname] = uigetfile({'*.txt'}, 'Select the Maze Text about DrawMatrix');
    new_filename = sprintf('MazeDrawMatrix/%s', filename);
    %disp("この上");
    writematrix(R,new_filename);
    %disp("この上");
end